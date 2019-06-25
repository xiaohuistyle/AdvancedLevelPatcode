#include "pch.h"
#include "_1006.h"

struct sign
{
	string name;
	string start;
	string end;
};

bool start(sign one, sign two) {

	return one.start < two.start;

}

bool end(sign one, sign two) {
	return one.end > two.end;
}



_1006::_1006()
{
	vector<sign> list;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		sign temp;
		cin >> temp.name >> temp.start >> temp.end;
		list.push_back(temp);
	}
	sort(list.begin(),list.end(), start);
	string objearly = list[0].name;
	sort(list.begin(), list.end(), end);
	string objlate = list[0].name;
	cout << objearly << " " << objlate;






}


_1006::~_1006()
{
}
