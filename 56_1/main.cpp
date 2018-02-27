// 宏代码块和函数实现变量交换
#include <iostream>

using namespace std;

// 利用do{}while(0)作用域的作用，这样就能够反复调用这个宏
// 而不会出现t tmp 重复定义的编译错误！--巧妙的用法！
#define SWAP(t, a, b)        \
    do                       \
    {                        \
        t tmp = a;           \
        a = b;               \
        b = tmp;             \
    }while(0);

int main()
{
    int i1 = 3;
    int i2 = 4;

    SWAP(int, i1, i2);
    cout << "i1 = " << i1 << endl
         << "i2 = " << i2 << endl;

    float f1 = 3.14;
    float f2 = 8.88;

    SWAP(float, f1, f2);
    cout << "f1 = " << f1 << endl
         << "f2 = " << f2 << endl;

    string s1 = "Wood";
    string s2 = "Jim";

    SWAP(string, s1, s2);
    cout << "s1 = " << s1 << endl
         << "s2 = " << s2 << endl;

    return 0;
}
/* 运行结果
i1 = 4
i2 = 3
f1 = 8.88
f2 = 3.14
s1 = Jim
s2 = Wood
*/
