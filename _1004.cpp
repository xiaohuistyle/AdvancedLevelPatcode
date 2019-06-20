#include "pch.h"
#include "_1004.h"


struct node
{
	int level;//�ȼ�
	int flag;// �Ƿ��к���
	int father;//���ڵ�ĸ���

};


_1004::_1004()
{
	struct node nodes[205];
	int n, m;
	int nownode, nownodenumber, childnode;
	int maxlevel = 1;
	cin >> n >> m;
	//��ʼ��n���ڵ� �±��0��ʼ
	for (int i = 1; i <= n; i++)
	{
		nodes[i].level = 0;
		nodes[i].father = 0;
		nodes[i].flag = 0;
	}
	nodes[1].level = 1;
	while (m--)
	{
		cin >> nownode >> nownodenumber;
		if (nownodenumber!=0)
		{
			nodes[nownode].flag = 1;
		}
		while (nownodenumber--)
		{
			cin >> childnode;
			nodes[childnode].father = nownode;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			//�������нڵ� ���ҵ���ǰ�ڵ�ĸ��ף� ��ǰ�ڵ�ĵȼ�Ϊ���ڵ�ĵȼ� ��  1
			if (nodes[j].father == i)
			{
				nodes[j].level = nodes[i].level + 1;
			}
		}
	}
	int result[205];
	memset(result, 0, 205); //This will reinitialize all to ZERO
	//��ѯÿһ���ȼ��ж��ٸ�û�к��ӽڵ�ĵ�
	for (int i = 1; i <= n; i++)
	{
		//����ǰ�ڵ� �޺��ӽڵ�
		if (!nodes[i].flag && nodes[i].level>0)
		{
			result[nodes[i].level]++;
		}
		if (nodes[i].level>maxlevel)
		{
			maxlevel = nodes[i].level;
		}
	}

	for (int i = 1; i <= maxlevel; i++)
	{
		cout << result[i];
		if (i != maxlevel)
		{
			cout << " ";
		}
		
	}
}


_1004::~_1004()
{
}
