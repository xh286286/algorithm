#include "LongInt.h"
#include <QtCore/QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;
ifstream fin; 
ofstream fout;

void preWork();
void work();
//  setprecision£¡@£¡£¡£¡£¡£¡£¡
int sorttime;
int main(int argc, char *argv[])
{
	//preWork();
	QCoreApplication a(argc, argv);
	fin.open ( "input.txt");
	int now =clock();
	sorttime=0;
	fout.open("output.txt");
	int n;
	fin >>n;
	for (int i=0; i<n; i++)
	{
		fout<<"Case #"<<i+1<<": ";
		cout<<"Case #"<<i+1<<": begin";
		int time0 = clock();
		work();
		int time1 = clock();
		fout<<endl;
		cout<<" end, time cost "<< (time1 - time0) / 1000.0<<endl;
	}
	int now2= clock();
	cout<<now<<endl<<now2<<endl<< now2-now<<endl;
	cout<<sorttime<<endl;
	fin.close();
	fout.close();
}

void preWork()
{

}

bool verify(vector<long long> a, vector<long long> b, long long f0, long long f1) {
	int i;
	for (i=36; i>=0; i--) {
		if (a[i]!=b[i]) break;
	}
	int j;
	for (j=i; j>=0; j--) {
		if (a[j]!=a[i]) break;
	}
	for (int k=j; k>=0; k--) {
		if (a[k]!=a[i]-1) return false;
	}
	for (int x = 0; x<37; x++) {
		f0+=a[x]-b[x];
		if (a[x]<b[x]) return false;
	}
	if (f0 ==  f1) return true;
	return false;
}

double check(vector<long long> a, vector<long long> b) {
	long long o = 0;
	 
	for (int i=0; i<36; i++) {
		o += b[i];
		if (a[i]<a[i+1]) {
			long long t = a[0] * (i+1);
			return (t-o)/double(t) * 36 * a[0]; 
		}
	}	
	return 0;
}
double getResult1(vector<long long> a, long long B) {
	long long B0;
	vector<long long> b;
	b = a;
	B0 = B;
	for (int i=0; i<36; i++) {
		if (a[i] == a[i+1]) continue;	
		long long dif = a[i+1] - a[i];
		long long  t = B0 / (i+1);
		long long z = min(t, dif);
		for (int j=0; j<=i; j++) a[j]+=z;
		B0-=z*(i+1);
		if (t >= dif) continue;
		break;
	}
	int x= 36;
	for (int i=0; i<36; i++) {
		if (a[i] == a[i+1]) continue;
		x = i; 
		break;
	}
	int zzz = 40;
	while(B0>0 && zzz-- > 0 && x>=0) {
		a[x]++;
		x--;
		B0--;
	}

	int kkk = 100;
	double result = 0;
	x++;
	while(kkk-->0 ) {
		bool flag = verify(a,b,B0,B);
		assert(flag);
		double z = check(a,b) + B0 - B;
		if (z > result) result = z;
		if (a[x]==b[x]) x = 0;
		if (a[x]==b[x]) break;
		a[x]--;
		B0++;
		x++;
	}
	return result;
}
bool calc(long long v, long long h, vector<long long> a, long long B, double & result) {
	long long bet = 0, extra = 0;
	for (int i=0; i<v; i++) {
		if (a[i] < h) bet+= h-a[i];
		if (a[i]>h) return false;
	}
	for (int i=v; i<37; i++) {
		if (a[i] <= h) {
			extra += h+1-a[i];
		}
	}
	if (extra+bet > B) return false;
	result = double(bet) / v * 36 -bet - extra;
	return true;
}
double getResult2(vector<long long> a, long long B) {
	double result = 0;
	vector<long long> b;
	for (int i=1; i<=35; i++) {
		long long top,bot;
		top = a[36];
		bot = a[i-1];
		double r = 0;
		while(bot < top-1) {
			long long m = (top+bot) /2;
			if (calc(i,m,a,B,r)) {
				bot = m;
			}
			else {
				top = m;
			}
		}
		calc(i,bot,a,B,r);
		if (r>result) result = r;

	}
	return result;
}
void work()
{
	long long B;
	int n;
	fin>>B>>n;
	vector<long long> a;
	a.resize(37);
	for (int i=0; i<n; i++) fin>>a[i];
	sort(a.begin(), a.end());
	double r1,r2;
	r1 = getResult1(a,B);
	r2 = getResult2(a,B);
	if (r1 != r2) {
		cout<<11212<<endl;
	}
	//fout<< r1 <<' '<< r2;
	fout<<setprecision(10)<<r1;
}