// Class.h
#ifndef __CLASS_H_
#define __CLASS_H_

// 利用这个实现封装性
typedef void Test;
typedef void Child;

// 声明成员函数(接口)
Test* Test_Creat(int i, int j);
int Test_getMi(Test* pThis);
int Test_getMj(Test* pThis);
int Test_add(Test* pThis, int v);
void Test_free(Test* pThis);

Child* Child_Creat(int i, int j, int k);
int Child_getMk(Child* pThis);
int Test_add(Child* pThis, int v);

#endif
