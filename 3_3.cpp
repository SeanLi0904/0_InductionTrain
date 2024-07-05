/*
	2024��7��3��
	��Ŀ��	-- p236
		0����˾��Ƹ��5��Ա����ABCDE������Ҫָ�����ĸ����Ź�����
		1��Ա����Ϣ������������������ɣ�
		2�����ŷ�Ϊ��NBU��ADC��Sales;
		3�������5��Ա�����乤�ʺͲ���;
		4��ͨ�� multimap������Ϣ�Ĳ��룻
		5��key�����ű�ţ�value��Ա����;
		6���ֲ�����ʾԱ����Ϣ
*/

#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <ctime>

// ��--Ա��
class Employee
{
public:
	string m_Name;
	int m_Salary;
};

// ����--����Ա������
void createEmployee(vector<Employee>& v)
{
	string employee_Name_Seed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		Employee employee;
		employee.m_Name = "Ա��";
		employee.m_Name += employee_Name_Seed[i];
		employee.m_Salary = rand() % 10001 + 10000;

		// ��Ա������β��������
		v.push_back(employee);
	}
}

// ����--���飺Ա��-�������
void setGroup(vector<Employee>& v, multimap<string, Employee>& m)
{
	// ��ʼ������
	vector<string> depart;
	depart.push_back("NBU");
	depart.push_back("ADC");
	depart.push_back("Sales");

	for (vector<Employee>::iterator it = v.begin(); it != v.end(); it++)
	{
		int depart_idx = rand() % 3;
		string depart_assign = depart[depart_idx]; // depart[idx];

		m.insert(make_pair(depart_assign, *it));
	}
}

// ����--�ֲ�����ʾԱ����Ϣ

void printInfo(multimap<string, Employee>& m)
{
	// ---------------------
	cout << "---NBU�ֲ��������---" << endl;
	multimap<string, Employee>::iterator pos = m.find("NBU");
	int depart_employee_count = m.count("NBU");
	int idx = 0;
	for (; pos != m.end() && idx < depart_employee_count; pos++, idx++)
	{
		cout << pos->second.m_Name << " ����: " << pos->second.m_Salary << endl;
	}

	// ---------------------
	cout << "---ADC�ֲ��������---" << endl;
	pos = m.find("ADC");
	depart_employee_count = m.count("ADC");
	idx = 0;
	for (; pos != m.end() && idx < depart_employee_count; pos++, idx++)
	{
		cout << pos->second.m_Name << " ����: " << pos->second.m_Salary << endl;
	}

	// ---------------------
	cout << "---Sales�ֲ��������---" << endl;
	pos = m.find("Sales");
	depart_employee_count = m.count("Sales");
	idx = 0;
	for (; pos != m.end() && idx < depart_employee_count; pos++, idx++)
	{
		cout << pos->second.m_Name << " ����: " << pos->second.m_Salary << endl;
	}
}

void test01()
{
	// 0. ʱ�����
	srand((unsigned int)time(NULL));

	// 1. ����Ա����������
	vector<Employee> vE;
	createEmployee(vE);
	// ------------- checkpoint:1 ---------------
	//for (vector<Employee>::iterator it = vE.begin(); it != vE.end(); it++)
	//{
	//	cout << "������ " << (*it).m_Name << " ���ʣ� " << (*it).m_Salary << endl;
	//	 // cout << "������ " << it->m_Name << " ���ʣ� " << it->m_Salary << endl;
	//}

	// 2. Ա������
	multimap<string, Employee> mE;
	setGroup(vE, mE);

	// 3. �ֲ�����ʾԱ����Ϣ
	multimap<string, Employee>::iterator pos = mE.find("ADC");
	printInfo(mE);

	// ------------- checkpoint:2 ---------------
	//cout << "--------------" << endl;
	//int depart_employee_count = mE.count("NBU");
	//cout << "find_pos: " << (*pos).first << endl;
	//cout << "find_pos: " << pos->second.m_Salary << endl;
	//cout << "find_pos: " << depart_employee_count << endl;

}


int main()
{
	test01();

	return 0;
}
