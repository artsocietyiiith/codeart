#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    // scanf("%d",&t);
    while (1)
    {
        long long int x,y,n;
        scanf("%lld %lld %lld",&x,&y,&n);
        if(x==0)
        {
            break;
        }
        long long int ans=1;
        while(y)
        {
            if(y%2)
            {
                ans=(ans*x)%n;
            }
            x=(x*x)%n;
            y/=2;

        }
        printf("%lld\n",ans);    
    }
    // scanf("%d",&t);
}