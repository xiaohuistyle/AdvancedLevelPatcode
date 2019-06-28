#include "pch.h"
#include "_1010.h"


_1010::_1010()
{
	string n1, n2;
	int tag, radix;
	cin >> n1 >> n2 >> tag >> radix;
	long long a = 0, b = 0, res;
	if (tag == 2) swap(n1, n2);

	char ch;
	int index = 0;
	//a 主要用于最大值的边界
	while (!n1.empty())
	{
		ch = n1.back();
		if (ch >= 'a' && ch <= 'z')
		{
			a += (ch - 'a' + 10) * pow(radix, index);
		}
		else
		{
			a += (ch - '0') * pow(radix, index);
		}
		n1.pop_back();
		index++;
	}

	long long temp = 0;
	for (int i = 0; i < n2.length(); i++)
	{
		if (n2[i] > temp) temp = n2[i];
	}
	if (temp >= 97) temp -= 87;
	else temp -= 48;

	long long left = temp + 1;
	long long right = a + 1;
	res = a + 2;
	while (left <= right)
	{
		temp = (left + right) / 2;
		index = 0;
		b = 0;
		string tempn2 = n2;
		while (!tempn2.empty())
		{
			ch = tempn2.back();
			if (ch >= 'a' && ch <= 'z')
			{
				b += (ch - 'a' + 10) * pow(temp, index);
			}
			else
			{
				b += (ch - '0') * pow(temp, index);
			}
			tempn2.pop_back();
			index++;
			if (b > a || b < 0) break;
		}
		if (a == b)
		{
			res = min(res, temp);
			right--;
		}
		else if (b > a || b < 0)
		{
			right = temp - 1;
		}
		else if (b < a)
		{
			left = temp + 1;
		}
	}
	if (res == a + 2) cout << "Impossible" << endl;
	else cout << res << endl;
}


_1010::~_1010()
{
}
