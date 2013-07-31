//#include "LongInt.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
//#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <cassert>
#include <cmath>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <sstream>

using namespace std;
//ifstream fin; 
//ofstream fout;

//  越界 问题  浮点 除 变 整除，  abs 问题

//  容器的初始化 clear

// 查看 归并 排序 等 算法， 插入排序
#define  __int64 long long int

void preWork();
void work();
void work1();
int sorttime;
int main(int argc, char *argv[])
{


	//	char * inputName="A-large.in";
	//	fin.open(inputName);


	int now =clock();
	sorttime=0;
//	fout.open("output.txt");

#define  _MULTITASK

#ifdef _MULTITASK
	int n;
	//fin >>n;
	cin>>n;
	for (int i=0; i<n; i++)
	{
//		fout<<"Case #"<<i+1<<": ";
		//work1();
		work();
		cout<<endl;
		//if (!cin) break;
//		fout<<endl;
	}

#else
	//work1();
	work();
#endif
//	fin.close();

//	fout.close();
	int now2= clock();

//	cout<<now<<endl<<now2<<endl<< now2-now<<endl;
//	cout<<sorttime<<endl;


}
void preWork() {}


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
bool intersect(Point a0, Point b0, Point a1, Point b1, double & t0, double & t1, Point & r);
bool parallelLine(Point a0, Point b0, Point a1, Point b1);
int point_line_position(Point a0, Point b0, Point c, double & na, Point & t);
double hypotenuse(double a, double b)
{
	return sqrt(a*a+b*b);
}
vector < Point > polygon;
vector <Point > hill;
Point central;

void  rotateChoice(int v, Point t, Point c, int & nv, Point & nt, Point & nc, bool directionLeft );
void output(Point p);
//double rightBound;
void work()
{
	polygon.clear();
	hill.clear();

	int n;
	cin >>n;
	Point p;
	for (int i=0; i<n; i++)
	{
		cin >>p.x>>p.y;
		polygon.push_back(p);
	}
	cin>>central.x>>central.y;
	vector<Point> slope;
	while( true)
	{
		cin >>p.x>>p.y;
		slope.push_back(p);
		if (p.y==0) break;
	}
	slope.back().x+=1000;
	cin >>p.x>>p.y;
	//rightBound = p.x;
	hill.push_back(p);
	for (int i=0; i<(int)slope.size(); i++)
	{
		double a,b;
		b= slope[i].x / ( sqrt(1+ slope[i].y* slope[i].y));
		a= slope[i].y * b;
		p.x-=b;
		p.y-=a;
		hill.push_back(p);
	}
	
	vector < int > intersectIndex;

	for (int i=0; i<(int)polygon.size(); i++)
	{
		for (int j=0; j<(int)hill.size()-1; j++)
		{
			double na, z;
			Point p;
			z= point_line_position(hill[j],  hill[j+1],  polygon[i], na,p);
			if (z==0 && na>=0 && na<=1)
			{
				intersectIndex.push_back(i);
			}
		}
	}
	assert(intersectIndex.size()>0);
	int minI, maxI;
	minI=intersectIndex[0]; maxI=intersectIndex[0];

	for (int i=0; i<(int)intersectIndex.size(); i++)
	{
		int z;
		z = intersectIndex[i];
		if (polygon[z].x > polygon[maxI].x)
		{
			maxI=z;
		}
		if (polygon[z].x < polygon[minI].x)
		{
			minI=z;
		}
	}
	int v;
	
	bool rotateLeft;

	if (central.x< polygon[minI].x)
	{
		v= minI;
		rotateLeft =true;
	}
	else if (central.x> polygon[maxI].x)
	{
		v= maxI;
		rotateLeft =false;
	}
	else
	{
		output(central);
		return;
	}
	Point nowc, nowt;
	nowc= central;
	nowt= polygon[v];
	int nowv;
	nowv = v;
	while( true)
	{
		Point newc, newt;
		int newv;
		rotateChoice(nowv,nowt,nowc,newv,newt,newc,rotateLeft);

		//Point dis0,dis1;
		//dis0= newt- nowt;
		//dis1= polygon[nowv]- polygon[newv];
		//double d0,d1;
		//d0 = hypotenuse( dis0.x, dis0.y);
		//d1 = hypotenuse( dis1.x, dis1.y);
		if (newc.y>= nowc.y) break;
		nowc= newc;
		nowt= newt;
		nowv= newv;
		if (rotateLeft)
		{
			if (nowc.x>= nowt.x) break;
		}
		else
		{
			if (nowc.x<=nowt.x) break;
		}
	}
	output(nowc);
}



int point_line_position(Point a0, Point b0, Point c, double & na, Point & t) // return 0 online, 1 up, -1 down;
{
	Point p1,p2;
	p1= b0-a0;
	p2= c-a0;
	na= p2.x / p1.x;

	t.x=  p1.x*na +a0.x;
	t.y= p1.y*na + a0.y;

	if (   p1.y* p2.x - p1.x* p2.y ==0) 
	{
		return 0; 
	}
	double y;
	y= na * p1.y + a0.y;
	if (abs(y-c.y) <1e-6) return 0;
	if (y > c.y) return -1;
	else return 1;
}

