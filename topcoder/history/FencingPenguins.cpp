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
#define REP(i,n)  for (int i=0; i<(n); ++i)
#define SET0(zn) memset(zn,0,sizeof(zn))
#define SET(zn, k) memset(zn,k,sizeof(zn))
const long long modulo = 100007;
class FencingPenguins {
public:
	int countWays(int, int, vector <int>, vector <int>, string);
};
struct Point {
	double x, y;
};
vector<Point> postPosi;
bool edgeOk[300][300];
int edgeContain[300][300];
long long dy[300][300];
long long dy0[300][300];
int n,m;
vector <int> px, py;
string pcolor;
void direction(int ai, int bi, int x, int y, int & hori, int & vert) {
	hori = 0; vert = 0;
	double difx,dify;
	difx = postPosi[ai].x - postPosi[bi].x;
	dify = postPosi[ai].y - postPosi[bi].y;
	if (abs(difx) > 1e-6) {
		double ny = (x - postPosi[bi].x) / difx *  dify + postPosi[bi].y;
		if (ny > y) vert = 1; else vert = -1;
	}
	if (abs(dify) > 1e-6) {
		double nx = (y - postPosi[bi].y) / dify *  difx + postPosi[bi].x;
		if (nx > x) hori = 1; else hori = -1;
	}
}
bool inside(int x, int y) {
	int a1 = 0, a0 = 0;
	REP(i,n) {
		double x0 = postPosi[i].x, x1 = postPosi[i+1].x;
		if ( x< min(x0,x1) || x> max(x0,x1) ) continue;
		int h,v;
		direction(i,i+1, x,y, h,v);
		if (v > 0) a1++;
		if (v < 0) a0++;
	}
	return a1*a0 > 0;
}
bool contain(int ai, int bi, int x, int y) {
	double difx = postPosi[ai].x - postPosi[bi].x;
	double dify = postPosi[ai].y - postPosi[bi].y;
	int h,v;
	direction(ai, bi, x,y, h,v);
	if (abs(difx) < 1e-6) {
		if (dify>0) { if (h == 1) return true; }
		else {cout<<"error";}
	}
	else if (difx>0) {
		if (v==-1) return true; 
	}
	else {
		if (v==1) return true; 
	}
	return false;
}
long long find(int ai, int bi) {
	if (dy[ai][bi]>=0) return dy[ai][bi];
	if (ai+1>=bi) return 1;
	dy[ai][bi] = 0;
	int num = edgeContain[ai][bi];
	if (num ==0) return 1;
	long long r = 0;
	for (int i = ai; i<bi; i++) {
		for (int j=i+1; j<bi; j++) {
			if (!edgeOk[i][j]) continue;
			//if (edgeContain[i][j]!=num) continue;
			long long t = find0(i,j);
			long long t1 = find(j,bi);
			r = (r + t*t1) % modulo;
		}
	}
	dy[ai][bi] = r;
	return r;
}
long long find0(int ai, int bi) {
	if (dy[ai][bi]>=0) return dy[ai][bi];
	dy[ai][bi] = 0;
	
	

}
int FencingPenguins::countWays(int numPosts, int radius, vector <int> x, vector <int> y, string color) {
	px = x;
	py = y;
	pcolor = color;
	const double PI = acos(-1.0);
	n = numPosts; m = x.size();
	postPosi.resize(n+1);
	REP(i,n) {
		double angle =  double(i) / n * 2 * PI;
		postPosi[i].x = cos(angle); 
		postPosi[i].y = sin(angle);
	}
	postPosi[n] = postPosi[0];
	SET0(edgeContain);
	SET(edgeOk,false);
	REP(i,m) if (!inside(x[i],y[i])) return 0;
	REP(i,n+1) REP(j,i) {
		int ttt = (i-j) % n;
		if ( ttt <= 1 || ttt >= n - 1 )  continue;
		int colorStats[200];
		SET0(colorStats);
		bool ok = true;
		int acc = 0;
		REP(k,m) {
			if (contain(j,i,x[k],y[k])) {
				if (colorStats[color[k]] == -1) { ok = false; break; }
				acc ++;
				colorStats[color[k]] = 1;
			}
			else {
				if (colorStats[color[k]] == 1) { ok = false; break; }
				colorStats[color[k]] = -1;
			}
		}
		edgeOk[j][i] = ok;
		edgeOk[i][j] = ok;
		edgeContain[i][j] = acc;
		edgeContain[j][i] = acc;
	}
	edgeContain[0][n] = m;
	edgeOk[0][n] = true;
	SET(dy, -1);
	SET(dy0,-1);
	return find(0,n);
}

//<%:testing-code%>
//Powered by [KawigiEdit] 2.0!