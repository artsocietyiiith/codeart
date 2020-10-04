#include <bits/stdc++.h>
using namespace std;

vector <long long int> s;
bool p[102000000];


int main()
{
    long long int n=102000000;
    long long int c=0;
    s.push_back(0);
    long long int sum=0;
    for(long long int i=2;i<n;i++)
    {
        if(p[i]==0)
        {
            long long int num=i;
            vector <int> bi;
            while(num)
            {
                bi.push_back(num%2);
                num/=2;
            }
            // for(long long int j=bi.size()-1;j>=0;j--)
            // {
            //     sum+=bi[j];
            //     s.push_back(sum);
            // }
            for(long long int j=i*i;j<n;j+=i)
            {
                p[j]=1;
            }
        }
    }
    // printf("%lld\n",s.size());
    // int t;
    // // printf("yo\n");
    // scanf("%d",&t);
    // while(t--)
    // {
    //     scanf("%lld",&n);
    //     printf("%lld\n",s[n]);
    // }
}