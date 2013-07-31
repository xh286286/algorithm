#include <string>
using namespace std;

void stringtoInt64(const string & s, __int64 & a);
void int64toString( __int64 a, string & s);

__int64 gy(__int64 a, __int64 b)
{
	while (b!=0)
	{
		__int64 c;
		c= a%b;
		a=b;
		b=c;
	}
	return a;
}


void stringtoInt64(const string & s, __int64 & a)
{
	int sign;
	if (s[0]=='-')
	{
		sign=-1;
	}
	else
	{
		sign= 1;
	}
	a=0;
	for (int i=0; i< s.size(); i++)
	{
		if (s[i]=='-' || s[i]== '+') continue;
		a= a*10+ s[i]-'0';
	}
	a*= sign;
}
void int64toString( __int64 a, string & s)
{

	s="";
	if (a==0) 
	{
		s+='0';
		return;
	}
	int sign;
	if (a<0) 
	{
		sign= -1;
		a=-a;
	}
	else
	{
		sign=1;
	}
	while (a>0)
	{
		int z;
		z= a%10;
		s+= '0'+z;
		a= a/10;
	}
	if (sign<0) s+= '-';

	string n;
	n="";
	for (int i= s.size()-1; i>=0 ; i--)
	{
		n+= s[i];
	}
	s=n;
}
