#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//���ü�λ"����λ"
#define maxw_ 10010

int main()
{
    long maxw,i,k,s,v,w;
    maxw=maxw_-1;
    //total
    //a[maxw]Ϊ������a[maxw-1]~a[1]����ΪС�����1~maxw-1λ
    //�洢���Ӹ�λ����λ
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
    //c�����λ����λ��
    w=maxw;
    //�߾��ȳ˵;���
    //�;�����С�ڵ���8λ���Ӷ�ʹ��һ��8λ��������һ��С��10����,
    //С�ڵ���9λ,��longint��Χ��
    s=3;
    for (k=1;k;k++,s+=2)
    {
        //c(High)=c(High)*k(Low)
        //ǰk�����ĳ˻����ϵ�k+1�����ķ��ӣ����С��1(�����鷶Χ��)

        //��ǰλ���г˷����㣬����ǰһλ�Ľ�λ
        //c[0]=0��Ϊ�޹�λ
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
        //c[i]��ֵ��c[i-1]��ֵ��Ӱ��
        v=0;
        for (i=w;i>=1;i--)
        {
            v=v*10+c[i];
            c[i]=v/s;
            v=v%s;
        }
        while (c[w]==0 && w!=0)
            w--;
        //С����ǰmaxw-1λΪ0
        if (w==0)
            break;
        //a(high)=a(high)+c(High)
        //c��λ��С�ڵ���a��λ��
        //a+c<10(�����鷶Χ��)
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
    //add 1~k-1 �� 10^(-maxw) ��
    //����k-1+2=k+1(���λ����С������maxwλ)
    a[1]+=(k+1);
    k=1;
    while (a[k]>=10)
    {
        a[k+1]+=a[k]/10;
        k++;
    }
    //a[i]ǰkλ�����޸ģ��������λ��û�з����仯
    printf("С��λ��=%ld\n",maxw-1-k);
    printf("%ld.",a[maxw]);
    for (i=maxw-1;i>k;i--)
        printf("%ld",a[i]);
    printf("\n");
    return 0;
}
