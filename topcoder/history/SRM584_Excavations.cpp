#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <string>
#include <vector>
#include <sstream> 
using namespace std;
ifstream fin; 
typedef vector<int> vecint;
typedef vector<string> vecstr;
typedef long long int lli;
//SRM 584
const int MAX = 40;
const int modulo = 1000000007;
struct Node {
	int kind;
	int index;
	int depth;
};
bool cmp1(Node a, Node b) {
	if (a.depth < b.depth) return true;
	return false;
}

class  Excavations{
public:
	long long count(vector <int> kind, vector <int> depth, vector <int> found, int K){
		vector<int> foundFlag;
		foundFlag.resize(100);
		for (int i=0; i<100; i++) foundFlag [i] = 0;
		for (int i=0; i<found.size(); i++) foundFlag[found[i]] = 1;
		int n;
		n = kind .size();
		vector<Node> z;
		z.resize(n);
		for (int i=0; i<n; i++) {
			z[i].kind = kind[i];
			z[i].depth = depth[i];
		}
		sort(z.begin(),  z.end(), cmp1);
		for (int i=0; i<n; i++) {
			z[i].index = i;
		}
		long long result = 0;
		int top,bot;
		for (top =0; top<=n; top++) {
			if (top!=n && foundFlag[z[top].kind]!=0) continue;
				long long d0[2][100], d1[2][100];
				memset(d0,0,sizeof(d0));
				d0[0][0] = 1;
				for (int kkk = 0; kkk<51; kkk++) {
					for (int pos =0; pos<n; pos++) {
						if (z[pos].kind != kkk) continue;
						if (pos == top) {
							memset(d1,0,sizeof(d1));
						}
						else {
							memcpy(d1,d0,sizeof(d1));
						}
						bool flag;
						if (foundFlag[kkk]) {
							if (top== n || z[pos].depth < z[top].depth) flag = true;
							else flag =false;
						}
						else {
							flag = false;
						}
						if (foundFlag[kkk] || pos>= top)
						for (int j=0; j<K; j++) {
							if (flag) d1[1][j+1] +=d0[0][j] + d0[1][j];
							else {
								d1[0][j+1] += d0[0][j];
								d1[1][j+1] += d0[1][j];
							}
						}
						memcpy(d0,d1,sizeof(d0));
					}
					int key = foundFlag[kkk];
					for (int i=0; i<100; i++) {
						d0[0][i] = d0[key][i];
						d0[1][i] = 0;
					}
				}

				result += d0[0][K];
		}
		return result;
	}

};
Excavations work;
#define  workFunc count
#define  NNN  4
typedef long long RRR;

typedef vector<int> AAA;
typedef vector<int> BBB;
typedef vector<int> CCC;
typedef int DDD;
typedef int EEE;
typedef int FFF;


AAA aaa;
BBB bbb;
CCC ccc;
DDD ddd;
EEE eee;
FFF fff;

int getData(istringstream & iss, int) {
	int z;
	iss>>z;
	if (iss.fail()) return 0;
	return z;
}

string getData(istringstream & iss, const string &) {

	string s;
	char c;
	iss >>c;
	if (iss.fail()) return "";
	assert(c=='"');
	while(true) {
		iss.get(c);
		if (c=='"') break;
		s+=c;
	}
	return s;
}

template<class T>
vector<T> getData(istringstream & iss, const vector< T > &) {
	vector<T> data;
	char c;
	while (true) {
		iss>>c;
		if (iss.fail()) return data;
		if (c=='}') break;
		assert(c=='{' || c==',');
		T temp = getData(iss, T());
		data.push_back(temp);
	}
	return data;
}


int main() {

	fin.open ( "input.txt");
	string ss;
	while (!fin.eof()) {
		char c[1000];
		fin.getline(c,1000);
		ss+=  string(c);
		ss += ' ';

	}
	istringstream iss(ss);
	RRR result;

	aaa = getData(iss, AAA());
	bbb = getData(iss, BBB());
	ccc = getData(iss, CCC());
	ddd = getData(iss, DDD());
	eee = getData(iss, EEE());
	fff = getData(iss, FFF());

#if NNN == 1
	result = work.workFunc(aaa);
#elif NNN == 2
	result = work.workFunc(aaa,bbb);
#elif NNN == 3
	result = work.workFunc(aaa,bbb,ccc);
#elif NNN == 4
	result = work.workFunc(aaa,bbb,ccc,ddd);
#elif NNN == 5
	result = work.workFunc(aaa,bbb,ccc,ddd,eee);
#elif NNN == 6
	result = work.workFunc(aaa,bbb,ccc,ddd,eee,fff);
#endif
	return 0;
}
