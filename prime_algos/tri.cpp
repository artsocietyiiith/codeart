#include <bits/stdc++.h>
using namespace std;

bool p[100000008];
vector <long long int> prime;
vector <pair <int,int> > cod;

int main()
{
    long long int n=100000000;
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
    long long int c=0;
    for(int i=1;c<prime.size();i++)
    {
        for(int j=1;j<=i && c<prime.size();j++)
        {
            cod.push_back(make_pair(i,j));
            c++;
        }
    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int a;
        scanf("%lld",&a);
        if(!binary_search(prime.begin(),prime.end(),a))
        {
            printf("-1\n");
            continue;
        }
        long long int idx=upper_bound(prime.begin(),prime.end(),a)-prime.begin()-1;
        printf("%d %d\n",cod[idx].first,cod[idx].second);
    }

}