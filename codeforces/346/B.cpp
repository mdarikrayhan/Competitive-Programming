#include<bits/stdc++.h>
using namespace std;
int n, m, k, i, len, f[101], dp[101][101][101];  string a, b, c, ans;

void build(){
    len = f[0] = 0;
    for (i = 1; i < k; i++){
        while (len && c[i] != c[len]) len = f[len - 1];
        if (c[i] == c[len]) len++;
        f[i] = len;
    }
}

int calc(int ix, int jx, int len){
    if (ix >= n || jx >= m) return 0;
    int &ret = dp[ix][jx][len];
    if (~ret) return ret;
    ret = max(calc(ix + 1, jx, len), calc(ix, jx + 1, len));
    if (a[ix] == b[jx]){
        while (len && a[ix] != c[len]) len = f[len - 1];
        if (a[ix] == c[len]) len++;
        if (len < k) ret = max(ret, 1 + calc(ix + 1, jx + 1, len));
    }
    return ret;
}

void path(int ix, int jx, int len){
    if (ix >= n || jx >= m) return;
    if (dp[ix][jx][len] == calc(ix + 1, jx, len)) path(ix + 1, jx, len);
    else if (dp[ix][jx][len] == calc(ix, jx + 1, len)) path(ix, jx + 1, len);
    else {
        while (len && a[ix] != c[len]) len = f[len - 1];
        if (a[ix] == c[len]) len++;
        if (len < k) ans += a[ix], path(ix + 1, jx + 1, len);
    }
}

int main()
{
    cin >> a >> b >> c;  ans = "";
    n = a.size(), m = b.size(), k = c.size();
    memset(dp, -1, sizeof dp);
    build(), calc(0, 0, 0), path(0, 0, 0);
    return cout << (ans.size() ? ans : "0"), 0;
}