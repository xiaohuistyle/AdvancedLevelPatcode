#include "pch.h"
#include "_1023.h"

string Max_Num_Mul(string input,string mul) {
	string res = "";
	reverse(input.begin(),input.end());
	reverse(mul.begin(), mul.end());
	vector<int> list(input.size() + mul.size(), 0);
	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < mul.size(); j++)
		{
			list[i + j] = (input[i]-'0') * (mul[j]-'0');
		}
	}
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]>=10)
		{
			list[i + 1] += list[i] / 10;
			list[i] %= 10;

		}
	}
	int flag = -1;
	for (flag = list.size() - 1; flag > 0 && list[flag] == 0; flag--);
	for (; flag >= 0; flag--)
	{
		res += to_string( list[flag]);
	}
	return res;
}


_1023::_1023()
{
	string input, result;
	cin >> input;
	string mul = "2";
	result = Max_Num_Mul(input, mul);
	int flag[10];
	memset(flag, 0, sizeof(flag));
	for (int i = 0; i < input.size(); i++)
	{
		flag[input[i]]++;
	}
	for (int i = 0; i < result.size(); i++)
	{
		flag[result[i]]--;
	}
	bool isnot = true;
	for (int i = 0; i < size(flag); i++)
	{
		if (flag[i])
		{
			isnot = false;
			break;
		}
	}
	if (isnot)
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}
	cout << result;



}


_1023::~_1023()
{
}
