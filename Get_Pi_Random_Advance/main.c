#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define maxn 100000000
#define times 10
//做法的优点：答案精确，稳定
int main()
{
    long k,ans,i;
    double x,y,u,v,r,t=0;
    srand((unsigned)time(NULL));
    //rand 0~32767(RAND_MAX) integer
    for (i=1;i<=times;i++)
    {
        ans=0;
        for (k=1;k<=maxn;k++)
        {
            /*
            u=rand()/((double)RAND_MAX+1);
            v=rand()/((double)RAND_MAX+1)/((double)RAND_MAX+1);
            r=rand()/((double)RAND_MAX+1)/((double)RAND_MAX+1)/(double)RAND_MAX;
            //横坐标
            x=u+v+r;
            u=rand()/((double)RAND_MAX+1);
            v=rand()/((double)RAND_MAX+1)/((double)RAND_MAX+1);
            r=rand()/((double)RAND_MAX+1)/((double)RAND_MAX+1)/(double)RAND_MAX;
            //纵坐标
            y=u+v+r;
            */

            u=rand()/((double)RAND_MAX+1);
            v=rand()/((double)RAND_MAX+1)/(double)RAND_MAX;
            x=u+v;
            u=rand()/((double)RAND_MAX+1);
            v=rand()/((double)RAND_MAX+1)/(double)RAND_MAX;
            y=u+v;

            //到中(原)点的距离
            if (x*x+y*y<=1.0000)
                ans++;
        }
        printf("%lf\n",4.0*ans/maxn);
        t+=4.0*ans/maxn;
    }
    printf("ave=%lf\n",t/times);
    //基本确定3.141
    return 0;
}
/*
有x,y
3.141824
3.141602
3.141554
3.141716
3.141382
3.141564
3.141700
3.141574
3.141809
3.141401
ave=3.141613

3.141531
3.141779
3.141409
3.141478
3.141684
3.141611
3.141821
3.141502
3.141264
3.141821
ave=3.141590

3.141486
3.141692
3.141670
3.141324
3.141726
3.141549
3.141659
3.141859
3.141206
3.141776
ave=3.141595
*/
/*
有x,y,z
3.141730
3.141605
3.141760
3.141419
3.141494
3.141520
3.141448
3.141792
3.141558
3.141668
ave=3.141599

3.141721
3.141673
3.141752
3.141462
3.141505
3.141572
3.141425
3.141733
3.141561
3.141774
ave=3.141618

3.141323
3.141845
3.141545
3.141721
3.141464
3.141518
3.141548
3.141426
3.141814
3.141563
ave=3.141577
*/

