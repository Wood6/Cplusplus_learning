// C++风格代码与C风格代码混用造成的bug
#include <iostream>

using namespace std;

int main()
{
    string s = "12345";

    // 程序试图用C的方式访问字符串（不建议这样用！）
    const char* p = s.c_str();  // c_str表示C方式的字符串

    cout << "s = " << s << endl;
    cout << "p = " << p << endl;

    s.append("abcde");   // p成为野指针，因为追加字符串，可能
                         // 导致堆内存的重新分配，从而m_cstr
                         // 指的堆内存地址改变了，但p并不知道！

    cout << "s = " << s << endl;   // linux 下bug就显露出来了
    cout << "p = " << p << endl;   // 仍然指向旧的地址（野指针）

    // 原因就是：string类是C++标准库提供的一个类，在这个类的内部
    // 维护了一个指向数据的char*指针(m_cstr)，这里用于存放字符串
    // 数据的堆空间地址。因字符串操作（如复制、合并、追加等），所以
    // 这个指针可能在程序运行的过程中发生改变，而将原来的指针已经
    // 释放掉了，但p却依旧还指向原来指针，所以自然就造成了两者输出
    // 不一致了，甚至会产生段错误（p指向的地址已经被释放成为了野指针）

    // 解决方案就是：C++编码中尽量不要混合使用C分格代码

    return 0;
}
/* 运行结果 Windows下QtCreator编译后运行结果
s = 12345
p = 12345
s = 12345abcde
p = 12345abcde

 ** linux下g++编译后运行结果
s = 12345
p = 12345
s = 12345abcde
p = 12345
*/
