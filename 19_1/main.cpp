// 特殊的构造函数：无参构造和拷贝构造
#include <stdio.h>

class Test
{
private:
    int i;
    int j;

public:
    // 无参构造函数
    Test() {printf("Test()\n");}

    // 拷贝构造函数
    Test(const Test& obj)
    {
        i = obj.i;
        j = obj.j;
        printf("Test(const Test& obj)\n");
    }

    int getI() {return i;}
    int getJ() {return j;}
};

int main()
{
    // 调用无参构造函数，注意如果我们定义了构造函数（含无参、带参或拷贝
    // 构造函数时）系统就不再提供默认的，需自己定义无参构造函数。
    // 去掉上面自定义的无参构造保留拷贝构造 error: no matching function for call to 'Test::Test()'
    // 证明有拷贝构造函数存在也是不会提供默认的无参构造函数了
    Test t1;      // 调用Test()

    Test t2 = t1; // 调用拷贝构造函数，如果我们不定义，系统会提供默认的

    printf("t1.i = %d, t1.j = %d\n", t1.getI(), t1.getJ());
    printf("t2.i = %d, t2.j = %d\n", t2.getI(), t2.getJ());

    return 0;
}
/* 运行结果
Test()
Test(const Test& obj)
t1.i = 2686856, t1.j = 4200459
t2.i = 2686856, t2.j = 4200459
*/
