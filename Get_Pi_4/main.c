#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//设置几位"保险位"
#define maxw_ 10010

int main()
{
    long maxw,i,k,s,v,w;
    maxw=maxw_-1;
    //total
    //a[maxw]为个数，a[maxw-1]~a[1]依次为小数点后1~maxw-1位
    //存储：从高位到低位
    long *a=(long *) malloc (sizeof(long)*maxw_);
    //multiphy
    long *c=(long *) malloc (sizeof(long)*maxw_);
    for (i=0;i<maxw;i++)
    {
        a[i]=0;
        c[i]=0;
    }
    a[maxw]=2;
    c[maxw]=2;
    //c的最高位所在位数
    w=maxw;
    //高精度乘低精度
    //低精度需小于等于8位，从而使得一个8位的数乘上一个小于10的数,
    //小于等于9位,在longint范围内
    s=3;
    for (k=1;k;k++,s+=2)
    {
        //c(High)=c(High)*k(Low)
        //前k个数的乘积乘上第k+1个数的分子，结果小于1(在数组范围内)

        //当前位进行乘法运算，加上前一位的进位
        //c[0]=0，为无关位
        for (i=1;i<=w;i++)
        {
            c[i]=c[i]*k+c[i-1]/10;
            c[i-1]%=10;
        }
        while (c[w]>=10)
        {
            c[w+1]=c[w]/10;
            c[w]%=10;
            w++;
        }
        //c(High)=c(High)/(2*k+1)(Low)
        //s=2*k-1
        //c[i]的值对c[i-1]的值无影响
        v=0;
        for (i=w;i>=1;i--)
        {
            v=v*10+c[i];
            c[i]=v/s;
            v=v%s;
        }
        while (c[w]==0 && w!=0)
            w--;
        //小数点前maxw-1位为0
        if (w==0)
            break;
        //a(high)=a(high)+c(High)
        //c的位数小于等于a的位数
        //a+c<10(在数组范围内)
        for (i=1;i<=w;i++)
        {
            a[i]+=c[i];
            if (a[i]>=10)
            {
                a[i]-=10;
                a[i+1]++;
            }
        }
    }
    //add 1~k-1 ， 10^(-maxw) ，
    //即加k-1+2=k+1(最低位，即小数点后第maxw位)
    a[1]+=(k+1);
    k=1;
    while (a[k]>=10)
    {
        a[k+1]+=a[k]/10;
        k++;
    }
    //a[i]前k位发生修改，而后面的位数没有发生变化
    printf("小数位数=%ld\n",maxw-1-k);
    printf("%ld.",a[maxw]);
    for (i=maxw-1;i>k;i--)
        printf("%ld",a[i]);
    printf("\n");
    return 0;
}
