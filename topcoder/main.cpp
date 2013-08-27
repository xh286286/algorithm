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
template <class T> void refreshMin(T & a, const T & b) {if (a>b) a = b;}
template <class T> void refreshMax(T & a, const T & b) {if (a<b) a = b;}
class XorAndSum {
public:
long long maxSum(vector<long long> number);

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long Arr0[] = {1,0}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(0, Arg1, maxSum(Arg0)); }
	void test_case_1() { long Arr0[] = {1,2,3}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 8LL; verify_case(1, Arg1, maxSum(Arg0)); }
	void test_case_2() { long Arr0[] = {0,0,0,0,0,0,0,0,0,0}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(2, Arg1, maxSum(Arg0)); }
	void test_case_3() { long Arr0[] = {2,3,5,7,11,13,17,19}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 233LL; verify_case(3, Arg1, maxSum(Arg0)); }
	void test_case_4() { long Arr0[] = {123456789012345, 0, 0, 0, 0, 0, 0, 0, 0, 0}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1234567890123450LL; verify_case(4, Arg1, maxSum(Arg0)); }
	void test_case_5() { long Arr0[] = {627,674,281,272,289,877,62,122,603,189,615}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 10742LL; verify_case(5, Arg1, maxSum(Arg0)); }
	void test_case_6() { long Arr0[] = {557}; vector<long long> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 557LL; verify_case(6, Arg1, maxSum(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(){
XorAndSum ___test;
___test.run_test(-1);
system("pause");
}
// END CUT HERE
#line 42 "main.cpp"
long long XorAndSum :: maxSum(vector<long long> number) {
//$CARETPOSITION$
}
