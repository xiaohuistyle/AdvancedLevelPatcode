#include "pch.h"
#include "_1028.h"

struct Student
{
	char number[7];
	string name;
	int score;
};

bool sort_number(Student A,Student B) {
	return strcmp(A.number, B.number) < 0;
}
bool sort_name(Student A, Student B) {
	if (A.name == B.name)
	{
		return strcmp(A.number, B.number) < 0;
	}
	else
	{
		return A.name < B.name;
	}
	
}
bool sort_score(Student A, Student B) {
	if (A.score == B.score)
	{
		return strcmp(A.number, B.number) < 0;
	}
	else
	{
		return A.score < B.score;
	}
	
}

_1028::_1028()
{
	int N, C;
	cin >> N >> C;
	vector<Student> student_list;
	for (int i = 0; i < N; i++)
	{
		Student node;
		cin >> node.number >> node.name >> node.score;
		student_list.push_back(node);
	}
	if (C==1)
	{
		sort(student_list.begin(),student_list.end(), sort_number);
	}
	else if(C==2)
	{
		sort(student_list.begin(), student_list.end(), sort_name);
	}
	else if(C==3)
	{
		sort(student_list.begin(), student_list.end(), sort_score);
	}
	for (int i = 0; i < student_list.size(); i++)
	{
		cout << student_list[i].number << " " << student_list[i].name << " " << student_list[i].score;
		if (i!=student_list.size()-1)
		{
			cout << "\n";
		}
	}
}


_1028::~_1028()
{
}
