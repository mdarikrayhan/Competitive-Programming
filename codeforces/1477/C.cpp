#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<long long, long long>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    
    auto dist = [&](int i, int j) {
        return (a[i].first - a[j].first) * (a[i].first - a[j].first) + (a[i].second - a[j].second) * (a[i].second - a[j].second);
    };
    vector<int> perm, used(n, 0);
    perm.push_back(0);
    used[0] = 1;
    for (int i = 0; i < n - 1; i++) {
        int x = perm.back();
        int who = -1;
        for (int j = 0; j < n; j++) 
            if (used[j] == 0 && (who == -1 || dist(x, j) > dist(x, who)))
                who = j;
        perm.push_back(who);
        used[who] = 1;
    }
    for (auto x : perm) 
        cout << x + 1 << " ";
    return 0;
}