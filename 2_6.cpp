/*
	2024年7月2日
	题目： -- p141
		0）电脑主要组成部件为CPU，显卡，内存条；
		1）将每个零件封装出抽象基类，
		2）并提供不同的厂商生产不同的零件，例如Intel & Dell;
		3）创建电脑类，提供让电脑工作的函数
		4）并调用每个零件工作的接口
		5）组装三台不同的电脑，进行工作
*/


#include <iostream>
using namespace std;

// 1 -- 将每个零件封装出抽象基类
// 抽象基类--CPU
class CPU
{
public:
	// 纯虚函数--CPU计算
	virtual void calculate() = 0;
};

// 抽象基类--GPU
class GPU
{
public:
	// 纯虚函数--GPU显示
	virtual void display() = 0;
};

// 抽象基类--Memory
class Memory
{
public:
	// 纯虚函数--Memory存储
	virtual void storage() = 0;
};

// -------------------------------
// 3 -- 创建电脑类
class Computer
{
public:
	// 构造函数
	Computer(CPU* cpu, GPU* gpu, Memory* memo)
	{
		m_cpu = cpu;
		m_gpu = gpu;
		m_memo = memo;
	}

	// 3 -- ,提供让电脑工作的函数
	void running()
	{
		// 4 -- 调用每个零件工作的接口
		m_cpu->calculate();
		m_gpu->display();
		m_memo->storage();
	}

	// 析构函数
	~Computer()
	{
		// 释放零件--CPU
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		// 释放零件--GPU
		if (m_gpu != NULL)
		{
			delete m_gpu;
			m_gpu = NULL;
		}
		// 释放零件--Memory
		if (m_memo != NULL)
		{
			delete m_memo;
			m_memo = NULL;
		}
	}

private:
	// 0 -- 电脑主要组成部件为CPU，显卡，内存条
	CPU* m_cpu;
	GPU* m_gpu;
	Memory* m_memo;
};

// -------------------------------
// 2 -- 提供不同的厂商生产不同的零件

// ------------Intel-------------
// 零件--CPU-Intel
class CPU_Intel :public CPU
{
	void calculate()
	{
		cout << "电脑中负责计算的CPU零件来自Intel厂商" << endl;
	}
};

// 零件--GPU-Intel
class GPU_Intel :public GPU
{
	void display()
	{
		cout << "电脑中负责显示的GPU零件来自Intel厂商" << endl;
	}
};

// 零件--Memory-Intel
class Memory_Intel :public Memory
{
	void storage()
	{
		cout << "电脑中负责存储的Memory零件来自Intel厂商" << endl;
	}
};

// ------------Dell-------------
// 零件--CPU-Dell
class CPU_Dell :public CPU
{
	void calculate()
	{
		cout << "电脑中负责计算的CPU零件来自Dell厂商" << endl;
	}
};

// 零件--GPU-Dell
class GPU_Dell :public GPU
{
	void display()
	{
		cout << "电脑中负责显示的GPU零件来自Dell厂商" << endl;
	}
};

// 零件--Memory-Dell
class Memory_Dell :public Memory
{
	void storage()
	{
		cout << "电脑中负责存储的Memory零件来自Dell厂商" << endl;
	}
};

// 测试
void test01()
{
	// 第1台电脑零件
	CPU* cpu_intel = new CPU_Intel;
	GPU* gpu_intel = new GPU_Intel;
	Memory* memory_intel = new Memory_Intel;

	cout << "-------------------------" << endl;
	cout << "第1台电脑开始工作：" << endl;
	// 创建第1台电脑
	Computer* computer1 = new Computer(cpu_intel, gpu_intel, memory_intel);
	computer1->running();
	delete computer1;

	cout << "-------------------------" << endl;
	cout << "第2台电脑开始工作：" << endl;
	// 创建第2台电脑
	Computer* computer2 = new Computer(new CPU_Dell, new GPU_Dell, new Memory_Dell);
	computer2->running();
	delete computer2;

	cout << "-------------------------" << endl;
	cout << "第3台电脑开始工作：" << endl;
	// 创建第3台电脑
	Computer* computer3 = new Computer(new CPU_Intel, new GPU_Intel, new Memory_Dell);
	computer3->running();
	delete computer3;
}

int main()
{
	// 测试
	test01();

	return 0;
}
