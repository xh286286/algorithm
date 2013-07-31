#include <iostream>
#include <string>
#include <vector>
//using namespace std;

#include <cassert>

using namespace std;

class LongInt
{
public:
	LongInt(void);
	LongInt(int x);

	const LongInt & operator+(const LongInt & b) const;
private:
	static int  minus(int length, const vector<int> a, const  vector<int> b, vector<int> & t);

public:
	const LongInt & operator-(const LongInt & b) const ;

	const LongInt & operator*(const LongInt & b) const;
	const LongInt & operator / (const LongInt & b) const;
	const LongInt & operator % (const LongInt & b) const;
	
	const LongInt & mod(const LongInt & b, LongInt & c);

	bool operator>(const LongInt & b) const;
	bool operator<(const LongInt & b) const
	{
		return (b>*this);
	}
	bool operator>=(const LongInt & b) const
	{
		return ( !(*this<b) );
	};
	bool operator<=(const LongInt & b) const
	{
		return ( !(*this>b) );
	};
	bool operator==(const LongInt & b) const
	{
		if (this->sign != b.sign) return false;

		if (this->length != b.length) return false;

		for (int i=this->length-1; i>=0; i--)
		{
			if (this->num[i] != b.num[i]) return false;
		}
		return true;
	}
	bool operator!=(const LongInt & b) const
	{
		return !( *this==b ) ;
	}


	friend  std::ostream & operator<<(  std::ostream & out, const LongInt & x);
	friend std::istream & operator>> (std::istream & in ,LongInt & x);
public:
	//	~LongInt(void){};

	int MAXLENGTH;
	static const int CARRY=10000;
	static const int KNOT=4;
protected:
private:
	int length;

	vector<int> num;
	//int num[MAXLENGTH+10];
	int sign;
};


std::ostream & operator<<(  std::ostream & out, const LongInt & x)
{
	if (x.sign==-1) { 
		assert(x.length!=0); 
		if (x.length==0)
		{
			out<<"error"<<std::endl;
			return out;
		}
		out<<'-'; 
	}
	if (x.length==0) { out<<0; return out; }
	int length;
	length= x.length;
	length--;
	out<<x.num[length];
	assert(x.num[length] > 0 );
	static const int h[8]={10,100,1000,10000,100000,1000000,10000000,100000000};
	for (int i=length-1; i>=0; i--)
	{
		int j;
		for (j=0; j<x.KNOT-1; j++)
		{
			if (x.num[i]<h[j]) break;
		}
		for ( ; j<x.KNOT-1; j++)
		{
			out<<'0';
		}
		out<<x.num[i];
	}
	return out;

}

std::istream & operator>> (std::istream & in ,LongInt & x)
{
	char c;
	assert(in);
	if (!in) return in;
	in>> c;

	assert (c =='-' || c=='+' ||  (c>='0' && c<='9'));
	if ( !(c =='-' || c=='+' ||  (c>='0' && c<='9'))) 
	{
		assert(false);
		in.putback(c);
		in.setstate( ios_base::failbit );
		return in;
	}

	if (c=='-')  x.sign=-1;
	else if (c=='+') x.sign=1;
	else x.sign=1;
	if (c=='-' || c=='+')
	{
		assert(in);
		if (!in) return in;
		c=in.get();
	}
	assert( c>='0' && c<='9');
	if ( !(c>='0' && c<='9') ) 
	{
		in.setstate( ios_base::failbit );
		return in;
	}
	int MAX=8;
	vector<short> num;
	num.resize(MAX);
	int tot;
	tot=x.KNOT;
	//tot= 0;
	while(c>='0' && c<='9')
	{
		num[tot]=c-'0';
		tot++;
		//assert(tot<=MAX);
		if (tot>MAX) 
		{
			MAX*=2;
			num.resize(MAX);
		}
		if (!in) break;
		
		c=in .get();
	}

	if ( !(c>='0' && c<='9') ) in.putback(c);

	int i,j;
	for (i=0; i<x.KNOT; i++)
	{
		num[i]=0;
	}
	for (i=x.KNOT; i<tot; i++)
	{
		if (num[i] != 0) break;
	}

	if (i>=tot) { x=0; return in; }

	x.length=0;
	j=tot-1;
	while (j>=i)
	{
		int t;
		t=0;
		for (int k=x.KNOT-1; k>=0; k--)
		{
			t=t*10+num[j-k];
		}
		x.num[x.length]=t;
		x.length++;
		if (x.length>= x.MAXLENGTH)
		{
			x.MAXLENGTH*=2;
			x.num.resize(x.MAXLENGTH);
		}
		j=j-x.KNOT;
	}

	return in;

}



