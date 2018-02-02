// 局部对象的构造顺序
#include <stdio.h>
#include "Test.h"

Test t4("t4");      // 全局变量

int main()
{
    Test t5("t5");  // 局部变量

    // 注意：全局变量会先于main函数执行，因此
    // 4个全局变量t1-t4会被先构造，再其顺序是不确定的，
    // 要依赖于编译器。
    // 当构造完全局对象后，会执行main函数，可以发现
    // t5是最后一个被构造的。

    return 0;
}
/* 运行结果 Windows环境QtCreator编译后运行结果
Test(const char* s),t3
Test(const char* s),t2
Test(const char* s),t1
Test(const char* s),t4
Test(const char* s),t5

 ** linux g++编译后运行结果 **
Test(const char* s),t3
Test(const char* s),t2
Test(const char* s),t1
Test(const char* s),t4
Test(const char* s),t5

 ** 另一个linux 环境下 g++编译后运行结果 **
Test(const char* s),t4
Test(const char* s),t1
Test(const char* s),t2
Test(const char* s),t3
Test(const char* s),t5
*/
