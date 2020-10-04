#include <bits/stdc++.h>
using namespace std;

bool p[2000];
vector <int> prime;
vector <int> nold;


int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=2;i<2000;i++)
    {
        if(p[i]==0)
        {
            prime.push_back(i);
            for(int j=i*i;j<2000;j+=i)
            {
                p[j]=1;
            }
        }
    }
    int c=0;
    for(int i=0;prime[i]+prime[i+1]+1<=n;i++)
    {
        if(binary_search(prime.begin(),prime.end(),prime[i]+prime[i+1]+1))
        {
            c++;
        }
    }
    if(c<k)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }
}