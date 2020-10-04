#include <bits/stdc++.h>
using namespace std;

long long int m=1000000007;

long long int pp(long long int x,long long int y)
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
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n;
        scanf("%lld",&n);
        if(n<2)
        {
            printf("1\n");
        }
        else if(n==2)
        {
            printf("2\n");
        }
        else
        {
            long long int o=pp(3,n/3-1);
            if(n%3==1)
            {
                o=(o*4)%m;
            }
            else if(n%3==2)
            {
                o=(o*6)%m;
            }
            else
            {
                o=(o*3)%m;
            }
                printf("%lld\n",o);
        }
    }
}