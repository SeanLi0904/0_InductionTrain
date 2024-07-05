/*
	2024��7��2��
	��Ŀ�� -- p170
		1�����ú���ģ���װһ������ĺ���
		2���Բ�ͬ�������͵������������
		3����������С�����㷨Ϊ ð������
		4���ֱ��� char �� int �������
*/


#include <iostream>
using namespace std;

// 0 -- ����ģ���װ--��������Ԫ��
template <typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

// 1 -- ����ģ���װ--ð����������
template <typename T>
void bubble_sort(T arr[], int len)
{
	// �����㷨--ð��
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			// ���� -- ��С����
			if (arr[j] > arr[j + 1])
			{
				mySwap(arr[j], arr[j + 1]);
			}
		}
	}
}

// 0 -- ����ģ���װ--��ӡ����
template<typename T>
void printArr(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

// --------------
// ���� char����
void test01()
{
	char cArr[] = "wsyxzba";
	int length = sizeof(cArr) / sizeof(cArr[0]);
	bubble_sort(cArr, length);
	printArr(cArr, length);
}

// --------------
// ���� int����
void test02()
{
	int iArr[] = { 3,5,4,9,8,6,2,1,7 };
	int length = sizeof(iArr) / sizeof(int);
	bubble_sort(iArr, length);
	printArr(iArr, length);

}

int main()
{
	// ���� char & int ����
	test01();
	test02();

	return 0;
}
