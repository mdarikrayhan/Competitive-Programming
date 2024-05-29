// There is an east wind coming.
#include "bits/stdc++.h"

using namespace std;

#define int long long

vector<int> z_algo(string &s) {
    int n = (int) s.size();
    vector<int> z(n);
    z[0] = n;
    for (int i = 1, L = 1, R = 1; i < n; i++) {
        int k = i - L;
        if (z[k] + i >= R) {
            L = i;
            R = max(R, i);
            while (R < n && s[R - L] == s[R]) R++;
            z[i] = R - L;
        } else z[i] = z[k];
    }
    return z;
}

vector<int> prefix_function(string s) {
    int n = (int) s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void Get_AC() {
    string a, b;
    getline(cin, a);
    getline(cin, b);
    if ((int) a.size() != (int) b.size()) {
        cout << "-1 -1\n";
        return;
    }
    int n = (int) a.size();
    string s = a, t = b + '?' + a;
    reverse(s.begin(), s.end());
    s += '?' + b;
    auto p = prefix_function(s);
    auto z = z_algo(t);
    int ai = -1, aj = -1;
    for (int i = 0; i < n - 1 && a[i] == b[n - i - 1]; i++) {
        if (z[i + n + 2] + p[2 * n - i - 1] >= n - i - 1)ai = i, aj = n - p[2 * n - i - 1];
    }
    cout << ai << ' ' << aj << '\n';
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    int tc = 1;
//    cin >> tc;
    for (int i = 1; i <= tc; i++) {
//       cout << "Case " << i << ": ";
        Get_AC();
    }
    return 0;
}