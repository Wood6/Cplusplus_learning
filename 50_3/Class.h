// Class.h
#ifndef __CLASS_H_
#define __CLASS_H_

// 利用这个实现封装性
typedef void Test;

// 声明成员函数(接口)
Test* Test_Creat(int i, int j);
int Test_getMi(Test* p);
int Test_getMj(Test* p);
int Test_add(Test* p, int v);
void Test_free(Test* p);

#endif
