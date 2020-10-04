def po(x,y,m):
    a=1
    x%=m
    while y:
        if y%2:
            a=(a*x)%m
        x=(x*x)%m
        y//=2
    return a    


p=[]
for i in range(0,100000):
    p.append(0)

prime=[]
n=100000

for i in range(2,100000):
    if p[i]==0:
        prime.append(i)
        j=i*i
        while j<n:
            p[j]=1
            j+=i

test=int(input())
for t in range(0,test):
    l,r=[int(i) for i in input().split(' ')]
    pp=[]
    plr=[]
    for i in range(0,r-l+1):
        pp.append(0)
    i=0
    while(prime[i]*prime[i]<=r):
        j=(l//prime[i])*prime[i]
        while(j<=r):
            if j<l or j==prime[i]:
                j+=prime[i]
                continue
            pp[j-l]=1
            j+=prime[i]
        i+=1
    for i in range(0,r-l+1):
        if pp[i]==0:
            plr.append(i+l)
    i=r+1
    while(1):
        f=1
        j=0
        while(prime[j]*prime[j]<=i):
            if i%prime[j]==0:
                f=0
                break
            j+=1
        if f:
            plr.append(i)
            break
        i+=1
    a=0
    for i in range(1,len(plr)):
        ten=10
        while(plr[i-1]//ten):
            ten*=10
        bt=((plr[i]-plr[i-1])*po(ten,plr[i]-2,plr[i]))%plr[i]
        a+=((bt*ten)+plr[i-1])
    print(a)