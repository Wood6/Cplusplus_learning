// add.h 头文件
#ifndef _ADD_H_
#define _ADD_H_

// C++文件以C的方式编译：将add的函数名就是目标名
#ifdef __cplusplus
extern "C" {
#endif

int add(int a, int b);

#ifdef __cplusplus
}
#endif

#endif
