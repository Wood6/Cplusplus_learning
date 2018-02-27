// 重载->操作符其作用于类的对象而不是指针
#include <iostream>

using namespace std;

class A
{
public:
    int x;

public:
    A() {x = 1;}

    void action()
    {
        cout << "Action in class A!" << endl;
    }
};

class B
{
private:
    A a;
    int x;

public:
    B() {x =2;}

    A* operator->()
    {
        return &a;
    }

    void action()
    {
        cout << "Action in class B!" << endl;
    }
};

class C
{
private:
    B b;
    int x;

public:
    C() {x =3;}

    B operator->()
    {
        return b;
    }

    void action()
    {
        cout << "Action in class C!" << endl;
    }
};

int main(int argc, char *argv[])
{
    C* pc = new C;
    pc->action();   // pc为指针，直接调用pc的action

    C c;
    c->action();    // 因C的重载->函数返回的是一个对象B，继续调用B的->,
                    // 遇至返回指针A*，递归调用结束，则调用A的action。
                    // 打印"Action in class A!"
    int x = c->x;   // 理由同上，从c的->出发，返回对象，继续调用该对象
                    // 的->直到返回指针（A*），然后调用A的x，然的x为1

    cout << x << endl;   // 打印1

    return 0;
}
/* 运行结果
Action in class C!
Action in class A!
1
*/
