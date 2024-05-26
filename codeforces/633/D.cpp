#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cnt[a[i]]++;
    sort(a.begin(), a.end());
    int ans = 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (a[i] == 0 && a[j] == 0) continue;
            ll f2 = a[i], f1 = a[j];
            vector<ll> v;
            v.push_back(f1); v.push_back(f2);
            cnt[f1]--;
            cnt[f2]--;
            for (int len = 3; ; ++len) {
                ll f = f1 + f2;
                if (abs(f) > 1e9) break;
                if (cnt[f] > 0) ans = max(ans, len); else break;
                cnt[f]--;
                v.push_back(f);
                f2 = f1;
                f1 = f;
            }
            for (auto x : v) cnt[x]++;
        }
    }
    ans = max(ans, cnt[0]);
    cout << ans << endl;
    return 0;
}