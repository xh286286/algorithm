
const int EE =10000;
const int VV = 400;
const int INF = 1000000;
int from[EE], to[EE],  cost[EE], choose[EE];
int E, V, root;
void addEdge(int f, int t, int cost_) {
	from[E] = f; to[E] = t; cost[E] = cost_;   choose[E] = false; E++;
}
static int minCost[VV], contracted[VV][VV], belong[VV],  project[VV][VV], adjustCost[EE];
void outtest1() {
	for (int i=0; i<V; i++) {
		cout<<belong[i]<<' ';
	}
	cout <<endl;
}
void outtest2() {
	for (int i=0; i<E; i++) {
		if (choose[i])
			cout<<'('<<from[i]<<' '<<to[i]<<")  ";
	}
	cout <<endl;
}
int dmst() {
	for (int i=0; i<V; i++) contracted[0][i] = i;
	for (int e=0; e<E; e++) { adjustCost[e] = cost[e]; choose[e] = false; }
	int recur = -1;
	while(true) {
		recur++;
		if (recur > 120) {
			cout<<1;
		}
		int (& conre) [VV] = contracted[recur],  (& prore) [VV] = project[recur];
		for (int i=0; i<V; i++) {
			prore[i] = -2;
			minCost[i] = INF;
		}
		project[recur][root] = -1;
		for (int e=0; e<E; e++) {
			if (to[e] == root || conre[from[e]] == conre[to[e]]) continue;
			int cset = conre[to[e]];
			if (adjustCost[e] < minCost[cset]) {
				minCost[cset] = adjustCost[e];
				project[recur][cset] = e;
			}
		}
		for (int i=0; i<V; i++) if (prore[conre[i]] == -2) return -1;
		for (int i = 0; i<V; i++) belong[i] = -1;
		bool circle = false;
		int target, mc;
		for (target=0; target<V; target++) {
			if (target==root || conre[target]!= target) continue;
			int o = target, limit = V;
			mc  = INF;
			while(true) {
				belong[o] = target;
				int e =  prore[o];
				if (e < 0) break;
				if (adjustCost[e]< mc ) mc = adjustCost[e];
				o = conre[from[e]];
				if (o == target || --limit <0 ) break;
			}
			if (o == target) { circle = true; break; }
		}	
		//	outtest1();
		if (!circle) break; 
		for (int e = 0; e<E; e++) {
			if (belong[conre[from[e]]] == target || belong[conre[to[e]]] != target ) continue;
			adjustCost[e] -= adjustCost[prore[conre[to[e]]]] + mc;
		}
		for (int i=0; i<V; i++) {
			if (belong[conre[i]] == target) contracted[recur+1][i] = target;
			else contracted[recur+1][i] = conre[i];
		}
	}
	while(true) {
		for (int i=0; i<V; i++) {
			if (contracted[recur][i] != i) continue;
			int e = project[recur][i];
			if (e>=0) choose[e] = true;
		}
		//	outtest2();
		if (recur -- == 0) break;
		for (int e = 0; e < E; e++) {
			if (!choose[e] ) continue;
			project[recur][contracted[recur][to[e]]] = -1;
		}

	}

	int result = 0;
	for (int e = 0; e<E; e++) if (choose[e]) result += cost[e];
	return result;
}
