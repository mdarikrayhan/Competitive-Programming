#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    deque<int> dq(n);
    for (int i = 0; i < n; i++) {
        cin >> dq[i];
    }
    vector<pair<int, int>> op;
    vector<int> ans;
    int offset = 0;
    for (int rep = 0; rep < n && !dq.empty(); rep++) {
        int at = -1;
        vector<int> vals;
        for (int i = 1; i < (int) dq.size(); i++) {
            if (dq[i] == dq[0]) {
                at = i;
                break;
            }
            vals.emplace_back(dq[i]);
        }
        if (at == -1) {
            cout << -1 << '\n';
            return;
        }
        for (int i = 0; i <= at; i++) {
            dq.pop_front();
        }
        for (int i = 0; i < (int) vals.size(); i++) {
            op.emplace_back(offset + at + i + 1, vals[i]);
            dq.emplace_front(vals[i]);
        }
        int len = 2 * at;
        ans.emplace_back(len);
        offset += len;
    }
    cout << (int) op.size() << '\n';
    for (auto [pos, val] : op) {
        cout << pos << ' ' << val << '\n';
    }
    int len = (int) ans.size();
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}