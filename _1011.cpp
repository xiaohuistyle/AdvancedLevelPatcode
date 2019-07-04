#include "pch.h"
#include "_1011.h"


_1011::_1011()
{
	//设一个数组记录 
	int num[3];
	char flag[3] = { 'W','T','L' };
	double sum = 1, k;
	for (int i = 0; i < 3; i++)
	{
		//设一个最大值
		double max = 0;
		//输入每一行是进行最大值的定位
		for (int j = 0; j < 3; j++)
		{
			scanf_s("%lf",&k);
			if (k>max)//最大值的定位
			{
				max = k;//获得当前最大值
				num[i] = j;//进行定位
			}
		}
		sum *= max;
	}
	printf("%c %c %c ",flag[num[0]],flag[num[1]],flag[num[2]]);
	printf("%.2f", (sum*0.65 - 1) * 2);
}


_1011::~_1011()
{
}
