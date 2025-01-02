// LUOGU_RID: 159464405
//transcend
//夏が過ぎてく
#include<bits/stdc++.h>

#define NL std::cout<<'\n'
#define int long long
#define pii std::pair<int,int>

const int maxn = 5e5+5;
const int mod = 1e9 + 7;
const int inf = 1e18;
const double eps = 1e-9;
const int p = 131;

int head[maxn],e[maxn],en[maxn],idx = 1,val[maxn];

void add(int u,int v){
    e[idx] = v;
    en[idx] = head[u];
    head[u] = idx++;
}

std::set<int> s[maxn];

void solve(){
    int n,m; std::cin >> n >> m;
    std::map<unsigned int,int> mp;
    for(int i = 1; i <= n; ++i) {
        std::cin >> val[i];
    }
    for(int i = 1; i <= n; ++i) {
        s[i].clear();
    }
    std::vector<unsigned int> f(n+1);
    for(int i = 0; i < m; ++i) {
        int u,v; std::cin >> u >> v;
        s[v].insert(u);
    }
    for(int i = 1; i <= n; ++i) {
        for(auto x:s[i]) {
            f[i] = f[i] * p + x;
        }
    }
    for(int i = 1; i <= n; ++i) {
        mp[f[i]] += val[i];
    }
    int ans = 0;
    for(auto [x,y]:mp) {
        if(!x) continue;
        if(!ans) ans = y;
        else ans = std::__gcd(ans,y);
    }
    std::cout << ans;
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);std::cout.tie(0);
//    freopen("test.in","r",stdin);
//    freopen("test.out","w",stdout);
    int T = 1;
    std::cin >> T;
    while(T--){
        solve();NL;
    }
}