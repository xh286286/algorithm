//c++实现的KMP算法，所有涉及字符串，其初始下标从0开始(上述算法均是从1开始)
//example: char s[100],t[100];cin>>s>>t;KMP(s,t);
//获取待查询模式的next数组
int* get_next(char* T, int* next)
{
	int i = 0, j = -1;
	int length = strlen(T);
	int *temp = next;
	*next = -1;
	while(i< length)
	{
		if(j==-1 || *(T+i)==*(T+j))
		{
			i++;
			j++;
			//优化后的get_next方法，可以防止出现形如"aaaaab"这种模式的计算退化
			if(*(T+i)!=*(T+j))	*(next+i)=j;
			else	*(next+i)=*(next+j);
		}
		else
		j=*(next+j);
	}
	return temp;
}

//KMP算法
int KMP(char *S, char *T)
{
	int S_Length = strlen(S);
	int T_Length = strlen(T);
	//若模式长度大于字符串，则直接返回查询失败
	if( S_Length < T_Length)
	return 0;
	int i = 0, j = 0;
	int* next = new int[T_Length];
	get_next(T, next);
	while(i < S_Length && j < T_Length)
	{
		if(j == -1 || *(S+i) == *(T+j))
		{
			i++;
			j++;
		}
		else
		j=*(next+j);
	}
	if(j>=T_Length)
	return i-T_Length;
	return 0;
} 