/*
	2024年6月28日
	题目: -- p49
		1）有6名同学（同学1、同学2、同学3、同学4、同学5、同学6）
		2）在一次考试中的成绩分别如下表
		3）请分别输出6名同学的总成绩
		4）并输出每门学科的最高分
*/

#include<iostream>
using namespace std;

const int student_cnt = 6;
const int subject_cnt = 3;

// 定义函数--输出总成绩
int totalScore(int array[], int len)
{
	int total_score = 0;
	for (int i = 0; i < len; i++)
	{
		total_score += array[i];
	}

	return total_score;
}

// 定义函数--输出每门学科的最高分
void maxScores(int* subject_scores, int scores[][subject_cnt], int len_col, int len_row)
{
	for (int i = 0; i < len_col; i++)
	{
		for (int j = 0; j < len_row; j++)
		{
			if (scores[j][i] > subject_scores[i])
			{
				subject_scores[i] = scores[j][i];
			}
		}
	}
}

int main()
{
	// 定义成绩二维数组表
	int scores[student_cnt][subject_cnt] 
		= 
			{
				{99, 88, 96},
				{82, 75, 80},
				{95, 70, 89},
				{73, 99, 85},
				{91, 100, 80},
				{80, 90, 70}
			};
	int row = sizeof(scores) / sizeof(scores[0]);
	int col = sizeof(scores[0]) / sizeof(scores[0][0]);

	// 分别输出6名同学的总成绩
	for (int i = 0; i < row; i++)
	{
		int total_score = totalScore(scores[i], col);
		cout << "同学" << i + 1 << "的总成绩为: " << total_score << endl;
	}

	// 输出每门学科的最高分
	int max_subject_score[] = { 0, 0, 0 };
	maxScores(max_subject_score, scores, subject_cnt, student_cnt);
	
	cout << "每门学科的最高分: ";
	for (int i = 0; i < subject_cnt; i++)
	{
		cout << max_subject_score[i] << ' ';
	}

	return 0;
}
