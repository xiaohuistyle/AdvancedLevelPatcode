#include "pch.h"
#include "bag.h"
/*������������Ʒ���մӴ�С���򣨼�ֵ/������*/
void swap(float ave[], int s[], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			/*���ǰ���ֵС�ں����ֵ�����λ��*/
			if (ave[s[i]] <= ave[s[j]])
			{
				/*ע�����ﻥ�������±겢����������ֵ����Ϊ���滹Ҫ�õ�����*/
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
	float totalV = 0; //�ܼ�ֵ
	for (i = 0; i < n; i++)
	{
		/*�����ǰ��������װ��i��Ʒ����ȫ��װ��*/
		if (volume >= w[s[i]])
		{
			volume -= w[s[i]]; //������������ȥװ�������
			totalV += p[s[i]]; //����ǰ�����ļ�ֵ����װ�����Ʒ�ļ�ֵ
			cout << "����Ϊ" << w[s[i]] << ",��ֵΪ" << p[s[i]] << "����Ʒ��ȫ������" << endl;
		}
		else
		{
			/*�������ȫ��װ����װ�벿��ֱ��ȫ��װ��*/
			totalV += volume / w[s[i]] * p[s[i]]; //��Ӧ�ļ�ֵ������Ӧ�ı�����������
			cout << "����Ϊ" << w[s[i]] << ",��ֵΪ" << p[s[i]] << "����Ʒ����" << volume / w[s[i]] << endl;
			volume = 0;
			break;
		}
	}
	cout << "��װ��������ֵΪ��" << totalV << endl;
}

bag::bag()
{
	int s[20], i;
	float w[20], p[20]; //wΪ������pΪ��ֵ

	cout << "���������������" << endl;
	float volume; //�������
	cin >> volume;

	cout << "��������Ʒ������������" << endl;
	int n; //��Ʒ��������
	cin >> n;

	cout << "�����������Ʒ�������ͼ�ֵ��" << endl;
	for (i = 0; i < n; i++)
	{
		cin >> w[i] >> p[i];
	}

	float ave[20]; //aveΪ��λ�����ϵļ�ֵ
	for (i = 0; i < n; i++)
	{
		ave[i] = p[i] / w[i]; //�������Լ�ֵ
	}

	for (i = 0; i < n; i++)
	{
		/*�±꺯��*/
		s[i] = i;
	}

	swap(ave, s, n);
	bag_C(w, p, s, volume, n);
}


bag::~bag()
{
}
