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

void preWork();
void work();
void work1();
int sorttime;
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	preWork();
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
	int now2= clock();
	cout<<now<<endl<<now2<<endl<< now2-now<<endl;
	cout<<sorttime<<endl;
	fin.close();
	fout.close();

}



void preWork()
{


}
struct Edge;
struct City {
	vector<Edge *> route;
	int index;
	int s1,s2;
	bool f1,f2;
};
struct Edge {
	City * a, * b;
	int minDis, maxDis;
	bool shortest;
};
City cityPool [1100];
Edge edgePool[3000];
int N,M,P;
vector<int> path;

bool check (int pm) {
	if (pm==0) return true;
	for (int i=1; i<=N; i++) {
		cityPool[i].s1 = 1e10;
		cityPool[i].s2 = 1e10;
		cityPool[i].f1 = false;
		cityPool[i].f2 = false;
	}
	for (int i=1; i<=M; i++) {
		edgePool[i].shortest = false;
	}
	int as = 0;
	for (int i=0; i<pm; i++) {
		Edge & e = edgePool[path[i]];
		e.shortest = true;
		as += e.minDis;
	}
	edgePool[path[pm-1]].b->s2 = as;
	cityPool[1].s1 = 0;
	// find s1
	while(true) {
		int minCost = 1e10;
		int x = -1;
		for (int i=1; i<=N; i++) {
			if (cityPool[i].f1) continue;
			if (cityPool[i].s1<minCost) {
				x = i;
				minCost = cityPool[i].s1;
			}
		}
		if (x<0) break;
		cityPool[x].f1 = true;
		for (int i=0; i<cityPool[x].route.size(); i++) {
			int t = cityPool[x].s1;
			Edge *  e =  cityPool[x].route[i];
			if (e->shortest) {
				t+= e->minDis;
			}
			else {
				t+= e->maxDis;
			}
			if (t<e->b->s1) e->b->s1 = t;
		}
	}
	// find s2
	while (true) {
		int minCost = 1e10;
		int x = -1;
		for (int i=1; i<=N; i++) {
			if (cityPool[i].f2) continue;
			if (cityPool[i].s2<minCost && cityPool[i].s2<= cityPool[i].s1) {
				x = i;
				minCost = cityPool[i].s2;
			}
		}
		if (x<0) break;
		cityPool[x].f2 = true;
		for (int i=0; i<cityPool[x].route.size(); i++) {
			int t = cityPool[x].s2;
			Edge *  e =  cityPool[x].route[i];
			t+= e->minDis;
			if (t<e->b->s2) e->b->s2 = t;
		}
	}
	return cityPool[2].f2;
}

void work()
{
	fin>>N>>M>>P;
	for (int i=1; i<=N; i++) {
		cityPool[i].route.clear();
	}
	for (int i=1; i<=M; i++) {
		int u,v,a,b;
		fin>>u>>v>>a>>b;
		edgePool[i].a = &(cityPool[u]);
		edgePool[i].b = &(cityPool[v]);
		edgePool[i].minDis = a;
		edgePool[i].maxDis = b;
		cityPool[u].route.push_back( &(edgePool[i]));
	}
	path.clear();
	for (int i=0; i<P; i++) {
		int z ;
		fin>>z;
		path.push_back(z);
	}
	int bot, top;
	bot = 0;
	top = P+1;
	while(bot < top -1 ) {
		int m = (bot+top) / 2;
		if (check(m)) {
			bot = m;
		}
		else {
			top = m;
		}
	}
	if (bot == P) {
		fout<<"Looks Good To Me";
	}
	else {
		fout<<path[bot];
	}
}


