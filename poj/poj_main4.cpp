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

//  Խ�� ����  ���� �� �� ������  abs ����

//  �����ĳ�ʼ�� clear

// �鿴 �鲢 ���� �� �㷨�� ��������
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