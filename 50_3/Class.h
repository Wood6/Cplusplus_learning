// Class.h
#ifndef __CLASS_H_
#define __CLASS_H_

// �������ʵ�ַ�װ��
typedef void Test;

// ������Ա����(�ӿ�)
Test* Test_Creat(int i, int j);
int Test_getMi(Test* p);
int Test_getMj(Test* p);
int Test_add(Test* p, int v);
void Test_free(Test* p);

#endif
