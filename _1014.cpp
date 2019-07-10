#include "pch.h"
#include "_1014.h"

struct Node
{
	int id;
	int time;
};

_1014::_1014()
{
	int N, M, K, Q;
	cin >> N >> M >> K >> Q;
	vector<int> finishTime(K + 1);
	vector<int> trans(K + 1);
	for (int i = 1; i <= K; i++)
	{
		cin >> trans[i];
	}
	//定义N个窗口
	vector<queue<Node>> window(N);
	for (int i = 1; i <= K; i++)
	{
		int minLenth = 0;
		int firstFinish = 0;
		Node node;
		node.id = 1;
		for (int j = 0; j < N; j++)
		{
			if (window[j].size() == 0)
			{
				minLenth = j;
				break;
			}
			else
			{
				if (window[j].size() < window[minLenth].size())
				{
					minLenth = j;
				}
				if (window[j].front().time < window[firstFinish].front().time)
				{
					firstFinish = j;
				}
			}
		}
		//若队列未满
		if (window[minLenth].size() < M)
		{
			if (window[minLenth].size() != 0)
			{
				node.time = window[minLenth].back().time + trans[i];
			}
			else
			{
				node.time = 480 + trans[i];
			}
			window[minLenth].push(node);
			finishTime[i] = node.time;
		}
		else//若队列满
		{
			node.time = window[firstFinish].back().time + trans[i];
			window[firstFinish].pop();
			window[firstFinish].push(node);
			finishTime[i] = node.time;
		}
	}
	for (int i = 0; i < Q; i++)
	{
		int qry;
		cin >> qry;
		if (finishTime[qry] - trans[qry] >= 17 * 60)
		{
			printf("Sorry\n");
		}
		else
		{
			printf("%02d:%02d\n", finishTime[qry] / 60, finishTime[qry] % 60);
		}
	}

}


_1014::~_1014()
{
}
