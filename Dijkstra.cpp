#include "pch.h"
#include "Dijkstra.h"

//伪代码 跑不通 请看useful

#define MAXNUM 100
#define MAXINT 100
int edge[100][100];//边
int distlen[MAXNUM];
int prevnode[MAXNUM];

void dijkstra(int start,int n) {
	bool s[MAXNUM];//确定定点是否在集合当中、
	for (int i = 0; i < n; i++)
	{
		distlen[i] = edge[start][i];//从起始点到各个点的初值
		s[i] = false;//将所有节点加入s集合
		if (distlen[i] == MAXINT)
		{
			prevnode[i] = -1;//没有前驱节点
		}
		else
		{
			prevnode[i] = start;
		}
	}
	distlen[start] = 0;
	s[start] = true;
	for (int i = 0; i < n; i++)
	{
		int min = MAXINT;
		int u = start;
		for (int j = 0; j < n; j++)
		{
			if (!s[j] && distlen[j] < min)
			{
				u = j;
				min = distlen[j];
			}
			s[u] = true;
			for (int j = 0; j < n; j++)
			{
				if (!s[j] && distlen[j]> distlen[u]+edge[u][j])
				{
					distlen[j] = distlen[u] + edge[u][j];
					prevnode[j] = u;
				}
			}
		}
	}



}



Dijkstra::Dijkstra()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> edge[i][j];
		}
	}
	dijkstra(0, n);



}


Dijkstra::~Dijkstra()
{
}
