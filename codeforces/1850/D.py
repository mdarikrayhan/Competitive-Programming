R=lambda:map(int,input().split())
t,=R()
exec(t*"n,k=R();a=sorted(R());print(n-max(0,0,*map(len,''.join('* '[y-x>k]for x,y in zip(a,a[1:])).split()))-1);")