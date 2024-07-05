/* 
	2024��6��29��
	��Ŀ : -- p70
		1��ѧУ������������Ŀ��ÿ����ʦ��6��ѧ�����ܹ���3����ʦ
		2�����ѧ������ʦ�Ľṹ�壬
		3����ʦ�ṹ�壬��Ա����ʦ���������䣬ְ�ƺ�һ�����6��ѧ��������
		4��ѧ���ṹ�壬��Ա��ѧ�����������䣬���Է���
		5��Ҫ�󴴽�������3����ʦ
		6��ͨ��������ÿ����ʦ������ѧ�����и�ֵ
		7������ͨ��������ӡ����ʦ��ѧ��������
*/

#include<iostream>
#include<string>
#include<ctime>
using namespace std;

// ��ƽṹ��--ѧ��
struct Student
{
	// ��Ա��ѧ�����������䣬���Է���
	string name;
	int age;
	int score;
};

// ��ƽṹ��--��ʦ
struct Teacher
{
	// ��Ա����ʦ���������䣬ְ�ƺ�һ�����6��ѧ��������
	string name;
	int age;
	string title;
	Student sArr[6];
};

void assignValue(Teacher tarray[], int length)
{
	string nameArr = "123456";
	string tName = "��ʦ";
	string sName = "ѧ��";

	for (int i = 0; i < length; i++)
	{
		tarray[i].name = tName + nameArr[i];
		tarray[i].age = rand() % 41 + 25; // 25-65��
		tarray[i].title = "����";
		
		// ����ѧ��
		int len_stu = sizeof(tarray[i].sArr) / sizeof(tarray[i].sArr[0]);
		for (int j = 0; j < len_stu; j++)
		{
			tarray[i].sArr[j].name = sName + nameArr[j];
			tarray[i].sArr[j].age = rand() % 8 + 18; // 18-25��
			tarray[i].sArr[j].score = rand() % 26 + 75; // 75-100��
		}
	}
}

void printInfo(Teacher tarray[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << tarray[i].name
			<< " ����: " << tarray[i].age
			<< " ְ��: " << tarray[i].title
			<< endl;

		int len_stu = sizeof(tarray[i].sArr) / sizeof(tarray[i].sArr[0]);
		for (int j = 0; j < len_stu; j++)
		{
			cout << "\t "<< tarray[i].sArr[j].name 
				<< " ����: " << tarray[i].sArr[j].age 
				<< " ����: " << tarray[i].sArr[j].score
				<< endl;
		}
	}
}

int main()
{
	// ���������
	srand((unsigned int)time(NULL));

	// ����������3����ʦ
	Teacher tArr[3];
	int len = sizeof(tArr) / sizeof(tArr[0]);

	// ͨ��������ÿ����ʦ������ѧ�����и�ֵ
	assignValue(tArr, len);

	// ͨ��������ӡ����ʦ��ѧ��������
	printInfo(tArr, len);

	return 0;
}