void point_vertical_line(Point a,Point b, Point v, double & na, Point & t)
{
	Point c,d;
	c= b-a;
	d= a-v;
	//double na;
	na= - ( c.y*d.x +c.y*d.x) / ( c.y*c.y + c.x* c.x);
	
	t.x=  c.x*na +a.x;
	t.y= c.y*na + a.y;


}

vector<Point> findRotateInterPoint(double length, Point t)
{
	Point a,b,c,d;
	vector<Point> re;
	for (int i=0; i<(int)hill.size()-1; i++)
	{
		a= hill[i];
		b= hill[i+1];
		double na;
		Point ip;
		point_vertical_line(a,b,t,na,ip);
		c= ip -t;
		double g;
		g=  hypotenuse(c.x, c.y);
		double f;
		f= sqrt(length * length - g*g);
		d= b-a;
		double ld;
		ld = hypotenuse(d.x,d.y);
		f/= ld;
		
		double aa;
		aa= na+f;
		if (aa>=0 && aa<=1)
		{
			Point p;
			p.x= d.x*aa + a.x;
			p.y= d.y*aa + a.y;
			re.push_back(p);
		}
	}
	return re;
}
double vectorAngle(Point p)
{
	static double pi = acos(-1.0);
	double length;
	length = hypotenuse(p.x,p.y);
	double z= acos( p.x/ length);
	if (p.y<0) z= 2*pi-z;
	return z;
}
Point rotatePoint ( Point l, Point c, double angle)
{
	double oangle;
	double length;
	length= hypotenuse(l.x, l.y);
	oangle= vectorAngle( l);
	oangle += angle;
	Point r;
	r.x = c.x + length * cos(oangle);
	r.y = c.y + length * sin(oangle);
	return r;
}
void  rotateChoice(int v, Point t, Point c, int & nv, Point & nt, Point & nc , bool  directionLeft)
{
	static double pi = acos(-1.0);
	vector<double > allAngle;
	for (int i=0; i<(int)polygon.size(); i++)
	{
		if (i== v) continue;
		double length;
		Point ab;
		ab= polygon[i]- polygon[v];
		length= hypotenuse(ab.x,ab.y);
		vector<Point > interPoint;
		interPoint = findRotateInterPoint(length,t);
		double originAngle;
		originAngle = vectorAngle(ab);
		for (int j=0; j< (int) interPoint.size(); j++)
		{
			Point disP;
			disP= interPoint[j]- t;
			double ddd;
			ddd= hypotenuse(disP.x, disP.y);
			double angle;
			angle=  vectorAngle( interPoint[j] - t);
			angle-= originAngle;
			if (angle <0) angle+=2*pi;
			if (angle>= 2*pi) angle -= 2*pi;
			allAngle.push_back(angle);

			Point vvv;
			vvv= rotatePoint(polygon[i]- polygon[v],t,angle);
			int zzzz;
			zzzz=1;
		}
	}
	sort(allAngle.begin(), allAngle.end());
	unique(allAngle.begin(), allAngle.end());
	double extremeX;
	int extremeIndex = -1;
	Point extremePoint ;
	extremeX = t.x;
	for (int i=0; i<(int) allAngle.size(); i++)
	{
		double angle= allAngle[i];
		int equal;
		int down;
		equal =0;
		down =0;
		double ex= t.x;
		int eindex = -1;
		Point ep;
		for (int j=0; j<(int)polygon.size(); j++)
		{
			if (j==v) continue;
			Point p;
			p= rotatePoint(polygon[j]-polygon[v], t,angle);
			bool visited;
			visited =false;
			for (int k=0; k<(int) hill.size()-1; k++)
			{
				Point a,b;
				a= hill[k];
				b= hill[k+1];
				double na;
				Point tt;
				int z;
				z= point_line_position(a,b,p,na,tt);
				if (na>=0 && na<=1)
				{
					visited = true;
					if (z==0)
					{
						if ( (directionLeft && tt.x<ex) || (!directionLeft && tt.x>ex) )
						{
							ex= tt.x;
							ep= tt;
							eindex = j;
						}
						equal ++;
					}
					if (z<0) down ++;
					break;
				}
			}
			if (!visited) down ++;
		}
		assert(equal==1);
		if (down>0) continue;
		if (equal >1  || equal <0)
		{
			int z;
			z= 1;
			while (z>0)
			{
				z++;
			}
		}
		if ( (directionLeft && ex<extremeX) || (!directionLeft && ex>extremeX) )
		{
			extremeX = ex;
			extremePoint = ep;
			extremeIndex = eindex ;
			nc= rotatePoint( central- polygon[v], t,angle);
		}
	}
	assert(extremeIndex!=-1);
	nv = extremeIndex;
	nt= extremePoint;
 
	double d0,d1;
	Point dis0,dis1;
	dis0 = t-nt;
	dis1= polygon[v] - polygon [nv];
	d0 = hypotenuse(dis0.x, dis0.y);
	d1= hypotenuse( dis1.x,dis1.y);
	int zzzzz;
	zzzzz =1;
}

void output(Point p)
{
	int a,b;
	a= int( p.x * 1000 +0.5 );
	b= int( p.y * 1000 +0.5 );
	cout<<setiosflags(ios::fixed)<<setprecision(3)<<a/1000.0<<' '<<b/1000.0;
}