//"msh mohm!"
#include "bits/stdc++.h"

using namespace std;
#define int long long
#define ll long long
#define ld long double
#define  all(s) s.begin(),s.end()
#define  sz(s) (int)s.size()

template<typename T = int>
istream &operator>>(istream &in, vector<T> &v) {
    for (auto &x: v) in >> x;
    return in;
}

template<typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v) {
    for (const T &x: v) out << x << ' ';
    return out;
}

vector<int> z_algo(string s) {
    int n = s.size();
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

signed main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int cur = 1;

        for (int i = 1; i < n; i++) {
            // search for smallest char
            if (s[i % cur] != s[i]) {
                if (s[i % cur] > s[i])
                    cur = i + 1;
                else
                    break;
            }
        }
        string ans = s.substr(0, cur);
        while (ans.size() < k)ans += ans;
        while (ans.size() > k)ans.pop_back();
        cout << ans << '\n';
    }
}