
struct node
{
	__int64 prime;
	int c;
};
list<node> l_n;
list<node> addLNgongbeishu( const list<node> & a,const list<node> & b)
{
	list<node> c;
	list<node>::const_iterator lnia, lnib;
	lnia= a.begin();
	lnib= b.begin();
	while (lnia != a.end() || lnib!= b.end())
	{
		if (lnia== a.end())
		{
			c.push_back( *lnib);
			lnib++;
			continue;
		}

		if (lnib== b.end())
		{
			c.push_back( * lnia);
			lnia++;
			continue;
		}
		if ( lnia->prime < lnib->prime)
		{
			c.push_back(*lnia);
			lnia++;
			continue;
		}
		if ( lnia->prime > lnib->prime)
		{
			c.push_back(*lnib);
			lnib++;
			continue;
		}
		assert( lnia->prime == lnib->prime);

		node o;
		o.prime = lnia->prime;
		o.c= max(lnia->c , lnib->c);
		c.push_back(o);
		lnia++;
		lnib++;
	}
	return c;
}
list<node> addLNgongyueshu( const list<node> & a,const list<node> & b)
{
	list<node> c;
	list<node>::const_iterator lnia, lnib;
	lnia= a.begin();
	lnib= b.begin();
	while (lnia != a.end() || lnib!= b.end())
	{
		if (lnia== a.end())
		{
			//c.push_back( *lnib);
			break;
			lnib++;
			continue;
		}

		if (lnib== b.end())
		{
			//c.push_back( * lnia);
			break;
			lnia++;
			continue;
		}
		if ( lnia->prime < lnib->prime)
		{
			//c.push_back(*lnia);
			lnia++;
			continue;
		}
		if ( lnia->prime > lnib->prime)
		{
			//c.push_back(*lnib);
			lnib++;
			continue;
		}
		assert( lnia->prime == lnib->prime);

		node o;
		o.prime = lnia->prime;
		o.c= min(lnia->c , lnib->c);
		c.push_back(o);
		lnia++;
		lnib++;
	}
	return c;
}
list<node> minusLN( const list<node> & a,const list<node> & b, bool & greaterequal)
{
	list<node> c;
	return c;
}