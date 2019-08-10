#include "pch.h"
#include "_1021.h"
const int maxsize = 10005;
vector<int> edge[maxsize];
int DeepN;
int DeepVisited[maxsize];
int DeepDepth[maxsize];
int hashTable[maxsize];
int max_depth=0;

void DFS(int start) {
	DeepVisited[start] = 1;
	for (int i = 1; i <= DeepN; i++)
	{
		//find will return visited object ,if iter not have target , will return end iter;
		//if edge content i and not visited ,next will dfs this note
		if (!DeepVisited[i] && find(edge[start].begin(),edge[start].end(),i) != edge[start].end())
		{
			DFS(i);
		}
	}
}
int BFS(int start) {
	queue<int> q;
	max_depth = 0;
	q.push(start);
	while (!q.empty())
	{
		int head = q.front();
		max_depth = max(max_depth,DeepDepth[head]);
		DeepVisited[head] = 1;
		q.pop();
		for (int i = 0; i < edge[head].size(); i++)
		{
			if (!DeepVisited[edge[head][i]])
			{
				DeepDepth[edge[head][i]] = max_depth + 1;
				q.push(edge[head][i]);
			}
		}
	}
	int max_index = -1;
	for (int i = 1; i <= DeepN; i++)
	{
		if (DeepDepth[i]>max_index)
		{
			max_index = DeepDepth[i];
		}
	}
	return max_index;
}

_1021::_1021()
{
	int first, second;
	cin >> DeepN;
	for (int i = 1; i < DeepN; i++)
	{
		cin >> first >> second;
		edge[first].push_back(second);
		edge[second].push_back(first);
	}
	memset(DeepVisited,0,sizeof(DeepDepth));
	// use DFS to search connect component
	int count = 0;
	for (int i = 1; i <= DeepN; i++)
	{
		if (!DeepVisited[i])
		{
			DFS(i);
			count++;
		}
	}
	// when only have one connect component, use bfs find deeply root 

	if (count == 1)
	{
		for (int i = 1; i <= DeepN; i++)
		{
			memset(DeepVisited,0,sizeof(DeepVisited));
			memset(DeepDepth,0,sizeof(DeepDepth));
			hashTable[i] = BFS(i);
		}
		//find max node
		int max_index = 0;
		for (int i = 1; i <= DeepN; i++)
		{
			if (hashTable[i] > max_index)
			{
				max_index = hashTable[i];
			}
		}
		for (int i = 1;i <= DeepN; i++)
		{
			if (hashTable[i] == max_index)
			{
				cout << i << "\n";
			}
		}



	}
	else
	{
		cout << "Error: "<<count<<" components";
	}

}


_1021::~_1021()
{
}
