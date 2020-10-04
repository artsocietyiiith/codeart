#include <bits/stdc++.h>
using namespace std;

long long int relu(long long int a)
{
    if(a<0)
    {
        return 0;
    }
    else
    {
        return a;
    }
}

bool p[100005];
vector <long long int> prime;

int main()
{
    int n=100000;
    for(long long int i=2;i<n;i++)
    {
        if(!p[i])
        {
            prime.push_back(i*i);
            for(long long int j=i*i;j<n;j+=i)
            {
                p[j]=1;
            }
        }
    }
    int t;
    scanf("%d",&t);
    while (t--)
    {
        long long int n,k;
        scanf("%lld %lld",&n,&k);
        long long int tot=upper_bound(prime.begin(),prime.end(),n)-prime.begin();
        long long int kk=upper_bound(prime.begin(),prime.end(),k)-prime.begin();
        printf("%lld %lld\n",tot,relu(tot-kk));
    }

}