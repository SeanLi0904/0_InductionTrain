/*
	2024��6��28��
	��Ŀ��	-- p28
		1������ֻС��ABCDE��ͨ���û��ֱ��������ǵ�������
		2�����жϡ������ʾ��ֻС�����أ�
*/

#include<iostream>
using namespace std;

int main()
{
	// �������--С������
	const int n = 5;
	int puppys_weight[n];
	char puppys_name[n] = {'a', 'b', 'c', 'd', 'e'};

	// ͨ���û��ֱ�������������
	cout << "�����ηֱ�������ֻС��������:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> puppys_weight[i];
	};

	// �ж�����
	int max_weight = puppys_weight[0];
	int max_weight_idx = 0;
	for (int i = 1; i < n; i++)
	{
		if (puppys_weight[i] <= max_weight)
		{
			continue;
		}
		else
		{
			max_weight = puppys_weight[i];
			max_weight_idx = i;
		}
	}
	// �����ʾ���صĹ�
	cout << "�������Ĺ�Ϊ: " << puppys_name[max_weight_idx] << endl;
	cout << "������Ϊ:  " << max_weight << endl;
	
	return 0;
}
