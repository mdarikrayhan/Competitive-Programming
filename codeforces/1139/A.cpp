#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int digit = s[i] - '0';
        if (digit % 2 == 0) ans += (i + 1);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}