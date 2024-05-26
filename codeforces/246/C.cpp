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
int n, k;
map<ll, vector<int>> appear;

void build(vector<int> &x) {
    for (int i = 1; i <= n; ++i) {
        if (appear.size() >= k) break;
        vector<int> m;
        ll sum = 0;
        for (int j = n - i; j < n; ++j)
            m.push_back(x[j]), sum += x[j];

        for (int j = 0; j < n - i; ++j) {
            auto tmp = m;
            tmp.push_back(x[j]);
            sum += x[j];
            appear[sum] = tmp;
            sum -= x[j];
        }
    }
}

void solve() {
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i], appear[x[i]] = {x[i]};
    sort(all(x));
    build(x);
    reverse(all(x));
    build(x);

    auto it = appear.begin();
    while (k--) {
        cout << it->second.size() << ' ';
        for (const auto &i: it->second)
            cout << i << ' ';
        cout << '\n';
        ++it;
    }
}


int main() {
    Shadow::Fast();
    Shadow::Files();
    int T = 1;
//    cin >> T;
    while (T--) solve();
    return 0;
}