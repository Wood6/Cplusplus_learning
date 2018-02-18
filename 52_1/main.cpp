// 纯虚函数实现抽象类用于被继承实现多态
#include <iostream>

using namespace std;

// 抽象类
class Shape
{
public:
    virtual double area() = 0;  // 纯虚函数，没有具体的实现
};

// 矩形类
class Rect : public Shape
{
private:
    int m_len;
    int m_width;

public:
    Rect(int l, int w) : m_len(l), m_width(w) {}

    double area()  // 子类中实现纯虚函数
    {
        return m_len * m_width;
    }
};

// 圆类
class Circle : public Shape
{
private:
    int m_r;

public:
    Circle(int r) : m_r(r) {}

    double area()
    {
        return 3.14 * m_r * m_r;
    }
};

double run(Shape* p)
{
    return p->area();   // 多态
}

int main()
{
    Rect R(3, 4);
    Circle C(5);

    cout << run(&R) << endl;
    cout << run(&C) << endl;

    return 0;
}
/* 运行结果
12
78.5
*/
