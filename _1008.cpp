#include "pch.h"
#include "_1008.h"


_1008::_1008()
{
	int N;
	cin >> N;
	vector<int> list;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		list.push_back(temp);
	}
	int time = 0;
	for (int i = 0; i < list.size(); i++)
	{
		if (i==0)
		{
			if (list[i] > 0)
			{
				time += (list[i] - 0)*6;
			}
		}
		else if(i>0)
		{
			//若是上楼
			if (list[i] > list[i - 1])
			{
				time += (list[i] - list[i - 1]) * 6;
			}//若是下楼
			else if (list[i] < list[i - 1])
			{
				time += (list[i-1] - list[i]) * 4;
			}
			
		}
		time += 5;
	}
	cout << time;




}


_1008::~_1008()
{
}
