#include "pch.h"
#include "_1009.h"


_1009::_1009()
{
	double a[1001] = { 0 }, b[1001] = { 0 }, c[2001] = { 0 };
	int n1, n2;
	int k;
	cin >> n1;
	for (int i = 0; i < n1; i++)
	{
		cin >> k;
		double temp;
		cin >> temp;
		//+= 是为了在输入相同时，进行同类项的合并
		a[k] += temp;
	}
	cin >> n2;
	for (int i = 0; i < n2; i++)
	{
		cin >> k;
		double temp;
		cin >> temp;
		b[k] += temp;
	}
	//进行相乘
	for (int i = 0; i < 1001; i++)
	{
		for (int j = 0; j < 1001; j++)
		{
			//有效的多项式进行相乘
			if (a[i]&&b[j])
			{
				c[i + j] += a[i] * b[j];
			}
		}
	}
	//统计多项式个数 并统计最大值
	k = 0;

	int bignum = 0;
	for (int i = 0; i < 2001; i++)
	{
		if (c[i])
		{
			k++;
			if (i> bignum)
			{
				bignum = i;
			}
		}
	}
	cout << k;
	for (int i = bignum; i >=0 ; i--)
	{
		if (c[i])
		{
			cout << " " << i << " ";
			printf("%.1lf", c[i]);
		}
	}
}


_1009::~_1009()
{
}
