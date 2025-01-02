#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef set<int> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e9;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 200100
#define MAXL 19
 
int N,E,Q;
int p[MAXN][MAXL], depth[MAXN];
ll D[MAXN][MAXL];
vpi adjList[MAXN];
 
struct edge {
    int a, b;
    ll w;
    edge (int _a=0, int _b=0, ll _w=0): a(_a), b(_b), w(_w) {}
};
 
int par(int x) { return (x==p[x][0])?x:p[x][0]=par(p[x][0]);}
void merge(int a, int b) {p[par(a)][0] = par(b);}
vector<edge> edgeList;
bool cmp (edge x, edge y) { return x.w < y.w; } //Swap the comparator for maximum
 
void dfs(int x){
  for (auto i : adjList[x] ){
    if (p[i.f][0] != -1)continue;
    depth[i.f] = depth[x] + 1;
    p[i.f][0] = x;
    D[i.f][0] = i.s;
    dfs(i.f);
  }
}
 
int LCA(int a, int b){
    if (a == b)return a;
    if (depth[a] < depth[b])swap(a,b);
    ll h = depth[a]-depth[b];
    for (ll i = 0; i < MAXL; i++) {
      if (((1 << i) & h) > 0) { 
        a = p[a][i];
      }
    }
    if (a == b)return a;
    for (ll i = MAXL - 1; i >= 0; i--){
        if (p[a][i] != p[b][i]){
            a = p[a][i];
            b = p[b][i];
        }
    }
    return p[a][0];
}
 
ll fd(int c, int d){ // Distance from c to its d-th parent
  ll ans = 0;
  for (int i = 0; i < MAXL; i++) {
    if (((1 << i) & d) > 0) {
      if (c==-1) return -1;
      ans = max(ans,D[c][i]);
      c = p[c][i];
    }
  }
  return ans;
}
 
 
int a,b;
ll w;
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen("in.txt","r",stdin);
    cin >> N >> E;
    for (int i = 1; i <= N; i++)p[i][0] = i;
    for (int i = 0; i < E; ++i){
        cin >> a >> b >> w;
        edgeList.pb({a,b,w});
    }
    sort(edgeList.begin(), edgeList.end(), cmp);
    for(auto it : edgeList){
        if (par(it.a) == par(it.b)) continue;
        p[par(it.a)][0] = par(it.b);
        adjList[it.a].pb(mp(it.b,it.w));
        adjList[it.b].pb(mp(it.a,it.w));
        //cout << it.a << ' ' << it.b << ' ' << it.w << '\n';
    }
    memset(p,-1,sizeof(p));
    dfs(1);
    for (int i = 1; i < MAXL; i++){
      for (int j = 1; j <= N; j++){
        if (p[j][i-1] == -1) {
            p[j][i] = -1;
            D[j][i] = -1;
        }
        else {
            p[j][i]=p[p[j][i-1]][i-1];
            D[j][i] = max(D[p[j][i-1]][i-1], D[j][i-1]);
        }
     }
   }
   int ans=0;
   for (auto i : edgeList){
        a = i.a;
        b = i.b;
        int l = LCA(a,b);
        // cout<<a<<' '<<b<<l<<'\n';
        int w = max(fd(a,depth[a] - depth[l]), fd(b,depth[b]-depth[l]));
        // cout<<i.w<<' '<<w<<'\n';
        if (w == i.w)++ans;
   }
   cout<<ans-N+1;
}