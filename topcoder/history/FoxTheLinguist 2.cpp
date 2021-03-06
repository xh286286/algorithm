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


const int EE =10000;
const int VV = 10000;
const int INF = 1000000;
int from[EE], to[EE],  cost[EE];
int circle[VV], proj[VV], root;
vector<int> edges[VV];
int E, V;
void clearGraph() {
	for (int i=0; i<V; i++) edges[i].clear();
}
void addEdge(int f, int t, int cost_) {
	edges[f].push_back(E);
	edges[t].push_back(E);
	from[E] = f; to[E] = t; cost[E] = cost_;   E++;
}

int dmst() {
	int minCost[VV];
	for (int i=0; i<V; i++) {
		proj[i] = -2;
		minCost[i] = INF;
	}
	proj[root] = -1;
	for (int e=0; e<E; e++) {
		if (to[e] == root) { continue; }
		if (cost[e] < minCost[to[e]]) {
			minCost[to[e]] = cost[e];
			proj[to[e]] = e;
		}
	}
	for (int i=0; i<V; i++) if (proj[i] == -2) {return -1;}
	while(true) {
		bool done = true;
		int target ;
		for (target = 0; target<V; target++) circle[target] = -1;
		for (target=0; target<V; target++) {
			if (target==root) continue;
			circle[target] = target;
			int o = from[proj[target]];
			int limit = V;
			while(o!=target && proj[o]>=0 && --limit>=0) {
				circle[o] = target;
				o = from[proj[o]];
			}
			if (o != target) continue;
			done = false;
			break;
		}
		if (done) break;
		int  ti2 = -1, center,  minEdit = INF;
		for (int e=0; e<E; e++) {
			if (circle[from[e]] == target || circle[to[e]] != target) continue;
			int e0 = proj[to[e]];
			if (cost[e] - cost[e0] < minEdit ) {
				minEdit = cost[e] - cost[e0]; 
				ti2 = e; center = to[e];
			}
		}
		if (ti2<0) return -1;
		proj[center] = ti2;
	}
	int result = 0;
	for (int i=0; i<E; i++) if (proj[i] >= 0) result += cost[proj[i]];
	return result;
}



class FoxTheLinguist {
public:
	int minimalHours(int, vector <string>);
};

int FoxTheLinguist::minimalHours(int n, vector <string> courseInfo) {
	E = 0;
	string s = accumulate(courseInfo.begin(), courseInfo.end(), string(""));
	V = n*10 + 1;
	root = n*10;
	for (int i=0; i<n; i++) {
		addEdge(root, i*10,0);
		for (int j = 9; j>0; j--) {
			addEdge(i*10+j, i*10+j-1,0);
		}
	}
	int z= 0;
	while(z<s.size() && s[z]!=' ') {
		int c1, c2;
		int l1, l2;
		int hour;
		c1 = s[z] - 'A';
		l1 = s[z+1] - '0';
		z+=4;
		c2 = s[z] - 'A';
		l2 = s[z+1] - '0';
		z+=3;
		hour = (s[z]-'0') * 1000 + (s[z+1]-'0') * 100+ (s[z+2]-'0') * 10+ (s[z+3]-'0') ;
		addEdge(c1*10+l1, c2*10+l2, hour);
		z+=5;
	}
	int result = dmst();
	clearGraph();
	return result;
}




double test0() {
	int p0 = 1;
	string t1[] = {"A0->A9:1000 A0->A6:0300 A3->A9:0600"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	FoxTheLinguist * obj = new FoxTheLinguist();
	clock_t start = clock();
	int my_answer = obj->minimalHours(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 900;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
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
	//string t1[] = {"A0->A9:1000 B0->B9:1000 A1->B9:0300 B1->A9:0200"};
	string t1[] = {"B0->B9:1000 B1->A9:0200"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	FoxTheLinguist * obj = new FoxTheLinguist();
	clock_t start = clock();
	int my_answer = obj->minimalHours(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1200;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
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
	string t1[] = {"C0->A6:00", "01 A3", "->B9:0001 A3->C6:000", "1",
		" C3->A9:0001 A9->C9:0001 A0->A9:9999",
		" B0->B9:9999 C0->C9:9999 A6->A9:9999"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	FoxTheLinguist * obj = new FoxTheLinguist();
	clock_t start = clock();
	int my_answer = obj->minimalHours(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
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
	string t1[] = {"A0->A6:6666 A0->A9:9999",
		" B0->B6:6666 B0->B9:9999",
		" C0->C6:6666 C0->C9:9999",
		" D0->D6:6666 D0->D9:9999",
		" A6->B6:0666 B6->C6:0666",
		" C6->D6:0666 D6->A6:0666",
		" A9->B9:0099 B9->C9:0099",
		" C9->D9:0099 D9->A9:0099"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	FoxTheLinguist * obj = new FoxTheLinguist();
	clock_t start = clock();
	int my_answer = obj->minimalHours(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 10296;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 1;
	string t1[] = {"A0->A9:9999 A0->A9:8888"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	FoxTheLinguist * obj = new FoxTheLinguist();
	clock_t start = clock();
	int my_answer = obj->minimalHours(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 8888;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int p0 = 1;
	string t1[] = {"A9->A9:0000",
		" A9->A0:0000"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	FoxTheLinguist * obj = new FoxTheLinguist();
	clock_t start = clock();
	int my_answer = obj->minimalHours(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
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


	time = test2();
	if (time < 0)
		errors = true;

	time = test0();
	if (time < 0)
		errors = true;

	time = test1();
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

//Powered by [KawigiEdit] 2.0!
