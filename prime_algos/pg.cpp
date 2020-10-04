#include <bits/stdc++.h>
using namespace std;

bool p[1000000];
vector <unsigned long long int> prime;


long long int ceil(long long int a,long long int b)
{
    if(a%b)
    {
        return (a/b)+1;
    }
    else
    {
        return a/b;
    }
} 


int main()
{
    unsigned long long int n=1000000;
    for(unsigned long long int i=2;i<n;i++)
    {
        if(p[i]==0)
        {
            prime.push_back(i);
            for(unsigned long long int j=i*i;j<n;j+=i)
            {
                p[j]=1;
            }
        }
    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        unsigned long long int r,l;
        scanf("%lld %lld",&l,&r);
        vector <unsigned long long int> plr;
        bool pp[r-l+1];
        for(int i=0;i<r-l+1;i++)
        {
            pp[i]=0;
        }
        for(int i=0;prime[i]*prime[i]<=r;i++)
        {
            for(long long int j=(l)/prime[i]*prime[i];j<=r;j+=prime[i])
            {
                if(j<l or j==prime[i])
                {
                    continue;
                }
                pp[j-l]=1;
            }
        }
        if(l==1)
        {
            pp[0]=1;
        }
        for(int i=0;i<r-l+1;i++)
        {
            if(pp[i]==0)
            {
                printf("%lld\n",(i+l));
            }
        }
        // printf("\n");
    }
}
