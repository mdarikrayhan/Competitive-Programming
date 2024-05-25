/*
Problem: 1342E
Date: 25-05-2024 02:36 PM
*/


#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5, M = 998244353;
int n, k;
ll kk;

ll mod(ll a, ll m) {
    return (a % m + m) % m;
}
ll euclid(ll a, ll b, ll &x, ll &y) {
    ll xx = y = 0;
    ll yy = x = 1;
    while(b) {
        ll q = a / b;
        ll t = b; b = a % b; a = t;
        t = xx; xx = x - q * xx; x = t;
        t = yy; yy = y - q * yy; y = t;
    }
    return a;
}
ll modinverse(ll a, ll m) {
    ll x, y;
    ll g = euclid(a, m, x, y);
    return g > 1 ? -1 : mod(x, m);
}
ll modpow(ll a, ll b) {
    ll x = a, ans = 1;
    while(b > 0) {
        if(b & 1) {
            ans = (ans * x) % M;
        }
        b /= 2;
        x = (x * x) % M;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> kk;
    if(kk >= n) {
        cout << "0\n";
        return 0;
    }
    k = kk;
    ll choose = 1;
    ll sum = 0;
    k = n - k;
    for(int i = 0; i <= k; i++) {
        ll val = mod(choose * modpow(i, n), M);
        if((k - i) % 2 == 1) {
            val = mod(-val, M);
        }
        sum = mod(sum + val, M);
        choose = mod(mod(choose * (k - i), M) * modinverse(i + 1, M), M);
    }
    for(int i = 1; i <= k; i++) {
        sum = mod(mod(sum * (n - i + 1), M) * modinverse(i, M), M);
    }
    cout << (k == n ? sum : mod(sum * 2, M)) << '\n';
}