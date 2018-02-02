// Test.h
#ifndef _TEST_H_
#define _TEST_H_

#include <stdio.h>

class Test
{
public:
    Test()
    {
        printf("Test::Test()\n");
    }

    Test(const char* s)
    {
        printf("Test(const char* s),%s\n", s);
    }

    Test(const Test& obj)
    {
        printf("Test(const Test& obj)\n");
    }
};

#endif
