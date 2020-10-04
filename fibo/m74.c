#include <stdio.h>
#include <string.h>

long long int m=1000000007;
char sf[100005];
long long int n;

long long int fibo(unsigned long long int n)
{
    long long int a[2][2]={{1,1},{1,0}};
    long long int t[2][2]={{1,0},{0,1}};
    while(n)
    {
        if(n%2)
        {
            long long int tt[2][2];
            tt[0][0]=((t[0][0]*a[0][0])%m+(t[0][1]*a[1][0])%m)%m;
            tt[0][1]=((t[0][0]*a[1][0])%m+(t[0][1]*a[1][1])%m)%m;
            tt[1][0]=((t[1][0]*a[0][0])%m+(t[1][1]*a[1][0])%m)%m;
            tt[1][1]=((t[1][0]*a[1][0])%m+(t[1][1]*a[1][1])%m)%m;
            t[0][0]=tt[0][0];
            t[0][1]=tt[0][1];
            t[1][0]=tt[1][0];
            t[1][1]=tt[1][1];
        }
        long long int aa[2][2];
        aa[0][0]=((a[0][0]*a[0][0])%m+(a[0][1]*a[1][0])%m)%m;
        aa[0][1]=((a[0][0]*a[1][0])%m+(a[0][1]*a[1][1])%m)%m;
        aa[1][0]=((a[1][0]*a[0][0])%m+(a[1][1]*a[1][0])%m)%m;
        aa[1][1]=((a[1][0]*a[1][0])%m+(a[1][1]*a[1][1])%m)%m;
        a[0][0]=aa[0][0];
        a[0][1]=aa[0][1];
        a[1][0]=aa[1][0];
        a[1][1]=aa[1][1];
        n/=2;
    }
    return t[1][0];
}


int main()
{
    int t;
    // scanf("%d",&t);
    t=1;
    while(t--)
    {
        scanf("%s",sf);
        n=strlen(sf);
        long long int rb=0;
        for(int i=0;i<n;i++)
        {
            rb=((rb*10)+(sf[i]-48))%(m-1);
        }

        printf("%lld %lld\n",rb,fibo(rb));
    }
}