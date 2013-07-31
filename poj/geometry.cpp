struct Point 
{
	double x,y;
	Point operator - (const Point & b)
	{
		Point c;
		c.x = x- b.x;
		c.y = y- b.y;
		return c;
	}
};
bool intersect(Point a0, Point b0, Point a1, Point b1, double & t0, double & t1, Point & r)
{
	Point p1,p2,p3;
	p1=  b0-a0;
	p2= b1-a1;
	p3= a0 - a1;
	const double denominator =  p1.x * p2.y  - p1.y * p2.x ;
	if (abs(denominator) < 1e-10)
	{
		return false;
	}
	double na, nb;
	na= p2.x* p3.y - p3.x* p2.y;
	na/= denominator;

	nb= p3.y* p1.x - p1.y* p3.x ;
	nb/= denominator;

	t0= na;
	t1= nb;

	r.x= a0.x+ p1.x* na;
	r.y= a0.y+ p1.y*na;

	return true;
}

bool parallelLine(Point a0, Point b0, Point a1, Point b1)
{
	Point p1,p2;
	p1= b0-a0;
	p2= b1-a1;
	if (   p1.y* p2.x - p1.x* p2.y ==0) return true; else return false;
}

bool contact(Point a0, Point b0, Point a1, Point b1) {
	double t0,t1;
	Point r;
	if (intersect(a0,b0,a1,b1,t0,t1,r)) {
		if (t0 + 1e-10>=0 && t0 - 1e-10<=1 && t1 + 1e-10>=0 && t1 - 1e-10<=1) return true;
		return false;
	}
	Point z0,z1, l;
	l = a1-b1;
	double s = sqrt(l.x * l.x + l.y * l.y);
	double s1,s2, g1,g2;
	z0 = a0-a1;
	z1 = a0-b1;
	g1 = sqrt(z0.x * z0.x + z0.y * z0.y);
	g2 = sqrt(z1.x * z1.x + z1.y * z1.y) ;
	s1 = g1 + g2;
	if (abs(s-s1) <1e-10) return true;

	z0 = b0-a1;
	z1 = b0-b1;
	g1 = sqrt(z0.x * z0.x + z0.y * z0.y);
	g2 = sqrt(z1.x * z1.x + z1.y * z1.y) ;
	s1 = g1 + g2;
	if (abs(s-s1) <1e-10) return true;
	return false;
}


struct Angle{
	Angle(int x_, int y_) {
		x = x_ , y = y_;
		e = -1;
		bool sw = false;
		if (x>0) {
			if (y>=0) e = 0;
		}
		else  {
			if (y>0) { e = 1; sw=true; }
		}
		if (x<0) {
			if (y<=0) e = 2;
		}
		else {
			if (y<0)  {e = 3;sw = true; }
		}
		if (x<0) x=-x; if (y<0) y=-y;
		if (sw) swap(x,y);
	}
	long long int x, y;
	int e;
	bool operator < (const Angle & b) {
		if (e < b.e) return true;
		if (y * b.x < b.y * x) return true;
		return false;
	}
};
