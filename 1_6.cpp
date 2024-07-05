/*
	2024年6月28日
	题目: -- p46
		1）封装一个函数，用
		2）冒泡排序法实现数组[1,3,8,9,0,2,4,5,6,7]的
		3）降序排列
*/

#include <iostream>
using namespace std;

// 封装函数--冒泡排序
void bubbleSort(int * array, int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			// 降序排列
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
	// 定义数组
	int arr[] = { 1,3,8,9,0,2,4,5,6,7 };
	int length = sizeof(arr) / sizeof(arr[0]);
	
	cout << "原数组: " << endl;
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	
	// 冒泡排序--降序
	bubbleSort(arr, length);

	// 输出结果
	cout << "数组--冒泡排序降序: " << endl;
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	return 0;
}
