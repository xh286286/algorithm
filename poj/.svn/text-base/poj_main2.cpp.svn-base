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


	int now =clock();
	sorttime=0;

#define  _MULTITASK

#ifdef _MULTITASK
	int n;
	//cin>>n;
	n=1;
	for (int i=0; i<n; i++)
	{
		//work1();
		work();
		cout<<endl;
		i--;
		//if (!cin) break;
	}
#else
	//work1();
	work();
#endif
	int now2= clock();
	//	cout<<now<<endl<<now2<<endl<< now2-now<<endl;
	//	cout<<sorttime<<endl;
}
void preWork() {}
int gy(int a, int b)
{
	while (b!=0)
	{
		int c;
		c= a%b;
		a=b;
		b=c;
	}
	return a;
}

void work()
{
	int n;
	cin >>n;
	if (n==0) exit(0);
	int a,b;
	cin >>a>>b;
	int step;
	step= gy(abs(a-b),n);
	int z[1100];
	fill(z,z+1100, -1);
	bool yes;
	yes = true;
	for (int i=0; i<n; i++)
	{
		int k;
		cin >>k;
		int t;
		t= i% step;
		if (z[t]==-1) z[t] = k% step;
		else
		{
			if (z[t] != k%step)
			{
				yes= false;
			}
		}
	}
	if (yes)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}

}