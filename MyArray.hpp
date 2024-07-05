#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyArray
{
public:
	// 默认构造
	/*
	MyArray()
	{
		this->m_Capacity = 10;
		this->m_Size = 0;
		this->m_pAddress = new T[this->m_Capacity];
	}
	*/

	// 有参构造
	MyArray(int capacity)
	{
		cout << "-------MyArray:有参构造------" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		// 2--将数组中的数组存储到堆区
		this->m_pAddress = new T[this->m_Capacity];
	}

	// 拷贝构造
	MyArray(const MyArray& arr)
	{
		cout << "-------MyArray:拷贝构造------" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		// this->m_pAddress = arr.pAddress;

		// 深拷贝
		this->m_pAddress = new T[arr.m_Capacity];

		// 将arr中的数据都拷贝
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->m_pAddress[i] = arr.m_pAddress[i];
		}
	}

	// operator= 防止浅拷贝问题
	MyArray& operator=(const MyArray& arr)
	{
		cout << "-------MyArray:operator=构造------" << endl;
		// 相比拷贝构造，需要先判断堆区有无数据
		if (this->m_pAddress != NULL)
		{
			delete[] this->m_pAddress;
			this->m_pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		// 深拷贝
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->m_pAddress = new T[this->m_Capacity];

		// 将arr中的数据都拷贝 
		for (int i = 0; i < arr.m_Size; i++)
		{
			this->m_pAddress[i] = arr.m_pAddress[i];
		}
		return *this; // *this 可以理解为 解引用
	}

	// 尾插函数
	void Push_Back(const T& val)
	{
		// 判断容量与数组大小
		if (this->m_Capacity == this->m_Size)
		{
			// this->m_Capacity += this->m_Size;
			return;
		}
		this->m_pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	// 尾删函数
	void Pop_Back()
	{
		// 屏蔽最后一个元素
		if (this->m_Size == 0)
		{
			return;
		}
		this->m_Size--;
	}

	// 函数--通过下标方式访问数组中的元素
	T& operator[](int idx)
	{
		return this->m_pAddress[idx];
	}

	// 函数--返回数组容量
	int getCapacity()
	{
		return this->m_Capacity;
	}
	// 函数--返回数组大小
	int getSize()
	{
		return this->m_Size;
	}

	// 析构函数
	~MyArray()
	{
		cout << "-------MyArray:析构函数------" << endl;
		if (this->m_pAddress != NULL)
		{
			delete[] this->m_pAddress;  // 手动销毁
			this->m_pAddress = NULL;    // 置空，防止野指针
		}
	}

private:
	// 数组
	T* m_pAddress;

	// 容量
	int m_Capacity;

	// 大小
	int m_Size;

};