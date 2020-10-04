#include <stdio.h>

long long int pp(long long int x,long long int y,long long int m)
{
    long long int ans=1;
    while(y)
    {
        if(y%2)
        {
            ans=(ans*x)%m;
        }
        x=(x*x)%m;
        y/=2;
    }
    return ans%m;
}

int main()
{
    while(1)
    {
        long long int x,a,n,c;
        scanf("%lld %lld %lld %lld",&x,&a,&n,&c);
        if(x+a+n+c==0)
        {
            break;
        }
        long long int ans=(pp(a,n,c)*x)%c-(((pp(a,n+1,c)-1)%c)*pp(a-1,c-2,c))%c+1;
        ans%=c;
        if(ans<0)
        {
            ans+=c;
        }
        printf("%lld\n",ans%c);
    }
}