#include "pch.h"
#include "_1002.h"

map<int, double, greater<int> > poly;
_1002::_1002()
{
	int k1 = 0, k2 = 0;
	cin >> k1;
	int e = 0;
	double c = 0;
	for (int i = 0; i < k1; ++i) {
		cin >> e >> c;
		poly[e] = c;
	}
	cin >> k2;
	for (int i = 0; i < k2; ++i) {
		cin >> e >> c;
		if (poly.count(e) == 0)
			poly[e] = c;
		else
			poly[e] += c;

		//注意加和后系数可能为0
		if (poly[e] == 0.0 || poly[e] == -0.0) {
			poly.erase(e);
		}
	}

	cout << poly.size();
	cout.precision(1);//精度控制
	for (auto it = poly.begin(); it != poly.end(); it++) {
		cout << fixed << " " << it->first << " " << it->second;
	}

	
}


_1002::~_1002()
{
}
