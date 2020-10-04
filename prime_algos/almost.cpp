#include <bits/stdc++.h>
using namespace std;

bool p[3000];
vector <int> prime;

int main()
{
    for(int i=2;i<3000;i++)
    {
        if(p[i]==0)
        {
            prime.push_back(i);
            for(int j=i*i;j<3000;j+=i)
            {
                p[j]=1;
            }
        }
    }
    int n;
    scanf("%d",&n);
    int c=0;
    for(int num=1;num<=n;num++)
    {
        int d=0;
        for(int i=0;i<prime.size() && prime[i]<num;i++)
        {
            if(num%prime[i]==0)
            {
                d++;
            }
        }
        if(d==2)
        {
            c++;
        }
    }
    printf("%d\n",c);
}