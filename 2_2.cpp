/*
	2024年6月29日
	题目： -- p104
		1）设计一个立方体类
		2）私有属性包括：长--m_L，宽--m_W,高--m_H
		3）要求通过成员函数计算立方体的面积和体积
		4）并分别用全局函数和成员函数判断两个立方体是否相等
*/

#include<iostream>
using namespace std;

class Cube
{
private:
	// 私有属性--长/宽/高
	int m_L;
	int m_W;
	int m_H;

public:
	// 设置立方体--长
	void setL(int l)
	{
		m_L = l;
	}
	// 设置立方体--宽
	void setW(int w)
	{
		m_W = w;
	}
	// 设置立方体--高
	void setH(int h)
	{
		m_H = h;
	}
	
	// 获取立方体--长
	int getL()
	{
		return m_L;
	}
	// 获取立方体--宽
	int getW()
	{
		return m_W;
	}
	// 获取立方体--高
	int getH()
	{
		return m_H;
	}

	// 计算立方体面积
	int calculateArea()
	{
		return 2 * (m_L * m_W + m_L * m_H + m_W * m_H);
	}

	// 计算立方体体积
	int calculateVolume()
	{
		return m_L * m_W * m_H;
	}

	// 判断与其他立方体是否相等
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
	// 创建立方体类
	Cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);

	cout << "c1的面积为: " << c1.calculateArea() << endl;
	cout << "c1的体积为: " << c1.calculateVolume() << endl;

	// 创建立方体类
	Cube c2;
	c2.setL(10);
	c2.setW(10);
	c2.setH(10);

	bool ret = isSame(c1, c2);
	if (ret)
	{
		cout << "（全局函数）c1 与 c2 立方体相同" << endl;
	}
	else 
	{
		cout << "（全局函数）c1 与 c2 立方体不相同" << endl;
	}

	bool ret_class = c1.isSame(c2);
	if (ret_class)
	{
		cout << "（成员函数）c1 与 c2 立方体相同" << endl;
	}
	else
	{
		cout << "（成员函数）c1 与 c2 立方体不相同" << endl;
	}

	return 0;
}
