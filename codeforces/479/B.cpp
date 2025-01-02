#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF 1e18
#define ll long long
#define ul unsigned long
#define ld long double
#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

void IN_OUT() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

vector<pair<int, int>> solve(int n, int k, vector<ll> a, ll &s, uint64_t &m) {
    multiset<pair<ll, int>> set;
    for (int i = 0; i < n; i++)
        set.insert({a[i], i});

    vector<pair<int, int>> b;
    for (; k > 0; k--) {
        auto min_ = set.begin();
        auto max_ = prev(set.end());
        if (min_->first >= max_->first)
            break;

        b.emplace_back(max_->second + 1, min_->second + 1);

        set.insert({min_->first + 1, min_->second});
        set.insert({max_->first - 1, max_->second});

        set.erase(min_);
        set.erase(max_);
    }

    s = set.rbegin()->first - set.begin()->first;
    m = b.size();

    return b;
}

int main() {
    fastio();
    IN_OUT();

    int n, k;
    cin >> n >> k;

    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll s;
    uint64_t m;
    auto ans = solve(n, k, a, s, m);
    cout << s << ' ' << m << endl;

    for (auto it: ans)
        cout << it.first << ' ' << it.second << endl;

    return 0;
}