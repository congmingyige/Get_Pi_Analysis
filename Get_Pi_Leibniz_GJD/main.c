#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define maxn 100000
#define maxw 100000

int main()
{
    long *a=(long *) malloc (sizeof(long)*(maxw+1));
    //long *b=(long *) malloc (sizeof(long)*(maxw+1));
    long *c=(long *) malloc (sizeof(long)*(maxw+1));
    long i,k,t,value;
    for (i=1;i<=maxw;i++)
        a[i]=0;
    for (k=1;k<=maxn;k+=4)
    {
        //1/n-1/(n+2)=2/n(n+2) *4 = 8/n(n+2)
        //c/k=b
        for (i=1;i<maxw;i++)
            c[i]=0;
        c[maxw]=8;
        value=0;
        //t太大时，long long范围容易出错
        t=k*(k+2);
        /*
        for (i=mawx;i>=1;i--)
        {
            value=value*10+c[i];
            b[i]=value/t;
            value=value%t;
        }
        //add
        for (i=1;i<maxw;i++)
        {
            a[i]+=b[i];
            if (a[i]>=10)
            {
                a[i]-=10;
                a[i+1]++;
            }
        }
        */
        for (i=maxw;i>=1;i--)
        {
            value=value*10+c[i];
            a[i]+=value/t;
            value=value%t;
            if (a[i]>=10)
            {
                a[i]-=10;
                a[i+1]++;
            }
        }
    }
    printf("%ld.",a[maxw]);
    for (i=maxw-1;i>=1;i--)
        printf("%ld",a[i]);
    printf("\n");
    return 0;
}
