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


const int EE =10000;
const int VV = 400;
const int INF = 1000000;
int from[EE], to[EE],  cost[EE], choose[EE];
int E, V, root;
void addEdge(int f, int t, int cost_) {
	from[E] = f; to[E] = t; cost[E] = cost_;   choose[E] = false; E++;
}
static int minCost[VV], contracted[VV][VV], belong[VV],  proj[VV][VV], adjustCost[EE];
void outtest1() {
	for (int i=0; i<V; i++) {
		cout<<belong[i]<<' ';
	}
	cout <<endl;
}
void outtest2() {
	for (int i=0; i<E; i++) {
		if (choose[i])
		cout<<'('<<from[i]<<' '<<to[i]<<")  ";
	}
	cout <<endl;
}
int dmst() {
	for (int i=0; i<V; i++) contracted[0][i] = i;
	for (int e=0; e<E; e++) { adjustCost[e] = cost[e]; choose[e] = false; }
	int recur = -1;
	while(true) {
		recur++;
		if (recur > 120) {
			cout<<1;
		}
		int (& conre) [VV] = contracted[recur],  (& prore) [VV] = proj[recur];
		for (int i=0; i<V; i++) {
			prore[i] = -2;
			minCost[i] = INF;
		}
		proj[recur][root] = -1;
		for (int e=0; e<E; e++) {
			if (to[e] == root || conre[from[e]] == conre[to[e]]) continue;
			int cset = conre[to[e]];
			if (adjustCost[e] < minCost[cset]) {
				minCost[cset] = adjustCost[e];
				proj[recur][cset] = e;
			}
		}
		for (int i=0; i<V; i++) if (prore[conre[i]] == -2) return -1;
		for (int i = 0; i<V; i++) belong[i] = -1;
		bool circle = false;
		int target, mc;
		for (target=0; target<V; target++) {
			if (target==root || conre[target]!= target) continue;
			int o = target, limit = V;
			mc  = INF;
			while(true) {
				belong[o] = target;
				int e =  prore[o];
				if (e < 0) break;
				if (adjustCost[e]< mc ) mc = adjustCost[e];
				o = conre[from[e]];
				if (o == target || --limit <0 ) break;
			}
			if (o == target) { circle = true; break; }
		}	
	//	outtest1();
		if (!circle) break; 
		for (int e = 0; e<E; e++) {
			if (belong[conre[from[e]]] == target || belong[conre[to[e]]] != target ) continue;
			adjustCost[e] -= adjustCost[prore[conre[to[e]]]] + mc;
		}
		for (int i=0; i<V; i++) {
			if (belong[conre[i]] == target) contracted[recur+1][i] = target;
			else contracted[recur+1][i] = conre[i];
		}
	}
	while(true) {
		for (int i=0; i<V; i++) {
			if (contracted[recur][i] != i) continue;
			int e = proj[recur][i];
			if (e>=0) choose[e] = true;
		}
	//	outtest2();
		if (recur -- == 0) break;
		for (int e = 0; e < E; e++) {
			if (!choose[e] ) continue;
			proj[recur][contracted[recur][to[e]]] = -1;
		}

	}

	int result = 0;
	for (int e = 0; e<E; e++) if (choose[e]) result += cost[e];
	return result;
}



class EllysReversals {
public:
	int getMin(vector <string>);
};

int EllysReversals::getMin(vector <string> words) {
	int n = words.size();
	int tot[70][50][50];
	int total[50][50];
	int single[50];
	SET0(tot);
	SET0(total);
	SET0(single);
	for (int i=0; i<n; i++) {
		for (int j =0; j<words[i].size()/2; j++) {
			char a,b;
			a = words[i][j*2];
			b = words[i][j*2+1];
			if (a>b) swap(a,b);
			tot[i][a-'a'][b-'a'] ++;
			total[a-'a'][b-'a']++;
		}
	}
	bool kickout[100];
	SET(kickout,false);
	REP(i,n) if( words[i].size() %2 ==1) single[words[i][words[i].size()-1] -'a'] ++;
	root = 0;

	REP(j,26) REP(i,j+1) {
		REP(k,n) {
			if (tot[k][i][j] > total[i][j] / 2.0)
				kickout[k] = true;
		}
	}
	int result = 0;

	V = n+1;
	bool engage[100];
	SET(engage,false);
	REP(j,26) REP(i,j+1) {
		if (total[i][j] % 2 == 0) continue;
		bool done = false;
		REP(k,n) {
			if (tot[k][i][j] == 0 ) continue;
			if (kickout[k]) done = true;
		}
		if (done) continue;
		REP(k,n) {
			if (tot[k][i][j] == 0 ) continue;
			engage[k] = true;
			addEdge(k+1, V, 0);
			addEdge(V, k+1, 0);
		}
		V++;
	}
	REP(i,26) {
		if (single[i] %2==0) continue;
		bool done = false;
		REP(k,n) {
			if (words[k].size() %2 ==0) continue;
			if (words[k][words[k].size()-1]-'a' != i) continue;
			if (kickout[k]) done = true;
		}
		if (done) continue;
		REP(k,n) {
			if (words[k].size() %2 ==0) continue;
			if (words[k][words[k].size()-1]-'a' != i) continue;
			engage[k] = true;
			addEdge(k+1, V, 0);
			addEdge(V, k+1, 0);
		}
		V++;
	}
	REP(i,n) {
		int cost = 1;
		if (kickout[i] ) {
			cost = 0; result ++; 
		}
		if (!engage[i]) cost = 0;
		addEdge(root,i+1,cost);
	}

	return result+dmst();
}


double test0() {
	string t0[] = {"esprit", "god", "redotopc", "odcpoter", "dog"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	EllysReversals * obj = new EllysReversals();
	clock_t start = clock();
	int my_answer = obj->getMin(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
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
	string t0[] = {"no", "zaphod", "just", "very", "improbable"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	EllysReversals * obj = new EllysReversals();
	clock_t start = clock();
	int my_answer = obj->getMin(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
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
	string t0[] = {"rats", "live", "stressed", "to", "act", "as", "star", "desserts", "of", "evil", "cat", "sa", "fo", "ot"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	EllysReversals * obj = new EllysReversals();
	clock_t start = clock();
	int my_answer = obj->getMin(p0);
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
double test3() {
	string t0[] = {"topcoder", "redocpot", "doretopc", "cpotdoer", "harlemshake"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	EllysReversals * obj = new EllysReversals();
	clock_t start = clock();
	int my_answer = obj->getMin(p0);
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
double test4() {
	string t0[] = {"iprlzgukfggzg", "bmhxvjbrtkbxy", "khapjiabbny", "nqlwgmcyvdikt",
		"nxromtvtpug", "leealcapovm", "ushnxwjczczbmd", "bwhykzupcux",
		"xrlboyuwlnsp", "bbjoketeheezfs", "dxfztrldomjqkv", "dkbktqdtgfujcut",
		"zfybzyuxgpnt", "ffmsldrdftode", "vopuufksxd", "pqhbsiujwda",
		"yhwbkzupcux", "hkbabnapjiy", "zqsqefrrzehtxn", "yovinyguyudmv"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	EllysReversals * obj = new EllysReversals();
	clock_t start = clock();
	int my_answer = obj->getMin(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 16;
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

	time = test2();
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
