#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> pos;
    vector<pair<int, int>> neg;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        auto &[s, d] = v[i];
        cin >> s >> d;
        if (d >= 0) {
            pos.push_back({s, -i});
        }
        else {
            neg.push_back({ -s, i});
        }
    }
    auto f = [&](int i, int j) {
        if (v[i].first != v[j].first) {
            return v[i].first > v[j].first;
        }
        return i < j;
    };
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), f);
    ll ans = 0;
    for (auto &[_, i] : pos) {
        i = -i;
        v[i].first += v[i].second;
        int j = 0;
        while (p[j] != i) j++;
        sort(p.begin(), p.end(), f);
        int pos = 0;
        while (p[pos] != i) pos++;
        ans += j - pos;
    }
    for (auto &[_, i] : neg) {
        v[i].first += v[i].second;
        int j = 0;
        while (p[j] != i) j++;
        sort(p.begin(), p.end(), f);
        int pos = 0;
        while (p[pos] != i) pos++;
        ans += pos - j;
    }
    cout << ans << '\n';
}