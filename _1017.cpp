#include "pch.h"
#include "_1017.h"
struct Node
{
	int Come;
	int Time;
}customer;

bool cmp(Node a,Node b)
{
	return a.Come < b.Come;
}

_1017::_1017()
{
	int n, k;
	scanf_s("%d %d",&n,&k);
	vector<Node> cus;
	for (int i = 0; i < n; i++)
	{
		int hh, mm, ss, time;
		scanf_s("%d:%d:%d %d",&hh,&mm,&ss,&time);
		int ComeTime = hh * 3600 + mm * 60 + ss;
		if (ComeTime>61200)
		{
			continue;
		}
		customer = { ComeTime ,time*60};
		cus.push_back(customer);
	}
	sort(cus.begin(),cus.end(),cmp);
	vector<int> window(k, 28800);
	double res = 0.0;
	for (int i = 0; i < cus.size(); i++)
	{
		int tempindex = 0;
		int minfinish = window[0];
		//找位置
		for (int j = 1; j < k; j++)
		{
			if (minfinish > window[j])
			{
				minfinish = window[j];
				tempindex = j;
			}
			
		}
		//找到位置后再操作
		if (window[tempindex]<=cus[i].Come)
		{
			window[tempindex] = cus[i].Come + cus[i].Time;
		}
		else
		{
			res += window[tempindex] - cus[i].Come;
			window[tempindex] += cus[i].Time;
		}
	}
	if (cus.size()==0)
	{
		printf_s("0.0");
	}
	else
	{
		printf_s("%.1f",res/60.0/cus.size());
	}









}


_1017::~_1017()
{
}
