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
	a1 = n-a;
	if (a1<0) a1 = 0;
	a1 *= n-b;
	if (a1<0) a1 = 0;

	if (a==b) a1 *= 4;
	else  a1*= 8;

	double a2 = 0;
	int tot;
	if (a==b) di = direct2;
	else di = direct1;
	if (a==b) tot = 4;
	else tot = 8;

	for (int i=0; i<tot; i++) {
		for (int j=0; j<tot; j++) {
			if (i==j) continue;
			int x0,y0,x1,y1;
			x0 = y0 = x1 = y1 = 0;
			x0 = min(di[i][0], x0);
			y0 = min(di[i][1], y0);
			x1 = max(di[i][0], x1);
			y1 = max(di[i][1], y1);
			x0 = min(di[j][0], x0);
			y0 = min(di[j][1], y0);
			x1 = max(di[j][0], x1);
			y1 = max(di[j][1], y1);
			long long z = n-(x1-x0);
			if (z<0) z = 0;
			z *= n - (y1 - y0);
			if (z<0) z = 0;
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

double test0() {
	int p0 = 2;
	int p1 = 1;
	int p2 = 1;
	TheKnights * obj = new TheKnights();
	clock_t start = clock();
	double my_answer = obj->find(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 3.3333333333333335;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 47;
	int p1 = 7;
	int p2 = 74;
	TheKnights * obj = new TheKnights();
	clock_t start = clock();
	double my_answer = obj->find(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 2.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 3;
	int p1 = 2;
	int p2 = 1;
	TheKnights * obj = new TheKnights();
	clock_t start = clock();
	double my_answer = obj->find(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 4.888888888888889;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 9999;
	int p1 = 999;
	int p2 = 99;
	TheKnights * obj = new TheKnights();
	clock_t start = clock();
	double my_answer = obj->find(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 16.25885103191273;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 10;
	int p1 = 1;
	int p2 = 6;
	TheKnights * obj = new TheKnights();
	clock_t start = clock();
	double my_answer = obj->find(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 7.636363636363637;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
