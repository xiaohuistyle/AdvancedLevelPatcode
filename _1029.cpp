#include "pch.h"
#include "_1029.h"

bool sort_value_node(int a,int b) {
	return a > b;
}

_1029::_1029()
{
	vector<int> median_list;
	int N1;
	cin >> N1;
	for (int i = 0; i < N1; i++)
	{
		int node;
		cin >> node;
		median_list.push_back(node);
	}
	int N2;
	cin >> N2;
	for (int i = 0; i < N2; i++)
	{
		int node;
		cin >> node;
		median_list.push_back(node);
	}

	sort(median_list.begin(),median_list.end(), sort_value_node);
	cout << median_list[median_list.size() / 2];
}


_1029::~_1029()
{
}
