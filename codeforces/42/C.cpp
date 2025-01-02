#include<bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file(s) freopen(s".in", "r", stdin);freopen(s".out", "w", stdout);
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ft first
#define sd second
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
const int N = 5e5 + 10;
const int M = 2e7 + 5;
//const int B = 316;
const ll msize = 2;
const ll mod1 = 1e9 + 7;
const ll mod2 = 998244353;
const long double Phi = acos(-1);
const long long inf = 2e18;
const vector <pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

ll binmul(ll x, ll ti, ll m);
ll binpow(ll x, ll ti, ll m);

ll a, b, c, d;

const void solve() {
    cin >> a >> b >> c >> d;

    vector <string> ans;
    while (a > 1) {
        if (a % 2 == 0 && b % 2 == 0) {
            ans.pb("/1\n");
            a /= 2; b /= 2;
        } else if (a % 2 == 0 && b % 2 == 1) {
            ans.pb("+2\n");
            ans.pb("/1\n");
            ++ b; ++ c;
            a /= 2; b /= 2;
        } else if (a % 2 == 1 && b % 2 == 1) {
            ans.pb("+1\n");
            ans.pb("/1\n");
            ++ a, ++ b;
            a /= 2, b /= 2;
        } else {
            ans.pb("+1\n");
            ans.pb("+2\n");
            ans.pb("/1\n");
            ++ a, b += 2, ++ c;
            a /= 2, b /= 2;
        }
    }
    if (ans.size() > 1000) {
        cout << -1;
        return;
    }

    while (b > 1) {
        if (b % 2 == 0 && c % 2 == 0) {
            ans.pb("/2\n");
            b /= 2; c /= 2;
        } else if (b % 2 == 0 && c % 2 == 1) {
            ans.pb("+3\n");
            ans.pb("/2\n");
            ++ c; ++ d;
            b /= 2; c /= 2;
        } else if (b % 2 == 1 && c % 2 == 1) {
            ans.pb("+2\n");
            ans.pb("/2\n");
            ++ b, ++ c;
            b /= 2, c /= 2;
        } else {
            ans.pb("+2\n");
            ans.pb("+3\n");
            ans.pb("/2\n");
            ++ b, c += 2, ++ d;
            b /= 2, c /= 2;
        }
    }
    if (ans.size() > 1000) {
        cout << -1;
        return;
    }
//
    while (c > 1) {
        if (c % 2 == 0 && d % 2 == 0) {
            ans.pb("/3\n");
            c /= 2; d /= 2;
        } else if (c % 2 == 0 && d % 2 == 1) {
            ans.pb("+2\n");
            ans.pb("+3\n");
            ans.pb("/2\n");
            ++ b, c += 2, ++ d;
            b /= 2, c /= 2;
        } else {
            ans.pb("+2\n");
            ans.pb("/2\n");
            ++ b, ++ c;
            b /= 2, c /= 2;
        }
    }
    if (ans.size() > 1000) {
        cout << -1;
        return;
    }
//
    while (d > 1) {
        if (d % 2 == 1) {
            ans.pb("+3\n");
            ans.pb("/3\n");
            ++ c, ++ d;
            c /= 2, d /= 2;
        } else {
            ans.pb("+2\n");
            ans.pb("/3\n");
            ans.pb("+1\n");
            ans.pb("+2\n");
            ans.pb("/1\n");
            ans.pb("/2\n");
            d /= 2;
        }
    }
    if (ans.size() > 1000) {
        cout << -1;
        return;
    }

    for (auto x : ans) cout << x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    srand(time(NULL));

    // file("maze");

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int tt = 1;
//    cin >> tt;
    for (int i = 1; i <= tt; ++ i) {
        solve();
    }

#ifndef ONLINE_JUDGE
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif

    return 0;
}


// Template functions
ll binmul(ll x, ll ti, ll m) { ll res = 0;while (ti){if(ti & 1)res += x;x += x;ti >>= 1; x %= m; res %= m;} return res;}
ll binpow(ll x, ll ti, ll m) { ll res = 1;while (ti){if(ti & 1)(res *= x)%=m;(x*=x)%=m;ti >>= 1; x %= m; res %= m;} return res;}