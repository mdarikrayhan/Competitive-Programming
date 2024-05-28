#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

void __MAIN__ () {
    ll n, m, k, l, r, sum, ans = 0; cin >> n >> m >> k;
    vector <string> a(n);
    vector <ll> p(26);
    vector < vector <ll> > s(n + 2, vector <ll> (m + 2));
    for (ll x = 0; x < n; x++) {
        cin >> a[x];
        for (ll y = 0; y < m; y++)
            s[x + 1][y] = s[x][y] + (a[x][y] == 'a');
    }
    for (ll x = 0; x < n; x++)
        for (ll y = x + 1; y < n; y++) {
            for (auto &e : p) e = 0;
            l = r = sum = 0;
            while (r < m) {
                while (r < m && a[x][r] != a[y][r]) {
                    sum += s[y + 1][r] - s[x][r];
                    r++;
                }
                if (r == m) break;
                sum += s[y + 1][r] - s[x][r];
                r++;
                while (sum > k) {
                    sum -= s[y + 1][l] - s[x][l];
                    if (a[x][l] == a[y][l]) p[a[x][l] - 'a']--;
                    l++;
                }
                if (l < r) ans += p[a[x][r - 1] - 'a'];
                p[a[x][r - 1] - 'a']++;
            }
        }
    cout << ans << "\n";
}

int main () {
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll __T__ = 1; //cin >> __T__;
    while (__T__--) __MAIN__();
    return 0;
}