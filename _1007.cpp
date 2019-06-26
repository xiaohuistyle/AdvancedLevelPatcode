#include "pch.h"
#include "_1007.h"


_1007::_1007()
{
	int K;
	cin >> K;
	vector<int> list;
	for (int i = 0; i < K; i++)
	{
		int temp;
		cin >> temp;
		list.push_back(temp);
	}
	//动态规划
	//存储第i个数对应的最大子序列和
	int data[100];
	//将 data 中的100个空间全部初始化为0
	memset(data,0,100);
	data[0] = list[0];
	//最大和
	int sum = list[0];
	//开始位置
	int start[100];
	memset(start, 0, 100);
	start[0] = 0;
	int first = 0;
	int late = 0;
	for (int i = 1; i < K; i++)
	{
		//分别讨论当前位为 负数 0 正数的情况
		//当前位为正数的情况
		//若第一位加第二位大于第二位 则证明 第一位第二位都为正数
		if (data[i-1]+list[i]>list[i])
		{
			//更新第二位对应的最大序列
			data[i] = data[i - 1] + list[i];
			//更新当前值所对应的的位置
			start[i] = start[i - 1];
			if (data[i]>sum)
			{
				sum = data[i];
				first = start[i];
				late = i;

			}
		}//当前位为0的情况
		else if(data[i - 1] + list[i] == list[i])
		{
			//
			data[i] = list[i];
			//与上一位是同样的地址
			start[i] = start[i - 1];
			if (data[i] > sum)
			{
				sum = data[i];
				first = start[i];
				late = i;

			}
		}//当前位小于0的情况
		else
		{
			//若是小于 则说明第i位为负数 即当前位为负数
			//将当前位的最大值赋值 并且将当前位的的当前最大子序列的下标开始 即重新开始计算子序列
			data[i] = list[i];
			start[i] = i;
			if (data[i] > sum)
			{
				sum = data[i];
				first = start[i];
				late = i;

			}
		}
	}
	if (sum>=0)
	{
		cout << sum << " " << list[first] << " " << list[late];
	}
	else
	{
		cout << 0 << " " << list[0] << " " << list[K - 1];
	}




}


_1007::~_1007()
{
}
