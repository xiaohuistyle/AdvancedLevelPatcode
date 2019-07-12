#include "pch.h"
#include "_1015.h"

bool isPrimes(int number) {
	for (int i = 2; i < sqrt(number); i++)
	{
		if (number%2==0)
		{
			return false;
		}
	}
	return true;
}


int reverse(int N,int D) {
	int num = 0;
	while (N)
	{
		num = num * D + N % D;
		N /= D;
	}
	return num;
}




_1015::_1015()
{
	int N, D;
	bool flag = true;
	while (flag)
	{
		cin >> N >> D;
		//程序退出条件
		if (N < 0)
		{
			flag = false;
			return ;
		}
		int reNum = reverse(N,D);
		if (isPrimes(reNum))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}

}


_1015::~_1015()
{
}
