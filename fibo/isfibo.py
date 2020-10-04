f=[0,1]

while(f[-1]<=4*10**16):
    f.append(f[-1]+f[-2])

test=int(input())

for t in range(0,test):
    n=int(input())
    a=0
    i=0
    while f[i]<=n and i<len(f):
        if(f[i]%2==0):
            a+=f[i]
        i+=1
    print(a)
