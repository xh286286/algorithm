
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

long long get2power(int x) {
	long long result = 1,  ob = 2;
	while (x>0) {
		if (x%2 == 1) result = (result * ob )% modulo;
		x/=2;
		ob = (ob * ob) % modulo;
	}
	return result;
}


void main() {
	long long n,m,k;
	cin >>n>>m>>k;
	long long om = m;
	long long  disturb = min ( n-m, m/(k-1));
	m -= (k-1) * disturb;

	long long dou = m/k;

	long long result = 0;
	result = (k * 2) % modulo * (get2power(dou) - 1 + modulo) % modulo;
	result += om - dou * k;
	cout<<result%modulo;
}