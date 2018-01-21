// C到C++的升级二
#include <stdio.h>

// 在C++中Student是一种新的类型，但在C语言要用typedef来重命名
// C语言要为Student类型必须这样  typedef struct Student Student;
struct Student
{
    const char* name;
    int age;
};

// C语言中下列是合法的，等价于int f(int i);
// 但C++所有的标识符须定义类型，不认识i的类型，会报错
/*
f(i)
{
    printf("i = %d\n", i);
}
*/

// C语言中下列是合法的，表示返回值int，接受任意参数
// 但C++表示返回值int,无参数，相于当int g(void)
g()
{
    return 5.5;
}

int main()
{

    Student s1 = {"Hello", 30};
    Student s2 = {"World", 20};

    // f(10);                             // C合法，C++会报错

    //printf("g() = %d\n",g(1,2,3,4,5));  // C合法，C++中不能为g传入参数

    printf("g() = %d\n",g());             // 证明C++默认也是返回int型的(没有返回5.5)

    return 0;
}
/*
g() = 5
*/
