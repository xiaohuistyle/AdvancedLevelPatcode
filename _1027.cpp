#include "pch.h"
#include "_1027.h"


_1027::_1027()
{
	int n;
	char c[14] = { "0123456789ABC" };
	cout << "#";
	for (int i = 0; i < 3; i++) {
		cin >> n;

		cout << c[n / 13] << c[n % 13];
	}
}


_1027::~_1027()
{
}
