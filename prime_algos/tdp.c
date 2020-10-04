#include <stdio.h>
#include <stdbool.h>

bool p[100000008];

int main()
{
    long long int n=100000000;
    long long int c=0;
    long long int i=2;
    for(;i<n;i++)
    {
        if(p[i]==0)
        {
            c++;
            if(c%100==1)
            {
                printf("%lld\n",i);
            }
            for(long long int j=i*i;j<=n;j+=i)
            {
                p[j]=1;
            }
        }
    }
}
