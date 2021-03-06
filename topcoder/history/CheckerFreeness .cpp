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

class CheckerFreeness {
public:
	string isFree(vector <string>, vector <string>, vector <string>, vector <string>);
};
vector<int> conta(vector<string> & vs) {
	string s;
	for (int i=0; i<vs.size(); i++)  s+=vs[i];
	istringstream iss(s);
	int z;
	vector<int> r;
	while(iss>>z) {
		r.push_back(z);
	}
	return r;
}
vector<int> wx,wy, bx,by;
struct Angle{
	Angle(int x_, int y_) {
		x = x_ , y = y_;
		e = -1;
		bool sw = false;
		if (x>0) {	if (y>=0) e = 0;}
		else  { if (y>0) { e = 1; sw=true; } }
		if (x<0) { if (y<=0) e = 2; }
		else { if (y<0)  {e = 3;sw = true; } }
		if (x<0) x=-x; if (y<0) y=-y;
		if (sw) swap(x,y);
	}
	long long int x, y;
	int e;
	bool operator < (const Angle & b) {
		if (e < b.e) return true;
		if (y * b.x < b.y * x) return true;
		return false;
	}
};

struct Node {
	int index;
	char  color;
	Angle a;
	bool operator< (const Node & b) {
		if (a<b.a) return true;
		return false;
	}
};
vector<Node> circle[230];
string CheckerFreeness::isFree(vector <string> whiteX, vector <string> whiteY, vector <string> blackX, vector <string> blackY) {
	wx = conta(whiteX);
	wy = conta(whiteY);
	bx = conta(blackX);
	by = conta(blackY);
	for (int i=0; i<wx.size(); i++) {
		circle[i].clear();
		for (int j=0; j<bx.size(); j++) {
			Node o;
			o.a = Angle(bx[j] - wx[i], by[j] - wx[i]);
			o.index =j;
			circle[i].push_back(o);
		}
		sort(circle[i].begin(), circle[i].end());
	}
	for (int i=0; i<wx.size(); i++) {
		for (int j=i+1; j<wx.size(); j++) {
			int z = circle[i][0].index;
			int pos = -1;
			for (int k=0; k<bx.size(); k++) {
				if (circle[j][k].index == z) { pos = k; break; }
			}
			for (int k=0; k<bx.size(); k++) {
		}
	}
	return "NO";
}

//Powered by [KawigiEdit] 2.0!