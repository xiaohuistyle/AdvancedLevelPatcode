#include "pch.h"
#include "_1011.h"


_1011::_1011()
{
	//��һ�������¼ 
	int num[3];
	char flag[3] = { 'W','T','L' };
	double sum = 1, k;
	for (int i = 0; i < 3; i++)
	{
		//��һ�����ֵ
		double max = 0;
		//����ÿһ���ǽ������ֵ�Ķ�λ
		for (int j = 0; j < 3; j++)
		{
			scanf_s("%lf",&k);
			if (k>max)//���ֵ�Ķ�λ
			{
				max = k;//��õ�ǰ���ֵ
				num[i] = j;//���ж�λ
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
