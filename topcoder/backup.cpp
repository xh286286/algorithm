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
class  Test{
public:
	int test(vector<int>, vector<int>, vector<string>) {
		return 0;
	}

} work;
#define  workFunc test
#define  NNN  3
typedef int RRR;

typedef vector<int> AAA;
typedef vector<int> BBB;
typedef vector<string> CCC;
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
