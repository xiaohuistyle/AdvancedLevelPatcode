#include "pch.h"
#include "_1005.h"


_1005::_1005()
{
	string numEnglish[10] = { "zero","one","two","three","four","five","six","seven","eight","nine"};
	string input;
	cin >> input;
	int sum = 0;
	for (int i = 0; i < input.length(); i++)
	{
		sum += input[i]-48;
	}

	for (int i = 0; i < to_string(sum).length(); i++)
	{
		char result = to_string(sum)[i];
		switch (result)
		{
			case'0':
				cout << "zero";
				break;
			case'1':
				cout << "one";
				break;
			case'2':
				cout << "two";
				break;
			case'3':
				cout << "three";
				break;
			case'4':
				cout << "four";
				break;
			case'5':
				cout << "five";
				break;
			case'6':
				cout << "six";
				break;
			case'7':
				cout << "seven";
				break;
			case'8':
				cout << "eight";
				break;
			case'9':
				cout << "nine";
				break;
			default:
				break;
		}
		if (i!= to_string(sum).length()-1)
		{
			cout << " ";
		}
	}



}


_1005::~_1005()
{
}
