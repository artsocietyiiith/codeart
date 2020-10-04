#include <stdio.h>
#include <stdlib.h>


long long int flor(double a,double b)
{
    if((long long int)a%(long long int)b==0)
    {
        return (int)(a/b);
    }
    else
    {
        if(a/b >=0)
        {
            return (int)(a/b);
        }
        else
        {
            return (int)(a/b)-1;
        }
    }

}

long long int cil(double a,double b)
{
    if((long long int)a%(long long int)b==0)
    {
        return (int)(a/b);
    }
    else
    {
        if(a/b >=0)
        {
            return (int)(a/b)+1;
        }
        else
        {
            return (int)(a/b);
        }
    }

}


long long int min(long long int a,long long int b)
{
    if(a>b)
    {
        return b;
    }
    else
    {
        return a;
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



long long int gcd(long long int a,long long int b,long long int *x,long long int *y)
{
    if(b==0)
    {
        *y=0;
        *x=1;
        return a;
    }
    long long int x1,y1;
    long long int g=gcd(b,a%b,&x1,&y1);
    *x=y1;
    *y=x1-y1*(a/b);
    return g;
}


int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        long long int a,b,c,x1,x2,y1,y2;
        scanf("%lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&x1,&x2,&y1,&y2);
        long long int x,y;
        long long int g=gcd(a,b,&x,&y);
        printf("Case %d:",i); 
        if(a==0 && b!=0)
        {
            if(c%b)
            {
                printf("0\n");
            }
            else
            {
                if(-c/b>=y1 && -c/b<=y2)
                {
                    printf("%lld\n",x2-x1+1);
                }
                else
                {
                    printf("0\n");
                }
            }
            continue;
        }
        if(b==0 && a!=0)
        {
            if(c%a)
            {
                printf("0\n");
            }
            else
            {
                if(-c/a>=x1 && -c/a<=x2)
                {
                    printf("%lld\n",y2-y1+1);
                }
                else
                {
                    printf("0\n");
                }
            }
            continue;
        }
        if(a==0 && b==0)
        {
            if(c==0)
            {
                printf("%lld\n",(y2-y1+1)*(x2-x1+1));
            }
            else
            {
                printf("0\n");
            }
            continue;
        }
        if(c==0)
        {
            
        }
        if(c%g)
        {
            printf("0\n");
            continue;
        }
        x*=(a/abs(a))*(-c/g);
        y*=(b/abs(b))*(-c/g);
        long long int ak= b/g,bk=a/g;
        long long int minkx,maxkx;
        if(ak>0)
        {
            minkx=cil((double)(x1-x),(double)(ak));
            maxkx=flor((double)(x2-x),(double)(ak));
        }
        else if(ak<0)
        {
            minkx=cil((double)(x2-x),(double)(ak));
            maxkx=flor((double)(x1-x),(double)(ak));
        }
        long long int minky,maxky;
        if(bk>0)
        {
            minky=cil((double)(y-y2),(double)(bk));
            maxky=(long long int)flor((double)(y-y1),(double)(bk));
        }
        else if(bk<0)
        {
            maxky=flor((double)(y-y2),(double)(bk));
            minky=cil((double)(y-y1),(double)(bk));
        }
        long long int mink=max(minkx,minky),maxk=min(maxkx,maxky);
        if(minkx>maxkx || minky>maxky || mink>maxk)
        {
            printf("0\n");
        }
        else
        {
            printf("%lld\n",maxk-mink+1);
        }
    }
}