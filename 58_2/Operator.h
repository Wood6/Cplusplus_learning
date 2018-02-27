// Operator.h 类模板头文件
/*类模板只是“无限多个class的定义”的“处方”而已,模板定义本身的代码并不能直接
编译成二进制代码, 而是指导编译器生成代码的指令,只有当类模板被实例化后,实例化
的具体类型才能编译为真正的程序代码。实例化类模板需要注意4点。
    (1)只有当类模板实例真正被使用时(如调用使用类模版定义对象、或通过对象调用
       类模板的成员函数)编译器才会实例化类模板。
    (2)实例化类模板时编译器需要知道类模板的定义。
    (3)不能将模板类的成员函数放在独立的实现文件中，因为在实例化时编译器需要看
       到函数定义的源码。
    (4)实例化类模板,不会自动实例化类模板成员函数的定义。

2.类模板的编译方法：
(1)包含编译：将类模板声明和定义的两者直接写在.h文件中（如本例）.因为模板实例化
   需要看到模板的定义，而不仅仅是声明。所以模板类的定义全部放在头文件中。这种叫
   做包含编译模型
(2)分离编译：将类模板声明在XXX.h文件、类模板实现在XXX.cpp文件。(不推荐此方法)
      A、方法1：在 XXX.h文件的后面包含XXX.cpp
      B、方法2：在要需要使用模板的单元（如main.cpp)中#include XXX.cpp
      C、方法3：在XXX.cpp中显式实例化模板：
         template class Operator<string>。并在main.cpp中用
         extern template class Operator<string>来声明是外部的模板实例化
*/
#ifndef _OPERATOR_H_
#define _OPERATOR_H_

template < typename T >
class Operator
{
public:
    T add(T a, T b);
    T minus(T a, T b);
    T multiply(T a, T b);
    T divide(T a, T b);
};

// 类模板外部定义的成员函数需要加上模板<>声明
template < typename T >
T Operator<T>::add(T a, T b)
{
    return a + b;
}

template < typename T >
T Operator<T>::minus(T a, T b)
{
    return a - b;
}

template < typename T >
T Operator<T>::multiply(T a, T b)
{
    return a * b;
}

template < typename T >
T Operator<T>::divide(T a, T b)
{
    return a / b;
}

#endif
