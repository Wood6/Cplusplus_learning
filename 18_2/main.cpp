// 构造函数的手工调用
#include <stdio.h>

class Test
{
private:
    int m_value;

public:
    Test()
    {
        m_value = 0;
        printf("Test()\n");
    }

    Test(int v)
    {
        m_value = v;
        printf("Test(int v), v = %d\n", v);
    }

    int getValue() {return m_value;}
};

int main()
{
    Test array1[] = {0, 1, 2};  // 编译器自动调用带参构造函数
    printf("---------------------\n");

    Test t = Test(100);  // 定义并手动调用带参构造函数来初始化对象
    printf("---------------------\n");

    // 定义对象数组，并手动调用对应的构造函数来初始化各个对象元素
    Test array2[] = {Test(), Test(1), Test(2)};
    for(int i=0; i<sizeof(array2)/sizeof(array2[0]); i++)
    {
        printf("array2[%d] = %d\n", i, array2[i]);
    }

    return 0;
}
/* 运行结果
Test(int v), v = 0
Test(int v), v = 1
Test(int v), v = 2
---------------------
Test(int v), v = 100
---------------------
Test()
Test(int v), v = 1
Test(int v), v = 2
array2[0] = 0
array2[1] = 1
array2[2] = 2
*/
