#include "pch.h"
#include "_1004.h"


struct node
{
	int level;//等级
	int flag;// 是否有孩子
	int father;//本节点的父亲

};


_1004::_1004()
{
	struct node nodes[205];
	int n, m;
	int nownode, nownodenumber, childnode;
	int maxlevel = 1;
	cin >> n >> m;
	//初始化n个节点 下标从0开始
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
			//遍历所有节点 若找到当前节点的父亲， 则当前节点的等级为父节点的等级 加  1
			if (nodes[j].father == i)
			{
				nodes[j].level = nodes[i].level + 1;
			}
		}
	}
	int result[205];
	memset(result, 0, 205); //This will reinitialize all to ZERO
	//查询每一个等级有多少个没有孩子节点的点
	for (int i = 1; i <= n; i++)
	{
		//若当前节点 无孩子节点
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
