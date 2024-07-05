/*
	2024年6月28日
	题目：	-- p28
		1）有五只小狗ABCDE，通过用户分别输入他们的重量，
		2）并判断、输出显示哪只小狗最重？
*/

#include<iostream>
using namespace std;

int main()
{
	// 定义变量--小狗重量
	const int n = 5;
	int puppys_weight[n];
	char puppys_name[n] = {'a', 'b', 'c', 'd', 'e'};

	// 通过用户分别输入他们重量
	cout << "请依次分别输入五只小狗的重量:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> puppys_weight[i];
	};

	// 判断重量
	int max_weight = puppys_weight[0];
	int max_weight_idx = 0;
	for (int i = 1; i < n; i++)
	{
		if (puppys_weight[i] <= max_weight)
		{
			continue;
		}
		else
		{
			max_weight = puppys_weight[i];
			max_weight_idx = i;
		}
	}
	// 输出显示最重的狗
	cout << "重量最大的狗为: " << puppys_name[max_weight_idx] << endl;
	cout << "其重量为:  " << max_weight << endl;
	
	return 0;
}
