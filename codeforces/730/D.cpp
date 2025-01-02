#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    ll r;
    cin >> n >> r;
    vector<ll> v;
    int l[n], t[n];
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    const int MX = 1e5;
    ll drinks = 0;
    ll len = 0;//stores remaining length thatll be ran sped up
    ll timer = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] < l[i]) {
            cout << "-1\n";
            return 0;
        }
        ll mn = min((ll)l[i], len);
        l[i] -= mn;
        t[i] -= mn;
        len -= mn;
        timer += mn;
        if (l[i] <= 0) continue;
        int run = max(2 * l[i] - t[i], 0);//this much i must run
        timer += 2 * (l[i] - run);
        int need = (run + r - 1) / r;
        len = need * r - run;
        drinks += need;
        int cur = 0;
        while (v.size() <= MX && v.size() < drinks) {
            v.push_back(timer + 1LL * r * cur);
            cur++;
        }
        timer += run;
    }
    cout << drinks << '\n';
    if (v.size() <= MX) {
        for (auto x : v) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}