// 重载赋值函数实现深拷贝
#include <iostream>

using namespace std;

class Test
{
private:
    int* m_pointer;

public:
    Test()
    {
        m_pointer = new int(0);
        cout << "Test()" << endl;
    }

    Test(int n)
    {
        m_pointer = new int(n);
        cout << "Test(int n)" << endl;
    }

    Test(const Test& obj)
    {
        m_pointer = new int(*obj.m_pointer);
        cout << "Test(const Test& obj)" << endl;
    }

    // 有疑问：为什么拷贝构造不先 delete m_pointer呢？
    // 而赋值操作则需要先 delete m_pointer再赋新值呢？
    // 原因是两者发生时间点不一样，拷贝构造函数起作用时是
    // 当前对象还没有被创建出来，m_pointer还没有指向任何
    // 内存空间，自然也就没必要先delete了；
    // 而赋值发生的时间时当前对象已经被创建出来了，所以得先
    // delete掉对象所指以避免双重释放问题

    // 赋值4个注意点：
    // 1.返回值为引用。2.参数是const引用的对象
    // 3.避免自赋值(this!=&obj)。4.返回时*this;
    Test& operator = (const Test& obj)
    {
        cout << "Test& Test(const Test& obj)" << endl;
        if( this != &obj )
        {
            delete m_pointer;
            m_pointer = new int(*obj.m_pointer);
        }

        return *this;
    }

    void print()
    {
        cout << "m_pointer = " << m_pointer << endl;
    }

    ~Test()
    {
        cout << "~Test()" << endl;
        delete m_pointer;
    }
};

int main()
{
    Test t1(1);
    Test t2 = t1;
    Test t3;

    t3 = t1;     // operator=,赋值操作符

    t1.print();
    t2.print();
    t3.print();  // t3.m_pointer != t1.m_pointer;

    return 0;
}
/* 运行结果
Test(int n)
Test(const Test& obj)
Test()
Test& Test(const Test& obj)
m_pointer = 0x3519c8
m_pointer = 0x3519d8
m_pointer = 0x3519e8
~Test()
~Test()
~Test()
*/
