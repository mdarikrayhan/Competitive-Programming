from bisect import bisect_left

t = int(input())
for _ in range(t):
    n = int(input())
    a = [0] + list(map(int, input().split()))
    v = [0] + list(map(int, input().split()))
    c = v.copy()

    for i in range(1, n+1):
        v[i] += v[i-1]

    f = [0] * (n+1)
    ans = [0] * (n+1)

    for i in range(1, n+1):
        tar = a[i] + v[i-1]
        if v[n] <= tar:
            f[n] += 1
            f[i-1] -= 1
        else:
            ind = bisect_left(v, tar)
            if ind >= i:
                f[ind-1] += 1
                f[i-1] -= 1
                ans[ind] += tar - v[ind-1]
            else:
                ans[i] += tar - v[i-1]

    for i in range(n-1, -1, -1):
        f[i] += f[i+1]

    for i in range(1, n+1):
        ans[i] += c[i] * f[i]
        print(ans[i], end=" ")
    print()
