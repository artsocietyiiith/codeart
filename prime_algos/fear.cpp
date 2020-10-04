#include <bits/stdc++.h>
using namespace std;

bool p[1000006];
vector <int> prime;
vector <int> fear;

int main()
{
    long long int n=1000000;
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
    for(int i=0;i<prime.size();i++)
    {
        int pc=prime[i];
        long long int ten=10;
        int f=1;
        while(pc/ten)
        {
            if((pc/ten)%10==0)
            {
                f=0;
            }
            ten*=10;
        }
        pc=prime[i];
        while(ten>1 and f)
        {
            if(!binary_search(prime.begin(),prime.end(),pc%ten))
            {
                f=0;
            }  
            ten/=10;
            pc%=ten;
        }
        if(f)
        {
            fear.push_back(prime[i]);
        }
    }
    // printf("%d\n",fear.size());
    // for(int i=0;i<101;i++)
    // {
    //     printf("%d\n",fear[i]);
    // }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",upper_bound(fear.begin(),fear.end(),n)-fear.begin());
    }
}