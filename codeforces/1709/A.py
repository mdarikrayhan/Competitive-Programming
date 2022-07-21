for _ in range (int (input ())):
    p=int (input())
    arik=list (map(int, input ().split ()))
    e=arik[p-1]
    x=0
    while(e!=0):
        e=arik[e-1]
        x+=1
    if x==2:
        print("YES")
    else:
        print("NO")