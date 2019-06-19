#include "pch.h"
#include "DjikstraUserful.h"
const int maxnum = 100;
const int maxint = 999999;
//�����鶼���±� 1 ��ʼ
int dist[maxnum];//��ǰ�ڵ㵽Դ�ڵ�����·��
int nodeprev[maxnum];//�����ڵ��ǰһ���ڵ�
int c[maxnum][maxnum];
int n, line;

// n �ڵ��� v��ʼ�ڵ� dist ������ prev ǰ���ڵ� c ����ͼ
void Dijkstrauserful(int n,int v,int *dist,int *prev,int c[maxnum][maxnum]) {
	bool s[maxnum];//�ж��Ƿ���뼯�ϵ���
	for (int i = 0; i <= n; i++)
	{
		dist[i] = c[v][i];//��¼�׶ε�����Ȩ��ֵ
		s[i] = 0;//��ʼ��δ�ù��ĵ�
		if (dist[i] == maxint)//��¼ǰ���ڵ�
		{
			prev[i] = 0;
		}
		else
		{
			prev[i] = v;
		}
	}
	dist[v] = 0;
	s[v] = 1;//��ǽڵ�
	for (int i = 2; i <= n; ++i)
	{
		int temp = maxint;
		int u = v;
		//�ҳ���С��·��Ȩֵ
		for (int j = 1; j <= n; ++j)
		{
			if (!s[j] && dist[j]<temp)
			{
				u = j;
				temp = dist[j];
			}
		}
		s[u] = 1;//��ǽڵ�
		//���� dist
		for (int j = 1; j <= n; ++j)
		{
			if (!s[j] && c[u][j]<maxint)
			{
				//�µ�·������ֵ
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
	cin >> n;//�ڵ���
	cin >> line;//·����
	int p, q, len;
	//�±��1��ʼ ��ʼ����������ͼ
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			c[i][j] = maxint;
		}
	}
	//����ͼ�ľ���
	for (int i = 1; i <= line; ++i)
	{
		cin >> p >> q >> len;
		//�ų����ر� ����ʼ��Ϊ�Գ�ͼ
		if (len<c[p][q])
		{
			c[p][q] = len;
			c[q][p] = len;
		}
	}
	//��ʼ������
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
	cout << "Դ�㵽���һ����������·������: " << dist[n] << endl;

	// ·��
	cout << "Դ�㵽���һ�������·��Ϊ: ";
	searchPath(nodeprev, 1, n);

}


DjikstraUserful::~DjikstraUserful()
{
}
