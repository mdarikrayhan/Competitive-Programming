import math
import sys
import random
def calculate_ans(n):
    ans=[]
    n=n-1
    temp=1
    tempval=0
    while n>=temp:
        n-=temp
        temp*=2
        ans.append(tempval)
        tempval+=1
    
    tempval=len(ans)-1
    while n!=0:
        x=2**tempval
        if n>=x:
            ans.append(tempval)
            n-=x
        tempval-=1
    
    return ans

for tempval in range(int(input())):
    n = int(input())
    ans = calculate_ans(n)
    
    print(len(ans))
    for tempval in ans:
        print(tempval, end=' ')
    print()