#include "pch.h"
#include "_1024.h"
string Palindromic_Add(string N) {
	int AN = atoi(N.c_str());
	reverse(N.begin(), N.end());
	int RN = atoi(N.c_str());
	return to_string(AN+RN);
}
bool Is_Palindromic(string N) {
	for (int i = 0; i < N.size(); i++)
	{
		if (N[i]!=N[N.size()-i-1])
		{
			return false;
		}
	}
	return true;
}
_1024::_1024()
{
	string N;
	int  K;
	cin >> N >> K;
	int flag = K;

	for (int i = 0; i < K; i++)
	{
		N = Palindromic_Add(N);
		if (Is_Palindromic(N))
		{
			flag = i+1;
			break;
		}
	}
	cout << N << "\n" << flag;
}


_1024::~_1024()
{
}
