#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
    int __tc = 1; cin >>__tc; nxt:
    while (__tc--)
    {
    int n; cin >> n;
    string s; cin >> s;

    deque<int> one;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') one.push_back(i);
    }

    vector<int> ans;
    for (int i = n - 1; ~i; --i) {
        if (one.empty() || one.front() >= i) break;
        if (s[i] == '0') {
            ans.push_back(one.front()); one.pop_front();
            ans.push_back(i);
        }
    }

    if (ans.empty()) {
        cout << 0 << "\n";
        goto nxt;
    }
    cout << 1 << "\n";
    cout << ans.size() << " ";
    sort(ans.begin(), ans.end());
    for (auto x: ans) cout << x + 1 << " ";
    cout << "\n";
    }
}