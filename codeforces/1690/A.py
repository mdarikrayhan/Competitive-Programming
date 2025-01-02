for _ in range(int (input())):
    b = int (input())

    t = (b-3) //3
    r = b-t
    if (r%2 == 0) :
        f = (r+2)//2
        s = b-(f+t)
    else:
        s = (r-1)//2
        f = (r+1)//2
    print(s, f, t)