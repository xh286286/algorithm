long long get2power(int x) {
	long long result = 1,  ob = 2;
	while (x>0) {
		if (x%2 == 1) result = (result * ob )% modulo;
		x/=2;
		ob = (ob * ob) % modulo;
	}
	return result;
}


long long z[1000];
long long get2power(int x) {
	int acc = 1;
	if (x==0) return 1;
	long long result = 1;
	while (x>0) {
		if (x%2 == 1) result = (result * z[acc] )% modulo;
		acc++;
		x/=2;
	}
	return result % modulo;
}
void main() {
	z[0] = 1; z[1] = 2;
	for (int i=2; i<200; i++) {
		z[i] = (z[i-1] * z[i-1] ) %modulo;
	}
	
}

