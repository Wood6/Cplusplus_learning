// 优化: 利用sizeof使其适用于任何类型
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
char isPtr(T* v)          // match pointer
{
    return '0';           // 返回值char型
}

// 变参函数-匹配的优先级比模板函数低
int isPtr(...)           // match non-pointer
{
    return 0;            // 返回值为int型
}

// 定义这个宏的主要目的是，为了避免传自定义类型给变参函数时，可能出现的上个程序的报错问题
// 可以利用sizeof来判断返回值的大小。如果为1表示char型，说明是匹配了模板函数，
// 为4表示int型，匹配到了变参函数，从而区别变量到底是指针还是非指针类型，这样
// 就巧妙地利用了sizeof编译期就能确定的特性，从而避开上个程序运行期的错误。
#define ISPTR(p) (sizeof(char) == sizeof(isPtr(p)))

int main()
{
    int i = 1;
    int *pi = &i;

    cout << "i is pointer: " << std::boolalpha << ISPTR(i) << endl;
    cout << "pi is pointer: " << std::boolalpha << ISPTR(pi) << endl;

    Test t;
    Test *pt = &t;

    cout << "t is pointer: " << std::boolalpha << ISPTR(t) << endl;
    cout << "pt is pointer: " << std::boolalpha << ISPTR(pt) << endl;

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
