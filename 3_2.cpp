/*
	2024��7��4��
	��Ŀ�� -- p 183
		0��ʵ��һ��ͨ�õ������࣬
		1�����Զ��������������Լ��Զ����������͵����ݽ��д洢��
		2���������е����ݴ洢��������
		3�����캯���п��Դ��������������
		4���ṩ��Ӧ�Ŀ������캯���Լ� operator=��ֹǳ�������⣻
		5���ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ����
		6������ͨ���±귽ʽ���������е�Ԫ�أ�
		7�����Ի�ȡ�����е�ǰԪ�ظ����������������
*/


#include <iostream>
#include <string>
using namespace std;

// #include "MyArray.hpp"

template <class T>
class MyArray
{
public:
	// Ĭ�Ϲ���
	/*
	MyArray()
	{
		this->m_Capacity = 10;
		this->m_Size = 0;
		this->m_pAddress = new T[this->m_Capacity];
	}
	*/

	// �вι���
	MyArray(int capacity)
	{
		cout << "-------MyArray:�вι���------" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		// 2--�������е�����洢������
		this->m_pAddress = new T[this->m_Capacity];
	}

	// ��������
	MyArray(const MyArray& arr)
	{
		cout << "-------MyArray:��������------" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		// this->m_pAddress = arr.pAddress;

		// ���
		this->m_pAddress = new T[arr.m_Capacity];

		// ��arr�е����ݶ�����
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->m_pAddress[i] = arr.m_pAddress[i];
		}
	}

	// operator= ��ֹǳ��������
	MyArray& operator=(const MyArray& arr)
	{
		cout << "-------MyArray:operator=����------" << endl;
		// ��ȿ������죬��Ҫ���ж϶�����������
		if (this->m_pAddress != NULL)
		{
			delete[] this->m_pAddress;
			this->m_pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		// ���
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->m_pAddress = new T[this->m_Capacity];

		// ��arr�е����ݶ����� 
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->m_pAddress[i] = arr.m_pAddress[i];
		}
		return *this; // *this �������Ϊ ������
	}

	// β�庯��
	void Push_Back(const T& val)
	{
		// �ж������������С
		if (this->m_Capacity == this->m_Size)
		{
			// this->m_Capacity += this->m_Size;
			return;
		}
		this->m_pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	// βɾ����
	void Pop_Back()
	{
		// �������һ��Ԫ��
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	// ����--ͨ���±귽ʽ���������е�Ԫ��
	T& operator[](int idx)
	{
		return this->m_pAddress[idx];
	}

	// ����--������������
	int getCapacity()
	{
		return this->m_Capacity;
	}
	// ����--���������С
	int getSize()
	{
		return this->m_Size;
	}

	// ��������
	~MyArray()
	{
		cout << "-------MyArray:��������------" << endl;
		if (this->m_pAddress != NULL)
		{
			delete[] this->m_pAddress;  // �ֶ�����
			this->m_pAddress = NULL;    // �ÿգ���ֹҰָ��
		}
	}

private:
	// ����
	T* m_pAddress;

	// ����
	int m_Capacity;

	// ��С
	int m_Size;

};

template <typename T>
void printArray(T& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "���������Ϊ�� " << arr.getCapacity() << endl;
	cout << "����Ĵ�СΪ�� " << arr.getSize() << endl;
}

// ����--������������
void test01()
{
	// �вι���
	MyArray<int> arr1(5);

	for (int i = 0; i < 5; i++)
	{
		// β�巨�������в�������
		arr1.Push_Back(i);
	}

	// ��������
	MyArray<int> arr2(arr1);

	// operator=����
	MyArray<int> arr3(10);
	arr3 = arr1;

	cout << "����Ĵ�ӡ���Ϊ�� " << endl;
	printArray(arr1);

	cout << "-----βɾ������-----" << endl;
	cout << "ɾ��ǰ: ";
	printArray(arr3);

	cout << "ɾ����: ";
	arr3.Pop_Back();
	printArray(arr3);

}

// �Զ�������--��
class Person
{
public:
	// ��--��Ա����
	// Ĭ�Ϲ��캯��
	Person() {};

	// �вι��캯��
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	// ��--��Ա����
	string m_Name;
	int m_Age;
};

template <typename T>
void printArray_person(T& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "����: " << arr[i].m_Name << " ����: " << arr[i].m_Age << endl;
	}

	cout << "���������Ϊ�� " << arr.getCapacity() << endl;
	cout << "����Ĵ�СΪ�� " << arr.getSize() << endl;
}

// ����--�Զ�����������
void test02()
{
	// �����������
	Person p1("Vicient Liu", 24);
	Person p2("Sean Li", 25);

	// ��������������
	MyArray<Person> arr4(10);
	arr4.Push_Back(p1);
	arr4.Push_Back(p2);

	// ��������
	MyArray<Person> arr5(arr4);

	// operator=����
	MyArray<Person> arr6(10);
	arr6 = arr4;

	// ��ӡ������Ϣ
	cout << "����Ĵ�ӡ���Ϊ�� " << endl;
	printArray_person(arr4);

	cout << "-----βɾ������-----" << endl;
	cout << "ɾ��ǰ: ";
	printArray_person(arr4);

	cout << "ɾ����: ";
	arr4.Pop_Back();
	printArray_person(arr4);
}

int main()
{
	cout << "########����洢���ԣ�����   ��������########" << endl;
	test01();

	cout << "########����洢���ԣ��Զ�����������########" << endl;
	test02();

	return 0;
}
