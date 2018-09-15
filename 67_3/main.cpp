// 方案2: 直接利用函数模板的重载
#include <iostream>
#include <string>

using namespace std;

class Test
{
public:
    Test() {}
    virtual ~Test() {}
};

// 模板函数-匹配指针
template < typename T >
bool isPtr(T* v)          // match pointer
{
    return true;
}

// 模板函数-匹配非指针
template < typename T >
bool isPtr(T v)          // match non-pointer
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

    cout << "t is pointer: " << std::boolalpha << isPtr(t) << endl;
    cout << "pt is pointer: " << std::boolalpha << isPtr(pt) << endl;

    return 0;
}
/* 运行结果
 * windows下 qtCreator5.9.6 运行结果
i is pointer: false
pi is pointer: true
t is pointer: false
pt is pointer: true

*** linux g++ 编译结果
i is pointer: false
pi is pointer: true
t is pointer: false
pt is pointer: true
*/
