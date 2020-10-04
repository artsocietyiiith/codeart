m=1000000007

def dot(x,y):
    result = [[0, 0,],  
		    [0, 0]] 
    for i in range(len(x)): 
    	for j in range(len(y[0])): 
    		for k in range(len(y)): 
	    		result[i][j] = (result[i][j]+(x[i][k] * y[k][j])%m)%m 
    return result



def fibo(n):
    a=([1,1],[1,0])
    t=([1,0],[0,1])
    while(n):
        if(n%2):
            t=dot(a,t)
        a=dot(a,a)
        n=int(n/2)
    return(t[1][0])

n=int(input())
print(fibo(n))