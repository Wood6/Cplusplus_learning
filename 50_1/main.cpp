// 类对象的内存布局实质就是一个struct
#include <iostream>

using namespace std;

class classTest
{
private:
    int i;
    int j;
    char c;
    double d;

public:
    void print()
    {
        cout << "i = " << i << endl
             << "j = " << j << endl
             << "c = " << c << endl
             << "d = " << d << endl;
    }
};

struct stTest
{
    int i;
    int j;
    char c;
    double d;
};

int main()
{
    classTest t1;

    // class 和 struct 在内存布局上是一样的。大小相同
    cout << "sizeof(classTest) = " << sizeof(classTest) << endl; // 24
    cout << "sizeof(t1) = " << sizeof(t1) << endl;               // 24
    cout << "sizeof(stTest) = " << sizeof(stTest) << endl;       // 24

    t1.print();

    cout << endl;

    stTest* pst = reinterpret_cast<stTest*>(&t1); // 将类强制转化结构体

    // 利用结构体对类的 private 成员进行赋值(注意是 private 成员)
    // 说明 class 在运行时,private 访问权限只在编译期起作用。
    pst->i = 1;
    pst->j = 2;
    pst->c = 'c';
    pst->d = 3.1415;

    t1.print();        // class 中的 private 成员被改变

    return 0;
}
/* 运行结果  Windows下QtCreator编译后运行结果
sizeof(classTest) = 24
sizeof(t1) = 24
sizeof(stTest) = 24
i = 4200656
j = 65535
c =
d = 1.23077e-312

i = 1
j = 2
c = c
d = 3.1415

  ** linux 下g++编译后运行结果 **
sizeof(classTest) = 20
sizeof(t1) = 20
sizeof(stTest) = 20
i = -1219271507
j = -1217731644
c =
d = -9.64093e-42

i = 1
j = 2
c = c
d = 3.1415
*/

