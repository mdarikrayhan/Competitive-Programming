from collections import defaultdict

T = int(input())

for _ in range(T):
    n, k = map(int, input().split())
    s = input().strip()
    
    map1 = defaultdict(int)
    map2 = defaultdict(int)
    arik = 0
    
    for x in s:
        if x.isupper():
            map1[x] += 1
        else:
            map2[x] += 1
    
    for x in map1:
        c = x.lower()
        while map2.get(c, 0) > 0 and map1[x] > 0:
            arik += 1
            map2[c] -= 1
            map1[x] -= 1
        while map1[x] >= 2 and k > 0:
            k -= 1
            arik += 1
            map1[x] -= 2
    
    for x in map2:
        while map2[x] >= 2 and k > 0:
            k -= 1
            arik += 1
            map2[x] -= 2
    
    print(arik)
