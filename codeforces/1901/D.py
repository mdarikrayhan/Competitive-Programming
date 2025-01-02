n=int(input())
arr = list(map(int, input().split()))
a = [0]*n
b = [0]*n
for i in range(1,n):
    a[i] = max(a[i-1], arr[i-1] + n - i)
    b[n-i-1] = max(b[n-i], arr[n-i] + n - i)
print(min(max(arr[i],a[i],b[i]) for i in range(n)))