#include "pch.h"
#include "_1031.h"


_1031::_1031()
{
	string input;
	cin >> input;
	int len = input.size();
	int k;
	if (len <= 7) {
		k = (len - 1) / 2;
	}
	else {
		k = (len + 2) / 3;
	}
	for (int i = 0; i < k; i++) {
		if (i != k - 1) {
			cout << input[i];
			for (int j = 0; j < len - 2 * k; j++) {
				cout << " ";
			}
			cout << input[len - i - 1] << endl;
		}
		else {
			for (int j = 0; j < len - 2 * k + 2; j++) {
				cout << input[j + k - 1];
			}
			cout << endl;
		}
	}

}


_1031::~_1031()
{
}
