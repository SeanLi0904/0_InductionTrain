/*
	2024��7��2��
	��Ŀ�� -- p141
		0��������Ҫ��ɲ���ΪCPU���Կ����ڴ�����
		1����ÿ�������װ��������࣬
		2�����ṩ��ͬ�ĳ���������ͬ�����������Intel & Dell;
		3�����������࣬�ṩ�õ��Թ����ĺ���
		4��������ÿ����������Ľӿ�
		5����װ��̨��ͬ�ĵ��ԣ����й���
*/


#include <iostream>
using namespace std;

// 1 -- ��ÿ�������װ���������
// �������--CPU
class CPU
{
public:
	// ���麯��--CPU����
	virtual void calculate() = 0;
};

// �������--GPU
class GPU
{
public:
	// ���麯��--GPU��ʾ
	virtual void display() = 0;
};

// �������--Memory
class Memory
{
public:
	// ���麯��--Memory�洢
	virtual void storage() = 0;
};

// -------------------------------
// 3 -- ����������
class Computer
{
public:
	// ���캯��
	Computer(CPU* cpu, GPU* gpu, Memory* memo)
	{
		m_cpu = cpu;
		m_gpu = gpu;
		m_memo = memo;
	}

	// 3 -- ,�ṩ�õ��Թ����ĺ���
	void running()
	{
		// 4 -- ����ÿ����������Ľӿ�
		m_cpu->calculate();
		m_gpu->display();
		m_memo->storage();
	}

	// ��������
	~Computer()
	{
		// �ͷ����--CPU
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		// �ͷ����--GPU
		if (m_gpu != NULL)
		{
			delete m_gpu;
			m_gpu = NULL;
		}
		// �ͷ����--Memory
		if (m_memo != NULL)
		{
			delete m_memo;
			m_memo = NULL;
		}
	}

private:
	// 0 -- ������Ҫ��ɲ���ΪCPU���Կ����ڴ���
	CPU* m_cpu;
	GPU* m_gpu;
	Memory* m_memo;
};

// -------------------------------
// 2 -- �ṩ��ͬ�ĳ���������ͬ�����

// ------------Intel-------------
// ���--CPU-Intel
class CPU_Intel :public CPU
{
	void calculate()
	{
		cout << "�����и�������CPU�������Intel����" << endl;
	}
};

// ���--GPU-Intel
class GPU_Intel :public GPU
{
	void display()
	{
		cout << "�����и�����ʾ��GPU�������Intel����" << endl;
	}
};

// ���--Memory-Intel
class Memory_Intel :public Memory
{
	void storage()
	{
		cout << "�����и���洢��Memory�������Intel����" << endl;
	}
};

// ------------Dell-------------
// ���--CPU-Dell
class CPU_Dell :public CPU
{
	void calculate()
	{
		cout << "�����и�������CPU�������Dell����" << endl;
	}
};

// ���--GPU-Dell
class GPU_Dell :public GPU
{
	void display()
	{
		cout << "�����и�����ʾ��GPU�������Dell����" << endl;
	}
};

// ���--Memory-Dell
class Memory_Dell :public Memory
{
	void storage()
	{
		cout << "�����и���洢��Memory�������Dell����" << endl;
	}
};

// ����
void test01()
{
	// ��1̨�������
	CPU* cpu_intel = new CPU_Intel;
	GPU* gpu_intel = new GPU_Intel;
	Memory* memory_intel = new Memory_Intel;

	cout << "-------------------------" << endl;
	cout << "��1̨���Կ�ʼ������" << endl;
	// ������1̨����
	Computer* computer1 = new Computer(cpu_intel, gpu_intel, memory_intel);
	computer1->running();
	delete computer1;

	cout << "-------------------------" << endl;
	cout << "��2̨���Կ�ʼ������" << endl;
	// ������2̨����
	Computer* computer2 = new Computer(new CPU_Dell, new GPU_Dell, new Memory_Dell);
	computer2->running();
	delete computer2;

	cout << "-------------------------" << endl;
	cout << "��3̨���Կ�ʼ������" << endl;
	// ������3̨����
	Computer* computer3 = new Computer(new CPU_Intel, new GPU_Intel, new Memory_Dell);
	computer3->running();
	delete computer3;
}

int main()
{
	// ����
	test01();

	return 0;
}
