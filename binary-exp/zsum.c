#include <stdio.h>

long long int m=10000007;

long long int pp(long long int x,long long int y)
{
    long long int ans=1;
    while(y)
    {
        if(y%2==1)
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
        long long int n,k;
        scanf("%lld %lld",&n,&k);
        if(n+k==0)
        {
            break;
        }
        printf("%lld\n",(pp(n,k)+2*pp(n-1,k)+pp(n,n)+2*pp(n-1,n-1))%m);
    }
}