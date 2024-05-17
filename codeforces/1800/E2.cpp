#include <iostream>
#include <map>
typedef long long ll;
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    string s, t; cin >> s >> t;
    map<char,int> mp;
    for (int i = 0; i < n; i++) {
        if (i >= k or i + k < n) mp[s[i]]++, mp[t[i]]--;
        else {
            if (s[i] != t[i]) return cout << "NO\n", void();
        }
    }
    for (auto [x,y] : mp) if (y) return cout << "NO\n", void();
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1; cin >> t;
    while (t--) solve();
}