LongInt::LongInt(void)
{
	sign=1;
	length=0;
	MAXLENGTH = 8;
	num.resize(MAXLENGTH);
	for (int i=0; i<MAXLENGTH; i++)
	{
		num[i]=0;
	}
}

LongInt::LongInt(int x)
{
	if (x>=0) sign=1; 
	else
	{
		sign=-1;
		x= -x;
	}
	MAXLENGTH =8;
	num.resize(MAXLENGTH);
	for (int i=0; i<MAXLENGTH; i++)
	{
		num[i]=0;
	}
	length=0;

	while (x>0)
	{
		num[length]	= x%CARRY;
		x= x/CARRY;
		length++;
	}
}

const LongInt & LongInt:: operator+(const LongInt & b) const
{
	LongInt c;
	c= b;
	if (this->sign!=c.sign)
	{
		LongInt c;
		c= c;

		c.sign*=-1;
		return *this-c;
	}
	int d;
	d=0;
	int mlength;
	if (this->length> c.length)	
	{
		mlength=this->length; 
	}
	else 
	{
		mlength= c.length;
	}
	for (int i=0; i<mlength; i++)
	{
		d+=this->num[i]+c.num[i];
		c.num[i]=c%CARRY;
		d/=CARRY;
	}
	while (d>0)
	{
		c.num[mlength]=d%CARRY;
		d/=CARRY;
		mlength++;
	}
	c.length=mlength;
	assert(mlength<MAXLENGTH);
	if (mlength>= MAXLENGTH)return 0;

	return c;
}

int  LongInt::minus(int length, const vector<int> a, const  vector<int> b, vector<int> & t)
{
	int c;
	c=0;
	for (int i=0; i<length; i++)
	{

		t[i]= a[i]-b[i]+c;
		if (t[i]<0)
		{
			t[i]+=CARRY;
			c=-1;
		}
		else c=0;

	}
	while (length>0)
	{
		if (t[length-1]==0) length--; else break;
	}
	return length;
}

const LongInt & LongInt::operator-(LongInt b) const 
{
	if (this->sign!=b.sign)
	{


		b.sign*=-1;

		return *this+b;


	}
	bool big;
	big=false;
	bool small;
	small=false;

	if (b.length==this->length )
	{
		for (int i=b.length-1; i>=0; i--)
		{
			if (b.num[i] < this->num[i]) {big=true; break;}
			if (b.num[i]> this->num[i]) {small=true; break;}
		}
		if (!big && !small) 
		{
			b=0;
			return b;
		}
	}
	else 
	{
		if (b.length< this->length) big=true;
	}

	if (big)
	{
		b.sign=this->sign;

		b.length=minus( this->length ,this->num,b.num,b.num);
	}
	else
	{
		b.sign= this->sign *-1;
		b.length=minus(b.length,b.num,this->num,b.num);
	}
	return b;
}


const LongInt & LongInt::operator*(const LongInt & b) const
{
	LongInt c;
	c.sign=this->sign * b.sign;
	assert (this->length + b.length<b.MAXLENGTH);
	if (this->length + b.length>=b.MAXLENGTH) return 0;
	int i,j;
	j=0;
	if (b.length>0)
	{
		for (i=0; i<this->length; i++)
		{
			int x=0;
			for (j=0; j<b.length; j++)
			{

				x+= this->num[i] * b.num[j]+c.num[i+j];
				c.num[i+j]= x % CARRY;
				x/= CARRY;
			}
			while (x>0)
			{
				x+=c.num[i+j];
				c.num[i+j] = x % CARRY;
				x/=CARRY;
				j++;
			}
		}
	}

	if (this->length * b.length ==0) 
		c.length=0;
	else
		c.length= i+j-1;

	assert(c.length<b.MAXLENGTH);
	if (c.length>=b.MAXLENGTH) return 0;
	return c;

}
bool LongInt::operator>(const LongInt & b) const
{
	if (this->sign==1 && b.sign==-1) return true;
	if (this->sign==-1 && b.sign==1) return false;
	if (this->sign==1)
	{
		if (this->length>b.length) return true;
		if (this->length<b.length) return false;
		for (int i=this->length-1; i>=0; i--)
		{
			if (this->num[i]>b.num[i]) return true;
			if (this->num[i]<b.num[i]) return false;
		}
		return false;
	}
	else
	{
		if (this->length>b.length) return false;
		if (this->length<b.length) return true;
		for (int i=this->length-1; i>=0; i--)
		{
			if (this->num[i]>b.num[i]) return false;
			if (this->num[i]<b.num[i]) return true;
		}
		return false;

	}
}
