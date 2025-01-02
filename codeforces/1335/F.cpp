// LUOGU_RID: 159656593
//transcend
//夏が過ぎてく
#include<bits/stdc++.h>

#define NL std::cout<<'\n'
//#define int long long
#define pii std::pair<int,int>

const int maxn = 1e6+5;
const int mod = 1e9 + 7;
const int inf = 1e18;
const double eps = 1e-9;

int head[maxn],e[maxn],en[maxn],idx = 1;
int n,m;
std::stack<int> s;
int bel[maxn],tot = 0,dfn[maxn],low[maxn],cnt = 0;
int sz[maxn],part[maxn];

void add(int u,int v){
    e[idx] = v;
    en[idx] = head[u];
    head[u] = idx++;
}

int head1[maxn],e1[maxn],en1[maxn],idx1 = 1;
std::set<int> d;

void add1(int u,int v) {
    e1[idx1] = v;
    en1[idx1] = head1[u];
    head1[u] = idx1++;
}

int id(int x,int y) {
    return x * m + y;
}

void tarjan(int x){
    if(dfn[x]) return;
    dfn[x] = low[x] = ++tot;
    s.push(x);
    for(int i = head[x]; i ; i = en[i]) {
        int to = e[i];
        if(dfn[to] == 0) {
            tarjan(to);
            low[x] = std::min(low[x],low[to]);
        }
        else if(bel[to] == 0) {
            low[x] = std::min(low[x],low[to]);
        }
    }
    if(dfn[x] == low[x]) {
        ++cnt;
        int cur = 0;
        while(s.top() != x) {
            bel[s.top()] = cnt;
            part[s.top()] = cur;
            s.pop();
            cur++;
        }
        bel[x] = cnt;
        part[x] = cur;
        sz[cnt] = cur + 1;
        s.pop();
    }
}

void solve(){
    std::cin >> n >> m;
    for(int i = 0; i < n * m; ++i) {
        head[i] = dfn[i] = tot = sz[i] = bel[i] = cnt = part[i] = 0;
        head1[i] = 0;
        idx = idx1 = 1;
    }
    std::vector<std::vector<int>> wb(n,std::vector<int>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            char x; std::cin >> x;
            wb[i][j] = x - '0';
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            char x; std::cin >> x;
            if(x == 'U') add(id(i,j),id(i-1,j));
            if(x == 'D') add(id(i,j),id(i+1,j));
            if(x == 'L') add(id(i,j),id(i,j-1));
            if(x == 'R') add(id(i,j),id(i,j+1));
        }
    }

    for(int i = 0; i < n * m; ++i) {
        if(dfn[i] == 0) tarjan(i);
    }
    int ans = 0;
    std::set<int> se;
    std::map<int,std::vector<int> > mp;
    for(int i = 0; i < n * m; ++i) {
        if(sz[bel[i]] > 1) {
            se.insert(bel[i]);
            mp[bel[i]].push_back(i);
        }
    }
    for(auto x:se) ans += sz[x];
    std::cout << ans << ' ';

    for(int i = 0; i < n * m; ++i) {
        for(int j = head[i]; j; j = en[j]) {
            add1(e[j],i);
        }
    }

    std::function<void(int,int,int)> dfs = [&](int now,int mod,int dis) {
       // std::cout << now;NL;
        for(int i = head1[now]; i ; i = en1[i]){
            int to = e1[i];
            if(bel[to] == bel[now]) continue;
            if(wb[to / m][to % m] == 0)
                d.insert((dis + 1) % mod);
            dfs(to,mod,dis + 1);
        }
    };

    ans = 0;
    for(auto x:se) {
        d.clear();
        for(auto y:mp[x]) {
            if(wb[y / m][y % m] == 0) d.insert(part[y]);
            dfs(y,sz[x],part[y]);
        }
        ans += d.size();
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