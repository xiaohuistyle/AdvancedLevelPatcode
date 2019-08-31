#include "pch.h"
#include "_1030.h"
int Cost[505][505], Dis[505][505];//�洢ÿ���ߵ�Ȩ�ء�����
int Travel_dis[505], Travel_cost[505], pathLast[505];//�洢��㵽�õ����̾��롢��㵽�õ����СȨ�ء���㵽�õ�ĸ��ڵ�
bool visit[505];//�洢��㵽�õ��Ƿ��ѱ�����
int Travel_MAX = 0x3f3f3f3f;
int Travel_N, Travel_M, S, D;

void Travel_Dijkstra() {
	while (!visit[D]) {//����յ㻹û�б����ʵ�
		int v = -1, MIN = Travel_MAX;//�ڵ�ǰδ���ʵĽ�����ҵ�������С�Ľ��
		for (int i = 0; i < Travel_N; ++i)
			if (!visit[i] && Travel_dis[i] < MIN) {
				MIN = Travel_dis[i];
				v = i;
			}
		if (v == -1) return;//��ͼ������ͨͼ��ֱ�ӷ���
		visit[v] = true;//�øõ��ѱ�����
		for (int i = 0; i < Travel_N; ++i)//�����õ��ܹ�����Ľ�㲢���������Ϣ
			if (!visit[i] && Dis[v][i] != 0 && Travel_dis[i] > Travel_dis[v] + Dis[v][i]) {
				Travel_dis[i] = Travel_dis[v] + Dis[v][i];
				Travel_cost[i] = Travel_cost[v] + Cost[v][i];
				pathLast[i] = v;
			}
			else if (Dis[v][i] != 0 && Travel_dis[i] == Travel_dis[v] + Dis[v][i] && Travel_cost[i] > Travel_cost[v] + Cost[v][i]) {
				Travel_cost[i] = Travel_cost[v] + Cost[v][i];
				pathLast[i] = v;
			}
	}
}
void Travel_DFS(int v) {
	if (v == S)
		printf("%d", v);
	else {
		Travel_DFS(pathLast[v]);
		printf(" %d", v);
	}
}
_1030::_1030()
{
	scanf_s("%d%d%d%d", &Travel_N, &Travel_M, &S, &D);
	for (int i = 0; i < Travel_M; ++i) {
		int a, b, c, d;
		scanf_s("%d%d%d%d", &a, &b, &c, &d);
		Dis[a][b] = Dis[b][a] = c;
		Cost[a][b] = Cost[b][a] = d;
	}
	fill(Travel_dis, Travel_dis + Travel_N, Travel_MAX);
	fill(Travel_cost, Travel_cost + Travel_N, Travel_MAX);
	Travel_dis[S] = Travel_cost[S] = 0;
	Travel_Dijkstra();
	Travel_DFS(D);
	printf(" %d %d", Travel_dis[D], Travel_cost[D]);
}


_1030::~_1030()
{
}





