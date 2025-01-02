#include<bits/stdc++.h>
using namespace std;
#define int long long
#define leng signed(2e6 + 5)
int jiech[leng];
const int MOD = 998244353;
const int _MOD = MOD - 2;
int mul(int a, int b) {
    return (a * b) % MOD;
}
int divi(int a, int b) {
    int base = b;
    int _b = 1;
    for(int i = 0; i <= 30; ++i) {
        if(_MOD & (1LL << i)) {
            _b = mul(_b, base);
        }
        base = mul(base, base);
    }
    return mul(a, _b);
}
int A(int a, int b) {
    return divi(jiech[a + b], mul(jiech[a], jiech[b]));
}
void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(abs(a - b) > 1) {
        cout << 0 << '\n';
        return;
    }
    if(abs(a - b) == 1) {
        int bigone = max(a, b);
        cout << mul(A(bigone - 1, c), A(bigone - 1, d)) << '\n';
        return;
    }
    if(a == 0) {
        if((c != 0) && (d != 0)) cout << 0 << '\n';
        else cout << 1 << '\n';
    } else {
        cout << (mul(A(a, c), A(a - 1, d)) + mul(A(a - 1, c), A(a, d))) % MOD << '\n';
    }
    
    // cout << divi(98, 2) << '\n';
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    jiech[0] = 1;
    for(int i = 1; i < leng; ++i) {
        jiech[i] = mul(jiech[i - 1], i);
    }
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
