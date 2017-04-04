#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define maxn 100000000
#define times 100

int main()
{
    long i,k,ans;
    double x,y,v[1000],total=0,ave,min=100.0,max=0,s=0;
    srand((unsigned)time(NULL));
    //rand 0~32767(RAND_MAX) integer
    for (i=1;i<=times;i++)
    {
        ans=0;
        for (k=1;k<=maxn;k++)
        {
            x=rand()/(double)RAND_MAX;
            y=rand()/(double)RAND_MAX;
            if (x*x+y*y<=1.0000)
                ans++;
        }
        v[i]=4.0*ans/maxn;
        printf("%lf\n",v[i]);
        total=total+v[i];
        if (v[i]<min)
            min=v[i];
        if (v[i]>max)
            max=v[i];
    }
    ave=total/times;
    for (i=1;i<=times;i++)
        s=s+(ave-v[i])*(ave-v[i]);
    s=sqrt(s/times);
    printf("\n");
    printf("ave=%lf\n",ave);
    printf("min=%lf\n",min);
    printf("max=%lf\n",max);
    printf("标准差=%lf\n",s);
    //3.141基本不变
    return 0;
}
/*
ave=3.141521
min=3.141196
max=3.141831
标准差=0.000149
*/
