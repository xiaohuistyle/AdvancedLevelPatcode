#include "pch.h"
#include "_1019.h"




_1019::_1019()
{
	int N, b;
	cin >> N >> b;
	int num=0;
	int bHex[100];
	while (N != 0) {
		bHex[num++] = N % b;
		N /= b;
	}
	bool flag = true;
	for (int i = 0; i < num/2; i++)
	{
		if (bHex[i]!=bHex[num-1])
		{
			flag = false;
		}
	}
	if (flag)
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}
	for (int i = num-1 ; i >= 0 ; i--)
	{
		cout << bHex[i];
		if (i!=0)
		{
			cout << " ";
		}
		
	}

}


_1019::~_1019()
{
}
