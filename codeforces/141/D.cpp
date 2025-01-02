#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
const int N = 2e5 + 5;

bool minimize(auto &a, auto b) {
    if(a <= b) return false;
    a = b;
    return true;
}

int n, L;
ll dp[N];
int prv[N], ramp_id[N];
vector<int> points;
tuple<int,int,int> ramp[N];
vector<tuple<int,int,int>> g[N];

void dijkstra(int u) {
    priority_queue<pii> q;
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    q.emplace(0, 0);
    while(q.size()) {
        auto [kc, v] = q.top(); q.pop();
        if(-kc > dp[v]) continue;
        for(auto [r, t, id] : g[v]) {
            if(minimize(dp[r], dp[v] + t)) {
                ramp_id[r] = id;
                prv[r] = v;
                q.emplace(-dp[r], r);
            }
        }
    }
}


void solve() {
    cin >> n >> L;
    for(int i = 1, x, d, t, p; i <= n; ++i) {
        cin >> x >> d >> t >> p;
        d = x + d;
        x -= p;
        t += p;
        ramp[i] = {x, d, t};
        if(x < 0) continue;
        points.push_back(x); points.push_back(d);
    }

    points.push_back(0); points.push_back(L);
    sort(all(points));
    points.resize(unique(all(points)) - points.begin());

    for(int i = 1; i < points.size(); ++i) {
        int t = points[i] - points[i - 1];
        g[i].emplace_back(i - 1, t, 0);
        g[i - 1].emplace_back(i, t, 0);
    }

    for(int i = 1; i <= n; ++i) {
        auto [sta, en, t] = ramp[i];
        if(sta < 0) continue;
        sta = lower_bound(all(points), sta) - points.begin();
        en = lower_bound(all(points), en) - points.begin();
        g[sta].emplace_back(en, t, i);
    }
    
    dijkstra(0);
    vector<int> res;
    int cur = points.size() - 1;
    cout << dp[cur] << '\n';
    while(cur) {
        if(ramp_id[cur]) res.push_back(ramp_id[cur]);
        cur = prv[cur];
    }
    reverse(all(res));
    cout << res.size() << '\n';
    for(int id : res) cout << id << ' ';
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int test = 1;
    // cin >> test;
    while(test--) solve();
    return 0;
}
 	 		  	 	   		 						   	    	