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

class DirectionBoard {
public:
	int getMinimum(vector <string>);
};
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
int getIndex(int x, int y) {
	if (x<0 || x>=n || y<0 || y>=m) return -1;
	return x*m + y;
}
int DirectionBoard::getMinimum(vector <string> board) {
	n = board.size();
	m = board[0].size();
	E = 0;
	V = n*m*2+2;
	src = n*m*2;
	sink = n*m*2+1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			static const int direct4[4][2] ={ {1,0}, {0,1}, {-1,0}, {0,-1} };
			static const char move[4] = { 'D', 'R', 'U', 'L'};
			int acc = 0;
			for (int k =0 ; k<4; k++) {
				int x,y;
				x = i+direct4[k][0] + n; x %= n;
				y = j+direct4[k][1] + m; y %= m;
				if (board[x][y] == move[(k+2)%4]) acc++;
				if (move[k]!=board[i][j]) {
					addEdge(getIndex(i,j)*2+1, getIndex(x,y)*2, 0, 1);
				}
			}
			if (acc == 0) {
				addEdge(getIndex(i,j)*2+1, sink, 0, 1);
			}
			else if (acc>1) {
				addEdge(src, getIndex(i,j)*2, 0, acc-1);
			}
		}
	}
	return mcmf();
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!