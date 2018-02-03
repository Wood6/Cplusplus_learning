// 静态成员函数初探
#include <stdio.h>

class Test
{
private:
    int m_i;
    static int s_i;

    Test(int v) {}

public:
    Test() {}
    int getMi();
    static void staticPrint(const char* s);
    static void staticSetMi(int v);
    static void staticSetMi(Test& obj, int v);
    static void staticSetSi(int v);
    static void staticSetSi(Test& obj, int v);
    static int staticGetSi();
    int getSi() {return s_i;}
};

int Test::s_i = 0;

int Test::getMi()
{
    return m_i;
}

void Test::staticPrint(const char *s)
{
    printf("%s\n", s);
}

void Test::staticSetMi(int v)
{
    //error: invalid use of member 'Test::m_i' in static member function
    //静态成员函数不能访问非静态成员变量,因为没有this指针
    //m_i = v;

    //getMi();  // error 静态成员函数中不能调用普通成员函数,原因也是无this指针
    Test();     // 但却可以直接调用构造函数
    Test(3);    // private的构造函数也可以直接调用
}

void Test::staticSetMi(Test& obj, int v)
{
    // 静态成员函数因为没有this指针，所以必须要有个对象
    // 来起到这个this指针的作用才能访问到普通成员变量
    obj.m_i = v;
}

void Test::staticSetSi(int v)
{
    s_i = v;
}

void Test::staticSetSi(Test &obj, int v)
{
    obj.s_i = v;
}

int Test::staticGetSi()
{
    return s_i;
}



int main()
{
    Test::staticPrint("main Being...");  // 通过类名调用静态成员函数

    Test t1;
    printf("t1.m_i = %d\n", t1.getMi());
    printf("t1.s_i = %d\n", Test::staticGetSi()); // 通过类名调用静态成员函数

    t1.staticSetMi(t1, 2);            // 静态成员函数通过传对象引用访问普通变量
    printf("t1.m_i = %d\n", t1.getMi());

    t1.staticSetSi(2);                    // 静态成员函数直接访问静态成员变量
    printf("t1.s_i = %d\n", t1.staticGetSi()); // 通过对象调用静态成员函数

    t1.staticSetSi(t1, 3);          // 静态成员函数通过传对象访问静态成员变量
    printf("t1.s_i = %d\n", t1.getSi());       // 普通成员函数访问静态成员变量

    Test::staticPrint("main End...");

    Test::staticSetMi(1);        // 证明静态成员函数可以直接调用构造函数

    return 0;
}
/* 运行结果
main Being...
t1.m_i = 58
t1.s_i = 0
t1.m_i = 2
t1.s_i = 2
t1.s_i = 3
main End...
*/
