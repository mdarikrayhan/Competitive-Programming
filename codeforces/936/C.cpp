// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include "bits/stdc++.h"
using namespace std;
using ll = long long int;
mt19937_64 RNG(chrono::high_resolution_clock::now().time_since_epoch().count());

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    string s, t; cin >> s >> t;

    vector<int> ops;
    auto op = [&] (int k) {
        ops.push_back(k);
        string s1 = s.substr(0, n-k);
        string s2 = s.substr(n-k);
        reverse(begin(s2), end(s2));
        s = s2 + s1;
    };

    for (int i = 0; i < n; ++i) {
        string pref = t.substr(0, i+1);
        string suf = s.substr(n-i-1);
        if (pref == suf) continue;

        int j = 0;
        while (j < n) {
            if (s[j] == t[i]) break;
            ++j;
        }
        if (j >= n-i) return cout << -1 << '\n', 0;

        op(n-1-j);
        op(1);
        op(n);
    }
    cout << ops.size() << '\n';
    for (int x : ops) cout << x << ' ';
    cout << '\n';

    assert(s == t);
}