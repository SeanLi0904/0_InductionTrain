/*
	2024年6月28日
	题目： -- p34
		1）有这样一个规律：一个3位数，每一位上数字的3次幂之和==本身
		2）例如：1^3+5^3+3^3=153
		3）请用for循环，求出所有3位数中符合这个规律的数字
*/

#include<iostream>
using namespace std;

int main()
{
	cout << "所有三位数中符合上述规律的数字如下： " << endl;

	// 遍历所有三位数 100--999
	for (int i = 100; i <= 999; i++)
	{
		// 取个位/十位/百位
		int u = i % 10;
		int t = (i / 10) % 10;
		int h = i / 100;

		// 条件判断--是否满足水仙花数
		if (u * u * u + t * t * t + h * h * h==i)
		{
			cout << i << endl;
		}
	}

	return 0;
}
