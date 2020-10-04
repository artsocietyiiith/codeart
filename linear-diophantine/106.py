import math
'''
def gcd(a,b):
    if b==0:
        return a,1,0
    g,x,y = gcd(b,a%b)
    return g,y,x-y*int(a/b)
'''
def xgcd(a,b):
    prevx, x = 1, 0; prevy, y = 0, 1
    while b:
        q = int(a/b)
        x, prevx = prevx - q*x, x
        y, prevy = prevy - q*y, y
        a, b = b, a % b
    return a, prevx, prevy


tc=input()

for t in range(0,int(tc)): 
    ip=input().split(' ')
    a=int(ip[0])
    b=int(ip[1])
    c=int(ip[2])
    x1=int(ip[3])
    x2=int(ip[4])
    y1=int(ip[5])
    y2=int(ip[6])

    g,x,y=xgcd(a,b)

    print("Case "+str(t+1),end=': ')
    # print(x,y)
    if(c%g):
        print("0")
        continue

    x*=(a/abs(a))*(-c/g);
    y*=(b/abs(b))*(-c/g);

    ak=b/g
    bk=a/g    

    # print(x,y,ak,bk)

    if(ak>0):
        minkx=math.ceil((x1-x)/(ak))
        maxkx=math.floor((x2-x)/(ak))
    elif(ak<0):
        minkx=math.ceil((x2-x)/(ak))
        maxkx=math.floor((x1-x)/(ak))


    if(bk>0):
        minky=math.ceil((y-y2)/(bk))
        maxky=math.floor((y-y1)/(bk))
    elif(bk<0):
        maxky=math.floor((y-y2)/(bk))
        minky=math.ceil((y-y1)/(bk))

    # print(minkx,maxkx,minky,maxky)

    mink=max(minkx,minky)
    maxk=min(maxkx,maxky)

    if(minkx>maxkx or minky>maxky or mink>maxk):
        print("0")
    else:
        print(maxk-mink+1)


bx+c=0

