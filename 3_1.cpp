/*
	2024年7月2日
	题目： -- p170
		1）利用函数模板封装一个排序的函数
		2）对不同数据类型的数组进行排序
		3）排序规则从小到大，算法为 冒泡排序
		4）分别用 char 和 int 数组测试
*/


#include <iostream>
using namespace std;

// 0 -- 函数模板封装--交换数组元素
template <typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

// 1 -- 函数模板封装--冒泡升序排序
template <typename T>
void bubble_sort(T arr[], int len)
{
	// 排序算法--冒泡
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			// 升序 -- 从小到大
			if (arr[j] > arr[j + 1])
			{
				mySwap(arr[j], arr[j + 1]);
			}
		}
	}
}

// 0 -- 函数模板封装--打印数组
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
// 测试 char数组
void test01()
{
	char cArr[] = "wsyxzba";
	int length = sizeof(cArr) / sizeof(cArr[0]);
	bubble_sort(cArr, length);
	printArr(cArr, length);
}

// --------------
// 测试 int数组
void test02()
{
	int iArr[] = { 3,5,4,9,8,6,2,1,7 };
	int length = sizeof(iArr) / sizeof(int);
	bubble_sort(iArr, length);
	printArr(iArr, length);

}

int main()
{
	// 测试 char & int 数组
	test01();
	test02();

	return 0;
}
