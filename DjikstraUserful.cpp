#include "pch.h"
#include "DjikstraUserful.h"
const int maxnum = 100;
const int maxint = 999999;
//各数组都从下表 1 开始
int dist[maxnum];//当前节点到源节点的最短路径
int nodeprev[maxnum];//电器节点的前一个节点
int c[maxnum][maxnum];
int n, line;

// n 节点数 v起始节点 dist 距离数 prev 前驱节点 c 无向图
void Dijkstrauserful(int n,int v,int *dist,int *prev,int c[maxnum][maxnum]) {
	bool s[maxnum];//判断是否存入集合当中
	for (int i = 0; i <= n; i++)
	{
		dist[i] = c[v][i];//记录阶段的所有权重值
		s[i] = 0;//初始化未用过的点
		if (dist[i] == maxint)//记录前驱节点
		{
			prev[i] = 0;
		}
		else
		{
			prev[i] = v;
		}
	}
	dist[v] = 0;
	s[v] = 1;//标记节点
	for (int i = 2; i <= n; ++i)
	{
		int temp = maxint;
		int u = v;
		//找出最小的路径权值
		for (int j = 1; j <= n; ++j)
		{
			if (!s[j] && dist[j]<temp)
			{
				u = j;
				temp = dist[j];
			}
		}
		s[u] = 1;//标记节点
		//更新 dist
		for (int j = 1; j <= n; ++j)
		{
			if (!s[j] && c[u][j]<maxint)
			{
				//新的路径距离值
				int newdist = dist[u] + c[u][j];
				if (newdist < dist[j])
				{
					dist[j] = newdist;
					prev[j] = u;
				}
			}
		}
	}
}


void searchPath(int *prev,int v,int u) {
	int que[maxnum];
	int tot = 1;
	que[tot] = u;
	tot ++ ;
	int temp = prev[u];
	while (temp != v)
	{
		que[tot] = temp;
		tot++;
		temp = prev[temp];
	}
	que[tot] = v;
	for (int i = tot; i >= 1 ; --i)
	{
		if (i!=1)
		{
			cout << que[i] << "->";
		}
		else
		{
			cout << que[i] << endl;
		}
	}

}


DjikstraUserful::DjikstraUserful()
{
	cin >> n;//节点数
	cin >> line;//路径数
	int p, q, len;
	//下标从1开始 初始化整个无向图
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			c[i][j] = maxint;
		}
	}
	//输入图的距离
	for (int i = 1; i <= line; ++i)
	{
		cin >> p >> q >> len;
		//排除有重边 并初始化为对称图
		if (len<c[p][q])
		{
			c[p][q] = len;
			c[q][p] = len;
		}
	}
	//初始化距离
	for (int i = 1; i <= n ; ++i)
	{
		dist[i] = maxint;
	}
	//
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			printf("%8d",c[i][j]);
		}
		printf("\n");
	}
	Dijkstrauserful(n,1,dist, nodeprev,c);
	cout << "源点到最后一个顶点的最短路径长度: " << dist[n] << endl;

	// 路径
	cout << "源点到最后一个顶点的路径为: ";
	searchPath(nodeprev, 1, n);

}


DjikstraUserful::~DjikstraUserful()
{
}
