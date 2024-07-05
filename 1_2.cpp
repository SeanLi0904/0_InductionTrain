/*
	2024年6月28日
	题目： -- p32
		1）通过系统生成一个100到199之间的随机数，
		2）玩家对该随机数进行猜测，如果猜错，提示数字过大过小，并重新猜（5次）
		3）如果猜对则恭喜玩家胜利并退出游戏
		4）猜错5次告知玩家游戏结束并退出
*/

#include<iostream>
#include<ctime>
using namespace std;

int main()
{
	// 通过系统生成一个100到199之间的随机数
	srand((unsigned int)time(NULL));
	int target_num = rand() % 100 + 100;

	cout << target_num << endl;
	
	// 猜数字--参数设置
	int guess_num;
	int guess_cnt = 0;
	
	// 猜数字--过程
	while (guess_cnt != 5)
	{
		cout << "玩家请输入数字: ";
		cin >> guess_num;

		if (guess_num > target_num && guess_cnt != 5)
		{
			cout << "猜测数字过大" << endl;
		}
		else if (guess_num < target_num && guess_cnt != 5)
		{
			cout << "猜测数字过小" << endl;
		}
		else if (guess_num == target_num && guess_cnt != 5)
		{
			cout << "恭喜玩家猜对，游戏结束" << endl;
			break;
		}
		else
		{
			cout << "玩家持续猜测5次，游戏结束" << endl;
			break;
		}
		guess_cnt++;
	}

	return 0;
}
