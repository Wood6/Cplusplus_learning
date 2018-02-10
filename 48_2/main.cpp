// 函数重写遇上赋值兼容产生的问题！
#include <iostream>

using namespace std;

class Parent
{
public:
    void print()
    {
        cout << "I'm Parent." << endl;
    }
};

class Child : public Parent
{
public:
    void print()
    {
        cout << "I'm Child." << endl;
    }
};

/*
编译以下函数时，编译器不可能知道指针p究竟指向了什么
但是编译器没有理由报错。于是，它认为最安全的做法是调用
父类的print函数，因为父类和子类肯定都有相同的print函数。
*/
void how_to_print(Parent& obj)
{
    obj.print();
}

int main()
{
    Parent p1;
    Child c1;

    how_to_print(p1);  // 期望：I'm Parent. 实际：I'm Parent.
    how_to_print(c1);  // 期望：I'm Child.  实际：I'm Parent.

    return 0;
}
/* 运行结果
I'm Parent.
I'm Parent.
*/

