#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m; cin >> n >> m;
    vector<long long int> a(m, 0);
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        for (auto c: s) {
            a[i] = a[i] * 2 + c - '0';
        }
        cin >> b[i];
    }
    
    vector<vector<long long int>> masks(6);
    for (int i = 0; i < 6; i++) {
        auto recurse = [&](auto self, int idx, int cnt, long long int mask) -> void {
            if (cnt == 0) {
                masks[i].push_back(mask);
                return;
            }
            if (idx == n) return;
            
            self(self, idx + 1, cnt, mask);
            mask += (1LL << idx);
            self(self, idx + 1, cnt - 1, mask);
        };
        recurse(recurse, 0, i, 0);
    }
    
    vector<long long int> check;
    for (auto mask: masks[b[0]]) {
        long long int good = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1LL << i)) {
                good += (a[0] & (1LL << i));
            } else if (!(a[0] & (1LL << i))) {
                good += (1LL << i);
            }
        }
        check.push_back(good);
    }
    
    int ans = 0;
    for (auto mask: check) {
        bool good = true;
        for (int i = 0; i < m; i++) {
            long long int x = mask ^ a[i];
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (x & (1LL << j)) cnt++;
            }
            if (b[i] + cnt != n) good = false;
        }
        if (good) ans++;
    }
    cout << ans;
}