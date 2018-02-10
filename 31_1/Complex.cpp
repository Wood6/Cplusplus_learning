// Complex.cpp
#include "Complex.h"
#include <math.h>

#define POWER(a) ((a)*(a))

double Complex::getModulus()
{
    return sqrt(POWER(a) + POWER(b));
}

Complex Complex::operator + (const Complex& right)
{
    double na = a + right.a;
    double nb = b + right.b;

    return Complex(na, nb);
}

Complex Complex::operator - (const Complex& right)
{
    double na = a - right.a;
    double nb = b - right.b;

    return Complex(na, nb);
}

Complex Complex::operator * (const Complex& right)
{
    double na = a * right.a - b * right.b;
    double nb = a * right.b - b * right.a;

    return Complex(na, nb);
}

Complex Complex::operator / (const Complex& right)
{
    double cm = POWER(right.a) + POWER(right.b);
    double na = (a * right.a + b * right.b) / cm;
    double nb = (a * right.a - b * right.b) / cm;

    return Complex(na, nb);
}

Complex& Complex::operator ++ ()
{
    a++;
    b++;

    return *this;
}

Complex Complex::operator ++ (int)
{
    Complex ret(a, b);

    a++;
    b++;

    return ret;
}

Complex& Complex::operator -- ()
{
    a--;
    b--;

    return *this;
}

Complex Complex::operator -- (int)
{
    Complex ret(a, b);

    a--;
    b--;

    return ret;
}

bool Complex::operator == (const Complex& right)
{
    return (a == right.a) && (b == right.b);
}

bool Complex::operator != (const Complex& right)
{
    // 直接利用==运算
    return !(*this == right);
}

Complex& Complex::operator = (const Complex& right)
{
    if( *this != right )
    {
        this->a = right.a;
        this->b = right.b;
    }

    return *this;
}
