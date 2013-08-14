vector< vector<int> >  equations;
pair<int,int> store[1000];
int maxIndex, baseEquation;
int getIndex(int a, int b) {
	pair<int,int> z = make_pair(a,b);
	for (int i =1; i<maxIndex; i++) if (store[i] == z) return i ;
	store[maxIndex] = z;
	return maxIndex++;
}
bool simplify() {
	int eql = equations.size(), ind;
	for (int i=0; i<eql; i++) equations[i] .resize(maxIndex);
	baseEquation = 0; ind = maxIndex-1;
	int i;
	while(true) {
		if (ind ==0 || baseEquation == eql) break;
		for (i=baseEquation; i<eql; i++) {
			if (equations[i][ind] !=0) break;
		}
		if (i==eql) {
			ind--; continue;
		}
		swap(equations[i], equations[baseEquation]);
		for (i=baseEquation+1; i<eql; i++) {
			for (int j=0; j<=ind; j++) {
				equations[i][j] = equations[i][j] * equations[baseEquation][ind] - equations[baseEquation][j] * equations[i][ind];
				equations[i][j] %= 10;				
			}
		}
		baseEquation++;
		ind --;
	}
	for (i = baseEquation; i< eql; i++) {
		if (equations[i][0] %10 != 0) return false;		
	}
	return true;
}
