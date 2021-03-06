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
#include <cstring>
using namespace std;
#define SIZE(vn) vn.size()
const long long modulo = 1000000009;
#define SET0(zn) memset(zn,0,sizeof(zn))
#define SET(zn, k) memset(zn,k,sizeof(zn))
#define REP(i,n)  for (int i=0; i<(n); ++i)
typedef long long LL;
class CoinsGame {
public:
	int ways(vector <string>);
};
static const int d4[4][2] ={ {1,0}, {0,1}, {-1,0}, {0,-1} };
struct PP {
	int x0, y0, x1, y1;
	void moveLeft(int i) {
		x0+=d4[i][0];
		y0+=d4[i][1];
	}
	void moveRight(int i) {
		x1+=d4[i][0];
		y1+=d4[i][1];
	}
};
int N,M;
char dy[1300000];
vector <string> board;
deque<int> que;
int getLabel(int x0, int y0, int x1, int y1) {
	int a = x0 * M + y0;
	int b = x1 * M + y1;
	if (a>b) return b * M * N + a;
	else return a * M * N + b;
}
int getLabel(const PP &p) { return getLabel(p.x0, p.y0, p.x1, p.y1); }

PP getPP(int z) {
	int a,b;
	b = z%(M*N);
	a = z/(M*N);
	PP p;
	p.y0 = a%M;
	p.x0 = a/M;
	p.y1 = b%M;
	p.x1 = b/M;
	return p ;
}

char getChar(int x, int y) {
if (x<0 || x>=N || y<0 || y>=M) return '?';
return board[x][y];
}
void work(const PP & p) {
	int z= getLabel(p);
	if (dy[z]!=0) return;
	dy[z] = 2;
	if (getChar(p.x0,p.y0) != '.') return;
	if (getChar(p.x1,p.y1) != '.') return;
	if (p.x0 == p.x1 && p.y0 == p.y1) return;
	dy[z] = 1;
	que.push_back(z);
}
int CoinsGame::ways(vector <string> board_) {
	board  = board_;
	SET0(dy);
	N = board.size();
	M = board[0].size();
	que.clear();
	REP(x1,N) REP(y1,M){
		if (board[x1][y1]=='#') continue;
		dy[getLabel(x1,y1,x1,y1)] = 2;
		if (x1 != 0 && x1 !=N-1 && y1!=0 && y1 !=M-1) continue;
		REP(x0,N) REP(y0, M) {
			if (board[x0][y0] =='#') continue;
			int r = 2;
			if (x1 == 0 || x1 ==N - 1) if (x0!=x1) r=1;
			if (y1 == 0 || y1 == M-1) if (y0!=y1) r=1;
			int z = getLabel(x0,y0,x1,y1);
			dy[z] = r; 
			que.push_back(z); 
		}
	}	

	while(que.size() > 0) {
		PP p = getPP(que.front());
		que.pop_front();
		for (int i=0; i<4; i++) {
			PP np = p;
			np.moveLeft(i); np.moveRight(i);
			work(np);
			PP g = p;
			g.moveLeft((i+2)%4);
			if (getChar(g.x0,g.y0)=='#') {
				np = p;
				np.moveRight(i);
				work(np);
			}
			g = p;
			g.moveRight((i+2)%4);
			if (getChar(g.x1,g.y1)=='#') {
				np = p;
				np.moveLeft(i);
				work(np);
			}
		}
	}

	long long result = 0;

	REP(x0,N) REP(y0, M) {
		if (board[x0][y0] !='#') continue;
		int x1 = x0, y1 = y0;
		long long z0, z1, z2, z3;
		z0 = 1; z1 = 0;
		while (true) {
			y1++;
			if (y1>=M) {
				y1 = 0; x1++;
			}
			if (x1>=N) break;
			if (board[x1][y1] != '#') continue;
			//z2 = 
			//if (dy[getLabel(x0,y0,x1,y1)] ==1 ) {
			//	
			//}
		}
	}


}

//Powered by [KawigiEdit] 2.0!