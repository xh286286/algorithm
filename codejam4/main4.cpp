//#include "LongInt.h"
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
#include <ctime>
using namespace std;
ifstream fin; 
ofstream fout;

void preWork();
void work();
int sorttime;
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	preWork();
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

double * st[21];
bool * flag[21];


void preWork()
{
	int t = 1;
	for (int i=0; i<=20; i++) {
		flag[i] = new bool[t];
		memset(flag[i],false, sizeof(bool)*t);
		st[i] = new double[t];
		t*=2;
	}
}
int n;
double getResult(string s) {
	int x = -1;
	for (int i=0; i<n; i++) {
		if (s[i] =='.') {
			x= i; 
			break;
		}
	}
	if (x==-1) return 0;
	int z = 0;
	for (int i=1; i<n; i++) {
		z = z*2;
		if (s[ (x+i) % n] == 'X') z += 1;
	}
	if (flag[n][z]) return st[n][z];

	int acc = 0;
	int acf = 0;
	int nf = n;
	double cost = 0;
	for (int i=0; i<n; i++) {
		int f = (x+1+i) % n;	
		if (s[f]=='X') {
			acc++;
			acf+=nf;
			nf--;
		}
		else {
			string s1 = s;
			s1[f] = 'X';
			acf+=nf;
			acc++;
			cost += ( acf + acc * getResult(s1) ) / n;
			acc = 0;
			acf = 0;
			nf = n;
		}
	}
	flag[n][z] = true;
	st[n][z] = cost;
	return cost;
}
void work()
{
	string s;
	fin >> s;
	n= s.size();
	fout<<setprecision(11)<<getResult(s);
}
