#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define maxn 100000000

int main()
{
    long k,ans=0;
    double x,y;
    srand((unsigned)time(NULL));
    //rand 0~32767(RAND_MAX) integer
    for (k=1;k<=maxn;k++)
    {
        x=rand()/(double)RAND_MAX;
        y=rand()/(double)RAND_MAX;
        if (x*x+y*y<=1.0000)
            ans++;
    }
    printf("%lf\n",4.0*ans/maxn);
    //3.141基本不变
    return 0;
}
/*
3.141768
3.141772
3.141685
3.141408
3.141554
*/
