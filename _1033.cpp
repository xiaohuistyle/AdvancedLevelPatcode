#include "pch.h"
#include "_1033.h"
const int inf = 0x3f3f3f3f;
struct station {
	double price, dis;
};
bool cmp_station(station a, station b) {
	return a.dis < b.dis;
}
_1033::_1033()
{
	double cmax, d, davg;
	int n;
	scanf_s("%lf%lf%lf%d", &cmax, &d, &davg, &n);
	vector<station> sta(n + 1);
	sta[0] = { 0.0, d };
	for (int i = 1; i <= n; i++)
		scanf_s("%lf%lf", &sta[i].price, &sta[i].dis);
	sort(sta.begin(), sta.end(), cmp_station);
	double nowdis = 0.0, maxdis = 0.0, nowprice = 0.0, totalPrice = 0.0, leftdis = 0.0;
	if (sta[0].dis != 0) {
		printf("The maximum travel distance = 0.00");
		return ;
	}
	else {
		nowprice = sta[0].price;
	}
	while (nowdis < d) {
		//��ǰ���ܵ�������ֵ
		maxdis = nowdis + cmax * davg;
		double minPriceDis = 0, minPrice = inf;
		int flag = 0;
		//�ڲ����ڵ�ǰ����������������վ
		for (int i = 1; i <= n && sta[i].dis <= maxdis; i++) {
			//��һ����վ�ľ���С�����ڵľ��� ����
			if (sta[i].dis <= nowdis) continue;
			//�бȵ�ǰ�۸��С����վ��ȥ�Ǹ���վ
			if (sta[i].price < nowprice) {
				//������
				totalPrice += (sta[i].dis - nowdis - leftdis) * nowprice / davg;
				leftdis = 0.0;
				//���¾���ͼ۸�
				nowprice = sta[i].price;
				nowdis = sta[i].dis;
				flag = 1;
				break;
			}
			//ɸѡ����С�ļ۸������
			if (sta[i].price < minPrice) {
				minPrice = sta[i].price;
				minPriceDis = sta[i].dis;
			}
		}
		//����û���ҵ���վ ��������С�ͼۼ�ֵ
		if (flag == 0 && minPrice != inf) {
			totalPrice += (nowprice * (cmax - leftdis / davg));
			leftdis = cmax * davg - (minPriceDis - nowdis);
			nowprice = minPrice;
			nowdis = minPriceDis;
		}
		if (flag == 0 && minPrice == inf) {
			nowdis += cmax * davg;
			printf("The maximum travel distance = %.2f", nowdis);
			return ;
		}
	}
	printf("%.2f", totalPrice);
}


_1033::~_1033()
{
}
