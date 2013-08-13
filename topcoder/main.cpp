
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
const long long modulo = 1000000007;
#define SET0(zn) memset(zn,0,sizeof(zn))
#define SET(zn, k) memset(zn,k,sizeof(zn))
#define REP(i,n)  for (int i=0; i<(n); ++i)
typedef long long LL;

class KeyDungeonDiv1 {
public:
	int maxKeys(vector <int>, vector <int>, vector <int>, vector <int>, vector <int>, vector <int>);
};
int dy[151][1<<12];
vector <int> doorR;
vector <int> doorG;
vector <int> roomR;
vector <int> roomG;
vector <int> roomW;
vector <int> keys;
int n;
void find(int stats) {
	int result;
	if (stats == 0) {
		for (int redKey =0; redKey<= 130; redKey++) {
			if (keys[0] + keys[2] < redKey) dy[redKey][stats] = -100000;
			else if (keys[0]>=redKey)  dy[redKey][stats] = keys[1] + keys[2];
			else dy[redKey][stats] = keys[0] + keys[2] - redKey + keys[1];
		}
		return;
	} 
	for (int redKey =0; redKey< 150; redKey++) {
		dy[redKey][stats] = -10000;
	}
	for (int redKey =0; redKey<= 130; redKey++) {
		for (int i=0; i<n; i++) {
			if (((1<<i)&stats) ==0) continue;
			int z = (1<<i) ^ stats;
			int leftg = dy[redKey][z];
			if (leftg <0) continue;
			if (leftg > dy[redKey][stats]) dy[redKey][stats] = leftg;
			if (redKey<doorR[i] || leftg < doorG[i]) continue;
			for (int k =0; k<=roomW[i]; k++) {
				int newleftr = redKey-doorR[i] + k + roomR[i];
				int newleftg = leftg - doorG[i] + roomG[i] + roomW[i] - k;
				if (dy[newleftr][stats] < newleftg) dy[newleftr][stats] = newleftg;
			}
		}	
	}
}
int KeyDungeonDiv1::maxKeys(vector <int> _doorR, vector <int> _doorG, vector <int> _roomR, vector <int> _roomG, vector <int> _roomW, vector <int> _keys) {
	doorR = _doorR;
	doorG = _doorG;
	roomR = _roomR;	
	roomG = _roomG;
	roomW = _roomW;
	keys = _keys;
	n= doorR.size();

	SET(dy,-1);
	for (int i=0; i<= (1<<n)-1; i++){
		if (i==(1<<n)) {
			int z =1;
		}
		find(i);
	}
	int result = 0;		
	for (int i=0; i<=130; i++) {
		int d = dy[i][(1<<n) -1] + i;
		if (d>result ) result = d;
	}
	return result;
}

//
//Powered by [KawigiEdit] 2.0!


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
