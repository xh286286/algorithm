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
#include <stack>
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

stack < int > desendHeight;
stack < int > desendX;
long long int score[200000];
//long long int height[200000];
void work()
{
	int n;
	cin >>n;
	int z;
	cin >>z;
	desendHeight.push(z);
	desendX.push(0);
	score[0] =0;
	for (int i=1; i<=n; i++)
	{
		cin >>z;
		score[i] =  score[i-1] + 1000000000;
		while (true)
		{
			if (desendHeight.empty()) break;
			int topH;
			int topX;
			topH= desendHeight.top();
			topX= desendX.top();
			if (topH+topX<i)
			{
				desendX.pop();
				desendHeight.pop();
				continue;
			}
			if (topH <= z)
			{
				if (score[topX]+ z- topH <score[i])
				{
					score[i]= score[topX] + z - topH;
				}
				desendX.pop();
				desendHeight.pop();
				continue;
			}
			if (score[topX] < score[i])
			{
				score[i]= score[topX];
			}
			break;
		}
		desendX.push(i);
		desendHeight.push(z);
	}
	cout<<score[n];
}

/*
5
1 3 4 2 3 1
*/