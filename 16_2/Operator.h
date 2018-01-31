// Operator.h 头文件
#ifndef _OPERATOR_H_
#define _OPERATOR_H_

class Operator
{
private:
    char mOp;     // 操作符
    double mP1;   // 操作数1
    double mP2;   // 操作数2

public:
    bool setOperator(char op);
    void setParameter(double p1, double p2);
    bool result(double& r);
};

#endif
