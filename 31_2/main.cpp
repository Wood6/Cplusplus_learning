// 探索为什么 =,[],(),-> 语法就规定不能重载为全局函数？
#include <stdio.h>

class Test
{
public:
    Test() {}
    Test(int) {}  // int 类型可以被隐式转换成 Test

    friend Test& operator+=(const Test& l, const Test& r);

    // error: 'Test& operator=(const Test&, const Test&)'
    // must be a nonstatic member function
    // 重载为全局函数 直接报错
    //friend Test& operator=(const Test& l, const Test& r);
};

// 只是测试，无实际实现
Test& operator+=(const Test& l, const Test& r) {printf("test +=\n");}

//Test& operator=(const Test& l, const Test& r) {printf("test =\n");}

int main()
{
    Test t;

    // 合法，使用友元重载函数，1 可以被隐式地转换为
    // Test 类型 －－友元函数的第一个参数
    1 += t;

    // 网上一类解释是：为了避免上面这类语句 1 = t变得合法
    // 但这个实例分析可以发现，+=重载就能够使得 1 += t 变得合法
    // 所以编译器不会是对 = 重载避免对其他操作符重载又不避免
    // 因此这个解释是不可靠的

    // 结论：猜测与与当时的编译技术有关系，所以就这么强制规定了
    // 放到现在 重载赋值操作符为全局函数  也不是什么难事

    return 0;
}
/* 运行结果
test +=
*/
