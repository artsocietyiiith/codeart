import numpy as np

def sum(n): 
    a=([1,1,1],[1,0,0],[0,0,1])
    t=([1,0,0],[0,1,0],[0,0,1])
    while(n):
        if(n%2):
            t=np.dot(a,t)%1000000007
        a=np.dot(a,a)%1000000007
        n=int(n/2)
    return(t[0][2])
    


t=int(input())
for test in range(0,t):
    inp=input().split(' ')
    n=int(inp[0])
    m=int(inp[1])
    if n==0:
        print(sum(m)%1000000007)
    else:
        print((sum(m)-sum(n-1))%1000000007)
