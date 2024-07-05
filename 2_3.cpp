/*
	2024年6月29日
	题目： -- p105
		1）设计一个圆形类（Circle）
		2）和一个点类（Point）,
		3）计算点和圆的关系
*/

#include<iostream>
using namespace std;

// 设计类--点 Point
class Point
{
private:
	//成员属性--x,y
	int m_X;
	int m_Y;

public://成员方法
	// 设置x
	void setX(int x)
	{
		m_X = x;
	}

	// 设置y
	void setY(int y)
	{
		m_Y = y;
	}

	// 获取x
	int getX()
	{
		return m_X;
	}

	// 获取y
	int getY()
	{
		return m_Y;
	}
};


// 设计类--圆形 Circle
class Circle
{
private:
	// 成员属性--半径/中心
	int m_R;
	Point m_C;

public://成员方法
	//设置半径
	void setR(int r)
	{
		m_R = r;
	}

	// 设置圆心
	void setCenter(Point& c)
	{
		m_C = c;
	}

	// 获取半径
	int getR()
	{
		return m_R;
	}

	// 获取圆心
	Point getCenter()
	{
		return m_C;
	}
};

// 定义函数--判断关系
void relation(Circle &c, Point &p)
{
	// 计算两点之间距离
	int distance = 
		(c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());

	// 圆形半径
	int radium = c.getR() * c.getR();

	// 判断关系
	if (distance < radium)
	{
		cout << "点在圆内" << endl;
	}
	else if (distance > radium)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆上" << endl;
	}
}

int main()
{
	// 创建对象--圆类
	Circle c;
	c.setR(10);
	Point c_center;
	c_center.setX(10);
	c_center.setY(0);
	c.setCenter(c_center);

	// 创建对象--点类
	Point p;
	p.setX(10);
	p.setY(10);
	
	// 判断关系
	relation(c, p);

	return 0;
}
