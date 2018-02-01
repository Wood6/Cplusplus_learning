// 编译错误程序
#include <stdio.h>

class Test
{
private:
    // const成员，会分配空间。其存储空间与对象存储位置一样
    // 可在栈上、堆或全局区等
    // 但编译期间无法确定初始化，所以不会进入符号表
    const int i;

public:
    Test()
    {
        //i = 1;  // error: assignment of read-only member 'Test::i'
                  // 不能这样初始化，ci是只读变量，不能作为左值
    }

    int getI() {return i;}
};

int main()
{
    // 当没有初始化成员i时定义对象t 时
    // error: 'const int Test::i' should be initialized
    // Test t;

    return 0;
}
