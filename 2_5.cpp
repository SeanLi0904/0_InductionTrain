/*
	2024��6��30��
	��Ŀ�� -- p139
		1�����ö�̬������ʵ��
		2��������Ʒ�����̣���ˮ-> ����-> ���뱭��-> ���븨��
		3���ṩ����������Ʒ����
		4���ṩ�������Ⱥ�������Ҷ������
*/

#include<iostream>
using namespace std;

// �������--������Ʒ
class AbstractMakeDrinks
{
public:
	// ���麯��--��ˮ
	virtual void Boil() = 0;
	// ���麯��--����
	virtual void Brew() = 0;
	// ���麯��--���뱭��
	virtual void Pour() = 0;
	// ���麯��--���븨��
	virtual void AddAux() = 0;

	// ������Ʒ����
	void makeDrink()
	{
		Boil();
		Brew();
		Pour();
		AddAux();
	}
};

// ����--��������
class MakeCoffe : public AbstractMakeDrinks
{
public:
	// ��ˮ
	void Boil()
	{
		cout << "���Ȫˮ--����" << endl;
	}
	// ����
	void Brew()
	{
		cout << "���ݿ���" << endl;
	}
	// ���뱭��
	void Pour()
	{
		cout << "���뱭��" << endl;
	}
	// ���븨��
	void AddAux()
	{
		cout << "����ţ��" << endl;
	}
};

// ����--������
class MakeTea : public AbstractMakeDrinks
{
public:
	// ��ˮ
	void Boil()
	{
		cout << "���Ȫˮ--����ɽ" << endl;
	}
	// ����
	void Brew()
	{
		cout << "���ݲ�Ҷ" << endl;
	}
	// ���뱭��
	void Pour()
	{
		cout << "���뱭��" << endl;
	}
	// ���븨��
	void AddAux()
	{
		cout << "����ˮ�ɻ�" << endl;
	}
};

// ������Ʒ����
void doWork(AbstractMakeDrinks* p)
{
	p->makeDrink();
	delete p;
}

void test01()
{
	// ��������
	doWork(new MakeCoffe);

	cout << "-------------" << endl;

	// ������Ҷ
	doWork(new MakeTea);
}

int main()
{
	test01();

	return 0;
}
