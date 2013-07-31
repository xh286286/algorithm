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

class ULSet
{
public:
	ULSet(int length)
	{
		set(length);
	}
	void set(int length)
	{
		target.resize(length);
		n= length;
		for (int i=0; i<n; i++)
		{
			target[i] =i;
		}
	}
	int look(int a)
	{
		int z= a;
		int k;
		while (target[z]!=z)
		{
			z= target[z];
		}
		while (target[a]!=z)
		{
			k= target[a];
			target[a] = z;
			a= k;
		}
		return z;
	}
	void combine(int a, int b)
	{
		target[ look(b)] = look(a);
	}
private:
	int n;
	vector< int > target;

};

struct Tuple3
{
	int d,s,t;
};

Tuple3 tuplePool[10000];
int totalTuple;
int beginIndex[1000];
int n;

int number[400][40];
int numberLength[400];

ULSet uls(0);

bool edge[400][400];

struct Node
{
	int a,b;
	int index;
};

Node comparePool[8000];
int totalCompare;

bool inputCompare();

bool checkCircle();


void work()
{
	cin >>n;
	if (n==0) exit(0);
	totalTuple =0;
	beginIndex[0] =0;
	int totalNumber;
	totalNumber = 0;
	for (int i=0; i<n; i++)
	{
		numberLength[i] =0;
		int k;
		cin >>k;
		for (int j=0; j<k; j++)
		{
			cin >>tuplePool[totalTuple].d>>tuplePool[totalTuple].s>>tuplePool[totalTuple].t;
			numberLength[i] += tuplePool[totalTuple].t - tuplePool[totalTuple].s+1;
			totalTuple++;
		}
		beginIndex[i+1] = totalTuple;
		for (int j=0; j<numberLength[i]; j++)
		{
			number[i][j] = totalNumber;
			totalNumber++;
		}
	}
	uls .set(totalNumber);
	for (int i=0; i<n; i++)
	{
		int nl;
		nl=0;
		for (int j=beginIndex[i]; j<beginIndex[i+1]; j++)
		{
			for (int k=tuplePool[j].s; k<=tuplePool[j].t; k++)
			{
				uls.combine(number[i][nl], number[ tuplePool[j].d-1] [k-1]);
				nl++;
			}
		}
	}
	for (int i=0; i<totalNumber; i++)
	{
	//	cout<<uls.look(i)<<' ';
	}
	if (!inputCompare())
	{
		cout<<"No";
		return;
	}
	while(totalCompare >0)
	{
		int newTotalCompare =0;
		for (int i=0; i<totalCompare; i++)
		{
			int a,b;
			a= comparePool[i].a;
			b= comparePool[i].b;
			while (comparePool[i].index< numberLength[a] && comparePool[i].index< numberLength[b] && uls.look(number[a][comparePool[i].index]) == uls.look(number[b][comparePool[i].index]))
			{
				comparePool[i].index++;
			}
			if (comparePool[i].index== numberLength[b] ) 
			{
				cout<<"No";
				return;
			}
			if (comparePool[i].index== numberLength[a]) continue;
			comparePool[newTotalCompare] = comparePool[i];
			newTotalCompare++;
		}
		totalCompare = newTotalCompare;

		if ( !checkCircle() ) break;

	}
	cout<<"Yes";
}



bool inputCompare()
{
	int m; 
	cin >>m;
	int small[400];
	int big[400];
	memset(edge,false, sizeof(edge));
	memset(small,0,sizeof(small));
	memset(big,0,sizeof(big));
	totalCompare =0;
	for (int i=0; i<m; i++)
	{
		int a,b;
		cin >>a>>b;
		a--;
		b--;
		if (!edge[a][b])
		{
			edge[a][b] = true;
			small[b]++;
			big[a]++;
			comparePool[totalCompare].a =  a;
			comparePool[totalCompare].b =  b;
			comparePool[totalCompare].index =0;
			totalCompare ++;
		}
	}
	while (true)
	{
		bool change = false;
		for (int i=0;i<n; i++)
		{
			if (big[i]>0 && small[i] ==0)
			{
				for (int j=0; j<n; j++)
				{
					if (edge[i][j]) small[j]--;
				}
				big[i]=0;
				change= true;
			}
		}
		if (!change) break;
	}
	for (int i=0; i<n; i++)
	{
		if (big[i]>0) return false;
	}
	return true;
}


bool numberCompare[400][400];

int numberPool[400];
int totalNumber;
int getNumberIndex(int z)
{
	for (int i=0; i<totalNumber; i++)
	{
		if (z== numberPool[i]) return i;
	}
	numberPool[totalNumber] = z;
	totalNumber++;
	return totalNumber-1;
}

bool visited[400];
bool nowVisited[400];
int path[400];
int totalPath;
int circlebeginIndex;
bool searchCircle(int length, int z)
{
	visited[z] = true;
	nowVisited[z] =true;
	path[length] = z;
	for (int i=0; i<totalNumber; i++)
	{
		if (!edge[z][i]) continue;
		if (nowVisited[i])
		{
			circlebeginIndex = i;
			totalPath = length+1;
			return true;
		}
		if (visited[i]) continue;
		if (searchCircle(length+1,i) ) return true;
	}
	return false;
}

bool checkCircle()
{
	totalNumber =0;
	memset(numberCompare,false, sizeof(numberCompare));
	for (int i=0; i<totalCompare; i++)
	{
		int a,b,index;
		a= comparePool[i].a;
		b= comparePool[i].b;
		index = comparePool[i].index;
		int na,nb;
		na= getNumberIndex(uls.look(number[a][index]));
		nb= getNumberIndex(uls.look(number[b][index]));
		numberCompare[na][nb] = true;
	}
	memset(visited,false,sizeof(visited));
	for (int i=0; i<totalNumber; i++)
	{
		if (!visited[i])
		{
			memset(nowVisited,false, sizeof(nowVisited));
			if (! searchCircle(0,i) ) continue;
			int j;
			for (j=0; j<totalPath; j++)
			{
				if (path[j] == circlebeginIndex) break;
			}
			int c;
			c= numberPool[circlebeginIndex];
			for (j++; j<totalPath; j++)
			{
				uls.combine(c, numberPool[path[j] ] );
			}
			return true;
		}
	}
	return false;
}

/*
3
2
2 1 3
2 5 5
3
1 1 3
3 3 3
3 2 2
2
1 3 4
2 4 4
2
2 1
1 3 

2
2
2 1 1
2 1 1
1
1 1 1
1
1 2
0
*/