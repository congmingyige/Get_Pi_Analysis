#include <stdio.h>
#include <stdlib.h>

int main()
{
    long n=1000000000,i;
    double value=1.0;
    for (i=2;i<n;i+=2)
    {
        value=value*i/(i-1)*i/(i+1);
        if (i % 10000000==0)
            printf("n=%ld value=%.10lf\n",i,value*2.000);
    }
    //3.1415926(423)
    return 0;
}
