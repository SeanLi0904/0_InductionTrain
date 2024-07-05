/* 
	2024年6月29日
	题目 : -- p70
		1）学校正在做毕设项目，每名老师带6个学生，总共有3名老师
		2）设计学生和老师的结构体，
		3）老师结构体，成员：老师姓名，年龄，职称和一个存放6名学生的数组
		4）学生结构体，成员：学生姓名，年龄，考试分数
		5）要求创建数组存放3名老师
		6）通过函数给每个老师及所带学生进行赋值
		7）最终通过函数打印出老师及学生的数据
*/

#include<iostream>
#include<string>
#include<ctime>
using namespace std;

// 设计结构体--学生
struct Student
{
	// 成员：学生姓名，年龄，考试分数
	string name;
	int age;
	int score;
};

// 设计结构体--老师
struct Teacher
{
	// 成员：老师姓名，年龄，职称和一个存放6名学生的数组
	string name;
	int age;
	string title;
	Student sArr[6];
};

void assignValue(Teacher tarray[], int length)
{
	string nameArr = "123456";
	string tName = "教师";
	string sName = "学生";

	for (int i = 0; i < length; i++)
	{
		tarray[i].name = tName + nameArr[i];
		tarray[i].age = rand() % 41 + 25; // 25-65岁
		tarray[i].title = "教授";
		
		// 所带学生
		int len_stu = sizeof(tarray[i].sArr) / sizeof(tarray[i].sArr[0]);
		for (int j = 0; j < len_stu; j++)
		{
			tarray[i].sArr[j].name = sName + nameArr[j];
			tarray[i].sArr[j].age = rand() % 8 + 18; // 18-25岁
			tarray[i].sArr[j].score = rand() % 26 + 75; // 75-100分
		}
	}
}

void printInfo(Teacher tarray[], int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << tarray[i].name
			<< " 年龄: " << tarray[i].age
			<< " 职称: " << tarray[i].title
			<< endl;

		int len_stu = sizeof(tarray[i].sArr) / sizeof(tarray[i].sArr[0]);
		for (int j = 0; j < len_stu; j++)
		{
			cout << "\t "<< tarray[i].sArr[j].name 
				<< " 年龄: " << tarray[i].sArr[j].age 
				<< " 分数: " << tarray[i].sArr[j].score
				<< endl;
		}
	}
}

int main()
{
	// 随机数种子
	srand((unsigned int)time(NULL));

	// 创建数组存放3名老师
	Teacher tArr[3];
	int len = sizeof(tArr) / sizeof(tArr[0]);

	// 通过函数给每个老师及所带学生进行赋值
	assignValue(tArr, len);

	// 通过函数打印出老师及学生的数据
	printInfo(tArr, len);

	return 0;
}
