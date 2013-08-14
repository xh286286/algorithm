// BEGIN CUT HERE

// END CUT HERE
#line 5 "main.cpp"
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
const long long modulo = 1234567891;
#define SET0(zn) memset(zn,0,sizeof(zn))
#define SET(zn, k) memset(zn,k,sizeof(zn))
#define REP(i,n)  for (int i=0; i<(n); ++i)
typedef long long LL;

class TheMagicMatrix {
public:
int find(int n, vector <int> rows, vector <int> columns, vector <int> values);

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4, 4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 10; verify_case(0, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arr1[] = {0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4, 7}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 0; verify_case(1, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 4; int Arr1[] = {0, 0, 0, 1, 2, 2, 2, 3, 3, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 3, 0, 1, 2, 0, 1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 5, 1, 9, 5, 1, 8, 6, 7, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 2; verify_case(2, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 474; int Arr1[] = {44, 77}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {47, 74}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4, 7}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 83494518; verify_case(3, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
TheMagicMatrix ___test;
___test.run_test(-1);
system("pause");
}
// END CUT HERE

vector< vector<int> >  equations;
pair<int,int> store[1000];
int maxIndex, baseEquation;
int getIndex(int a, int b) {
	pair<int,int> z = make_pair(a,b);
	for (int i =1; i<maxIndex; i++) if (store[i] == z) return i ;
	store[maxIndex] = z;
	return maxIndex++;
}
bool simplify() {
	int n = equations.size(), ind;
	REP(i,n) equations[i] .resize(maxIndex);
	baseEquation = 0; ind = maxIndex-1;
	int i;
	while(true) {
		if (ind ==0 || baseEquation == equations.size()) break;
		for (i=baseEquation; i<equations.size(); i++) {
			if (equations[i][ind] !=0) break;
		}
		if (i==equations.size()) {
			ind--; continue;
		}
		swap(equations[i], equations[baseEquation]);
		for (i=baseEquation+1; i<equations.size(); i++) {
			for (int j=0; j<=ind; j++) {
				equations[i][j] = equations[i][j] * equations[baseEquation][ind] - equations[baseEquation][j] * equations[i][ind];
				equations[i][j] %= 10;				
			}
		}
		baseEquation++;
		ind --;
	}
	for (i = baseEquation; i< equations.size(); i++) {
		if (equations[i][0] %10 != 0) return false;		
	}
	return true;
}
long long getResult(int z) {
	long long f = 1;
	while(--z>=0) f = (f*10) % modulo;
	return f;
}
int TheMagicMatrix :: find(int n, vector <int> rows, vector <int> columns, vector <int> values) {
	maxIndex = 1;
	equations.clear();
	if (n>rows.size() || rows.size() == 0 ) {
		return getResult( n*n - 2*n + 2 - rows.size());
	}
	int uni = getIndex(-1,-1);
	for (int i=0; i<n; i++) {
		vector<int> a,b;
		a.resize(200); b.resize(200);
		a[1] = 1; b[1] = 1;
		for (int j=0; j<n; j++) {
			a[getIndex(i,j)] = 1;
			b[getIndex(j,i)] = 1;
		}
		equations.push_back(a);
		equations.push_back(b);
	}
	for (int i=0; i<rows.size(); i++) {
		vector<int> a;
		a.resize(200);
		a[0] = values[i];
		a[getIndex(rows[i], columns[i])] = 1;
		equations.push_back(a);
	}
	if (!simplify()) return 0;
	bool flag = true;
	for (int i=2; i<maxIndex; i++) {
		if (equations[baseEquation-1][i] !=0) {
			flag = false;
			break;
		}
	}
	long long g =  getResult( n*n+1 - baseEquation);	
	if (!flag) return g;
	int acc = 0;
	for (int i = 0; i<10; i++) {
		int z = i * equations[baseEquation-1][1] - equations[baseEquation-1][0];
		if (z%10 == 0 ) acc++;
	}
	return (g * acc) % modulo;
}
