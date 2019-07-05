#include "pch.h"
#include "_1013.h"

const int maxn = 1005;
int visit[maxn];
int link[maxn][maxn];
int N1013, m, k;

void dfs(int x) {
	//���б��
	visit[x] = 1;
	//�ڵ��±��1��ʼ
	for (int i = 1; i <= N1013; i++)
	{
		//�ӵ�ǰ��x��Ϊ��� ���������Ķ��� ����������� �������һ������
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
		//ÿ������ visit ����·������ 
		memset(visit,0,sizeof(visit));
		visit[miscity] = 1;
		for (int i = 1; i <= N1013; i++)
		{
			//û�����ʹ��ĵ��������
			//ÿ�����ѽ����ʹ��ĵ���б�� ÿ�ν��з��� ���������е������ͨ��ͼ 
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
