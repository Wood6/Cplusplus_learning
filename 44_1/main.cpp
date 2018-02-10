// 组合与继承综合示例
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class Object
{
protected:         // 以下两个成员变量须被子类直接访问
    string m_name;
    string m_info;

public:
    Object()
    {
        m_name = "Object";
        m_info = "";
    }

    string getName()
    {
        return m_name;
    }

    string getInfo()
    {
        return m_info;
    }
};

class Point : public Object
{
private:      // 没有子类，无须被访问
    int m_x;
    int m_y;

public:
    Point(int i = 0, int j = 0)
    {
        ostringstream s;

        m_x = i;
        m_y = j;

        s << "P(" << i << "," << j << ")";

        m_name = "Point";
        m_info = s.str();
    }

    int getX() {return m_x;}
    int getY() {return m_y;}
};

class Line : public Object
{
private:
    Point m_p1;   // 组合了类Point
    Point m_p2;

public:
    Line(Point p1, Point p2) : m_p1(p1), m_p2(p2)
    {
        ostringstream s;

        //s << "p1(" << p1.getX() << "," << p1.getY() << ")" \
        //  << "to" << p2.getX() << "," << p2.getY();

        s << "Line from " << m_p1.getInfo() << " to " << m_p2.getInfo();

        m_name = "Line";
        m_info = s.str();
    }

    Point bigin()
    {
        return m_p1;
    }

    Point end()
    {
        return m_p2;
    }
};

int main()
{
    Object o;
    Point pa(0, 0);
    Point pb(3, 4);
    Line l(pa, pb);

    cout << endl;
    cout << o.getName() << endl;
    cout << o.getInfo() << endl;    // 空

    cout << endl;
    cout << pa.getName() << endl;
    cout << pa.getInfo() << endl;

    cout << endl;
    cout << l.getName() << endl;
    cout << l.getInfo() << endl;

    return 0;
}
/* 运行结果
Object


Point
P(0,0)

Line
Line from P(0,0) to P(3,4)
*/
