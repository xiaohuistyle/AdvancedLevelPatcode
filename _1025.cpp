#include "pch.h"
#include "_1025.h"

struct Testees
{
	char registration_number[13];
	int score;
	int final_rank;
	int location_number;
	int local_rank;
};
bool cmp_Testees_score(Testees A, Testees B) {
	if (A.score==B.score)
	{
		return strcmp(A.registration_number, B.registration_number) < 0;
	}
	else
	{
		return A.score > B.score;
	}
}
_1025::_1025()
{
	vector<vector<Testees>> All_list;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int NN;
		cin >> NN;
		vector<Testees> Single_list;
		for (int j = 0; j < NN; j++)
		{
			Testees node;
			cin >> node.registration_number;
			cin >> node.score;
			node.location_number = i+1;
			Single_list.push_back(node);
		}
		sort(Single_list.begin(),Single_list.end(), cmp_Testees_score);
		// initial 0 place 
		Single_list[0].local_rank = 1;
		for (int i = 1; i < NN; i++)
		{
			if (Single_list[i].score == Single_list[i-1].score)
			{
				Single_list[i].local_rank = Single_list[i-1].local_rank;
			}
			else
			{
				Single_list[i].local_rank = i + 1;
			}
		}
		All_list.push_back(Single_list);
	}
	for (int i = 1; i < N; i++)
	{
		All_list[0].insert(All_list[i-1].end(),All_list[i].begin(),All_list[i].end());
	}
	sort(All_list[0].begin(), All_list[0].end(), cmp_Testees_score);
	All_list[0][0].final_rank = 1;
	for (int i = 1; i < All_list[0].size(); i++)
	{
		if (All_list[0][i].score == All_list[0][i - 1].score)
		{
			All_list[0][i].final_rank = All_list[0][i - 1].final_rank;
		}
		else
		{
			All_list[0][i].final_rank = i+1 ;
		}
	}
	cout << All_list[0].size()<<"\n";
	for (int i = 0; i < All_list[0].size(); i++)
	{
		cout << All_list[0][i].registration_number<<" "<< All_list[0][i].final_rank << " " << All_list[0][i].location_number << " " << All_list[0][i].local_rank;
		if (i!=All_list[0].size()-1)
		{
			cout << "\n";
		}
	}
	



}
_1025::~_1025()
{
}
