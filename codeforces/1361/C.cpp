#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> ti3;
const int MAX = 1 << 21;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> c (n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        c[i].push_back(a);
        c[i].push_back(b);
    }
    
    // binary search
    int lo = 0;
    int hi = 21;
    int best = -1;
    vector<int> tour {};
    for (int i = 0; i < 2*n; i++) tour.push_back(i);
    while (lo < hi-1) {
        int mid = (lo + hi) / 2;
        vector<int> count (MAX, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                int mask = (1 << mid) - 1;
                int val = mask & c[i][j];
                count[val]++;
            }
        }

        bool possible = true;
        for (int i = 0; i < MAX; i++) {
            if (count[i] % 2 == 1) {
                possible = false;
                break;
            }
        }
        if (!possible) {
            hi = mid;
            continue;
        }

        // generate graph
        best = mid;
        vector<int> id (MAX, -1);
        int cnt = 0;
        for (int i = 0; i < MAX; i++) {
            if (count[i] > 0) id[i] = cnt++;
        }
        vector<vector<ti3>> adj_list (cnt);
        vector<vector<int>> other_id (cnt);
        vector<int> active (cnt, 0);
        for (int j = 0; j < n; j++) {
            int mask = (1 << best) - 1;
            int a = id[mask & c[j][0]];
            int b = id[mask & c[j][1]];
            other_id[a].push_back(adj_list[b].size());
            if (b != a) {
                other_id[b].push_back(adj_list[a].size());
                adj_list[b].push_back({a, 2*j+1, 2*j});
            }
            adj_list[a].push_back({b, 2*j, 2*j+1});
        }

        // Hierholzer
        stack<ti3> s {};
        s.push({0, -1, -1});
        vector<int> tour2 {};
        while (!s.empty()) {
            auto[v, a, b] = s.top();
            if (adj_list[v].size() > active[v]) {
                auto[pv, pa, pb] = adj_list[v][active[v]];
                if (pv != v) {
                    int pv_id = other_id[v][active[v]];
                    int tp_id = other_id[pv][active[pv]];
                    auto[tp, tpa, tpb] = adj_list[pv][active[pv]];
                    other_id[tp][tp_id] = pv_id;
                    swap(adj_list[pv][active[pv]], adj_list[pv][pv_id]);
                    swap(other_id[pv][active[pv]], other_id[pv][pv_id]);
                    active[pv]++;
                }
                active[v]++;
                s.push({pv, pa, pb});
            } else {
                s.pop();
                if (a != -1) {
                    tour2.push_back(b);
                    tour2.push_back(a);
                }
            }
        }
        if (tour2.size() == 2*n) {
            tour = tour2;
            lo = mid;
        } else {
            hi = mid;
        }
    }
    
    cout << lo << "\n";
    for (int& it: tour) cout << it+1 << " ";
    cout << "\n";
    return 0;
}