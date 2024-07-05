/*
	2024年6月28日
	题目: -- p45
		1）声明一个有10个元素的数字，
		2）并将数组元素逆序排列并输出
		3）如原数组：[1,3,8,9,0,2,4,5,6,7]
		4）逆序结果：[7,6,5,4,2,0,9,8,3,1]
*/

#include<iostream>
using namespace std;

// 定义函数--数组逆序排列
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
	// 声明数组
	const int n = 10;
	int arr[n] = { 1, 3, 8, 9, 0, 2, 4, 5, 6, 7 };
	// 原数组
	cout << "原数组: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	// 数组逆序
	reverse(arr, n);

	//输出数组逆序后结果
	cout << "数组逆序后: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] <<  ' ';
	}
	cout << endl;
	
	return 0;
}
