#include "pch.h"
#include "_1007.h"


_1007::_1007()
{
	int K;
	cin >> K;
	vector<int> list;
	for (int i = 0; i < K; i++)
	{
		int temp;
		cin >> temp;
		list.push_back(temp);
	}
	//��̬�滮
	//�洢��i������Ӧ����������к�
	int data[100];
	//�� data �е�100���ռ�ȫ����ʼ��Ϊ0
	memset(data,0,100);
	data[0] = list[0];
	//����
	int sum = list[0];
	//��ʼλ��
	int start[100];
	memset(start, 0, 100);
	start[0] = 0;
	int first = 0;
	int late = 0;
	for (int i = 1; i < K; i++)
	{
		//����һλ�ӵڶ�λ���ڵڶ�λ ��֤�� ��һλ�ڶ�λ��Ϊ����
		if (data[i-1]+list[i]>list[i])
		{
			//���µڶ�λ��Ӧ���������
			data[i] = data[i - 1] + list[i];
			//���µ�ǰֵ����Ӧ�ĵ�λ��
			start[i] = start[i - 1];
			if (data[i]>sum)
			{
				sum = data[i];
				first = start[i];
				late = i;

			}
		}//�����ڣ�������ڶ�λΪ0
		else if(data[i - 1] + list[i] == list[i])
		{
			//
			data[i] = list[i];
			//����һλ��ͬ���ĵ�ַ
			start[i] = start[i - 1];
			if (data[i] > sum)
			{
				sum = data[i];
				first = start[i];
				late = i;

			}
		}
		else
		{
			//���Ǹ���
			//
			data[i] = list[i];
			start[i] = i;
			if (data[i] > sum)
			{
				sum = data[i];
				first = start[i];
				late = i;

			}
		}
	}
	if (sum>=0)
	{
		cout << sum << " " << list[first] << " " << list[late];
	}
	else
	{
		cout << 0 << " " << list[0] << " " << list[K - 1];
	}




}


_1007::~_1007()
{
}
