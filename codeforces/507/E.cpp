#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define ll long long
#define ld long double
#define fuk return
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define pb push_back
#define tr(it,a) for(auto it=a.begin();it!=a.end();it++)
#define fo(i,n) for(int i=0;i<n;i++)
#define fop(i,x,n) for(int i=x;i<=n;i++)
#define forv(i,l,n) for(int i=l;i>=n;i--)
#define nl  << endl;
typedef pair<ll,ll> pl;
typedef vector<ll> vl;
typedef vector < pair <ll,ll > > vp;
typedef vector<bool> vb;
typedef vector<ld> vd;
typedef vector<string> vs;
#define inp(v, n) for(int i=0; i<n; ++i) cin >> v[i];
#define opt(v) for(auto x: v) cout << x << ' '; cout << endl;
const ll mod = 1000000007;
const ll N = 2e5+10;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
ll binpow(ll a, ll b) {
ll result = 1;
while (b > 0) {
if (b & 1)
result *= a;
        a *= a;
a %= mod;
b /= 2;
result %= mod;
}
return result;
}
ll m,n;
vector <vector < pair <ll,ll > > > g(N);
vector <pair <ll,ll> > wdist(N);
ll x[N],y[N],z[N];
ll visited[N];
ll par[N];
void dijkstra(ll sc){
    fop(i,1,n){
        wdist[i].first=1e18;
        wdist[i].second=1e18;
        visited[i]=0;
        par[i]=i;
    }
    priority_queue <pair <ll,ll> > pq;
    pq.push(make_pair(-0,sc));
    wdist[sc].first=0;
    wdist[sc].second=0;
    while (!pq.empty())
    {
        pair < ll,ll>  fs=pq.top();
        pq.pop();
        if(visited[fs.second]) continue;
        visited[fs.second]=1;
        for(auto v: g[fs.second]){
            ll neigh=v.first;
            ll cost=v.second;
            if(wdist[neigh].first>=wdist[fs.second].first+1 && (wdist[neigh].second)>wdist[fs.second].second+(1^cost)){
                wdist[neigh].first=wdist[fs.second].first+1;
                 (wdist[neigh].second)=wdist[fs.second].second+(1^cost);
                 par[neigh]=fs.second;
                 pq.push(make_pair(-wdist[neigh].first,neigh));
            }
        }
    }
    
}
void solve(){
    cin>>n>>m;
    ll ones=0;
    fo(i,m){
        cin>>x[i]>>y[i]>>z[i];
        if(z[i]) ones++;
        g[x[i]].push_back(make_pair(y[i],z[i]));
        g[y[i]].push_back(make_pair(x[i],z[i]));
    }
    fop(i,1,n) sort(all(g[i]));
    dijkstra(1);
    // cout<<wdist[n].first<<" "<<wdist[n].second nl
    ll xe=n;
    vl vec;
    set<ll> st;
    while(xe!=1){
        st.insert(xe);
        xe=par[xe];
        vec.pb(xe);
        // cout<<xe<<" ";
    }
    // cout nl
    ll cnt=vec.size();
    fop(i,1,n){
        if(st.find(i)==st.end()){
            par[i]=0;
        }
    }
    
    ones=ones-(vec.size()-wdist[n].second);
    ll k=ones+wdist[n].second;
    cout<<k nl
    fo(i,m){
        // cout<<x[i]<<" "<<y[i] nl
        if(par[x[i]]==y[i] || par[y[i]]==x[i]){
            ll cnt=z[i];
            if(z[i]){
                continue;
            }else{
                cout<<x[i]<<" "<<y[i]<<" 1\n";
            }
        }else{
            if(z[i]==0) continue;
            cout<<x[i]<<" "<<y[i]<<" 0\n";
        }
    }
    
}   
signed main(){
    IOS
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
    return 0;
}