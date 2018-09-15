// 方案1：利用函数模板与变参函数的优先级(类类型不适用)
#include <iostream>
#include <string>

using namespace std;

class Test
{
public:
    Test() {}
    virtual ~Test() {}
};

// 模板函数-优先匹配
template < typename T >
bool isPtr(T* v)          // match pointer
{
    return true;
}

// 变参函数-匹配的优先级比模板函数低
bool isPtr(...)           // match non-pointer
{
    return false;
}

int main()
{
    int i = 1;
    int *pi = &i;

    cout << "i is pointer: " << std::boolalpha << isPtr(i) << endl;
    cout << "pi is pointer: " << std::boolalpha << isPtr(pi) << endl;

    Test t;
    Test *pt = &t;

    // 如果直接调用isPtr来判断自定义类类型里，在linux g++下编译出现：
    // error: cannot pass objects of non-trivially-copyable type 'class Test' through '...'的错误。
    // 以下是trivially copyable type类型的定义：
    // 1.要么全部定义了拷贝/移动/赋值函数，要么全部没定义;
    // 2.没有虚成员;
    // 3.基类或其它任何非static成员都是trivally copyable。
    // 典型的内置类型bool、int等属于trivally copyable
    cout << "t is pointer: " << std::boolalpha << isPtr(t) << endl;    // 这句linux下编译error
    cout << "pt is pointer: " << std::boolalpha << isPtr(pt) << endl;  // 这句还是不会的，匹配的函数模板

    return 0;
}
/* 运行结果
 * windows下 qtCreator5.9.6 运行结果
i is pointer: false
pi is pointer: true
t is pointer: false
pt is pointer: true

*** linux g++ 编译结果
main.cpp: In function ‘int main()’:
main.cpp:36:58:error: cannot pass objects of non-trivially-copyable type ‘class Test’ through ‘...’
     cout << "t is pointer: " << std::boolalpha << isPtr(t) << endl;
*/
