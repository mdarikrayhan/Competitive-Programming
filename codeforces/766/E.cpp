//1L1YA
//Brightest lights rises from the darkest nights

#include<bits/stdc++.h>
using namespace std;

//#pragma GCC optimize ("O3,unrool-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

typedef long long       ll;
typedef pair<ll,ll>     pll;
typedef pair<int,int>   pii;

#define Pb              push_back
#define dokme(x)        cout << x << endl, exit(0)
#define F               first
#define S               second
#define endl            '\n'
#define sep             ' '
#define all(x)          x.begin(),x.end()
#define lc              (id<<1)
#define rc              (lc|1)
#define mid             (l+r>>1)
#define FastIO          ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FileIO          freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll oo=1e18;
const int mod=1e9+7;
const int inf=1e9+111;
const int N=2e5+11;
const int lg=23;

ll n,ans,a[N],b[N],val[N],cnt[N][2];
vector<int> adj[N];

void dfs(int v,int x,int p=0){
    val[v]^=b[v];
    cnt[v][0]=cnt[v][1]=0;
    cnt[v][val[v]]++;
    ans+=b[v]*(1<<x);
    for(int u: adj[v])
        if(u!=p){
            val[u]=val[v];
            dfs(u,x,v);
            ans+=(cnt[v][0]*cnt[u][1^b[v]]+cnt[v][1]*cnt[u][b[v]])*(1<<x);
            cnt[v][0]+=cnt[u][0];
            cnt[v][1]+=cnt[u][1];
        }
}

void solve(int k){
    for(int i=1;i<=n;i++)    b[i]=a[i]>>k&1;
    val[1]=0;
    dfs(1,k);
}

int main(){
    FastIO

    cin >> n;
    for(int i=1;i<=n;i++)    cin >> a[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        adj[u].Pb(v);
        adj[v].Pb(u);
    }
    for(int i=0;i<lg;i++)    solve(i);
    cout << ans << endl;

    return 0;
}