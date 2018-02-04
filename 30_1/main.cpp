// 操作符重载
#include <stdio.h>

class Complex
{
private:
    int a;
    int b;

public:
    Complex(int a = 0, int b = 0) : a(a), b(b){}
    int getA() {return a;}
    int getB() {return b;}

    //运行出错：不要返回栈上的引用
    //friend Complex& add(Complex& left, Complex& right);
    //方式一：通过全局普通的函数实现复数相加
    friend Complex add(const Complex& left, const Complex& right);

    //方式二：通过全局函数重载“+”操作符实现复数相加
    friend Complex operator + (const Complex& left, const Complex& right);

    //方式三：通过成员函数实现“+”操作符的重载，参数少了一个左操作数！
    Complex operator + (const Complex& right)
    {
        printf("member function overloading\n");
        Complex sum;

        sum.a = this->a + right.a;
        sum.b = this->b + right.b;

        return sum;
    }
};

//全局普通函数
Complex add(const Complex& left, const Complex& right)
{
    //下面这种初始化方式：(5, 6)被视为逗号表达式，
    //只取最后值6给sum.a，sum.b赋予默认值0,
    //这里可以推断这种初始化方式只能对一个参数的构造函数安全
    //Complex sum = (5, 6);

    Complex sum;

    sum.a = left.a + right.a;
    sum.b = left.b + right.b;

    return sum;
}

//全局重载操作符+
Complex operator + (const Complex& left, const Complex& right)
{
    printf("global function overloading\n");
    Complex sum;

    sum.a = left.a + right.a;
    sum.b = left.b + right.b;

    return sum;
}

int main()
{
    Complex l(1, 1);
    Complex r(2, 2);

    //方式一的调用  缺点是无法写成：c1 + c2的形式;
    Complex s1 = add(l, r);
    printf("s1 = (%d, %d)\n\n", s1.getA(), s1.getB());

    //方式二的调用  //把“opertor+”当成函数名一样的调用
    //这里就是在当函数使用，则有两个传参，只能调用方式二
    Complex s2 = operator+(l, r);
    printf("s2 = (%d, %d)\n\n", s2.getA(), s2.getB());

    //方式二/三的调用  //更直观,本质上是调用“operator+”这个函数
    //优先调用成员函数重载
    Complex s3 = l + r;
    printf("s3 = (%d, %d)\n", s3.getA(), s3.getB());

    return 0;
}
/* 运行结果
s1 = (3, 3)

global function overloading
s2 = (3, 3)

member function overloading
s3 = (3, 3)
*/
