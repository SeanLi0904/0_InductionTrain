/*
	2024��6��28��
	��Ŀ: -- p38
		1������Ƕ��ѭ��
		2����ӡ��ʾ�žų˷����е�������
*/

#include<iostream>
using namespace std;

int main()
{

	for (int i = 1; i <= 9; i++)
	{
		// ����ż����
		if (i % 2 == 0)
		{
			continue;
		}
		else
		{
			for (int j = 1; j <= i; j++)
			{
				// ��ӡ��ʾ�žų˷���
				cout << i << '*' << j << '=' << i * j << ' ';
			}
			cout << endl;
		}

	}

	return 0;
}
