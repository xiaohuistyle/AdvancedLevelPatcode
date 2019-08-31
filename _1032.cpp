#include "pch.h"
#include "_1032.h"
char sharing_data[1000000];
int sharing_next[1000000]; 
bool hash_table[1000000];


_1032::_1032()
{
	int begin1, begin2, N;
	scanf_s("%d%d%d",&begin1,&begin2,&N);
	while (N--)
	{
		int a;
		scanf_s("%d",&a);
		scanf_s(" %c %d", &sharing_data[a], &sharing_next[a]);
	}
	while (begin1!=-1)
	{
		hash_table[begin1] = true;
		begin1 = sharing_next[begin1];
	}
	while (begin2!=-1)
	{
		if (hash_table[begin2])
		{
			printf("%05d", begin2);
			return;
		}
		begin2 = sharing_next[begin2];
	}
	printf("-1");

}


_1032::~_1032()
{
}
