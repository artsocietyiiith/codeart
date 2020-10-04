#include <bits/stdc++.h>
using namespace std;

bool p[1000006];

int main()
{
    long long int n;
    scanf("%lld",&n);
    for(long long int i=2;i<=n+1;i++)
    {
        if(p[i]==0)
        {
            for(long long int j=i*i;j<=n+1;j+=i)
            {
                p[j]=1;
            }
        }
    }
    if(n<3)
    {
        printf("1\n");
    }
    else
    {
        printf("2\n");
    }
    for(int i=2;i<=n+1;i++)
    {
        printf("%d ",int(p[i])+1);
    }
    printf("\n");
}