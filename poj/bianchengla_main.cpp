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
#include <memory>
#include <cstdio>
#include <cstring>
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
	int n=1;
	//cin>>n;
	//char s[100];
	//cin.getline(s,100);
	for (int i=0; i<n; i++)
	{
		//cout<<"Case "<<i+1<<": ";
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


struct Edge
{
	int target;
	int dis;
	Edge * next;
	Edge(int t, int d)
	{
		target = t;
		dis= d;
		next= NULL;
	}
};


Edge * node[100000];
long long int cost[100000];
bool visited[100000];
void clear()
{
	for (int i=0; i<100000; i++)
	{
		Edge * p;
		p = node[i];
		while (p!=NULL)
		{
			Edge * q;
			q= p;
			p= p->next;
			delete q;
		}
	}
}
struct Node
{
	int index;
	long long int score;
	bool operator <(const Node & b) const
	{
		if (score> b.score) return true;
		return false;
	}
};
void work()
{
	int n,m;
	cin >>n>>m;
	if (!cin) exit(0);
	int s,t;
	for (int i=0; i<m; i++)
	{
		int a,b,c;
		cin >>a>>b>>c;
		Edge * p;
		p= new Edge (b,c);
		p->next = node[a];
		node[a]= p;
	}
	cin >>s>>t;
	fill(cost,cost + n+10, 281474976710656);
	fill(visited,visited+n+10, false);
	cost[s]= 0;
	priority_queue< Node> pqn;
	Node o;
	o.index= s;
	o.score =0;
	pqn.push(o);
	{
	clear();
	return;

	}
	while (pqn.size()>0)
	{
		o= pqn.top();
		pqn.pop();
		Edge * p; 
		int index= o.index;

		if (visited[index]) continue;
		visited[index] = true;

		long long int nows = o.score;
		p= node[index];
		if (index==t) break;
		while (p!=NULL)
		{
			if (nows+ p->dis < cost [p->target])
			{
				cost [p->target] =  p->dis + nows;
				o.index = p->target;
				o.score = cost[p->target];
				pqn.push(o);

			}
			p= p->next;
		}
	}
	cout<<cost[t];
	clear();
}
