import math
ip=input().split(' ')
a=int(ip[0])
b=int(ip[1])
c=int(ip[2])

def gcd(a,b):
    if b==0:
        return a,1,0
    g,x,y=gcd(b,a%b)
    return g,y,x-y*int(a/b)

g,x,y=gcd(a,b)

if(c%g):
    print("No")
    exit()
x*=c/g
y*=c/g
# print(g,x,y)

mink=math.ceil(-x*g/b)
maxk=math.floor(y*g/a)

# print(mink,maxk)

if(mink>maxk):
    print("No")
else:
    print("Yes")
