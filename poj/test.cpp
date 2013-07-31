#include <cstdio>
#include <algorithm>
#include <utility>
using std::swap;
const long long modulo = 1000000007;

template<class T>
T madd(T a, T b) {
	return (long long(a)+b)%modulo;
}

template<class T>
void maddSelf(T &a, T b) {
	a = (long long(a)+b)%modulo;
}

template<class T>
T mmulti(T a, T b) {
	return (long long(a)*b)%modulo;
}

template<class T>
void mmultiSelf(T &a, T b) {
	a = (long long(a)*b)%modulo;
}

long long euclidGCD(long long a, long long b) {
	while (b>0) {
		long long c = a % b;
		a = b;
		b = c;
	}
	return a;
}

long long extendedEuclidGCD(long long a, long long b,  long long & cox, long long & coy) {
	long long x0,y0,x1,y1;
	x0 = 1, y0 = 0, x1 = 0, y1 = 1;
	while (b>0) {
		long long z = a/b;
		long long c = a % b;
		a = b;
		b = c;
		x0 -= x1*z;
		y0 -= y1*z;
		swap(x0,x1);
		swap(y0,y1);
	}
	cox = x0, coy = y0;
	return a;

}
long long moduloInverse(long long a, long long n) {
	long long x = 0, y = 0;
	long long z = extendedEuclidGCD(a,n,x,y);
	//assert(z==1);
	if (z != 1) {
		cout<<"error";
		exit(0);
	}
	return (x%n + n)% n;
}
void main()
{
	long long a = 1000000009;
	long long b = 1000000007;
	long long r;

	 r = moduloInverse(3,a);
	 r = moduloInverse(3,b);

} 