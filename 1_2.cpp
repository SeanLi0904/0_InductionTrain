/*
	2024��6��28��
	��Ŀ�� -- p32
		1��ͨ��ϵͳ����һ��100��199֮����������
		2����ҶԸ���������в²⣬����´���ʾ���ֹ����С�������²£�5�Σ�
		3������¶���ϲ���ʤ�����˳���Ϸ
		4���´�5�θ�֪�����Ϸ�������˳�
*/

#include<iostream>
#include<ctime>
using namespace std;

int main()
{
	// ͨ��ϵͳ����һ��100��199֮��������
	srand((unsigned int)time(NULL));
	int target_num = rand() % 100 + 100;

	cout << target_num << endl;
	
	// ������--��������
	int guess_num;
	int guess_cnt = 0;
	
	// ������--����
	while (guess_cnt != 5)
	{
		cout << "�������������: ";
		cin >> guess_num;

		if (guess_num > target_num && guess_cnt != 5)
		{
			cout << "�²����ֹ���" << endl;
		}
		else if (guess_num < target_num && guess_cnt != 5)
		{
			cout << "�²����ֹ�С" << endl;
		}
		else if (guess_num == target_num && guess_cnt != 5)
		{
			cout << "��ϲ��Ҳ¶ԣ���Ϸ����" << endl;
			break;
		}
		else
		{
			cout << "��ҳ����²�5�Σ���Ϸ����" << endl;
			break;
		}
		guess_cnt++;
	}

	return 0;
}
