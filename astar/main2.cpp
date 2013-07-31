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
#include <cstring>
using namespace std;

//  越界 问题  浮点 除 变 整除，  abs 问题

//  容器的初始化 clear

// 查看 归并 排序 等 算法， 插入排序

// 已知的复杂条件要当做未知

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
		//i--;
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

int w, h, a, b, s, t,p, q;
int horizonWidth[20]; //13
int verticalHeight[20]; // 6

string baidu[6];

bool intersectRange(int a0,int b0, int a1,int b1)
{
	if (a0>=a1 && a1>=b0) return true;
	if (a0>=b1 && b1>=b0) return true;
	return false;
}

void work()
{
	baidu[0]= "1000000010000";
	baidu[1]= "1000100010000";
	baidu[2]= "1000000010000";
	baidu[3]= "1110101110101";
	baidu[4]= "1010101010101";
	baidu[5]= "1110101110111";
	cin >>w>> h>> a>> b>> s>> t>>p>> q;
	for (int i=0; i<20; i++)
	{
		horizonWidth[i] = a;
		verticalHeight[i] = a;
	}
	horizonWidth[1] = b;
	horizonWidth[7] = b;
	horizonWidth[11] = b;
	
	verticalHeight [0] = b-a;
	verticalHeight[4] =b;

	int result =0;

	for (int i=0; i<h; i++)
	{
		string now = "00000000000))";
		int acc;
		acc= i;
		for (int j=0; j<6;j++)
		{
			int nacc;
			nacc= verticalHeight[j]+ acc;
			if (intersectRange(acc,nacc,t,t+q) )
			{
				for (int k=0; k<13; k++)
				{
					if (now[k]=='1' || baidu[j][k]=='1') now[k] ='1';
				}
			}
			acc= nacc;
		}
		int xx;
		xx= s- (10*a+3*b)+1;
		if (xx>0) result += xx;
		xx= w-s-p - (10*a+3*b)+1;
		if (xx>0) result += xx;
		int zz;
		zz=0;
		for (int i=0; i<13; i++)
		{
			if (now[i]=='1') zz=0;
			else zz+=horizonWidth[i];
		}
	}


}