/*
	2024��6��29��
	��Ŀ�� -- p100
		1�����һ����ʦ�࣬
		2��˽�����������������䣬ְ�ƣ�ID��ţ��о�����
		3�����һ����ĳ�Ա�������������Ը�ֵ
		4�����һ����ĳ�Ա������ʾ��������
*/

#include<iostream>
#include<string>
using namespace std;

// �����--��ʦ
class Teacher
{
public:
	// ��Ա����--���������Ը�ֵ
	void setValue(string name, int age, string title, string id, string research)
	{
		m_Name = name;
		m_Age = age;
		m_Title = title;
		m_ID = id;
		m_Research = research;
	}

	// ��Ա����--��ʾ��������
	void showValue()
	{
		cout << m_Name 
			<< " ����: " << m_Age 
			<< " ְ��: " << m_Title
			<< " \t ID���: " << m_ID
			<< " �о�����: " << m_Research 
			<< endl;
	}

private:
	// ˽������
	string m_Name;
	int m_Age;
	string m_Title;
	string m_ID;
	string m_Research; 
};

int main()
{
	// ��������--��ʦ��
	Teacher t1;
	t1.setValue("����ʦ", 53, "����", "1000101", "������������ƹ���");
	t1.showValue();

	Teacher t2;
	t2.setValue("����ʦ", 32, "������", "1001016", "������������ƹ���");
	t2.showValue();

	return 0;
}
