import math

def inv(a, b): 
	if b == 0 : 
		return a,1,0
			
	gcd,x1,y1 = inv(b, a%b) 
	y = x1 - (a//b) * y1 
	x = y1 	
	return gcd,x,y 

while(1):
    inp = input().split(' ')
    a1=int(inp[0])
    b1=int(inp[1])
    a2=int(inp[2])
    b2=int(inp[3])
    if a1+a2+b2+b1 == 0:
        break
    c=a2-a1
    if(b1==0 and b2):
        if((a1-a2) %b2 ):
            print("Impossible")
        else:
            if((a1-a2)/b2 >=0):
                print(a1)
            else:
                print("Impossible")
        continue
    elif(b2==0 and b1):
        if((a2-a1) %b1 ):
            print("Impossible");
        else:
            if((a2-a1)/b1 >0):
                print(a2)
            else:
                print("Impossible")
        continue
    elif(b2+b1 == 0):
        if a1 == a2:
            print(a1)
        else:
            print("Impossible")
        continue
    g,x,y=inv(b1,b2)
    if(c%g):
        print("Impossible")
        continue
    y*=-1
    # print(g,x,y)
    big=1000000000000000000
    mink=-big
    maxk=big
    x*=(c/g)
    y*=(c/g)

    '''
    mink = math.floor(-x*g/b2) + 1
    if y*g%b1:
        mink = max(mink,math.floor(-y*g/b1)+1)
    else:
        mink = max(mink,math.floor(-y*g/b1))
    '''
    mink = math.floor(-y*g/b1) + 1
    if x*g%b2:
        mink = max(mink,math.floor(-x*g/b2)+1)
    else:
        mink = max(mink,math.floor(-x*g/b2))
       
    # print(x,y)
    # print(mink,x+mink*b2/g,y+mink*b1/g)
    print(int(a1+b1*(x + mink*b2/g)))



    '''
    # x = (c/g)*(x+k*b2/g)>0;
    if c>0:
        mink = int(-x/b2) + 1
        if y%b1:
            mink = max(mink,int(-y/b1)+1)
        else:
            mink = max(mink,int(-y/b1))
        #print(mink,((c/g)*(x + mink*b2/g)),((c/g)*(y + mink*b1/g)))
       # print(a1+b1*((c/g)*(x + mink*b2/g)),a2+b2*((c/g)*(y + mink*b1/g)))
        print(int(a1+b1*((c/g)*(x + mink*b2/g))))
    elif c<0:
        if(x%b2):
            maxk = math.floor(-x/b2)
        else:
            maxk = int(-x/b2) -1
        maxk = min(maxk,math.ceil(-y/b1))
       # print(maxk,((c/g)*(x + maxk*b2/g)),((c/g)*(y + maxk*b1/g)))
       # print(a1+b1*((c/g)*(x + maxk*b2/g)),a2+b2*((c/g)*(y + maxk*b1/g)))
        print(int(a1+b1*((c/g)*(x + maxk*b2/g))))
    '''