#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
const long long modulo = 1000000007;
#define SET0(zn) memset(zn,0,sizeof(zn))
#define SET(zn, k) memset(zn,k,sizeof(zn))
#define REP(i,n)  for (int i=0; i<(n); ++i)
typedef long long LL;




class TheKnights {
public:
	double find(int n, int a, int b);
};

double TheKnights::find(int n, int a, int b) {
	int direct1[8][2] = { {a,b}, {b,a}, {a,-b}, {-b,a}, {-a,-b}, {-b,-a}, {-a,b}, {b,-a} };
	int direct2[4][2] = { {a,b}, {a,-b}, {-a,-b}, {-a,b}};
	int (*di) [2] ;
	long long a1; 
	if (a==b) a1 = (long long) (n-a)*(n-b) * 4;
	else  a1 = (long long) (n-a)*(n-b) * 8;
	if (a1<0) a1 = 0;
	double a2 = 0;
	int tot;
	if (a==b) di = direct2;
	else di = direct1;
	if (a==b) tot = 4;
	else tot = 8;

	for (int i=0; i<tot; i++) {
		for (int j=0; j<tot; j) {
			if (i==j) continue;
			int x0,y0,x1,y1;
			x0 = y0 = x1 = y1 = 0;
			x0 = min(di[i][0], x0);
			y0 = min(di[i][1], y0);
			x1 = max(di[i][0], x1);
			y1 = max(di[i][1], y1);
			long long z = n-(x1-x0);
			z *= n - (y1 - y0);
			if (z<0) z == 0;
			a2 += z;
		}
	}
	long long grid = n;
	grid *= n;
	double grid2 = grid;
	grid2 *= grid;

	double deno = (grid2 -grid);
	double nume = double(grid - 1) * (a1 + grid) * 2 - a1 * 2 -a2;
	return nume / deno;
}