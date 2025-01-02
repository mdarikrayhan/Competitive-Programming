#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define N 300100
using namespace std;
struct node{int s, i;} a[N];
typedef double db;
int l[N], r[N], n, i, j;
db ans;
int gi() {
    int s = 0; char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s;
}
bool operator < (node a, node b) {
    return a.s < b.s;
}
int main()
{
    scanf("%d", &n);
    for (i = 1; i <= n; i++) a[i].s = gi(), a[i].i = i;
    for (i = 1; i <= n; i++) l[i] = i - 1, r[i] = i + 1;
    r[n + 1] = n + 1;
    sort(a + 1, a + n + 1);
    for (i = 1; i <= n; i++) {
        int xl = a[i].i, xr = xl;
        db now = 1.0, lf = 0, rt = 0;
        for (j = 1; j <= 45; j++) {
            lf += (xl - l[xl]) / now, rt += (r[xr] - xr) / now;
            xl = l[xl], xr = r[xr], now *= 2.0;
        }
        ans += a[i].s * lf * rt / 2.0;
        l[r[a[i].i]] = l[a[i].i];
        r[l[a[i].i]] = r[a[i].i];
    }
    ans /= 1.0 * n * n;
    printf("%.8lf", ans);
    return 0;
}