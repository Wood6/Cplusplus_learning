// 类的一些属性探索
#include <stdio.h>

class Test
{
private:
    int m_i;

public:
    Test()
    {
        m_i = 0;
    }

    Test(int v) : m_i(v) {}


    Test(const Test& obj)
    {
        m_i = obj.m_i;  // 这里t.mi为private属性，但编译仍然能通过。
                        // 是因为编译器开了个后门，允许类的成员函数
                        // 直接访问由该类创建的任何对象的局部变量。
    }

    void print()
    {
        printf("m_i = %d\n", m_i);
        printf("&m_i = 0x%p\n", &m_i);
        printf("this = 0x%p\n", this);
    }

};

void func() {}

int main()
{
    printf("&func = 0x%p\n", func);    // 函数名即函数指针
    printf("&func = 0x%p\n", &func);   // 普通函数对函数名取地址
                                       // 也还是该函数的指针(地址)
    printf("--------------------------------\n");

    Test t1(1);
    Test t2 = 2;
    Test t3 = Test(3);

    //t1 t2 t3的内存地址各不相同,各自的m_i地址也不同,但print函数地址是一样的
    t1.print();
    printf("&t1 = 0x%p\n", &t1);
    printf("&t1.printf = 0x%p\n", &t1.print);  // 函数名即函数指针
    //printf("&t1.printf = 0x%p\n", t1.print); // error:类成员函数地址必须加上&
    printf("--------------------------------\n");

    t2.print();
    printf("&t2 = 0x%p\n", &t2);
    printf("&t2.printf = 0x%p\n", &t2.print);
    printf("--------------------------------\n");

    t3.print();
    printf("&t3 = 0x%p\n", &t3);
    printf("&t3.printf = 0x%p\n", &t3.print);


    return 0;
}
/* 运行结果
&func = 0x00401630
&func = 0x00401630
--------------------------------
m_i = 1
&m_i = 0x0061FE8C                // 无虚函数的类中第一个成员变量的地址
this = 0x0061FE8C                // 无虚函数的类对象变量的地址与其第一个成员变量地址同
&t1 = 0x0061FE8C
&t1.printf = 0x00402940
--------------------------------
m_i = 2
&m_i = 0x0061FE88
this = 0x0061FE88
&t2 = 0x0061FE88
&t2.printf = 0x00402940          // 同&t1.printf
--------------------------------
m_i = 3
&m_i = 0x0061FE84
this = 0x0061FE84
&t3 = 0x0061FE84
&t3.printf = 0x00402940           // 同&t1.printf
*/
