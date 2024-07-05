/*
	2024年6月28日
	题目:
		1）封装一个函数，用
		2）选择排序法实现数组[1,3,8,9,0,2,4,5,6,7]的
		3）升序排列
*/

#include <iostream>
using namespace std;

// 封装函数--选择排序
void selectSort(int* array, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int minIdx = i;
		for (int j = i + 1; j < len; j++)
		{
			// 升序排列
			if (array[j] < array[minIdx])
			{
				minIdx = j;
			}
		}

		// 交换最小值与未排序部分的第一个元素
		int temp = array[i];
		array[i] = array[minIdx];
		array[minIdx] = temp;
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

	// 选择排序--升序
	selectSort(arr, length);

	// 输出结果
	cout << "数组--选择排序升序: " << endl;
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	return 0;
}
