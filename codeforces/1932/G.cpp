#include<bits/stdc++.h>
#define ll long long
#define SD ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define flot(n) cout << setprecision(n) << setiosflags(ios::fixed) << setiosflags(ios::showpoint)
#define all(a) (a).begin() , (a).end()
#define F first
#define S second
#define pii pair<ll,ll>
#define pb push_back
#define endl '\n'
#define ar array
#define ld long double
using namespace std;
void readFromFile(string input = "input.txt",string output="output.txt") {
    #ifndef ONLINE_JUDGE
        freopen(input.c_str(),"r",stdin);
        freopen(output.c_str(),"w",stdout);
    #endif
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(time(0));
ll rand(ll x, ll y) {
    return uniform_int_distribution<ll>(x, y)(rng);
}
const int INF = 0x3f3f3f3f;
const ll INFLL = 2e18;
const int mod= 1e9+9;
const ld eps = 1e-6;
ll mul(ll x,ll y,ll mod=mod){return (long long) (x%mod)*(y%mod)%mod;}
ll add(ll x,ll y,ll mod=mod){x+=y; return x%mod;}
ll sub(ll x,ll y,int mod=mod){x-=y;return (x%mod+mod)%mod;}
int power(int x,ll y,int mod=mod){if(!y)return 1;int ret=power(x,y/2,mod);
ret = mul(ret,ret,mod);if(y&1) ret = mul(ret,x,mod);return ret;}
const int N = 2e5+9;
const int sq = 500;
int n,m,h,l[N],s[N],d[N];
bool vis[N];
vector<int> gr[N];
ll dist[N];
ll gcd(ll x,ll y) {
    if(y == 0) return x;
    return gcd(y,x%y);
}
ll Inv(ll a,ll mod) {
    if(a == 1)
        return 1;
    return (1 - Inv(mod % a, a) * mod) / a + mod;
}
void solve() {
    cin >> n >> m >> h;
    for(int i = 1 ; i <= n ; i++) {
        cin >> l[i];
    }
    for(int i = 1 ; i <= n ; i++) {
        cin >> s[i];
        dist[i] = 4e18;
        gr[i].clear();
        vis[i]=0;
    }
    for(int i = 0 ; i < m ; i++) {
        int x,y;
        cin >> x >> y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    priority_queue<pii> pr;
    pr.push({0,1});
    dist[1] = 0;
    while(!pr.empty()) {
        int i = pr.top().S;
        pr.pop();
        if(vis[i])continue;
        vis[i] = 1;
        for(auto j:gr[i]) {
            if(vis[j])continue;
            int y = s[i]-s[j];
            int z = (l[j]+(ll)s[j]*d[i])%h-(l[i]+(ll)s[i]*d[i])%h;
            if(y<0)y+=h;
            if(z<0)z+= h;
            ll x;
            if(y == 0) {
                if(z != 0) continue;
                x = 0;
            }else {
                ll gc = gcd(y,h);
                if(z%gc != 0) continue;
                ll sz = h/gc;
                z /= gc;
                y /= gc;
                x = (z*Inv(y,sz))%sz;
            }
            if(dist[j] > dist[i]+x+1) {
                dist[j] = dist[i]+x+1;
                d[j] = dist[j]%h;
                pr.push({-dist[j],j});
            }
        }
    }
    if(dist[n] == 4e18)dist[n] =-1;
    cout << dist[n] << endl;
}
int32_t main() {
   readFromFile();
    SD;
    int t = 1;
    cin >> t;
    for(int i = 0 ; i < t ; i++) {
        solve();
    }
}
