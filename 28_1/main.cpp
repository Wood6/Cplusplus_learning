// 友元函数初探
#include <stdio.h>
#include <math.h>

#define POWER(a) ((a)*(a))

class Point
{
private:
    int x;
    int y;

public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    int printXY()
    {
        printf("Point::x = %d,Point::y = %d\n", x,y);
    }

    friend double Distance(Point& p1, Point& p2);
};

// 从这里看，Distance只是一个普通的函数
double Distance(Point& p1, Point& p2)
{
    double ret = 0;

    // 可以引用类中的私有成员!
    ret = sqrt( POWER(p2.x-p1.x) + POWER(p2.y-p1.y) );

    return ret;
}

int main()
{
    Point p1(0, 0);
    Point p2(3, 4);

    p1.printXY();
    p2.printXY();

    printf("|(p1, p2)| =  %f\n", Distance(p1, p2));

    return 0;
}
/* 运行结果
Point::x = 0,Point::y = 0
Point::x = 3,Point::y = 4
|(p1, p2)| =  5.000000
*/
