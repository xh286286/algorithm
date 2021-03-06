#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


const int EE =10000;
const int VV = 10000;
const int INF = 1000000;
int from[EE], to[EE],  cost[EE];
int circle[VV], proj[VV], root;
vector<int> edges[VV];
int E, V;
void clearGraph() {
	for (int i=0; i<V; i++) edges[i].clear();
}
void addEdge(int f, int t, int cost_) {
	edges[f].push_back(E);
	edges[t].push_back(E);
	from[E] = f; to[E] = t; cost[E] = cost_;   E++;
}

int dmst() {
	int minCost[VV];
	for (int i=0; i<V; i++) {
		proj[i] = -2;
		minCost[i] = INF;
	}
	proj[root] = -1;
	for (int e=0; e<E; e++) {
		if (to[e] == root) { continue; }
		if (cost[e] < minCost[to[e]]) {
			minCost[to[e]] = cost[e];
		}
	}
	for (int i=0; i<V; i++) {
		if (proj[i] == -2) return -1;
		circle[i] = -1;
	}
	int acc = 0;
	while(true) {
		acc++;
		bool done = true;
		int target = -1;
		for (target=0; target<V; target++) {
			if (target==root) continue;
			circle[target] = acc;
			int o = from[proj[target]];
			while(o!=target && proj[o]>=0) {
				circle[o] = acc;
				o = from[proj[o]];
			}
			if (o != target) continue;
			done = false;
			break;
		}
		if (done) break;
		int  ti2 = -1, center,  minEdit = INF;
		for (int e=0; e<E; e++) {
			if (circle[from[e]] == acc || circle[to[e]] != acc) continue;
			int e0 = proj[to[e]];
			if (cost[e0] - cost[e] < minEdit ) {
				minEdit = cost[e0] - cost[e]; 
				ti2 = e; center = to[e];
			}
		}
		if (ti2<0) return -1;
		proj[center] = ti2;
	}
	int result = 0;
	for (int i=0; i<E; i++) if (proj[i] >= 0) result += cost[proj[i]];
	return result;
}



class FoxTheLinguist {
public:
	int minimalHours(int, vector <string>);
};

int FoxTheLinguist::minimalHours(int n, vector <string> courseInfo) {
	E = 0;
	string s = accumulate(courseInfo.begin(), courseInfo.end(), string(""));
	V = n*10 + 1;
	for (int i=0; i<n; i++) {
		addEdge(n*10, i*10+9,0);
		for (int j = 9; j>0; j--) {
			addEdge(i*10+j-1, i*10+j,0);
		}
	}
	int z= 0;
	while(z<s.size() && s[z]!=' ') {
		int c1, c2;
		int l1, l2;
		int hour;
		c1 = s[z] - 'A';
		l1 = s[z+1] - '0';
		z+=4;
		c2 = s[z] - 'A';
		l2 = s[z+1] - '0';
		z+=3;
		hour = (s[z]-'0') * 1000 + (s[z+1]-'0') * 100+ (s[z+2]-'0') * 10+ (s[z+3]-'0') ;
		addEdge(c2*10+l2, c1*10+l1, hour);
	}
	int result = dmst();
	clearGraph();
	return result;
}
