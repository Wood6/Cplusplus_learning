// Class.h
#ifndef __CLASS_H_
#define __CLASS_H_

// �������ʵ�ַ�װ��
typedef void Test;
typedef void Child;

// ������Ա����(�ӿ�)
Test* Test_Creat(int i, int j);
int Test_getMi(Test* pThis);
int Test_getMj(Test* pThis);
int Test_add(Test* pThis, int v);
void Test_free(Test* pThis);

Child* Child_Creat(int i, int j, int k);
int Child_getMk(Child* pThis);
int Test_add(Child* pThis, int v);

#endif
