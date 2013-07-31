long long cn[1400][100];
#define REP(i,n)  for (int i=0; i<(n); ++i)
inline long long getfu(int m, int n) {
	// m+n-1  n-1
	if (n-1>m) return cn[m+n-1][m];
	else return cn[m+n-1][n-1];
}

	memset(cn,0,sizeof(cn));
	cn[0][0] = 1;
	REP(i,1400) {
		if (i==0) continue;
		REP(j,100) {
			cn[i][j] = cn[i-1][j];
			if (j>0) cn[i][j] = (cn[i-1][j]+cn[i-1][j-1]) % mo;
		}
	}