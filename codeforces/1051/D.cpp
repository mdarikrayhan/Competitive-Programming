#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5, MOD = 998244353;
int n, k, mem[N][2 * N][4];

int solve(int i, int cnt, int msk) {
    if (i == n) return cnt == k;

    int& r = mem[i][cnt][msk];
    if (~r) return r;

    r = 0;
    for (int m = 0; m < 4; ++m) {
        int x = 0;
        if (msk == 0 || msk == 3) x += msk != m;
        else if ((msk ^ m) == 3) x += 2;
        r = (r + solve(i + 1, cnt + x, m)) % MOD;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    cin >> n >> k;
    memset(mem, -1, sizeof mem);
    int ans = 0;
    for (int msk = 0; msk < 4; ++msk) {
        ans = (ans + solve(1, 1 + (msk == 1 || msk == 2), msk)) % MOD;
    }
    cout << ans;
    return 0;
}
