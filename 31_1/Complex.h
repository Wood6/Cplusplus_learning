// Complex.h
#ifndef _COMPLEX_H_
#define _COMPLEX_H_

class Complex
{
private:
    double a;
    double b;

public:
    Complex(double a = 0, double b = 0) : a(a), b(b) {}
    double getA() {return a;}
    double getB() {return b;}

    double getModulus();

    Complex operator + (const Complex& right);
    Complex operator - (const Complex& right);
    Complex operator * (const Complex& right);
    Complex operator / (const Complex& right);

    Complex& operator ++ ();     // 前置++
    Complex operator ++ (int);   // 后置++
    Complex& operator -- ();     // 前置--
    Complex operator -- (int);   // 后置--

    bool operator == (const Complex& right);
    bool operator != (const Complex& right);

    Complex& operator = (const Complex& right);  // 赋值运算符只能重载为成员函数
};

#endif
