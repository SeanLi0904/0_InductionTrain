/*
	2024��6��28��
	��Ŀ: -- p45
		1������һ����10��Ԫ�ص����֣�
		2����������Ԫ���������в����
		3����ԭ���飺[1,3,8,9,0,2,4,5,6,7]
		4����������[7,6,5,4,2,0,9,8,3,1]
*/

#include<iostream>
using namespace std;

// ���庯��--������������
void reverse(int * array, int length)
{
	for (int i = 0, j = length - 1; i < j; i++, j--)
	{
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

int main()
{
	// ��������
	const int n = 10;
	int arr[n] = { 1, 3, 8, 9, 0, 2, 4, 5, 6, 7 };
	// ԭ����
	cout << "ԭ����: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	// ��������
	reverse(arr, n);

	//��������������
	cout << "���������: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] <<  ' ';
	}
	cout << endl;
	
	return 0;
}
