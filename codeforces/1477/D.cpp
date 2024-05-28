#include<bits/stdc++.h>
#define int long long
#define fr first
#define sc second
#define inf 1e18
#define endl '\n'
#define LOGN 64
#define FOR(i, n)  for(int i = 0;i < n;i++)
#define pb push_back

using namespace std;

const int mod = 998244353;
const int codeforces = 1;
const int N = 1e6+10;

int p[N], q[N];
set <int> g[N];
int deg[N];
set <pair <int, int>> vertices;
    
void out(int x){
    vertices.erase({deg[x], x});
    for(auto v : g[x]){
        vertices.erase({deg[v], v});
        deg[v]--;
        vertices.insert({deg[v], v});
        g[v].erase(x);
    }
    return;
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        p[i] = q[i] = 0;
        g[i].clear();
        deg[i] = 0;
    }
    for(int i = 1;i <= m;i++){
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
        deg[a]++;
        deg[b]++;
    }    
    for(int i = 1;i <= n;i++){
        vertices.insert({deg[i], i});
    }
    while(!vertices.empty()){
        int v = (*--vertices.end()).second;
        int n = vertices.size();
        // cout << "a" << ' ' << n << ' ' << v << ' ' << deg[v] << '\n'; 
        if(deg[v] == n-1){
            p[v] = q[v] = n;
            out(v);
            continue;
        }
        int u;
        for(auto p : vertices){
            int x = p.second;
            if(x != v and g[v].find(x) == g[v].end()){
                u = x;
                break;
            }
        }
        if(deg[v] <= n-4){
            p[u] = n;
            p[v] = n-1;
            q[u] = n-1;
            q[v] = n;
            out(u);
            out(v);
            continue;
        }
        if(deg[v] == n-2){
            vector <int> anti;
            auto it = --vertices.end();
            while(it != --vertices.begin() and deg[(*it).second] == n-2){
                int xx = (*it).second;
                if(xx != u and g[u].find(xx) == g[u].end()){
                    anti.push_back(xx);
                }
                it--;
            }
            int k = anti.size();
            // cout << k << ' ';
            p[u] = n;
            q[u] = n-k;
            out(u);
            for(int i = 0;i < k;i++){
                int v = anti[i];
                p[v] = n-i-1;
                q[v] = n-i;
                out(v);
            }
            continue;
        }
        if(deg[v] == n-3){
            int w;
            for(auto p : vertices){
                int x = p.second;
                if(x != u and x != v and g[v].find(x) == g[v].end()){
                    w = x;
                    break;
                }
            }
            if(deg[w] == n-3 and g[u].find(w) == g[u].end()){
                p[u] = n;
                p[v] = n-1;
                p[w] = n-2;
                q[u] = n-2;
                q[v] = n;
                q[w] = n-1;
                out(u);
                out(v);
                out(w);
                continue;
            }
            p[u] = n-1;
            p[v] = n;
            q[u] = n;
            q[v] = n-1;
            out(u);
            out(v);
        }   
    }
    for(int i = 1;i <= n;i++){
        cout << p[i] << ' ';
    }
    cout << '\n';
    for(int i = 1;i <= n;i++){
        cout << q[i] << ' ';
    }
    cout << '\n';
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    if(codeforces) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}