#include <stdio.h>
#include <stdlib.h>
//#define max 32768
#define max 1000000

int main()
{
    long long ans=0,total;
    long i,j,max_;
    double per,pi;
    double *s=(double *) malloc (sizeof(double)*max);
    max_=max-1;
    for (i=0;i<max;i++)
        s[i]=1.0*i/max_;
    for (i=0;i<max;i++)
        for (j=0;j<max;j++)
            if (s[i]*s[i]+s[j]*s[j]<=1.0000)
                ans=ans+1;
    total=(long long)max*max;
    per=1.0*ans/total;
    pi=per*4;
    printf("%ld\n",max);
    printf("ans=%lld\n",ans);
    printf("total=%lld\n",total);
    printf("per=%lf\n",per);
    printf("pi=%lf\n",pi);
    return 0;
}
/*
32768
ans=843296058
total=1073741824
per=0.785381
pi=3.141523
*/
/*
1000
ans=784787
total=1000000
per=0.784787
pi=3.139148
*/
/*
10000
ans=78534025
total=100000000
per=0.785340
pi=3.141361
*/
/*
100000
ans=7853924234
total=10000000000
per=0.785392
pi=3.141570
 31.456 s
*/
/*

*/
