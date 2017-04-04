#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define n 4

int main()
{
    //半径为1圆的面积=pi
    //近似于求中点到边的长为1的正多边形的面积
    //180*n/(n+2)/2     pi=180

    //求pi的时候需要pi，所以不能这样做
    //printf("%lf\n",1.0*n/tan(0.25*pi*(n-2)/n));


    return 0;
}
