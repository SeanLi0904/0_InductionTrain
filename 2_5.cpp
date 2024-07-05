/*
	2024年6月30日
	题目： -- p139
		1）利用多态技术，实现
		2）制造饮品的流程，煮水-> 冲泡-> 倒入杯中-> 加入辅料
		3）提供抽象制作饮品基类
		4）提供制作咖啡和制作茶叶的子类
*/

#include<iostream>
using namespace std;

// 抽象基类--制作饮品
class AbstractMakeDrinks
{
public:
	// 纯虚函数--煮水
	virtual void Boil() = 0;
	// 纯虚函数--冲泡
	virtual void Brew() = 0;
	// 纯虚函数--倒入杯中
	virtual void Pour() = 0;
	// 纯虚函数--加入辅料
	virtual void AddAux() = 0;

	// 制作饮品流程
	void makeDrink()
	{
		Boil();
		Brew();
		Pour();
		AddAux();
	}
};

// 子类--制作咖啡
class MakeCoffe : public AbstractMakeDrinks
{
public:
	// 煮水
	void Boil()
	{
		cout << "煮矿泉水--怡宝" << endl;
	}
	// 冲泡
	void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}
	// 倒入杯中
	void Pour()
	{
		cout << "倒入杯中" << endl;
	}
	// 加入辅料
	void AddAux()
	{
		cout << "加入牛奶" << endl;
	}
};

// 子类--制作茶
class MakeTea : public AbstractMakeDrinks
{
public:
	// 煮水
	void Boil()
	{
		cout << "煮矿泉水--百岁山" << endl;
	}
	// 冲泡
	void Brew()
	{
		cout << "冲泡茶叶" << endl;
	}
	// 倒入杯中
	void Pour()
	{
		cout << "倒入杯中" << endl;
	}
	// 加入辅料
	void AddAux()
	{
		cout << "加入水仙花" << endl;
	}
};

// 制作饮品函数
void doWork(AbstractMakeDrinks* p)
{
	p->makeDrink();
	delete p;
}

void test01()
{
	// 制作咖啡
	doWork(new MakeCoffe);

	cout << "-------------" << endl;

	// 制作茶叶
	doWork(new MakeTea);
}

int main()
{
	test01();

	return 0;
}
