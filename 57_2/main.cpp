// 函数模板的两次编译
#include <iostream>

using namespace std;

class Test
{
private:
    Test(const Test& obj) {}  // 故意设置为私有的

public:
    Test() {}
};

template <typename T>
void Swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

typedef void(*pFuncI)(int&, int&);
typedef void(*pFuncD)(double&, double&);
typedef void(*pFuncT)(Test&, Test&);

int main()
{
    pFuncI pFi = Swap;  // 1. 编译器自动推导T为int
                        // 当编译到这行时，发生要用一个模板去初始化pFi
                        // 而pFi的类型又是void(*pFuncI)(int&, int&),
                        // 所以此时，编译器会用int去替换T
                        // 2. 然后生成一个Swap函数
                        // 3. 并把函数指针赋值给pFi

    pFuncD pFd = Swap;  // 编译器自动推导T为double,编译器生成另一个Swap函数

    // 以下证明pFi与pFd指向的是两个不同的函数
    // 这里必须先强制类型转换为内置的地址值才能输出地址值
    // 因为cout对于自定义类型的识别不出来，除非专门对这个自定义类型重载<<
    // void* int* 等都行,只要是内置的地址值就可以，但一般都转换为void*
    cout << "pFi = " << reinterpret_cast<void*>(pFi) << endl;
    cout << "pFd = " << reinterpret_cast<int*>(pFd) << endl;

    // 以下证明函数模板有两次编译
    //pFuncT pFt = Swap; // 编译器自动推导T为test。但是当进行T替换时
                         // 由于Swap函数内部的T tmp = a；会调用Test的
                         // 拷贝构造函数，但被我们故意设为private，所以
                         // 编译出错，这个例子是用来说明会生成另一个不同的
                         // 版本的Swap函数，编译器会对这个生成的Swap
                         // 函数在这里进行第二次编译，所以发生了编译错误。

    //cout << "pFt = " << reinterpret_cast<void*>(pFt) << endl;

    return 0;
}
/* 运行结果
pFi = 0x402904
pFd = 0x4028e0
*/
