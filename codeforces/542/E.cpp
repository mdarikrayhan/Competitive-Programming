#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;
typedef long double	ld;
typedef pair<int, int>	pii  ;
typedef pair<ll, ll>	pll  ;
typedef vector<pii>     vii  ;
typedef vector<int>     veci ;
typedef vector<pll>     vll  ;
typedef vector<ll>      vecll;

// find_by_order             order_of_key

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define F		        first
#define S		        second
#define pb		        push_back
#define endl            '\n'
#define Mp		        make_pair
#define all(x)          x.begin(), x.end()
#define debug(x)        cerr << #x << " = " << x << endl
#define set_dec(x)	    cout << fixed << setprecision(x);
#define fast_io         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io         freopen("in.txt" , "r+" , stdin) ; freopen("out.txt" , "w+" , stdout);
#define lb              lower_bound
#define ub              upper_bound
#define for1(n)         for(int i=1;i<=n;i++)
#define for0(n)         for(int i=0;i<n;i++)
#define forn(n)         for(int i=n;i>0;i--)
#define pq              priority_queue <int, vector<int>, greater<int>>


ll mod = 1e9+7 ;// 998244353 ;// 1e9+9;

ll inf=1e18;
const int N=1e3+100,L=21;
int A[N],B[N],C[N],D[N],E[N],n,m,k,dp[N],anss[N],dist[N][N],vis[N];
vector<int>g[N];

bool bfs(int v){
    queue<int> q;dist[v][v]=0;
    q.push(v);
    while(q.size()){
        int v2=q.front();q.pop();
        vis[v2]=v;
        for(int u:g[v2]){
            if(dist[v][u]>dist[v][v2]+1){
                dist[v][u]=dist[v][v2]+1;
                q.push(u);
            }
            if(dist[v][u]==dist[v][v2]) return 1;
        }
    }
    return 0;
}
int main(){
    fast_io
    cin>>n>>m;
    for1(m){
        int u,v;cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for1(n) for(int j=1;j<=n;j++)dist[i][j]=N;
    int ans=0;
    for1(n)if(bfs(i)) return cout<<-1<<endl,0;
    for1(n) for(int j=1;j<=n;j++) if(dist[i][j]!=N) anss[vis[i]]=max(anss[vis[i]],dist[i][j]);
    for1(n) ans+=anss[i];
    cout<<ans<<endl;

}



