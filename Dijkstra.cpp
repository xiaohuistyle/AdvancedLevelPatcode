#include "pch.h"
#include "Dijkstra.h"

//α���� �ܲ�ͨ �뿴useful

#define MAXNUM 100
#define MAXINT 100
int edge[100][100];//��
int distlen[MAXNUM];
int prevnode[MAXNUM];

void dijkstra(int start,int n) {
	bool s[MAXNUM];//ȷ�������Ƿ��ڼ��ϵ��С�
	for (int i = 0; i < n; i++)
	{
		distlen[i] = edge[start][i];//����ʼ�㵽������ĳ�ֵ
		s[i] = false;//�����нڵ����s����
		if (distlen[i] == MAXINT)
		{
			prevnode[i] = -1;//û��ǰ���ڵ�
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
