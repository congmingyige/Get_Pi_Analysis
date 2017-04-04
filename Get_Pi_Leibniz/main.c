#include <stdio.h>
#include <stdlib.h>

int main()
{
    long n=2000000000,i;
    double value=0;
    for (i=1;i<n;i+=4)
    {
        value+=1.0/i-1.0/(i+2);
        if (i % 10000000==1)
            printf("n=%ld value=%.10lf\n",i,value*4.000);
    }
    //3.1415926(446)
    return 0;
}
