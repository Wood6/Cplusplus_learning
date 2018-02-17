// �̳ж���ģ�ͣ���һ�̳е����麯��
#include <iostream>

using namespace std;

class Parent
{
protected:
    int m_i;
    int m_j;

public:
    virtual void print()
    {
        cout << "m_i = " << m_i << endl
             << "m_j = " << m_j << endl;
    }
};

class Child : public Parent
{
private:
    int m_k;

public:
    Child(int i, int j, int k)
    {
        m_i = i;
        m_j = j;
        m_k = k;
    }

    void print()
    {
        cout << "m_i = " << m_i << endl
             << "m_j = " << m_j << endl
             << "m_k = " << m_k << endl;
    }
};

struct st
{
    void* p;
    int m_i;
    int m_j;
    int m_k;
};

int main()
{
     // 12������8����Ϊ������һ���麯����ָ��
    cout << "sizeof(Parent) = " << sizeof(Parent) << endl;
    cout << "sizeof(Child) = " << sizeof(Child) << endl;  // 16 ԭ��ͬ��

    Child c1(1, 2, 3);

    // ����ʵ��֤�������麯���� Child ���ڴ�ģ���� st �ṹ����һ�µ�
    // 1����С��ͬ��2����1����Ա������vptrָ�룻3����������Ϊmi��mj��mk

    st* s = reinterpret_cast<st*>(&c1);

    cout << "Before Change..." << endl;
    c1.print();

    s->m_i = 10;
    s->m_j = 20;
    s->m_k = 30;

    cout << "Before Change..." << endl;
    c1.print();

    return 0;
}
/* ���н��
sizeof(Parent) = 12
sizeof(Child) = 16
Before Change...
m_i = 1
m_j = 2
m_k = 3
Before Change...
m_i = 10
m_j = 20
m_k = 30
*/
