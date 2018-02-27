// 类模板的特化示例
#include <iostream>

using namespace std;

template < typename T1, typename T2 >
class Test
{
public:
    void add(T1 a, T2 b)
    {
        cout << "void add(T1 a, T2 b)" << endl;
        cout << a + b << endl;
    }
};

// 上述类模板的特化，即参数类型为指针时的特殊情况如何处理，
// 下面是这种情况时的类实现。（因参数仍是泛型，故称为部分特化）
template < typename T1, typename T2 >
class Test <T1*, T2*>  // 特化时,必须在这里显式指定参数的类型(本例为指针)
{                      // 这个实现是上述类模板的特殊情况，本质是同一个类模板
public:
    void add(T1* a, T2* b)
    {
        cout << "void add(T1* a, T2* b)" << endl;
        cout << *a + *b << endl;
    }
};

// 类模板特化为两个参数相同时的情况（因参数仍是泛型，故称为部分特化）
template < typename T >
class Test <T, T>       // 特化时，必须显式指定参数的类型
{
public:
    void add(T a, T b)
    {
        cout << "void add(T a, T b)" << endl;
        cout << a + b << endl;
    }

    // 特化的类，可以有自己的成员函数。
    void print()
    {
        cout << "class Test<T, T>" << endl;
    }
};

// 完全特化,当两个参数是具体的类型(如int、void*),而不是泛型类型时
template <>   // 这里为空，因为没有泛型了，只有实际的类型
class Test <void*, void*>  // 特化时,这里须显式指定参数类型(这里特化为void*)
{
public:
    void add(void* a, void* b)
    {
        cout << "void add(void* a, void* b)" << endl;
        cout << "Error ,Can't add void* param...." << endl;
    }
};

// 重定义(虽然可以完成与完全特化的类模板一样的功能，但本质是这是另一个新的类)
class Test_void
{
public:
    void add(void* a, void* b)
    {
        cout << "void add(void* a, void* b)" << endl;
        cout << "Error ,Can't add void* param...." << endl;
    }
};

int main()
{
    Test<int, float> t1;
    Test<long, long> t2;
    Test<void*, void*> t3;
    Test<int*, double*> t4;

    // 一般的类模板（非特化的类模化）
    t1.add(1, 2.5);
    cout << endl;

    // 特化为两个相同参数类型
    t2.add(5, 5);
    cout << endl;

    // 特化为两个void*类型
    t3.add(NULL, NULL);
    cout << endl;

    // 特化为两个指针类型
    int i = 1;
    double d = 1.28;
    t4.add(&i, &d);
    cout << endl;

    // 重定义
    Test_void t5;
    t5.add(NULL, NULL);

    return 0;
}
/* 运行结果
void add(T1 a, T2 b)
3.5

void add(T a, T b)
10

void add(void* a, void* b)
Error ,Can't add void* param....

void add(T1* a, T2* b)
2.28

void add(void* a, void* b)
Error ,Can't add void* param....
*/
