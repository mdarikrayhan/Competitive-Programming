#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()


class Shadow {
public:
    static void Files() {
#ifndef ONLINE_JUDGE
        freopen("../INPUT.txt", "r", stdin);
        freopen("../OUTPUT.txt", "w", stdout);
        freopen("../BacKDooR.txt", "w", stderr);
#endif
    }

    static void Fast() {
        ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    }
};


//-----------------------------------------------------`|||`-----------------------------------------------------\\
\\-----------------------------------------------------`\|/`-----------------------------------------------------//
const int N = 3e5 + 3, F = 1e6 + 3, mod = 998244353, INF = 1e8;


void solve() {
    int n;
    cin >> n;
    set<char> end{'.', '!', '?'};
    string s;
    deque<string> w;
    while (cin >> s)
        w.push_back(s);
    vector<vector<string>> sentences;
    while (!w.empty()) {
        vector<string> tmp;
        while (!w.empty() && !end.count(w.front().back())) tmp.push_back(w.front()), w.pop_front();
        if (!w.empty()) tmp.push_back(w.front()), w.pop_front();
        sentences.emplace_back(tmp);
    }

    int ans = 1, currentSize = 0;
    for (const auto &sentence: sentences) {
        int sz = 0;
        for (const auto &i: sentence) sz += i.size() + 1;
        --sz;
        if (currentSize + sz + (currentSize ? 1 : 0) <= n) {
            currentSize += sz + (currentSize ? 1 : 0);
            continue;
        } else if (sz <= n) {
            currentSize = sz, ++ans;
            continue;
        } else return void(cout << "Impossible\n");
    }
    cout << ans << '\n';
}


int main() {
    Shadow::Fast();
    Shadow::Files();
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}