#include <bits/stdc++.h>
using namespace std;

long long int p[1000000];
vector <long long int> prime;
long long int nf[11][400000];


int main()
{
    long long int nfs[11];
    for(long long int i=0;i<11;i++)
    {
        nfs[i]=0;
    }
    long long int n=1000000;
    for(long long int i=2;i<n;i++)
    {
        if(p[i]==0)
        {
            prime.push_back(i);
            for(long long int j=i;j<n;j+=i)
            {
                p[j]+=1;
            }
        }
    }
    // for(int i=0;i<50;i++)
    // {
    //     printf("%d->%d\n",i,p[i]);
    // }
    // printf("Yo\n");
    for(long long int i=1;i<=n;i++)
    {
        if(p[i]>10)
        {
            continue;
        }
        nf[p[i]][nfs[p[i]]]=i;
        nfs[p[i]]++;
    }
    // for(int i=0;i<11;i++)
    // {
    //     printf("%d->%d\n",i,nfs[i]);
    // }
    // for(int i=0;i<11;i++)
    // {
    //     for(int j=0;j<20;j++)
    //     {
    //         printf("%d->",nf[i][j]);
    //     }
    //     printf("\n");   
    // }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int a,b,m;
        a=0;
        b=0;
        m=0;
        scanf("%lld %lld %lld",&a,&b,&m);
        if(binary_search(&nf[m][0],&nf[m][0]+nfs[m],a))
        {
            printf("%lld\n",(upper_bound(&nf[m][0],&nf[m][0]+nfs[m],b)-upper_bound(&nf[m][0],&nf[m][0]+nfs[m],a))+1);
        }
        else    
        {
            printf("%lld\n",(upper_bound(&nf[m][0],&nf[m][0]+nfs[m],b)-upper_bound(&nf[m][0],&nf[m][0]+nfs[m],a)));
        }
    }
}