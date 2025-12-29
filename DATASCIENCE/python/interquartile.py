import math

p=1.09/2.09
q=1-p
n=6
r=3
def binomialfunc(n,r):
    return math.comb(n,r)*p**n*q**(n-r)
res=[]
for i in range(r,n):
    res.append(binomialfunc(n,i))
print(round(sum(res),3))
    