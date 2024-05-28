// LUOGU_RID: 159708704
//私は猫です
#include <bits/stdc++.h>
using namespace std;
// #define int long long
int read(){
    int xx = 0, f = 1; char ch = getchar();
    for (;!isdigit(ch); ch = getchar())
        f = (ch == '-' ? -1 : 1);
    for (; isdigit(ch); ch = getchar())
        xx = (xx << 3) + (xx << 1) + ch - '0';
    return xx * f;
}
const int N = 300100;
int n, a[N], f[N];
bool check(int m, int mid){
    if (n - mid + 1 >= m){
        if (n - mid - m + 1 + mid >= a[mid])return true;
        else return false;
    }
    if (mid <= a[mid])return false;
    if (f[mid - a[mid]] + 1 + n - mid >= m)return true;
    return false;
}
signed main(){
    n = read(); for (int i = 1; i <= n; ++i)a[i] = read();
    sort(a + 1, a + n + 1); f[0] = 0;
    for (int i = 1; i <= n; ++i)if (a[i] <= i)
        f[i] = max(f[i - 1], f[i - a[i]] + 1);
    else f[i] = f[i - 1];
    int q = read();
    for (int i = 1, m, l, r, mid; i <= q; ++i){
        m = read(); l = 0, r = n;
        while(l < r){
            mid = (l + r + 1) >> 1;
            if (check(m, mid))l = mid;
            else r = mid - 1;
        }
        printf("%d\n", l);
    }
    return 0;
}

