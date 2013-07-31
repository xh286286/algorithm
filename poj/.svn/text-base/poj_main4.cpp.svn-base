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
	n =1;
	//cin>>n;
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

bool seated[16][16];
string s[40];
string result[2][4];
void vary(int * a, bool s)
{
	for (int i=0; i<3; i++)
	{
		for (int j=i+1; j<4; j++)
		{
			seated[a[i]][a[j]] = true;
			seated[a[j]][a[i]] = true;
		}
	}
	for (int i=4; i<7; i++)
	{
		for (int j=i+1; j<8; j++)
		{
			seated[a[i]][a[j]] = true;
			seated[a[j]][a[i]] = true;
		}
	}
}
bool check(int * a)
{
	for (int i=1; i<3; i++)
	{
		for (int j=i+1; j<4; j++)
		{
			if (seated[a[i]][a[j]]) return false;
		}
	}
	for (int i=4; i<6; i++)
	{
		for (int j=i+1; j<7; j++)
		{
			if (seated[a[i]][a[j]]) return false;
		}
	}
	return true;
}
bool search(int z)
{
	if (z==4) return true;
	int t = -1;
	for (int i=0; i<16; i++)
	{
		int acc =0;
		for (int j=0; j<16; j++)
		{
			if (!seated[i][j]) acc++;
		}
		if (acc==6) 
		{
			t=i;
			break;
		}
	}
	if (t<0) return false;
	
	int n[8], can[6];
	n[0] = t;
	n[7] = t;
	int l=0;
	for (int j=0; j<16; j++)
	{
		if (!seated[t][j])
		{
			can[l++] = j;
		}
	}
	n[1] = can[0];
	for (int i=1; i<5; i++)
	{
		for (int j=i+1; j<6; j++)
		{
			n[2] = can[i];
			n[3] = can[j];
			int l=4;
			for (int k=1; k<6; k++)
			{
				if (k!=i && k!=j) n[l++] = can[k];
			}
		}
	}
	if (!check(n)) return false;
	vary(n,true);
	result[0][z] = "    ";
	for (int i=0; i<4; i++)
	{
		result[0][z][i] = n[i] +'A';
	}
	result[1][z] = "    ";
	for (int i=4; i<8; i++)
	{
		result[1][z][i-4] = n[i] +'A';
	}
	if ( search(z+1) ) return true;
	vary(n,false);
	return false;
}
void work()
{
	memset(seated,false, sizeof(seated));
	for (int i=0; i<16; i++)
	{
		seated[i][i] = true;
	}
	for (int i=0; i<12; i++)
	{
		cin >> s[i];
		for (int j=0; j<4; j++)
		{
			for (int k=0; k<4; k++)
			{
				int a,b;
				a= s[i][j]-'A';
				b= s[i][k]-'B';
				seated[a][b] = true;
				seated[b][a] = true;
			}
		}
	}

	if (search(0) )
	{
		for (int i=0; i<12; i++)
		{
			cout<<s[i]<<' ';
			if (i%4==3) cout<<endl;
		}
		for (int i=0; i<2; i++)
		{
			for (int j=0; j<4; j++)
			{
				cout<<result[i][j]<<' ';
			}
			cout<<endl;
		}
	}
	else
	{
		cout<<"It is not possible to complete this schedule.";
	}
}