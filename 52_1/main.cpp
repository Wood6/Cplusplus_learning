// ���麯��ʵ�ֳ��������ڱ��̳�ʵ�ֶ�̬
#include <iostream>

using namespace std;

// ������
class Shape
{
public:
    virtual double area() = 0;  // ���麯����û�о����ʵ��
};

// ������
class Rect : public Shape
{
private:
    int m_len;
    int m_width;

public:
    Rect(int l, int w) : m_len(l), m_width(w) {}

    double area()  // ������ʵ�ִ��麯��
    {
        return m_len * m_width;
    }
};

// Բ��
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
    return p->area();   // ��̬
}

int main()
{
    Rect R(3, 4);
    Circle C(5);

    cout << run(&R) << endl;
    cout << run(&C) << endl;

    return 0;
}
/* ���н��
12
78.5
*/
