#include <stdio.h>

// 利用const定义一个常量 endl 表示换行符'\n'
const char endl = '\n';

class Console
{
public:
    Console& operator << (int i)
    {
        printf("%d", i);

        return *this;   // 返回引用就可以连续使用 <<
    }

    Console& operator << (char c)
    {
        printf("%c", c);

        return *this;
    }

    Console& operator << (const char* s)
    {
        printf("%s", s);

        return *this;
    }

    Console& operator << (double d)
    {
        printf("%lf", d);

        return *this;
    }

    Console& operator << (float d)
    {
        printf("%f", d);

        return *this;
    }

};

int main()
{
    Console cout;

    cout << 1 << ' ' << 'c' << ' ' << 3.14 << endl;

    double d1 = 2.12;

    cout << d1 << endl;
    cout << d1 + 5 << endl;

    return 0;
}
/* 运行结果
1 c 3.140000
2.120000
7.120000
*/
