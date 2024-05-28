#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const ll maxn = 2e5 + 10;
const ll maxm = 3010;
ll qpow(ll a, ll b = mod - 2){
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll d;
ll w[maxn];
ll lk[maxn];
ll s[2];
ll n, m;
ll f[maxm][maxm];
ll F(ll k, ll d1) {
    if(~f[k][d1]) return f[k][d1];
    if(k == m) return f[k][d1] = d1;
    ll d0 = k - d1;
    ll w0 = (s[0] - d0 + mod) % mod;
    ll w1 = (s[1] + d1) % mod;
    return f[k][d1] = ((ll)w0 * F(k + 1, d1) % mod + (ll)w1 * F(k + 1, d1 + 1) % mod) % mod * qpow((w0 + w1) % mod) % mod;
}
int main() {
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) cin >> lk[i];
    for(ll i = 1; i <= n; i++) cin >> w[i];
    for(ll i = 1; i <= n; i++) {
        s[lk[i]] += w[i];
        if(s[lk[i]] >= mod) s[lk[i]] -= mod;
    } 
    memset(f, -1, sizeof(f));
    ll d1 = F(0, 0);
    ll d0 = (m - d1 + mod) % mod;
    for(ll i = 1; i <= n; i++) {
        if(lk[i]) {
            cout << (w[i] + d1 * w[i] % mod * qpow(s[1]) % mod) % mod << endl;
        } else {
            cout << (w[i] - d0 * w[i] % mod * qpow(s[0]) % mod + mod) % mod << endl;
        }
    }
}