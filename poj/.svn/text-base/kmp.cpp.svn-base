

char virus[40000];
char target[2000100];

void work()
{
	cin.getline(virus,40000);
	cin.getline(target,1100100);

	int length1, lenght2;
	length1 = strlen(virus);
	lenght2 = strlen(target);

	int next[40000];
	int i,j;
	i=0;
	j=-1;
	next[0]= -1;
	while (i<length1)
	{
		while (j>=0 && virus[i] != virus[j] ) j = next[j];
		i++;
		j++;
		if (i<length1 && virus[i]==virus[j]) next[i] = next[j];
		else next[i] = j;
	}

	i=0; 
	j=0;
	int result =0;
	while (i<lenght2)
	{
		if (j==-1 || target[i] == virus[j])
		{
			i++;
			j++;
			if (j== length1) 
			{
				result++;
				j= next[j];
			}
		}
		else
		{
			j= next[j];
		}
	}
	cout<<result;
}