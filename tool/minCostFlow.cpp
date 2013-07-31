const int EE =10000;
const int VV = 10000;
const int INF = 1000000;
int from[EE], to[EE], cap[EE], cost[EE];
int dist[VV], how[VV];
int E, V, src, sink;
int n,m;
void addEdge(int f, int t, int cost_, int capacity) {
	from[E] = f; to[E] = t; cost[E] = cost_; cap[E] = capacity;  E++;
	from[E] = t; to[E] = f; cost[E] = -cost_; cap[E] = 0;  E++;
}
int mcmf() {
	int maxFlow = 0;
	int minCost = 0;
	while(true) {
		for (int i=0; i<V; i++) dist[i] = INF;
		dist[src] = 0;

		while(true) {
			bool done = true;
			for (int i=0; i<E; i++) {
				if (cap[i] == 0) continue;
				int u = from[i]; int v = to[i];
				if (dist[u] + cost[i] < dist[v]) {
					dist[v] = dist[u] + cost[i];
					how[v] = i;
					done = false;
				}
			}
			if (done) break;
		}
		if (dist[sink] >= INF) break;
		int aug = INF;
		for (int z = sink; z != src; z = from[how[z]]) {
			aug = min(cap[how[z]], aug);
		}
		for (int z = sink; z != src; z = from[how[z]]) {
			cap[how[z]] -= aug;
			cap[how[z]^1] +=aug;
		}
		maxFlow += aug;
		minCost += aug * dist[sink];
	}
	return minCost;
}


#define SZ(c)     ((int)(c).size())
#define REP(i,n)  for (int i=0; i<(n); ++i)
#define FORC(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)

const int  INF = 10000000;
const int  EE = 1000;
const int  VV = 1000;

int V, E, src, sink;
int from[EE], to[EE], cap[EE], cost[EE];
int dist[VV], how[VV];

void edge(int u, int v, int c, int w) {
	from[E] = u; to[E] = v; cap[E] = c; cost[E] = +w; ++E;
	from[E] = v; to[E] = u; cap[E] = 0; cost[E] = -w; ++E;
}

int mcmf() {
	int ret = 0;

	for (;;) {
		REP(i, V) dist[i] = INF;
		dist[src] = 0;

		for (;;) {
			int done = 1;

			REP(e, E) if (cap[e] > 0) {
				int u = from[e], v = to[e];

				if (dist[u] + cost[e] < dist[v]) {
					dist[v] = dist[u] + cost[e];
					how[v] = e;
					done = 0;
				}
			}

			if (done) break;
		}
		if (dist[sink] > 10000) break;

		int aug = INF;
		for (int i=sink; i!=src; i=from[how[i]])
			aug = min(aug, cap[how[i]]);

		for (int i=sink; i!=src; i=from[how[i]]) {
			cap[how[i]] -= aug;
			cap[how[i]^1] += aug;
		}

		ret += dist[sink] * aug;
	}

	return ret;
}