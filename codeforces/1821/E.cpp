#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


void solve() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.length();
    stack<int> st;
    vector<int> l(n, -1), r(n, -1);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            r[st.top()] = i;
            l[i] = st.top();
            st.pop();
        }
    }

    priority_queue<array<int, 3>> pq;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            pq.push({r[i] - i + 1, i, r[i]});
        }
    }

    vector<pair<int, int>> ops;

    while (k--) {
        if (pq.empty())
            break;
        auto [len, L, R] = pq.top();
        if (len == 1)
            break;
        pq.pop();
        pair<int, int> o = {L, R};
        if (!ops.empty()) {
            for (auto [x, y] : ops) {
                if (o.first > x and o.second < y)
                    L--;
                if (o.first > x and o.second < y)
                    R--;
            }
        }
        ops.push_back(o);
        string temp = "";
        for (int i = 0; i < L; i++)
            temp.push_back(s[i]);
        for (int i = L + 1; i < R; i++) {
            temp.push_back(s[i]);
        }
        temp.push_back(s[L]);
        for (int i = R; i < n; i++) {
            temp.push_back(s[i]);
        }
        swap(s, temp);
    }
    
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == ')') {
            st.push(i);
        } else {
            st.pop();
            ans += st.size();
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
}