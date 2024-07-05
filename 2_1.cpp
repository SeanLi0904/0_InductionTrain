/*
	2024年6月29日
	题目： -- p100
		1）设计一个教师类，
		2）私有属性有姓名，年龄，职称，ID编号，研究方向
		3）设计一个类的成员函数给所有属性赋值
		4）设计一个类的成员函数显示所有属性
*/

#include<iostream>
#include<string>
using namespace std;

// 设计类--教师
class Teacher
{
public:
	// 成员函数--给所有属性赋值
	void setValue(string name, int age, string title, string id, string research)
	{
		m_Name = name;
		m_Age = age;
		m_Title = title;
		m_ID = id;
		m_Research = research;
	}

	// 成员函数--显示所有属性
	void showValue()
	{
		cout << m_Name 
			<< " 年龄: " << m_Age 
			<< " 职称: " << m_Title
			<< " \t ID编号: " << m_ID
			<< " 研究方向: " << m_Research 
			<< endl;
	}

private:
	// 私有属性
	string m_Name;
	int m_Age;
	string m_Title;
	string m_ID;
	string m_Research; 
};

int main()
{
	// 创建对象--教师类
	Teacher t1;
	t1.setValue("彭老师", 53, "教授", "1000101", "控制理论与控制工程");
	t1.showValue();

	Teacher t2;
	t2.setValue("曹老师", 32, "副教授", "1001016", "控制理论与控制工程");
	t2.showValue();

	return 0;
}
