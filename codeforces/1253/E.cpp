// LUOGU_RID: 159654117



#include<iostream>
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<unordered_map>
#include<vector>
#include<array>
#include<math.h>
#include<map>
#include<stdio.h>
#include<queue>
#include<assert.h>
#include<string>
#include<limits.h>
#include<stack>
#include<set>
#include<list>  
#include<algorithm>
#include <chrono>
#include<random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL, LL>PII;
typedef pair<double, double>PDD;
typedef pair<char, char>PCC;
LL n, m, k;

const LL inf = 1e18;
const LL N = 3e5 + 10;
const LL mod = 1e9 + 7;
vector<pair<int,int>>g[N];
int dis[N], vis[N];
void solve() {
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        g[i].push_back({ i + 1, 1 });
        g[i + 1].push_back({ i,0 });
    }
    for (int i = 1;i <= n;i++) {
        int x, s;
        cin >> x >> s;
        int k = 0;
        int l = max(1, x - s), r = min(x + s+1, (int)m + 1);
        while (l) {
            g[l].push_back({r,k});
            
            k++;
            l--, r++;
        }
    }
    auto dijkstra = [&]()->void {
        priority_queue<pair<int, int>>q;
        memset(dis, 0x3f, sizeof dis);
        memset(vis, 0, sizeof vis);
        dis[1] = 0;
        q.push({ 0,1 });
        while (q.size()) {
            auto [t, u] = q.top();
            q.pop();
            if (vis[u])continue;
            vis[u] = 1;
            for (auto [v, w] : g[u]) {
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    q.push({ -dis[v],v });
                }
            }
        }
    };
    dijkstra();
    cout << dis[m + 1] << "\n";
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

