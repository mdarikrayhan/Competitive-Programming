R=lambda:map(int,input().split())
t,=R()
exec(t*'a,b,n=R();print(b+sum(min(x,a-1)for x in R()));')