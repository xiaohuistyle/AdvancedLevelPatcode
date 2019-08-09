#include "pch.h"
#include "_1020.h"
typedef struct Tree
{
	int data;
	Tree *Lchild;
	Tree *Rchild;
};
int treePost[30];
int treeIn[30];
int ans[30];
void dfs(int L1,int R1,int L2,int R2, Tree* &root) {
	root = new Tree();
	int flag=0;
	//search root index in INtree
	for (int i = L1; i <= R1; i++)
	{
		if (treeIn[i]==treePost[R2])
		{
			flag = i;
			break;
		}
	}
	// set root data
	root->data = treePost[R2];
	// when flag == L1 , root not have left child
	if (flag == L1)
	{
		root->Lchild = NULL;
	}
	else// 
	{
		dfs(L1, flag - 1, L2, L2 + flag - L1 - 1, root->Lchild);
	}
	if (flag == R1)
	{
		root->Rchild = NULL;
	}
	else
	{
		dfs(flag + 1, R2, R2 - (R1 - flag), R2 - 1, root->Rchild);
	}
}
int Count;
void bfs(Tree* &tree) {
	queue<Tree*> q;
	q.push(tree);
	while (!q.empty())
	{
		Tree *root = q.front();
		q.pop();
		ans[Count++] = root->data;
		if (root->Lchild)
		{
			q.push(root->Lchild);
		}
		if (root->Rchild)
		{
			q.push(root->Rchild);
		}
	}

}




_1020::_1020()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> treePost[i];
	}
	for (int i = 1; i <= N; i++)
	{
		cin >> treeIn[i];
	}
	Tree *tree;
	dfs(1, N, 1, N, tree);
	Count = 0;
	bfs(tree);
	for (int i = 0; i < Count; i++)
	{
		if (i==Count-1)
		{
			cout << ans[i] << "\n";
		}
		else
		{
			cout << ans[i];
		}
	}

}


_1020::~_1020()
{
}
