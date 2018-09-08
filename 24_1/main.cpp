// 构造函数/析构函数的顺序
#include <stdio.h>

class Member
{
private:
    const char* m_s;

public:
    Member(const char* s) : m_s(s)
    {
        printf("Member::Member(const char* s): %s\n", s);
    }

    ~Member()
    {
        printf("Member::~Member(): %s\n", m_s);
    }
};

class Test
{
private:
    Member m_A;  // 成员函数是按声明顺序构造的
    Member m_B;

public:
    Test() : m_A("mA"), m_B("mB")
    {
        printf("Test::Test()\n");
    }

    ~Test()
    {
        printf("Tese::~Test()\n");
    }
};

Member g_A("gA");

int main()
{
    Test t1;

    return 0;
}
/* 运行结果
Member::Member(const char* s): gA        // Member g_A("gA");
Member::Member(const char* s): mA        // Test t1;
Member::Member(const char* s): mB
Test::Test()
Tese::~Test()                            // 注意析构顺序与构造顺序是相反的！
Member::~Member(): mB
Member::~Member(): mA
Member::~Member(): gA
*/
