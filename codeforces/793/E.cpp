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
#define file_io         freopen("in.txt" , "r" , stdin) ; freopen("out.txt" , "w" , stdout);
#define lb              lower_bound
#define ub              upper_bound
#define for1(n)         for(int i=1;i<=n;i++)
#define for0(n)         for(int i=0;i<n;i++)
#define forn(n)         for(int i=n;i>0;i--)
#define pq              priority_queue <int, vector<int>, greater<int>>


ll mod = 1e9+7 ;// 998244353 ;// 1e9+9;

ll inf=1e18;
const int N=5e3+100,L=21;
int A[N],C[N],D[N],E[N],n,m,k,a,b,c,d,aa,cc,dp[N],sum[N],is[N],p[N];
vector<int>g[N],vec1,vec2;
bool o;
void dfs(int v,int p=0){
    for(int u:g[v])if(u!=p){
        dfs(u,v);
        sum[v]+=sum[u];
        if(is[u]){
            if(is[v] && v!=1) o=0;
            is[v]=is[u];
        }
    }
    for(int u:g[v]) if(u!=p){
        if((is[v]==1 || is[v]==2 || v==1) && is[u]==0) vec1.pb(sum[u]);
        if((is[v]==3 || is[v]==4 || v==1) && is[u]==0) vec2.pb(sum[u]);
        if(v==1 && is[u]==3) cc=sum[u];
        if(v==1 && is[u]==1) aa=sum[u];
    }
    sum[v]=max(sum[v],1);
    if(v==a) is[v]=1;
    if(v==b) is[v]=2;
    if(v==c) is[v]=3;
    if(v==d) is[v]=4;
}
bitset<N> B;
int main(){
    fast_io
    cin>>n;
    cin>>a>>b>>c>>d;
    for(int i=2;i<=n;i++){
        cin>>p[i];
        g[i].pb(p[i]);
        g[p[i]].pb(i);
    }
    o=1;
    dfs(1);
    if(o==0 || sum[1]%2==1)return cout<<"NO\n",0;
    B[cc]=1;
    for(int x:vec1)
        B|=B<<x;
    o&=B[(sum[1]-2)/2];
    B=0;
    B[aa]=1;
    for(int x:vec2)
        B|=B<<x;
    o&=B[(sum[1]-2)/2];
    cout<<(o ? "YES\n":"NO\n");

}



