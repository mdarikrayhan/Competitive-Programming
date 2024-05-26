#include <bits/stdc++.h>

using namespace std;

#define debug(x) cerr << #x << ": " << x << '\n'
typedef long long i64;
const int N = 3e5 + 5;
const i64 inf = LLONG_MAX;
typedef pair<i64, i64> PII;

int m;
i64 n, fx, fy, sx, sy, x[N], y[N], s = 0, t;  

struct node {
    i64 from, to, id;
} a[N];

vector<PII> e[N];
vector<i64> dist(N, inf);

i64 dijkstra(i64 s) {
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.emplace(0, s);
    dist[s] = 0;
    while (heap.size()) {
        auto [dis, from] = heap.top();
        heap.pop();
        if (dist[from] < dis) continue;
        for (auto& [to, w] : e[from]) {
            if (dist[to] > dis + w) {
                dist[to] = dis + w;
                heap.emplace(dist[to], to);
            }
        }
    }
    return dist[t];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    auto check = [&](i64 x, i64 y, bool op) {
        i64 ans1 = abs(a[x].from - a[y].from);
        i64 ans2 = abs(a[x].to - a[y].to);
        return op ? ans1 + ans2 : min(ans1, ans2);
    };

    auto add = [&](i64 from, i64 to, i64 w) {
        e[from].emplace_back(PII{to, w});
        e[to].emplace_back(PII{from, w});
    }; 
    cin >> n >> m; t = m + 1; cin >> sx >> sy >> fx >> fy;
    a[s].from = sx; a[s].to = sy; a[t].from = fx; a[t].to = fy;
    add(s, t, check(s, t, 1));
    for (i64 i = 1; i <= m; i++) {
        i64 x, y;
        cin >> x >> y;
        a[i] = {x, y, i};
        add(s, i, check(0, i, 0));
        add(t, i, check(t, i, 1));
    }
    sort(a + 1, a + m + 1, [](node x, node y) {
        return x.from < y.from;
    });
    for (int i = 2; i <= m; i++) {
        add(a[i].id, a[i - 1].id, check(i, i - 1, 0));
    }

    sort(a + 1, a + m + 1, [](node x, node y) {
        return x.to < y.to;
    });
    for (int i = 2; i <= m; i++) {
        add(a[i].id, a[i - 1].id, check(i, i - 1, 0));
    }
    cout << dijkstra(s) << '\n';
    return 0;
}

  	  			 	    			   			 	   	 	