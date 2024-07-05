/*
	2024��6��29��
	��Ŀ�� -- p105
		1�����һ��Բ���ࣨCircle��
		2����һ�����ࣨPoint��,
		3��������Բ�Ĺ�ϵ
*/

#include<iostream>
using namespace std;

// �����--�� Point
class Point
{
private:
	//��Ա����--x,y
	int m_X;
	int m_Y;

public://��Ա����
	// ����x
	void setX(int x)
	{
		m_X = x;
	}

	// ����y
	void setY(int y)
	{
		m_Y = y;
	}

	// ��ȡx
	int getX()
	{
		return m_X;
	}

	// ��ȡy
	int getY()
	{
		return m_Y;
	}
};


// �����--Բ�� Circle
class Circle
{
private:
	// ��Ա����--�뾶/����
	int m_R;
	Point m_C;

public://��Ա����
	//���ð뾶
	void setR(int r)
	{
		m_R = r;
	}

	// ����Բ��
	void setCenter(Point& c)
	{
		m_C = c;
	}

	// ��ȡ�뾶
	int getR()
	{
		return m_R;
	}

	// ��ȡԲ��
	Point getCenter()
	{
		return m_C;
	}
};

// ���庯��--�жϹ�ϵ
void relation(Circle &c, Point &p)
{
	// ��������֮�����
	int distance = 
		(c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());

	// Բ�ΰ뾶
	int radium = c.getR() * c.getR();

	// �жϹ�ϵ
	if (distance < radium)
	{
		cout << "����Բ��" << endl;
	}
	else if (distance > radium)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
	}
}

int main()
{
	// ��������--Բ��
	Circle c;
	c.setR(10);
	Point c_center;
	c_center.setX(10);
	c_center.setY(0);
	c.setCenter(c_center);

	// ��������--����
	Point p;
	p.setX(10);
	p.setY(10);
	
	// �жϹ�ϵ
	relation(c, p);

	return 0;
}
