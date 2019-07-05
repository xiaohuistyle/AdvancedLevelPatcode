#include "pch.h"
#include "_1013.h"

const int maxn = 1005;
int visit[maxn];
int link[maxn][maxn];
int N1013, m, k;

void dfs(int x) {
	//进行标记
	visit[x] = 1;
	//节点下标从1开始
	for (int i = 1; i <= N1013; i++)
	{
		//从当前的x点为起点 搜索相连的顶点 如果搜索到， 则进入下一个顶点
		if (visit[i]!=1 && link[i][x]==1)
		{
			dfs(i);
		}
	}
}


_1013::_1013(){

	cin >> N1013 >> m >> k;
	int city1, city2;
	memset(link,0,sizeof(link));
	for (int i = 0; i < m; i++)
	{
		cin >> city1 >> city2;
		link[city1][city2] = 1;
		link[city2][city1] = 1;
	}
	int miscity;
	int count;
	for (int i = 0; i < k; i++)
	{
		cin >> miscity;
		count = 0;
		//每次重置 visit 进行路劲查找 
		memset(visit,0,sizeof(visit));
		visit[miscity] = 1;
		for (int i = 1; i <= N1013; i++)
		{
			//没被访问过的点进行深搜
			//每次深搜将访问过的点进行标记 每次进行访问 则可算出所有的最大联通子图 
			if (visit[i] != 1)
			{
				dfs(i);
				count++;
			}
		}
		cout << count - 1<< endl;
	}



}


_1013::~_1013()
{
}
