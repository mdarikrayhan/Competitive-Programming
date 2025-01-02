// LUOGU_RID: 160498612
#include <bits/stdc++.h>
#define int long long
using namespace std;
char c[10000001];
int s1[10000001], s2[10000001];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, l, r;
    cin >> n >> m >> c[1];
    for (int i = 2; i <= n; i++) {
        cin >> c[i];
        s1[i] = s1[i - 1], s2[i] = s2[i - 1];
        if (c[i] != c[i - 1])
            continue;
        if (c[i] == '1')
            s1[i]++;
        else
            s2[i]++;
    }
    while (m--) {
        cin >> l >> r;
        cout << max(s1[r] - s1[l], s2[r] - s2[l]) + 1 << '\n';
    }
    return 0;
}