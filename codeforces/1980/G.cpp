#include<bits/stdc++.h>
using namespace std;
 
void __print(int x){cerr << x;}
void __print(bool x){cerr << (int)x;}
void __print(long long x){cerr << x;}

void __print(double x){cerr << x;}
void __print(long double x){cerr << x;}
void __print(char x){cerr << '\'' << x << '\'';}
void __print(const char *x){cerr << '\"' << x << '\"';}
void __print(const string &x){cerr << '\"' << x << '\"';}
 
template<typename T, typename V>
void __print(const pair<T, V> &x){cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x){int f = 0; cerr << '{'; for(auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print(){cerr << "]\n";}
template<typename T, typename... V>
void _print(T t, V... v){__print(t); if(sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int M = 4e5 + 3, K = 30;	

int trie[M*K][2][2], cnt[M*K][2];
int sz[2];

void Insert(int x, int z){
    int node = 0;

    for(int i=K-1; i>=0; i--){
        int c = (bool)(x >> i & 1);
        if(!trie[node][c][z]){
            trie[node][c][z] = ++sz[z];
        }
        node = trie[node][c][z];
        cnt[node][z]++;
    }
}

int Search(int x, int z){
    int node = 0, ret = 0;

    for(int i=K-1; i>=0; i--){
        int c = (bool)(x >> i & 1);
        if(trie[node][c^1][z]){
            ret |= 1 << i;
            node = trie[node][c^1][z];
        }else node = trie[node][c][z];
    }

    return ret;
}

void Delete(int x, int z){
    int node = 0;
    vector<int>v(1, 0);

    for(int i=K-1; i>=0; i--){
        int c = (bool)(x >> i & 1);
        node = trie[node][c][z];
        cnt[node][z]--;
        v.push_back(node);
    }


    for(int i=1, j=K-1; i<v.size(); i++, j--){
        int c = (bool)(x >> j & 1);
        if(!cnt[v[i]][z]){
            trie[v[i-1]][c][z] = 0;
        }
    }
}

vector<pii>g[M];
int depth[M], d[M];

void dfs(int u, int p=0){
    for(auto [v, w] : g[u]){
        if(v != p){
            depth[v] = depth[u] + 1;
            d[v] = d[u] ^ w;
            dfs(v, u);
        }
    }
}

void solve(){

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n-1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w), g[v].emplace_back(u, w);
    }
    dfs(1);
    
    for(int i=1; i<=n; i++){
        Insert(d[i], depth[i]%2);
    }

    int yc = 0;

    while(m--){
        char c;
        cin >> c;
        if(c == '^'){
            int y;
            cin >> y;
            yc ^= y;
        }else{
            int v, x;
            cin >> v >> x;
            int dv = d[v];
            if(depth[v] % 2) dv ^= yc;
            Delete(d[v], depth[v]%2);
            int ans = max(Search(dv ^ x, 0), Search(dv ^ x ^ yc, 1));
            cout << ans << " ";
            Insert(d[v], depth[v]%2);
        }
    }

    cout << "\n";
    
    for(int i=1; i<=n; i++){
        g[i].clear();
        d[i] = depth[i] = 0;
    }

    for(int i=0; i<2; i++){
        for(int j=0; j<=sz[i]; j++){
            trie[j][0][i] = trie[j][1][i] = 0;
            cnt[j][i] = 0;
        }
        sz[i] = 0;
    }



}

int main(){
 
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        solve();
    }





    
 
}