/*
	2024年6月28日
	题目: -- p38
		1）利用嵌套循环
		2）打印显示九九乘法表中的奇数行
*/

#include<iostream>
using namespace std;

int main()
{

	for (int i = 1; i <= 9; i++)
	{
		// 跳过偶数行
		if (i % 2 == 0)
		{
			continue;
		}
		else
		{
			for (int j = 1; j <= i; j++)
			{
				// 打印显示九九乘法表
				cout << i << '*' << j << '=' << i * j << ' ';
			}
			cout << endl;
		}

	}

	return 0;
}
