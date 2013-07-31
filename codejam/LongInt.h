#include <iostream>
//#include <fstream>
#include <string>
#include <vector>
#include <sstream>
//using namespace std;

#include <cassert>

using namespace std;



class LongInt
{
public:
	LongInt(void);
	LongInt(int x);
	//LongInt(char * s);
	LongInt(string s);
	const LongInt  operator+(const LongInt & b) const;
private:
	static int  minus(int lengtha,const vector<int> & a, int lengthb, const  vector<int> & b, vector<int> & t);
	static int  add(int lengtha, const vector<int> & a, int lengthb, const  vector<int> & b, vector<int> & t);
	static bool abslessthan( const LongInt & a, const LongInt & b );
public:
	const LongInt  operator-(const LongInt & b) const ;

	const LongInt  operator*(const LongInt & b) const;
	const LongInt  operator / (const LongInt & b) const;
	const LongInt  operator % (const LongInt & b) const;

	const LongInt  modDivide(const LongInt & b, LongInt * c=NULL);

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

	//	int MAXLENGTH;
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
		if (tot>=MAX) 
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
	x.num.resize( tot/x.KNOT +2);
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
		j=j-x.KNOT;
	}

	return in;

}



LongInt::LongInt(void)
{
	sign=1;
	length=0;
	//	MAXLENGTH = 8;
	num.resize(8);
	fill(num.begin(),num.end(),0);

}

LongInt::LongInt(int x)
{
	if (x>=0) sign=1; 
	else
	{
		sign=-1;
		x= -x;
	}
	//	MAXLENGTH =8;
	num.resize(8);
	fill(num.begin(), num.end(), 0);
	length=0;
	while (x>0)
	{
		num[length]	= x%CARRY;
		x= x/CARRY;
		length++;
	}
}

LongInt::LongInt(string s)
{
	istringstream sin(s);
	sin>>*this;
}

bool LongInt::abslessthan( const LongInt & a, const LongInt & b )
{
	if (a.length< b.length)
	{
		return true;
	}
	if (a.length> b.length)
	{
		return false;
	}
	for (int i=a.length-1; i>=0; i--)
	{
		if (a.num[i]< b.num[i])
		{
			return true;
		}
		if (a.num[i]> b.num[i])
		{
			return false;
		}
	}
	return false;
}


const LongInt  LongInt:: operator+(const LongInt & b) const
{
	if (this->sign!=b.sign)
	{
		LongInt c;
		bool lessthan;
		lessthan= abslessthan(*this,b);
		if (lessthan)
		{
			c.length = minus(b.length,b.num,this->length,this->num,c.num);
		}
		else
		{
			c.length = minus(this->length,this->num,b.length,b.num,c.num);
		}
		if (c.length==0) 
		{
			c.sign =1;
		}
		else
		{
			if (lessthan)
			{
				c.sign =b.sign;
			}
			else
			{
				c.sign= this->sign;
			}

		}
		return c;
	}
	else
	{
		LongInt c;
		bool lessthan;
		lessthan= (this->length< b.length);
		c.sign =b.sign;

		if (lessthan)
		{
			c.length = add(b.length,b.num,this->length,this->num,c.num);
		}
		else
		{
			c.length = add(this->length,this->num,b.length,b.num,c.num);
		}
		//		fout<<*this<<'+'<<endl;
		//		fout<<b<<'='<<endl;
		//		fout<<c<<endl;

		return c;

	}
}

const LongInt  LongInt::operator-(const LongInt & b) const 
{
	if (this->sign==b.sign)
	{
		LongInt c;
		bool lessthan;
		lessthan= abslessthan(*this,b);
		if (lessthan)
		{
			c.length = minus(b.length,b.num,this->length,this->num,c.num);
		}
		else
		{
			c.length = minus(this->length,this->num,b.length,b.num,c.num);
		}
		if (c.length==0)
		{
			c.sign=1;
		}
		else
		{
			if (lessthan)
			{
				c.sign =-b.sign;
			}
			else
			{
				c.sign= this->sign;
			}
		}
		return c;
	}
	else
	{
		LongInt c;
		bool lessthan;
		lessthan= (this->length< b.length);
		c.sign =-b.sign;

		if (lessthan)
		{
			c.length = add(b.length,b.num,this->length,this->num,c.num);
		}
		else
		{
			c.length = add(this->length,this->num,b.length,b.num,c.num);
		}
		return c;

	}

} 

