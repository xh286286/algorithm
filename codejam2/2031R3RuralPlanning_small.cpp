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

//  越界 问题  浮点 除 变 整除，  abs 问题


void preWork();
void work();
void work1();
int sorttime;
int main(int argc, char *argv[])
{
	//preWork();
	QCoreApplication a(argc, argv);

	//	char * inputName="A-large.in";
	//	fin.open(inputName);
	//	fin.open ( "A-small-practice.in");
	//fin.open ( "A-large-practice.in");
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


	fin.close();

	fout.close();
	int now2= clock();
	
	cout<<now<<endl<<now2<<endl<< now2-now<<endl;
	cout<<sorttime<<endl;

	//	return a.exec();
}


void preWork()
{


}
struct Point 
{
	double x,y;
	Point operator - (const Point & b)
	{
		Point c;
		c.x = x- b.x;
		c.y = y- b.y;
		return c;
	}
};
bool intersect(Point a0, Point b0, Point a1, Point b1, double & t0, double & t1, Point & r)
{
	Point p1,p2,p3;
	p1=  b0-a0;
	p2= b1-a1;
	p3= a0 - a1;
	const double denominator =  p1.x * p2.y  - p1.y * p2.x ;
	if (abs(denominator) < 1e-10)
	{
		return false;
	}
	double na, nb;
	na= p2.x* p3.y - p3.x* p2.y;
	na/= denominator;

	nb= p3.y* p1.x - p1.y* p3.x ;
	nb/= denominator;

	t0= na;
	t1= nb;

	r.x= a0.x+ p1.x* na;
	r.y= a0.y+ p1.y*na;

	return true;
}

bool parallelLine(Point a0, Point b0, Point a1, Point b1)
{
	Point p1,p2;
	p1= b0-a0;
	p2= b1-a1;
	if (   p1.y* p2.x - p1.x* p2.y ==0) return true; else return false;
}
bool contact(Point a0, Point b0, Point a1, Point b1) {
	double t0,t1;
	Point r;
	if (intersect(a0,b0,a1,b1,t0,t1,r)) {
		if (t0 + 1e-10>=0 && t0 - 1e-10<=1 && t1 + 1e-10>=0 && t1 - 1e-10<=1) return true;
		return false;
	}
	Point z0,z1, l;
	l = a1-b1;
	double s = sqrt(l.x * l.x + l.y * l.y);
	double s1,s2, g1,g2;
	z0 = a0-a1;
	z1 = a0-b1;
	g1 = sqrt(z0.x * z0.x + z0.y * z0.y);
	g2 = sqrt(z1.x * z1.x + z1.y * z1.y) ;
	s1 = g1 + g2;
	if (abs(s-s1) <1e-10) return true;

	z0 = b0-a1;
	z1 = b0-b1;
	g1 = sqrt(z0.x * z0.x + z0.y * z0.y);
	g2 = sqrt(z1.x * z1.x + z1.y * z1.y) ;
	s1 = g1 + g2;
	if (abs(s-s1) <1e-10) return true;
	return false;
}
bool check(vector<Point> ps) {
	int n = ps.size();
	ps.push_back(ps[0]);
	for (int i=0; i<n; i++) {
		for (int j=i+2; j<n; j++) {
			if (i==0 && j == n-1) continue;
			if (contact(ps[i],ps[i+1], ps[j], ps[j+1])) return false;
		}
	}
	return true;
}

double getSize(vector<Point> ps) {
	int n = ps.size();
	ps.push_back( ps[0] );
	double size = 0;
	for (int i=0; i<n; i++) {
		size += (ps[i].x - ps[i+1].x) * (ps[i].y + ps[i+1].y) / 2;
	}
	if (size<0) return -size;
	return size;
}

void work() {
	vector<int> z,result;
	int n;
	fin >>n;
	Point ps[20];
	for (int i=0; i<n; i++) {
		fin>>ps[i].x >>ps[i].y;
	}
	int total = 1;
	z.resize(n);
	for (int i=0; i<n; i++) {
		z[i] = i;
		total *= i+1;
	}
	total /=n;
	double maxSize = 0;
	for (int i=0; i<total; i++) {
		vector<Point> pps;
		for (int j=0; j<n; j++) pps.push_back(ps[z[j]]);
		if (!check(pps)) {
			next_permutation(z.begin(),z.end());
			continue;
		}
		double s = getSize(pps);
		if (s>maxSize) {
			maxSize = s;
			result = z;
		}
		next_permutation(z.begin(),z.end());
	}
	for (int i=0; i<n; i++) {
		fout<<result[i]<<' ';
	}
}