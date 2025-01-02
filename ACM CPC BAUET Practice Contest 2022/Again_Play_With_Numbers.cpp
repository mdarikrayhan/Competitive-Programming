#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'

#define rep(x, start, end)                                                     \
    for (auto x = (start) - ((start) > (end)); x != (end) - ((start) > (end)); \
         ((start) < (end) ? x++ : x--))
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

int n;
string s;
int mod;

int mul(int i, int j) {
    int res = 0;
    rep(x, 0, n - 1) {
        if (i & (1LL << x)) res ^= j;
        j <<= 1;
        if (j & (1LL << (n - 1))) j ^= mod;
    }
    return res;
}

int pow(int i) {
    int res = 1;
    int b = 2;
    while (i) {
        if (i & 1) res = mul(res, b);
        b = mul(b, b);
        i >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(ios::badbit | ios::failbit);
        mod = 0;
        cin >> s;
        vector<int> pos;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                pos.push_back(i);
            }
        }
        s.erase(s.find_last_not_of("0") + 1);
        int offset = s.find_first_not_of("0");
        s.erase(0, offset);
        n = s.length();
        if (pos.size() == 0) {
            cout << -1 << endl;
            return 0;
        }
        if (pos.size() == 1) {
            cout << n + offset << ' ' << n + offset + 1 << endl;
            return 0;
        }
        if (pos.size() == 2) {
            cout << pos[0] + 1 << ' ' << pos[1] + 1 << endl;
            return 0;
        }
        rep(x, 0, sz(s)) if (s[x] == '1') mod |= (1LL << x);

        int h = (n + 1) / 2;

        int val = mod;
        int prod = 1;
        rep(x, 3LL, 1 << h) if (x & 1) {
            int num = 0;
            while (true) {
                int curr = val;
                int other = 0;
                rep(bit, 0, n) if (curr & (1LL << bit)) {
                    curr ^= x << bit;
                    other ^= 1LL << bit;
                }
                if (curr == 0) {
                    val = other;
                    num++;
                } else
                    break;
            }

            if (num) {
                prod *= (1LL << (63 - __builtin_clzll(x))) - 1;
                rep(y, 1, num) prod *= 1LL << (63 - __builtin_clzll(x));
            }
        }
        if (val > 1) prod *= (1LL << (63 - __builtin_clzll(val))) - 1;

        int ans = 1LL << 60;
        for (int x = 1; x * x <= prod; x++) {
            if (prod % x == 0) {
                if (pow(x) == 1) ans = min(ans, x);
                if (pow(prod / x) == 1) ans = min(ans, prod / x);
            }
        }
        cout << 1 + offset << ' ' << ans + 1 + offset << endl;
}
