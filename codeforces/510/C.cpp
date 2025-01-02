//------------------Mukul457-----------------------------------

#include <bits/stdc++.h>
#include<chrono>
using namespace std;
//template <typename PB>
#define ll long long int
#define be begin()
#define en end()
#define pb push_back
#define pyes cout << "Yes\n"
#define pno cout << "No\n"
#define ce cout << '\n'
#define endl '\n'
#define pie 3.141592653589793238462643383279502884197169399
#define print(x) cout<<x<<endl
#define printb(x) cout<<x<<" "
#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define all(v) v.begin(), v.end()
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
#define fi first
#define se second
#define vll vector<ll>
#define vp vector<pair<ll,ll>>
#define trav(v) for (auto it = v.begin(); it != v.end(); it++)
#define rep(i, n) for (ll i = 0; i < n; i++)
const ll N = 2e5+10;
const ll N2 =205;
const ll INF= 1e18;
const ll N3 = 1010;

vector<pair<int,int>> movement = {
    {0,1},{-1,0},
    {1,0},{0,-1},
};
const ll ALPHABET_SIZE = 26;

vector<vll> g(ALPHABET_SIZE);
vll vis(ALPHABET_SIZE, 0);
vll indegree(ALPHABET_SIZE, 0);
vll order;
bool dfs(ll s) {
    vis[s] = 1;
    for (ll u : g[s]) {
        if (vis[u] == 1) {
            return true;
        }
        else if (vis[u] == 0) {
            if (dfs(u)) return true;
        }
    }
    vis[s] = 2;
    order.pb(s);
    return false;
}

void topologicalSort(ll n) {
    bool cycle = false;
    for (ll i = 0; i < n; i++) {
        if (vis[i] == 0) {
            if (dfs(i)) {
                cycle = true;
                break;
            }
        }
    }
    if(cycle) {
        cout << "Impossible" << endl;
    }
    else {
        rev(order);
        for(ll i : order) cout <<char(i+'a');
        ce;
    }
}

void solve(){
    ll n;
    cin >> n;
    vector<string> words(n);
    for(ll i = 0; i < n; i++)  cin >> words[i];
    for(ll i = 1; i < n; i++) {
        string& w1 = words[i - 1];
        string& w2 = words[i];
        bool difference_found = false;
        for (ll j = 0; j < min(w1.length(), w2.length()); j++) {
            if (w1[j] != w2[j]) {
                ll u = w1[j] - 'a';
                ll v = w2[j] - 'a';
                g[u].pb(v);
                indegree[v]++;
                difference_found = true;
                break;
            }
        }

        if (!difference_found && w1.length() > w2.length()) {
            cout << "Impossible" << endl;
            return;
        }
    }
    topologicalSort(ALPHABET_SIZE);
}

int main(){
    int t=1;
    ios::sync_with_stdio(false);
    //cin.tie(0);
    //cin>>t;
    while(t--){
        solve();
    }
}

/*
//----------------Finding Cycles------------------
int v1[100005];
bool cycle(int s){
    v1[s]=1;
    for (auto i: g[s]){
        if (!v1[i]){
            v.pb(i);
            if (cycle(i)) return true;
            v.pop_back();
        }
        else if (v1[i]==1){
                v.pb(i);
                return true;
        }
    }
    v1[s] = 2;
    return false;
}
*/

/*
//-----------------DFS-----------------
vll g[N];
bool vis[N];

void dfs(ll vertex){
    vis[vertex] = true;
    for(auto child : g[vertex]){
        if(vis[child]) continue;
        dfs(child);
    }
    return;
}
*/

/*
//-------------------BFS-----------------
vll g[N];
bool vis[N];
ll level[N];
void bfs(ll source){
    queue<ll> q;
    q.push(source);
    vis[source] = true;
    while(!q.empty()){
        int cur_vertex = q.front();
        q.pop();
        for(auto child : g[cur_vertex]){
            if(!vis[child]){
                q.push(child);
                vis[child] = true;
                level[child] = level[cur_vertex] + 1;
            }
        }
    }
}

*/

/*
//---------------------Dijkstar-----------------
vp g[N];
vll vis(N,0);
vll dist(N,INF);
ll p[N+1]={-1};
void dij(ll source){
    set<pair<ll,ll>> s;
    s.insert({0,source});
    dist[source]=0;
    while(s.size()>0){
        pair<ll,ll> node=*s.begin();
        ll v = node.second;
        ll dista=node.first;
        s.erase(s.begin());
        if(vis[v]) continue;
        vis[v]=1;
        for(auto child:g[v]){
            ll child_v=child.first;
            ll wt=child.second;
            if(dist[v]+wt<dist[child_v]){
                dist[child_v]=dist[v]+wt;
                s.insert({dist[child_v],child_v});
                p[child_v]=v;
            }
        }
    }
    return;
}
*/

/*
ll vis2[N2][N2];
ll level2[N2][N2];
//------------------BFS-Shortest path-----------
int bfss(ll x,ll y,ll endx,ll endy){
    int sourcex = x;
    int sourcey = y;
    int destx = endx;
    int desty = endy;
    queue<pair<int,int>> q;
    q.push({sourcex,sourcey});
    vis2[sourcex][sourcey]=1;
    while(!q.empty()){
        pair<int,int> v = q.front();
        int x=v.fi;
        int y=v.se;
        q.pop();
        for(auto move: movement){
            int childx=move.fi + x;
            int childy=move.se + y;
            if(!isValid(childx,childy)) continue;
            if(!vis2[childx][childy]){
                q.push({childx,childy});
                g[childx][childy]=level2[x][y]+1;
                vis2[childx][childy]=1;
            }
        }
        if(level2[destx][desty]!=INF){
            break;
        }
    }
    return level2[destx][desty];
}


void reset(){
    for(int i=0;i<N2;i++){
        for(int j=0;j<N2;j++){
            level2[i][j]=INF;
            vis2[i][j]=0;
        }
    }
}
*/

/*
//---------Flloyd-Warshall-----------
ll dist[N3][N3]={INF};

void solve(){
    ll n,m;
    cin>>n;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            cin>>dist[i][j];
        }
    }
    vll v;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        v.pb(x);
    }
    rev(v);
    vll ans;
    for(ll k=0;k<n;k++){
            ll k_v = v[k];
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
               ll newdis = dist[i][k_v]+dist[k_v][j];
               dist[i][j]=min(dist[i][j],newdis);
            }
        }
        ll sum=0;
    for(ll i=0;i<=k;i++){
        for(ll j=0;j<=k;j++){
                sum+=dist[v[i]][v[j]];
            }
        }
        ans.pb(sum);
    }
    rev(ans);
    for(ll i=0;i<n;i++){
        printb(ans[i]);
    }
    return;
}

*/

/*
//-------------------DSU-------------------
ll parent[N];
ll size[N];

void make(ll v){
    parent[v]=v;
    size[v]=1;
}

ll find(ll v){
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]);
}

void union(ll a, ll b){
    a=find(a);
    b=find(b);
    if(a!=b){
        if(size[a]<size[b]) swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
}
*/
