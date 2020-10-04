#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int a,b;
        scanf("%lld %lld",&a,&b);
        if(b==0)
        {
            printf("1\n");
            continue;
        }
        a%=10;
        b%=4;
        if(b==0)
            b=4;
        int ans=a;
        for(int i=1;i<b;i++)
        {
            ans*=a;
        }
        printf("%d\n",ans%10);
    }
}

