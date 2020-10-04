#include <bits/stdc++.h>
using namespace std;

bool p[10000007];
vector <long long int> prime;
vector <long long int> paul;
vector <long long int> paul2;

int main()
{
    long long int n=10000000;
    for(long long int i=2;i<n;i++)
    {
        if(p[i]==0)
        {
            prime.push_back(i);
            for(long long int j=i*i;j<n;j+=i)
            {
                p[j]=1;
            }
        }
    }
    for(int i=0;i*i<=n;i++)
    {
        for(int j=0;j*j*j*j<=n;j++)
        {
            long long int xy=(i*i)+(j*j*j*j);
            if(binary_search(prime.begin(),prime.end(),xy) && xy<n)
            {
                paul.push_back(xy);
            }
        }
    }
    sort(paul.begin(),paul.end());
    paul2.push_back(paul[0]);
    for(int i=1;i<paul.size();i++)
    {
        if(paul[i]!=paul[i-1])
        {
            paul2.push_back(paul[i]);
        }
    }
    // printf("%d %d\n",prime.size(),paul2.size());
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",upper_bound(paul2.begin(),paul2.end(),n)-paul2.begin());
    }
}