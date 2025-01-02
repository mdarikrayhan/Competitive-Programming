// LUOGU_RID: 160155785
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define N 400'005
#define endl '\n'
int n, ans = 0, a[N];
int b[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 24; i >= 0; i--) {
        for (int j = 1; j <= n; j++)
            b[j] = a[j] % (1 << (i + 1));
        int sum = 0;
        sort(b + 1, b + 1 + n);
        for (int j = 1; j <= n; j++) {
            int pos1 = lower_bound(b + 1 + j, b + 1 + n, (1 << i) - b[j]) - b;
            int pos2 = upper_bound(b + 1 + j, b + 1 + n, (1 << (i + 1)) - 1 - b[j]) - b;
            // cout <<(1 << i) - b[j]<<' '<< pos1 <<':'<<(1 << (i + 1)) - 1 - b[j]<< ' ' << pos2 << endl;
            sum += pos2 - pos1;
            pos1 = lower_bound(b + 1 + j, b + 1 + n, (1 << (i + 1)) + (1 << i) - b[j]) - b;
            //cout << pos1 << endl;
            sum += n - pos1 + 1;
        }
        if (sum % 2 == 1)
            ans |= (1 << i);
    }
    cout << ans;
}

signed main() {
    int t = 1;
    // cin >> t;
    // cout<<__lg((int)1e7);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (t--)
        solve();
    return 0;
}
