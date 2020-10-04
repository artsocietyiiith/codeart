#include <bits/stdc++.h>
using namespace std;

bool p[100000];
vector <unsigned long long int> prime;

unsigned long long int po(unsigned long long int x,unsigned long long int y,unsigned long long int m)
{
    unsigned long long int a=1;
    x%=m;
    while(y)
    {
        if(y%2)
        {
            a=(a*x)%m;
        }
        x=(x*x)%m;
        y/=2;
    }
    return a;
}

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
    unsigned long long int n=100000;
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
            for(long long int j=l/prime[i]*prime[i];j<=r;j+=prime[i])
            {
                if(j<l or j==prime[i])
                {
                    continue;
                }
                pp[j-l]=1;
            }
        }
        for(int i=0;i<r-l+1;i++)
        {
            if(pp[i]==0)
            {
                plr.push_back(i+l);
            }
        }
        for(unsigned long long int i=r+1;;i++)
        {
            int f=1;
            for(unsigned long long int j=0;prime[j]*prime[j]<=i;j++)
            {
                if(i%prime[j]==0)
                {
                    f=0;
                    break;
                }
            }
            if(f)
            {
                // printf("p->%lld\n",i);
                plr.push_back(i);
                break;
            }
        }
        // for(int i=0;i<plr.size();i++)
        // {
        //     printf("p->%lld\n",plr[i]);
        // }
        long long int a=0;
        for(int i=1;i<plr.size();i++)
        {
            unsigned long long int ten=10;
            while(plr[i-1]/ten)
            {
                ten*=10;
            }
            unsigned long long int bt=((plr[i]-plr[i-1])*po(ten,plr[i]-2,plr[i]))%plr[i];
            a+=(bt*ten+plr[i-1]); 
            printf("%lld %lld\n",po(ten,plr[i]-2,plr[i]),(bt*ten+plr[i-1]));
            if(a<0)
            {
                while(2)
                {
                    int aa=1;
                }
            }    
        }
        printf("%lld\n",a);
    }
}