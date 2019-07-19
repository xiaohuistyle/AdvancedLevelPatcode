#include "pch.h"
#include "DijkstraV2.h"
#define INF 1000
//设置图函数
int mapV2[1005][1005];
int vis[1005], dis[1005];

void initMap(int n) {
	
	memset(mapV2, INF, sizeof(mapV2));
	for (int i = 1; i <= n; i++)
	{
		mapV2[i][i] = 0;
	}
}
void getmap(int m) {
	int u=-1, v=-1, w=-1;
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d %d %d",u,v,w);
		if (mapV2[u][v] > w)
		{
			mapV2[u][v] = w;
			mapV2[v][u] = w;
		}
	}
}

void GoDijkstraV2(int u,int n) {
	memset(vis,0,sizeof(vis));
	for (int i = 1; i <= n; i++)
	{
		dis[i] = mapV2[u][i];
	}
	vis[u] = 1;
	for (int i = 1; i < n; i++)
	{
		int min = INF;
		int temp = 0;
		for (int j = 1; j <= n; j++)
		{
			//记录最小的值与相对应的下标
			if (!vis[j]&&dis[j]<min)
			{
				min = dis[j];
				temp = j;
			}
		}
		//修改是否访问过
		vis[temp] = 1;
		//用最小的点去访问周围的点，并且更新这个点周围的距离
		for (int j = 1; j <= n; j++)
		{
			if (mapV2[temp][j] + dis[temp] < dis[j])
			{
				dis[j] = mapV2[temp][j] + dis[temp];
			}
		}
	}

}



DijkstraV2::DijkstraV2()
{
	int n, m;
	scanf_s("%d %d",&n,&m);
	initMap(n);
	getmap(m);
	

}


DijkstraV2::~DijkstraV2()
{
}
