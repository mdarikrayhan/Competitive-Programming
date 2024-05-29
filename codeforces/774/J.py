n, k = map(int, input().split())
s = input()

cnt, mx = 0, 0

for i in range(n):
    if s[i] == "N":
        cnt += 1
    else:
        cnt = 0
    mx = max(mx, cnt)
    
if mx > k:
    print("NO\n")
    exit()

for r in range(k, n + 1):
    l = r - k
    if l > 0 and s[l - 1] == "N":
        continue
    if r < n and s[r] == "N":
        continue
    
    bad = False
    
    for i in range(l, r):
        if s[i] == "Y":
            bad = True
            break
        
    if not bad:
        print("YES\n")
        exit()

print("NO\n")
