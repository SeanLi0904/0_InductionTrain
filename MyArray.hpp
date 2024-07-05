#pragma once
#include <iostream>
using namespace std;

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