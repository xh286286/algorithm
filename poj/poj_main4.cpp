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

void main() {
	int x,y;
	cin>>x>>y;
	int z= abs(x) + abs(y);
	if (x<0) {
		cout<< -z<<' '<<0<<' ';
		if (y<0) cout<<0<<' '<<-z;
		else cout<<0<<' '<<z;
	}
	else {
		if (y<0) cout<<0<<' '<<-z;
		else cout<<0<<' '<<z;
		cout<<' '<< z<<' '<<0<<' ';
	}
}