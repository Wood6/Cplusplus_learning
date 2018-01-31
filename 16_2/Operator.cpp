// // Operator.cpp 实现和定义文件
#include "Operator.h"

bool Operator::setOperator(char op)
{
    bool bRet = ('+' == op) || ('-' == op) || ('*' == op) || ('/' == op);

    mOp = bRet ? op : '\0';

    return bRet;
}

void Operator::setParameter(double p1, double p2)
{
    mP1 = p1;
    mP2 = p2;
}

bool Operator::result(double &r)
{
    bool bRet = true;

    switch(mOp)
    {
        case '/' :
            if((-0.000000001 < mP2) && (mP2 < 0.000000001))
            {
                bRet = false;
            }
            else
            {
                r = mP1 / mP2;
            }
            break;

        case '+':
            r = mP1 + mP2;
            break;

        case '-':
            r = mP1 - mP2;
            break;

        case '*':
            r = mP1 * mP2;
            break;

        default:
            break;
    }

    return bRet;
}

