/*
	2024年7月3日
	题目：	-- p236
		0）公司招聘了5名员工（ABCDE），需要指派在哪个部门工作；
		1）员工信息包括：姓名、工资组成；
		2）部门分为：NBU，ADC，Sales;
		3）随机给5名员工分配工资和部门;
		4）通过 multimap进行信息的插入；
		5）key（部门编号）value（员工）;
		6）分部门显示员工信息
*/

#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <ctime>

// 类--员工
class Employee
{
public:
	string m_Name;
	int m_Salary;
};

// 函数--创建员工对象
void createEmployee(vector<Employee>& v)
{
	string employee_Name_Seed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		Employee employee;
		employee.m_Name = "员工";
		employee.m_Name += employee_Name_Seed[i];
		employee.m_Salary = rand() % 10001 + 10000;

		// 将员工对象尾插至容器
		v.push_back(employee);
	}
}

// 函数--分组：员工-部门配对
void setGroup(vector<Employee>& v, multimap<string, Employee>& m)
{
	// 初始化部门
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

// 函数--分部门显示员工信息

void printInfo(multimap<string, Employee>& m)
{
	// ---------------------
	cout << "---NBU分部门情况：---" << endl;
	multimap<string, Employee>::iterator pos = m.find("NBU");
	int depart_employee_count = m.count("NBU");
	int idx = 0;
	for (; pos != m.end() && idx < depart_employee_count; pos++, idx++)
	{
		cout << pos->second.m_Name << " 工资: " << pos->second.m_Salary << endl;
	}

	// ---------------------
	cout << "---ADC分部门情况：---" << endl;
	pos = m.find("ADC");
	depart_employee_count = m.count("ADC");
	idx = 0;
	for (; pos != m.end() && idx < depart_employee_count; pos++, idx++)
	{
		cout << pos->second.m_Name << " 工资: " << pos->second.m_Salary << endl;
	}

	// ---------------------
	cout << "---Sales分部门情况：---" << endl;
	pos = m.find("Sales");
	depart_employee_count = m.count("Sales");
	idx = 0;
	for (; pos != m.end() && idx < depart_employee_count; pos++, idx++)
	{
		cout << pos->second.m_Name << " 工资: " << pos->second.m_Salary << endl;
	}
}

void test01()
{
	// 0. 时间随机
	srand((unsigned int)time(NULL));

	// 1. 创建员工对象容器
	vector<Employee> vE;
	createEmployee(vE);
	// ------------- checkpoint:1 ---------------
	//for (vector<Employee>::iterator it = vE.begin(); it != vE.end(); it++)
	//{
	//	cout << "姓名： " << (*it).m_Name << " 工资： " << (*it).m_Salary << endl;
	//	 // cout << "姓名： " << it->m_Name << " 工资： " << it->m_Salary << endl;
	//}

	// 2. 员工分组
	multimap<string, Employee> mE;
	setGroup(vE, mE);

	// 3. 分部门显示员工信息
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
