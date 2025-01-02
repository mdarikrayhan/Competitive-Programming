// LUOGU_RID: 160003317
// LUOGU_RID: 159975477
// LUOGU_RID: 159961201
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5; 

int n; 
map<pair<int, int>, int> mpf; 
inline int ask(int u, int v) {
    if (u > v) swap(u, v); 
    if (u == v) return 0; 
    // if (mpf.find({u, v}) != mpf.end()) return mpf[{u, v}]; 
    cout << "? " << u << " " << v << endl; 
    int ans; cin >> ans; return ans; 
    // return mpf[{u, v}] = ans; 
}

int cnt[N], dist[N]; 
mt19937 Rand(time(0)); 
inline int rnd(int l, int r) { return uniform_int_distribution<int>(l, r)(Rand); }

int main(void) {
    ios::sync_with_stdio(0); 
    cin >> n; 
    int l = rnd(1, n), r = rnd(1, n); 
    for (int _ = 1; _ <= 70; ++_) {
        int dis = ask(l, r), mx = n, rt; 
        for (int i = 1; i <= 160; ++i) {
            int u = rnd(1, n); 
            int dl = ask(u, l), dr = ask(u, r); 
            ++cnt[dist[i] = (dl - dr + dis) / 2]; 
            if (cnt[dist[i]] > cnt[mx]) mx = dist[i], rt = u; 
        }
        int tot[2] = {0, 0}; 
        for (int i = 1; i <= 160; ++i)
            tot[0] += (dist[i] < mx), 
            tot[1] += (dist[i] > mx); 
        if (cnt[mx] > 80) {
            if (tot[0] >= tot[1]) r = rt; 
            else l = rt; 
        }

        for (int i = 1; i <= 160; ++i) cnt[dist[i]] = 0; 
    }

    int dis = ask(l, r); 
    vector<int> id(n); 
    for (int u = 1; u <= n; ++u) {
        int dl = ask(u, l), dr = ask(u, r); 
        ++cnt[(dl - dr + dis) / 2]; 
        if (dl + dr == dis) id[dl] = u; 
    }
    int cur = 0; 
    for (int i = 0, cur = 0; i < n; ++i) {
        cur += cnt[i]; 
        if (cur > n / 2) return cout << "! " << id[i] << endl, 0; 
    }
    return 0;
}