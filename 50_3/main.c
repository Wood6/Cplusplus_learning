// C���̣�C����ģ���������
#include <stdio.h>
#include "Class.h"

int main()
{
    Test* t1 = Test_Creat(1, 2);            // Test* t1 = new Test(1, 2);

    // �����������У���thisָ��:t1
    printf("m_i = %d\n", Test_getMi(t1));
    printf("m_j = %d\n", Test_getMj(t1));
    printf("t1.add(3) = %d\n", Test_add(t1, 3));

    //t1->m_i = 100;  //�൱��˽�б���������ֱ��ͨ��thisָ��(d)������

    return 0;
}
/* ���н��
m_i = 1
m_j = 2
t1.add(3) = 5
*/
