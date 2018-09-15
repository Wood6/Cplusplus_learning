// 构造函数中抛出异常测试
#include <iostream>
#include <string>

using namespace std;

class Test
{
public:
    Test()
    {
        cout << "Test()" << endl;
        throw 0;
    }

    virtual ~Test()
    {
        cout << "~Test()" << endl;
    }
};

int main()
{
    // 将指针p指向0x00000001，目的是为了后面的验证
    Test *p = reinterpret_cast<Test*>(1);

    try
    {
        p = new Test;
        // 结论：抛出异常，new Test 没有返回地址，连空指针都不会返回
    }
    catch(...)
    {
        cout << "Exception ..." << endl;
    }

    cout << "p = " << p << endl;   // p = 0x1，说明上面结论准确性
                                   // p new时没有分配地址
    return 0;
}
/* 运行结果
 * Windows 下 QtCreator5.9.1 的编译运行结果
Test()
Exception ...
p = 0x1

** linux g++ 编译运行结果
Test()
Exception ...
p = 0x1

linux下可以用如下命令检查是否内存泄漏
# valgrind --tool=memcheck --leak-check=full ./a.out
==3130== Memcheck, a memory error detector
==3130== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==3130== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==3130== Command: ./a.out
==3130==
Test()
Exception ...
p = 0x1
==3130==
==3130== HEAP SUMMARY:
==3130==     in use at exit: 0 bytes in 0 blocks
==3130==   total heap usage: 2 allocs, 2 frees, 104 bytes allocated
==3130==
==3130== All heap blocks were freed -- no leaks are possible
==3130==
==3130== For counts of detected and suppressed errors, rerun with: -v
==3130== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

上面检测结果表明没有内存泄漏，注意此时没有delete p却没有内存泄漏，说明了什么？
说明了，p 在 new Test时根本就没有被分配内存

** 构造函数中注释掉 throw 0 的检测结果：明显表明就有内存泄漏了
# valgrind --tool=memcheck --leak-check=full ./a.out
==3160== Memcheck, a memory error detector
==3160== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==3160== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==3160== Command: ./a.out
==3160==
Test()
p = 0x4348028
==3160==
==3160== HEAP SUMMARY:
==3160==     in use at exit: 4 bytes in 1 blocks
==3160==   total heap usage: 1 allocs, 0 frees, 4 bytes allocated
==3160==
==3160== 4 bytes in 1 blocks are definitely lost in loss record 1 of 1
==3160==    at 0x402A6DC: operator new(unsigned int) (in /usr/lib/valgrind/vgpreload_memcheck-x86-linux.so)
==3160==    by 0x80488EB: main (in /root/liyao_test/a.out)
==3160==
==3160== LEAK SUMMARY:
==3160==    definitely lost: 4 bytes in 1 blocks
==3160==    indirectly lost: 0 bytes in 0 blocks
==3160==      possibly lost: 0 bytes in 0 blocks
==3160==    still reachable: 0 bytes in 0 blocks
==3160==         suppressed: 0 bytes in 0 blocks
==3160==
==3160== For counts of detected and suppressed errors, rerun with: -v
==3160== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
*/
