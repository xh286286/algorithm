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




class TriangleXor {
public:
	int theArea(int);
};

int TriangleXor::theArea(int W) {
	static long long z1[100000], z2[100000], z3[100000];
	for (int i=0; i<100000; i++) {
		z1[i] = i;
		z2[i] = i*i;
		z3[i] = i*i*i;
	}
	for (int i=1; i<100000; i++) {
		z1[i]+= z1[i-1];
		z2[i]+= z2[i-1];
		z3[i]+= z3[i-1];
	}
	double result = 0;
	for (int ab = 0; ab<=W; ab++) {
		double y = double(W -ab) / (2*W - ab);
		double s = y*y/2 * ( double(W) * (ab+1)  -z1[ab]  );
		if ( (W-ab) %2 == 1) result -=s;
		else result +=s;
	}
	result *= 2;
	for (int i=1; i<=W; i++) {
		if (i%2==1) result += i/2.0;
		else result -= i/2.0;
	}
	result *= 2;
	if (W %2 ==0) result += W;
	int xxx = result;
	if (xxx>result ) xxx--;
	return xxx;
}

//<%:testing-code%>
//Powered by [KawigiEdit] 2.0!

double test0() {
	int p0 = 1;
	TriangleXor * obj = new TriangleXor();
	clock_t start = clock();
	int my_answer = obj->theArea(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 2;
	TriangleXor * obj = new TriangleXor();
	clock_t start = clock();
	int my_answer = obj->theArea(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
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
	TriangleXor * obj = new TriangleXor();
	clock_t start = clock();
	int my_answer = obj->theArea(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 4;
	TriangleXor * obj = new TriangleXor();
	clock_t start = clock();
	int my_answer = obj->theArea(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 5;
	TriangleXor * obj = new TriangleXor();
	clock_t start = clock();
	int my_answer = obj->theArea(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int p0 = 12345;
	TriangleXor * obj = new TriangleXor();
	clock_t start = clock();
	int my_answer = obj->theArea(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4629;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
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

	time = test5();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
