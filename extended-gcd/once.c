#include <stdio.h>
#include <math.h>

long long int min(long long int a,long long int b)
{
    if(a<b)
    {
        return a;
    }
    else
    {
        return b;
    }
}


long long int max(long long int a,long long int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}


long long int gcd(long long int a,long long int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}

long long int inv(long long int a,long long int b,long long int *x,long long int *y)
{
    if(b==0)
    {
        *x=1;
        *y=0;
        return a;
    }
    long long int x1,y1;
    long long int d= inv(b,a%b,&x1,&y1);
    *x=y1;
    *y=x1-y1*(a/b);
    return d;
}


int main()
{
    while(1)
    {
        long long int a1,a2,b1,b2;
        scanf("%lld %lld %lld %lld",&a1,&b1,&a2,&b2);
        if(a1+a2+b1+b2==0)
        {
            break;
        }
        long long int c=a2-a1;
        long long int x,y;
        long long int g=inv(b1,b2,&x,&y);
        if(c%g!=0)
        {
            printf("Impossible\n");
            continue;
        }
        y*=-1;
        //x=(c/g)*(x+k*b2/g)>0;
        //y=(c/g)*(y+k*b1/g)>=0;
        long long int big=1000000000000000000;
        long long int mink=-big;
        long long int maxk=big;
        //x = (c/g)*(x+k*b2/g)>0;
        printf("x=%lld y=%lld\n",x,y);
        if(c>0)
        {
            mink = -x/b2 + 1;
        }
        else if(c<0)
        {
            if(x%b2)
            {
                maxk= -x/b2;
            }
            else
            {
                maxk = -x/b2 -1;
            }
        }
        //y = (c/g)*(y+k*b1/g)>=0;
        if(c>0)
        {
            if(y%b1)
            {
                mink = max(mink,-y/b1 + 1);
            }
            else
            {
                mink = max(mink,-y/b1);
            }
        }
        else
        {
            maxk = min(maxk,-y/b1);
        }
        printf("mink=%lld maxk=%lld\n",mink,maxk);
        long long int k;
        if(mink==-big)
        {
            k=maxk;
        }
        else if (maxk==big)
        {
            k=mink;
        }
        else if (mink<=maxk)
        {
            int cc;
        }
        else
        {
            printf("Impossible\n");
            continue;
        }
        printf("%lld %lld\n",a1+b1*((c/g)*(x + k*b2/g)),a2+b2*((c/g)*(y + k*b1/g)));
    }
}