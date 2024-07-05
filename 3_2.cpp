/*
	2024年7月4日
	题目： -- p 183
		0）实现一个通用的数组类，
		1）可以对内置数据类型以及自定义数据类型的数据进行存储；
		2）将数组中的数据存储到堆区；
		3）构造函数中可以传入数组的容量；
		4）提供对应的拷贝构造函数以及 operator=防止浅拷贝问题；
		5）提供尾插法和尾删法对数组中的数据进行增加和删除；
		6）可以通过下标方式访问数组中的元素；
		7）可以获取数组中当前元素个数和数组的容量；
*/


#include <iostream>
#include <string>
using namespace std;

// #include "MyArray.hpp"

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

template <typename T>
void printArray(T& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "数组的容量为： " << arr.getCapacity() << endl;
	cout << "数组的大小为： " << arr.getSize() << endl;
}

// 测试--内置数据类型
void test01()
{
	// 有参构造
	MyArray<int> arr1(5);

	for (int i = 0; i < 5; i++)
	{
		// 尾插法向数组中插入数据
		arr1.Push_Back(i);
	}

	// 拷贝构造
	MyArray<int> arr2(arr1);

	// operator=构造
	MyArray<int> arr3(10);
	arr3 = arr1;

	cout << "数组的打印输出为： " << endl;
	printArray(arr1);

	cout << "-----尾删法测试-----" << endl;
	cout << "删除前: ";
	printArray(arr3);

	cout << "删除后: ";
	arr3.Pop_Back();
	printArray(arr3);

}

// 自定义类型--人
class Person
{
public:
	// 类--成员函数
	// 默认构造函数
	Person() {};

	// 有参构造函数
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	// 类--成员变量
	string m_Name;
	int m_Age;
};

template <typename T>
void printArray_person(T& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "姓名: " << arr[i].m_Name << " 年龄: " << arr[i].m_Age << endl;
	}

	cout << "数组的容量为： " << arr.getCapacity() << endl;
	cout << "数组的大小为： " << arr.getSize() << endl;
}

// 测试--自定义数据类型
void test02()
{
	// 创建人类对象
	Person p1("Vicient Liu", 24);
	Person p2("Sean Li", 25);

	// 创建人类型容器
	MyArray<Person> arr4(10);
	arr4.Push_Back(p1);
	arr4.Push_Back(p2);

	// 拷贝构造
	MyArray<Person> arr5(arr4);

	// operator=构造
	MyArray<Person> arr6(10);
	arr6 = arr4;

	// 打印数组信息
	cout << "数组的打印输出为： " << endl;
	printArray_person(arr4);

	cout << "-----尾删法测试-----" << endl;
	cout << "删除前: ";
	printArray_person(arr4);

	cout << "删除后: ";
	arr4.Pop_Back();
	printArray_person(arr4);
}

int main()
{
	cout << "########数组存储测试：内置   数据类型########" << endl;
	test01();

	cout << "########数组存储测试：自定义数据类型########" << endl;
	test02();

	return 0;
}
