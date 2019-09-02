#include "pch.h"
#include "bag.h"
/*排序函数，将物品按照从大到小排序（价值/重量）*/
void swap(float ave[], int s[], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			/*如果前面的值小于后面的值则调换位置*/
			if (ave[s[i]] <= ave[s[j]])
			{
				/*注意这里互换的是下标并不是真正的值，因为后面还要用到重量*/
				int temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
	}
}
void bag_C(float w[], float p[], int s[], float volume, int n)
{
	int i;
	float totalV = 0; //总价值
	for (i = 0; i < n; i++)
	{
		/*如果当前的容量能装下i物品，则全部装入*/
		if (volume >= w[s[i]])
		{
			volume -= w[s[i]]; //背包的容量减去装入的重量
			totalV += p[s[i]]; //将当前背包的价值加上装入的物品的价值
			cout << "重量为" << w[s[i]] << ",价值为" << p[s[i]] << "的物品被全部拿走" << endl;
		}
		else
		{
			/*如果不能全部装入则装入部分直至全部装满*/
			totalV += volume / w[s[i]] * p[s[i]]; //相应的价值按照相应的比例乘以重量
			cout << "重量为" << w[s[i]] << ",价值为" << p[s[i]] << "的物品拿走" << volume / w[s[i]] << endl;
			volume = 0;
			break;
		}
	}
	cout << "能装满的最大价值为：" << totalV << endl;
}

bag::bag()
{
	int s[20], i;
	float w[20], p[20]; //w为重量，p为价值

	cout << "请输入最大重量：" << endl;
	float volume; //最大重量
	cin >> volume;

	cout << "请输入商品的种类数量：" << endl;
	int n; //商品种类数量
	cin >> n;

	cout << "请输入各个商品的重量和价值：" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> w[i] >> p[i];
	}

	float ave[20]; //ave为单位重量上的价值
	for (i = 0; i < n; i++)
	{
		ave[i] = p[i] / w[i]; //重量除以价值
	}

	for (i = 0; i < n; i++)
	{
		/*下标函数*/
		s[i] = i;
	}

	swap(ave, s, n);
	bag_C(w, p, s, volume, n);
}


bag::~bag()
{
}
