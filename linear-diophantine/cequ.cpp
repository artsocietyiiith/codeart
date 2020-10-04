#include <stdio.h>

int gcd(int a,int b)
{
    if(a==0)
    {
        return b;
    }
    return gcd(b%a,a);
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(c%gcd(a,b))
        {
            printf("Case %d: No\n",i);
        }
        else
        {
            printf("Case %d: Yes\n",i);
        }
    }
}