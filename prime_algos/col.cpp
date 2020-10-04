#include <bits/stdc++.h>
using namespace std;

bool p[100001];
vector <int> prime;
vector <int> nold;
bool c[100001];
int con[100001];
bool nn[100001];

int main()
{
    for(long long int i=2;i<100001;i++)
    {
        if(p[i]==0)
        {
            prime.push_back(i);
            for(long long int j=i*i;j<100001;j+=i)
            {
                p[j]=1;
            }
        }
    }
    int n,m;
    scanf("%d %d",&n,&m);
    while(m--)
    {
        char as,nl;
        int a;
        scanf("%c",&nl);
        scanf("%c %d",&as,&a);
        if(as=='-')
        {
            if(nn[a])
            {
                vector <int> pf;
                int num=a;
                for(int i=0;prime[i]*prime[i]<=a;i++)
                {
                    if(num%prime[i]==0)
                    {
                        pf.push_back(prime[i]);
                        while(num%prime[i]==0)
                        {
                            num/=prime[i];
                        }
                    }
                }
                if(num!=1)
                {
                    pf.push_back(num);
                }
                for(int i=0;i<pf.size();i++)
                {
                    c[pf[i]]=0;
                    con[pf[i]]=0;
                }
                nn[a]=0;
                printf("Success\n");
            }
            else
            {
                printf("Already off\n");
            }
        }
        else
        {
            if(nn[a])
            {
                printf("Already on\n");
            }
            else
            {
                vector <int> pf;
                int num=a;
                for(int i=0;prime[i]*prime[i]<=a;i++)
                {
                    if(num%prime[i]==0)
                    {
                        pf.push_back(prime[i]);
                        while(num%prime[i]==0)
                        {
                            num/=prime[i];
                        }
                    }
                }
                if(num!=1)
                {
                    pf.push_back(num);
                }
                int f=1;
                for(int i=0;i<pf.size();i++)
                {
                    if(c[pf[i]])
                    {
                        f=0;
                        printf("Conflict with %d\n",con[pf[i]]);
                        break;
                    }
                }
                if(f)
                {
                    for(int i=0;i<pf.size();i++)
                    {
                        c[pf[i]]=1;
                        con[pf[i]]=a;
                    }
                    nn[a]=1;
                    printf("Success\n");    
                }
            }
        }
    }
}