int  LongInt::minus(int lengtha, const vector<int> & a, int lengthb, const  vector<int> & b, vector<int> & t)
{
	int c;
	c=0;
	vector<int> q;
	//int length;
	//length = a.size() ;
	assert(lengtha >= lengthb);
	q.resize( lengtha ) ;
	int i;

	for (i=0; i<lengthb; i++)
	{
		q[i]= a[i]-b[i]+c;
		if (q[i]<0)
		{
			q[i]+=CARRY;
			c=-1;
		}
		else c=0;
	}
	if (c<0)
	{
		while(a[i]==0)
		{
			q[i]= CARRY-1;
			i++;
		}
		q[i]= a[i]-1;
		i++;

	}
	while( i<lengtha)
	{
		q[i]= a[i];
		i++;
	}
	int length= lengtha;
	while (length>0)
	{
		if (q[length-1]==0) length--; else break;
	}
	t.resize(length);
	copy(q.begin(), q.begin()+length, t.begin());
	fill(t.begin()+length,t.end(),0);
	return length;

}
int  LongInt::add(int lengtha, const vector<int>  & a, int lengthb, const  vector<int> & b, vector<int> & t)
{
	int c;
	c=0;
	vector<int> q;
	//int length;
	//length = max(a.size(), b.size()+1 )  ;
	int length= lengtha;
	length+=1;
	q.resize( length ) ;
	assert(lengtha>= lengthb);
	int i;
	for (i=0; i<lengthb; i++)
	{

		q[i]= a[i]+b[i]+c;
		if (q[i]>=CARRY)
		{
			q[i]-=CARRY;
			c=1;
		}
		else c=0;
	}
	if (c>0)
	{
		while(i<lengtha)
		{
			if (a[i]<CARRY-1)
			{
				q[i]= a[i]+1;
				c=0;
				i++;
				break;
			}
			q[i]=0;
			i++;
		}
		if (i==lengtha)
		{
			q[i]=c;
		}
	}
	while(i<lengtha)
	{
		q[i]= a[i];
		i++;
	}
	while (length>0)
	{
		if (q[length-1]==0) length--; else break;
	}
	t.resize(length);
	copy(q.begin(), q.begin()+length, t.begin());
	fill(t.begin()+length,t.end(),0);
	return length;

}



const LongInt  LongInt::operator*(const LongInt & b) const
{
	LongInt c;
	c.sign=this->sign * b.sign;
	c.num.resize(this->length+b.length+1);
	fill(c.num.begin(), c.num.end(), 0);
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
	{
		c.length=0;
		c.sign=1;
	}
	else
	{
		c.length= i+j;
		while (c.num[ c.length-1]==0) c.length--;
	}

	return c;

}
bool LongInt::operator>(const LongInt & b) const
{
	if (this->sign==1 && b.sign==-1) return true;
	if (this->sign==-1 && b.sign==1) return false;
	if (this->sign==1)
	{
		if (abslessthan(b,*this)) return true;
		else return false;
	}
	else
	{
		if (abslessthan(*this,b)) return true;
		else return false;
	}
}


const LongInt  LongInt::modDivide(const LongInt & b, LongInt * c)
{
	if (length< b.length)
	{
		if (c!=NULL)
		{
			*c= *this;
			return LongInt(0);
		}
	}
	assert(b.length>0);
	LongInt target,result;
	target = *this;
	result.num.resize(length- b.length + 1);
	result.sign = this->sign * b.sign;
	result.length = length - b.length+ 1;
	for (int i= length-b.length; i>=0; i--)
	{
		int testResult;
		long long int numerator, denominator;
		int a1,b1;
		a1= target.length-1;
		b1= a1 - i;
		numerator = target.num[a1];
		if (b1<b.length ) denominator = b.num[b1];
		else denominator = 0;
		a1--;
		b1--;
		if (a1>=0) numerator = numerator * CARRY + target.num[a1];
		else numerator *= CARRY;

		assert(b1<b.length);

		if (b1>=0) denominator = denominator * CARRY + b.num[b1];
		else denominator *= CARRY;

		a1--;
		b1--;
		if (a1>=0) numerator = numerator * CARRY + target.num[a1];
		else numerator *= CARRY;

		assert(b1<b.length);

		if (b1>=0) denominator = denominator * CARRY + b.num[b1];
		else denominator *= CARRY;

		if (b1>=1) denominator ++;

		testResult =(int)( numerator / denominator );

		LongInt tempNumerator;
		tempNumerator.length = target.length -i;
		tempNumerator.num.resize(tempNumerator.length);
		copy(target.num.begin()+i, target.num.begin()+target.length,  tempNumerator.num.begin());
		LongInt f;
		f= b* testResult;
		f= b+f;
		while( ! abslessthan(tempNumerator,f))
		{
			testResult++;
			f= b+f;
		}
		LongInt d;
		d= b*testResult;
		d.num.resize(d.length+i);
		copy_backward(d.num.begin(), d.num.begin() + d.length,  d.num.begin()+d.length +i);
		fill(d.num.begin(),d.num.begin()+i,0);
		d.length +=i;
		d.sign= target.sign;
		target = target- d;
		result.num[i] = testResult;
	}

	while( result.length>0 && result.num[result.length-1]==0)
	{
		result.length--;
	}
	if (c!=NULL) *c= target;
	return result;
}
