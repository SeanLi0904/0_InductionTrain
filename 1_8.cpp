/*
	2024��6��28��
	��Ŀ: -- p49
		1����6��ͬѧ��ͬѧ1��ͬѧ2��ͬѧ3��ͬѧ4��ͬѧ5��ͬѧ6��
		2����һ�ο����еĳɼ��ֱ����±�
		3����ֱ����6��ͬѧ���ܳɼ�
		4�������ÿ��ѧ�Ƶ���߷�
*/

#include<iostream>
using namespace std;

const int student_cnt = 6;
const int subject_cnt = 3;

// ���庯��--����ܳɼ�
int totalScore(int array[], int len)
{
	int total_score = 0;
	for (int i = 0; i < len; i++)
	{
		total_score += array[i];
	}

	return total_score;
}

// ���庯��--���ÿ��ѧ�Ƶ���߷�
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
	// ����ɼ���ά�����
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

	// �ֱ����6��ͬѧ���ܳɼ�
	for (int i = 0; i < row; i++)
	{
		int total_score = totalScore(scores[i], col);
		cout << "ͬѧ" << i + 1 << "���ܳɼ�Ϊ: " << total_score << endl;
	}

	// ���ÿ��ѧ�Ƶ���߷�
	int max_subject_score[] = { 0, 0, 0 };
	maxScores(max_subject_score, scores, subject_cnt, student_cnt);
	
	cout << "ÿ��ѧ�Ƶ���߷�: ";
	for (int i = 0; i < subject_cnt; i++)
	{
		cout << max_subject_score[i] << ' ';
	}

	return 0;
}
