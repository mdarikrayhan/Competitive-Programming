#include<bits/stdc++.h>
using namespace std;
#define int            long long int

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(...) 42
#endif

const auto boostIO = []() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed; cout.precision(12);
    return 0;
}();

const int MOD = 1e9 + 7;

int power(int base, int exp, const int M = MOD) {
    int result = 1;
    base %= M;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % M;
        base = (base * base) % M;
        exp >>= 1;
    }
    return result;
}

void Hehe() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int n = s.length();
    int x = power(2, n - 1);
    int ans = 0;
    for(auto& c : s) {
        ans = c == '1' ? (ans + x) % MOD : ans;
        x <<= 1ll;
        x %= MOD;
    }
    cout << ans << "\n";
}

int32_t main() {
    int T = 1;
    // cin >> T;
    while(T --> 0)
        Hehe(); 
}