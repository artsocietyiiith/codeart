#include <bits/stdc++.h>
using namespace std;

bool p[5300000];
vector <long long int> prime;
vector <long long int> a;

int main()
{
    long long int n=5300000;
    for(long long int i=2;i<n;i++)
    {
        if(!p[i])
        {
            prime.push_back(i);
            for(long long int j=i*i;j<n;j+=i)
            {
                p[j]=1;
            }
        }
    }
    // printf("%lld\n",prime.size());
    long long int bound=10527485;
    // long long int bound=prime[2001]*prime[2002];
    // printf("%lld\n",prime[prime.size()-1]);
    // printf("%lld\n",bound);
    for(int i=0;i<=2001;i++)
    {
        for(int j=i+1;prime[j]*prime[i]<=bound;j++)
        {
            a.push_back(prime[j]*prime[i]);
        }
    }
    sort(a.begin(),a.end());
    // printf("%lld %lld\n",a.size(),upper_bound(a.begin(),a.end(),2000000)-a.begin());
    // printf("%lld\n",a[2000009]);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int k;
        scanf("%lld",&k);
        printf("%lld\n",a[k-1]);
    }

}