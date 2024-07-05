/*
	2024年6月30日
	题目： -- p137
		1）利用多态技术，设计实现
		2）对两个操作数进行加减乘除运算的计算器类
	
	总结： -- 多态好处
		1）组织结构清晰
		2）可读性强
		3）对于前/后期扩展以及维护性高
*/

#include<iostream>
using namespace std;

// 抽象基类
class Calculator
{
public:
	virtual int operate()
	{
		return 0;
	}
	int m_num1;
	int m_num2;
};

// 1-运算类--加法
class addCalculator: public Calculator
{
	int operate()
	{
		return m_num1 + m_num2;
	}
};

// 2-运算类--减法
class subCalculator : public Calculator
{
	int operate()
	{
		return m_num1 - m_num2;
	}
};

// 3-运算类--乘法
class mulCalculator : public Calculator
{
	int operate()
	{
		return m_num1 * m_num2;
	}
};

// 4-运算类--除法
class divCalculator : public Calculator
{
	int operate()
	{
		return m_num1 / m_num2;
	}
};

void test()
{
	// 多态使用条件
	// 父类指针 or 引用指向子类对象

	// 1--加法运行
	Calculator* p = new addCalculator;
	p->m_num1 = 10;
	p->m_num2 = 16;

	cout << p->m_num1 << "+" << p->m_num2 << "=" << p->operate() << endl;
	// 销毁 new出的指针
	delete p;
	
	
	// 2--加法运行
	p = new subCalculator;
	p->m_num1 = 10;
	p->m_num2 = 16;

	cout << p->m_num1 << "-" << p->m_num2 << "=" << p->operate() << endl;
	// 销毁 new出的指针
	delete p;


	// 3--加法运行
	p = new mulCalculator;
	p->m_num1 = 10;
	p->m_num2 = 16;

	cout << p->m_num1 << "*" << p->m_num2 << "=" << p->operate() << endl;
	// 销毁 new出的指针
	delete p;


	// 4--加法运行
	p = new divCalculator;
	p->m_num1 = 10;
	p->m_num2 = 16;

	cout << p->m_num1 << "/" << p->m_num2 << "=" << p->operate() << endl;
	// 销毁 new出的指针
	delete p;
}

int main()
{
	test();

	return 0;
}
