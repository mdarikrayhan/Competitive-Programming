#include<bits/stdc++.h>

#define int long long

using namespace std;

void fast() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int n;
vector<vector<int>>dp;
vector<pair<int, int>>a;

int mem(int l, int r) {
    if (l == n)return 0;
    int &ret = dp[l][r];
    if (~ret)return ret;
    ret = mem(l + 1, r);
    pair<int, int>p = {a[l].second + 1, 0};
    int to = lower_bound(a.begin(), a.end(), p) - a.begin();
    int go = 0, ok = 0;
    if (r == n || a[l].second <= a[r].second) {
        go = mem(l + 1, l) + mem(to, r) + 1;
    }
    return ret = max(ret, go + ok);
}

void burn() {
    cin >> n;
    int mx = 0;
    a = vector<pair<int, int>>(n);
    for(auto &i : a)cin >> i.first >> i.second, mx = max(mx, i.second);
    sort(a.begin(), a.end(), [&](pair<int, int>a, pair<int, int>b) {
        if (a.first != b.first)return a.first < b.first;
        return a.second > b.second;
    });
    dp = vector<vector<int>>(n + 2, vector<int>(n + 2, -1));
    cout << mem(0, n) << '\n';

}
int32_t main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) {
        burn();
    }
}