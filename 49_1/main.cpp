// 函数重写遇上赋值兼容产生的问题！-多态来解决
#include <iostream>

using namespace std;

class Parent
{
public:
    virtual void print()     // 多态版本，与48课唯一的不同！
    {
        cout << "I'm Parent." << endl;
    }
};

class Child : public Parent
{
public:
    void print()     // 虚函数,父类己加virtual,这里不必再写,写了也没错
    {
        cout << "I'm Child." << endl;
    }
};

void how_to_print(Parent& obj)
{
    obj.print();      // 展现多态的行为
}

int main()
{
    Parent p1;
    Child c1;

    // 多态，根据实际对象类型来调用虚函数
    how_to_print(p1);
    how_to_print(c1);

    return 0;
}
/* 运行结果
I'm Parent.
I'm Child.
*/

