/*
	2024��6��29��
	��Ŀ�� -- p104
		1�����һ����������
		2��˽�����԰�������--m_L����--m_W,��--m_H
		3��Ҫ��ͨ����Ա�����������������������
		4�����ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����
*/

#include<iostream>
using namespace std;

class Cube
{
private:
	// ˽������--��/��/��
	int m_L;
	int m_W;
	int m_H;

public:
	// ����������--��
	void setL(int l)
	{
		m_L = l;
	}
	// ����������--��
	void setW(int w)
	{
		m_W = w;
	}
	// ����������--��
	void setH(int h)
	{
		m_H = h;
	}
	
	// ��ȡ������--��
	int getL()
	{
		return m_L;
	}
	// ��ȡ������--��
	int getW()
	{
		return m_W;
	}
	// ��ȡ������--��
	int getH()
	{
		return m_H;
	}

	// �������������
	int calculateArea()
	{
		return 2 * (m_L * m_W + m_L * m_H + m_W * m_H);
	}

	// �������������
	int calculateVolume()
	{
		return m_L * m_W * m_H;
	}

	// �ж��������������Ƿ����
	bool isSame(Cube &c2)
	{
		if (m_L == c2.getL() && m_W == c2.getW() && m_H == c2.getH())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

bool isSame(Cube& c1, Cube& c2)
{
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	// ������������
	Cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);

	cout << "c1�����Ϊ: " << c1.calculateArea() << endl;
	cout << "c1�����Ϊ: " << c1.calculateVolume() << endl;

	// ������������
	Cube c2;
	c2.setL(10);
	c2.setW(10);
	c2.setH(10);

	bool ret = isSame(c1, c2);
	if (ret)
	{
		cout << "��ȫ�ֺ�����c1 �� c2 ��������ͬ" << endl;
	}
	else 
	{
		cout << "��ȫ�ֺ�����c1 �� c2 �����岻��ͬ" << endl;
	}

	bool ret_class = c1.isSame(c2);
	if (ret_class)
	{
		cout << "����Ա������c1 �� c2 ��������ͬ" << endl;
	}
	else
	{
		cout << "����Ա������c1 �� c2 �����岻��ͬ" << endl;
	}

	return 0;
}
