R=lambda:[*map(int,input().split())]
exec(R()[0]*'n,=R();a=R();b=R();print(min(sum(a)+n*min(b),sum(b)+n*min(a)));')