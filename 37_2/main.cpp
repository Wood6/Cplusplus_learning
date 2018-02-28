// main.cpp
#include <iostream>
#include "SmartPointer.h"

using namespace std;

class Test
{
private:
    int m_i;

public:
    Test(int i = 0) : m_i(i) {}

    int getValue() {return m_i;}
};

int main()
{
    // 这里是在构造p1对象，现代编译器这句本质就相当于
    // SmartPointer p1(new Test(5))，这个就会调用构造函数,new Test(5)
    // 返回的地址值就是构造函数SmartPointer(Test* pointer = NULL)的参数
    // 这样自然就构造了p1这个对象了
    SmartPointer<Test> p1 = new Test(5);

    SmartPointer<Test> p3(new Test(5));

    cout << p1->getValue() << endl;
    cout << "p1.m_pointer = " << p1.get() << endl;

    // p2接管了p1所指的堆空间，保证每次只能由一个智能指针指向堆空间
    SmartPointer<Test> p2 = p1;
    cout << "p1.m_pointer = " << p1.get() << endl;
    cout << "p2.m_pointer = " << p2.get() << endl;

    // p1指向NULL了，不再指向原来的堆空间
    // p2接管了p1所指堆空间
    cout << p1.isNull() << endl;
    cout << p2.isNull() << endl;

    cout << p2->getValue() << endl;

    // p2++;不重载++，因为每次只能一个智能指针指向堆空间，这种++操作没意义
    // p2智能指针生命期结束，会自动释放接管的堆空间

    return 0;
}
/* 运行结果
5
p1.m_pointer = 0x30210c8
p1.m_pointer = 0
p2.m_pointer = 0x30210c8
1
0
5
*/
