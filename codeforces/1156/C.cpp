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


void burn() {
    int n, z;
    cin >> n >> z;
    vector<int>a(n), done(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    for(auto &i : a)cin >> i;
    sort(a.begin(), a.end());
    int mx = 0;
 
    for(int i = 0; i < n; i++) {
        if (mx == n)break;
        if (done[i])continue;
        int idx = max(mx, lower_bound(a.begin(), a.end(), z + a[i]) - a.begin());
        if (idx != n)done[idx] = done[i] = 1, pq.push({a[i], a[idx]}), mx = idx + 1;
        else break;
    }
    int l = 0, r = 1;
    vector<int>v;
    for(int i = 0; i < n; i++) {
        if (!done[i])v.push_back(i);
    }
    if (v.size() == 1) {
        cout << pq.size() << '\n';
        return;
    }
    int ans = 0;

    while (r < v.size() && !pq.empty()) {
        int first = pq.top().first, second = pq.top().second;
        while(l < v.size() && done[v[l]])l++;
        while(l < v.size() && a[v[l]] - first < z)l++;
        r = l + 1;
        while(r < v.size() && done[v[r]])r++;
        while(r < v.size() && a[v[r]] - second < z)r++;
        if (r >= v.size())break;
        pq.pop();
        done[v[r]] = done[v[l]] = 1;
        ans+=2;
    }
    cout << ans + pq.size() << "\n";
}
int32_t main() {
    fast();
    int t = 1;
    //cin >> t;
    while (t--) {
        burn();
    }
}