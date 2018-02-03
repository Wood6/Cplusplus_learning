// 友元类的探索
#include <stdio.h>

class ClassC
{
private:
    const char* s;

public:
    ClassC(const char* s) : s(s)
    {
        printf("ClassC::ClassC(const char* s),%s\n", s);
    }

    friend class ClassB;
};

class ClassB
{
private:
    const char* s;

public:
    ClassB(const char* s) : s(s)
    {
        printf("ClassB::ClassB(const char* s),%s\n", s);
    }

    void getClassCName(ClassC& c)
    {
        printf("c.s = %s\n", c.s);
    }

    friend class ClassA;
};

class ClassA
{
private:
    const char* s;

public:
    ClassA(const char* s) : s(s)
    {
        printf("ClassA::ClassA(const char* s),%s\n", s);
    }

    void getClassBName(ClassB& b)
    {
        //合法，因为在类B中，己将A声明为友元类
        printf("b.s = %s\n", b.s);
    }

    void getClassCName(ClassC& c)
    {
        //错误，因为在类C中，并没将A声明为友元类
        //printf("c.n = %s\n", c.s);
    }

};


int main()
{
    // A是B的友元类，B是C的友元类，但A不能自动传递为C的友元类
    ClassA A("A");
    ClassB B("B");
    ClassC C("C");

    A.getClassBName(B); // A是B的友元类
    B.getClassCName(C); // B是C的友元类

    return 0;
}
/* 运行结果
ClassA::ClassA(const char* s),A
ClassB::ClassB(const char* s),B
ClassC::ClassC(const char* s),C
b.s = B
c.s = C
*/
