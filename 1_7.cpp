/*
	2024��6��28��
	��Ŀ:
		1����װһ����������
		2��ѡ������ʵ������[1,3,8,9,0,2,4,5,6,7]��
		3����������
*/

#include <iostream>
using namespace std;

// ��װ����--ѡ������
void selectSort(int* array, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int minIdx = i;
		for (int j = i + 1; j < len; j++)
		{
			// ��������
			if (array[j] < array[minIdx])
			{
				minIdx = j;
			}
		}

		// ������Сֵ��δ���򲿷ֵĵ�һ��Ԫ��
		int temp = array[i];
		array[i] = array[minIdx];
		array[minIdx] = temp;
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

	// ѡ������--����
	selectSort(arr, length);

	// ������
	cout << "����--ѡ����������: " << endl;
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	return 0;
}
