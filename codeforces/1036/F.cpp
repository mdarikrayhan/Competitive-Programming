#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

const int N = 1e6 + 7;
const ll INF = 1e18;

vector<pair<ll, ll>> v[64];
ll f[N];

ll mul(ll a, ll b) {
    if (a <= INF / b) {
        return a * b;
    } else {
        return INF + 100;
    }
}

ll binpow(ll a, int n) {
    ll r = 1;
    while (n > 0) {
        if (n & 1)
            r = mul(r, a);
        a = mul(a, a);
        n /= 2;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i < N; i++)
        f[i] = 1LL * i * i;
    for (int e = 3; e <= 63; e++) {
        for (int i = 1; i < N; i++)
            f[i] = mul(f[i], i);
        for (int i = 2; i < N; i++)
            if (f[i] <= INF)
                v[e].push_back(make_pair(i, f[i]));
    }
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> cnt(64, 0);
        for (int e = 2; e <= 63; e++) {
            int sol = 1;
            if (e == 2) {
                int l = 2, r = 1e9;
                while (l <= r) {
                    ll m = (l + r) / 2;
                    if (m * m <= n) {
                        l = m + 1;
                        sol = m;
                    } else {
                        r = m - 1;
                    }
                }
            } else {
                int l = 0, r = v[e].size() - 1;
                while (l <= r) {
                    int m = (l + r) / 2;
                    if (v[e][m].second <= n) {
                        l = m + 1;
                        sol = v[e][m].first;
                    } else {
                        r = m - 1;
                    }
                }
            }
            cnt[e] = sol - 1;
        }
        for (int e = 63; e >= 2; e--) 
            for (int i = 2 * e; i <= 63; i += e)
                cnt[e] -= cnt[i];
        n--;
        for (int e = 2; e <= 63; e++)
            n -= cnt[e];
        cout << n << "\n";
    }
    return 0;
}


