/*
	2024��6��30��
	��Ŀ�� -- p137
		1�����ö�̬���������ʵ��
		2�����������������мӼ��˳�����ļ�������
	
	�ܽ᣺ -- ��̬�ô�
		1����֯�ṹ����
		2���ɶ���ǿ
		3������ǰ/������չ�Լ�ά���Ը�
*/

#include<iostream>
using namespace std;

// �������
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

// 1-������--�ӷ�
class addCalculator: public Calculator
{
	int operate()
	{
		return m_num1 + m_num2;
	}
};

// 2-������--����
class subCalculator : public Calculator
{
	int operate()
	{
		return m_num1 - m_num2;
	}
};

// 3-������--�˷�
class mulCalculator : public Calculator
{
	int operate()
	{
		return m_num1 * m_num2;
	}
};

// 4-������--����
class divCalculator : public Calculator
{
	int operate()
	{
		return m_num1 / m_num2;
	}
};

void test()
{
	// ��̬ʹ������
	// ����ָ�� or ����ָ���������

	// 1--�ӷ�����
	Calculator* p = new addCalculator;
	p->m_num1 = 10;
	p->m_num2 = 16;

	cout << p->m_num1 << "+" << p->m_num2 << "=" << p->operate() << endl;
	// ���� new����ָ��
	delete p;
	
	
	// 2--�ӷ�����
	p = new subCalculator;
	p->m_num1 = 10;
	p->m_num2 = 16;

	cout << p->m_num1 << "-" << p->m_num2 << "=" << p->operate() << endl;
	// ���� new����ָ��
	delete p;


	// 3--�ӷ�����
	p = new mulCalculator;
	p->m_num1 = 10;
	p->m_num2 = 16;

	cout << p->m_num1 << "*" << p->m_num2 << "=" << p->operate() << endl;
	// ���� new����ָ��
	delete p;


	// 4--�ӷ�����
	p = new divCalculator;
	p->m_num1 = 10;
	p->m_num2 = 16;

	cout << p->m_num1 << "/" << p->m_num2 << "=" << p->operate() << endl;
	// ���� new����ָ��
	delete p;
}

int main()
{
	test();

	return 0;
}
