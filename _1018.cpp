#include "pch.h"
#include "_1018.h"
const int MAX_NUM = 0x3f3f3f3f;
int PbmcVis[510], PbmcDis[510];
int PbmcOut = MAX_NUM,PbmcBack = MAX_NUM;
vector<int>  path, tempath, e[510] , Ci;
int Cmax, N, SP,M, mindis;
int PbmcMap[510][510];
void PbmcDfs(int u,int w,int curout,int curback) {
	if (w>mindis)
	{
		return;
	}
	else if(u==SP && w==mindis)
	{
		if (curout < PbmcOut)
		{
			PbmcOut = curout;
			PbmcBack = curback;
			path = tempath;
		}
		else if( PbmcOut == curout && curback < PbmcBack)
		{
			PbmcBack = curback;
			path = tempath;
		}
		return;
	}
	for (int i = 0; i < e[u].size(); i++)
	{
		int v = e[u][i];
		if (!PbmcVis[i])
		{
			tempath.push_back(v);
			PbmcVis[v] = 1;
			int adjust = curback + Ci[v] - Cmax / 2;
			if (adjust >=0)
			{
				PbmcDfs(v, PbmcMap[u][v]+w, curout, adjust);
			}
			else
			{
				PbmcDfs(v, PbmcMap[u][v] + w, curout-adjust, 0);
			}
			PbmcVis[v] = 0;
			tempath.pop_back();

		}

	}




}




int PbmcOfDijkstra(int N,int map[510][510],int sp) {

	memset(PbmcDis, MAX_NUM,sizeof(PbmcDis));
	PbmcDis[0] = 0;
	for (int i = 0; i <= N; i++)
	{
		int u = -1, min = MAX_NUM;
		//找到最小的距离
		for (int j = 0; j < N; j++)
		{
			if (!PbmcVis[j] && PbmcDis[j]<min)
			{
				min = PbmcDis[u = j];
			}
		}
		if (u==-1)
		{
			break;
		}
		PbmcVis[u] = 1;
		for (int j = 0; j <= N; j++)
		{
			if (PbmcDis[j]>PbmcDis[u]+map[u][j])
			{
				PbmcDis[j] = PbmcDis[u] + map[u][j];
			}
		}
	}
	return PbmcDis[sp];
}



_1018::_1018()
{
	
	cin >> Cmax >> N >> SP >> M;
	
	//输入每个节点现在的自行车数量
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		Ci.push_back(temp);
	}
	//输入边权重关系 构建一个无向图
	
	memset(PbmcMap,0,sizeof(PbmcMap));

	for (int i = 0; i < M; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back(v);
		e[v].push_back(u);
		PbmcMap[u][v] = PbmcMap[v][u] = w;
	}
	mindis = PbmcOfDijkstra(N, PbmcMap,SP);
	memset(PbmcVis, 0, sizeof(PbmcVis));
	PbmcVis[0] = 1;
	PbmcDfs(0,0,0,0);
}


_1018::~_1018()
{
}
