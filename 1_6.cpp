/*
	2024��6��28��
	��Ŀ: -- p46
		1����װһ����������
		2��ð������ʵ������[1,3,8,9,0,2,4,5,6,7]��
		3����������
*/

#include <iostream>
using namespace std;

// ��װ����--ð������
void bubbleSort(int * array, int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			// ��������
			if (array[j] < array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

int main()
{
	// ��������
	int arr[] = { 1,3,8,9,0,2,4,5,6,7 };
	int length = sizeof(arr) / sizeof(arr[0]);
	
	cout << "ԭ����: " << endl;
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	
	// ð������--����
	bubbleSort(arr, length);

	// ������
	cout << "����--ð��������: " << endl;
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	return 0;
}
