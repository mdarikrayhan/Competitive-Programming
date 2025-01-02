// Author: 989
// Created: 16.05.2024 21:49:39

#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
#define str string

#define all(v)  v.begin(), v.end()
#define fi      first
#define se      second
#define pb      push_back
#define ent     cout << "\n";
#define sz(v)   ll(v.size())

using namespace std;

const long long MOD = 1e9+7, inf = 1e18;

ll binpow(ll a, ll b) {
    if (b == 0) return 1;
    else if (b % 2 != 0) return (a%MOD * binpow(a, b-1)%MOD)%MOD;
    ll tmp = binpow(a, b/2); return (tmp%MOD*tmp%MOD)%MOD;
}

void run() {
	ll n, m;
	cin >> n >> m;
	
	ll x = (binpow(2, m) % MOD - 1 % MOD) % MOD;
	
	cout << binpow(x, n);
}

int32_t main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    ll ttest=1;
    // cin >> ttest;

    for (ll test_number=1; test_number<=ttest; test_number++) {
        run();
    }

    return 0;
}
