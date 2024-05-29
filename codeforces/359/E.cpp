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
const int N=600,L=21;
int A[N][N],B[N],C[N],D[N],E[N],n,m,k,dp[N],vis[N][N],dist[N][N];
vector<pii>g[N][N];
queue<pii> q;
string ans;
int dir[]={1,-1,0,0};
int di[]={0,0,1,-1};
void dfs2(int x,int y,int p1=0,int p2=0){
    vis[x][y]=1;
    for0(4){
        int xx=x+dir[i],yy=y+di[i];
        if(vis[xx][yy]) continue;
        bool o=0;
        while(0<=xx && xx<=n && 0<=yy && yy<=n){
            o|=(A[xx][yy]==1);
            xx+=dir[i];
            yy+=di[i];
        }
        xx=x+dir[i];yy=y+di[i];
        if(o && (xx!=p1 || yy!=p2)){
            g[x][y].pb({xx,yy});
            dfs2(xx,yy,x,y);
        }
    }
    A[x][y]=(A[x][y]==1 ? 2:0);
}
void dfs(int v1,int v2){
    if(A[v1][v2]==0) cout<<1;
    for(auto[u1,u2]:g[v1][v2]){
        if(v1-u1==1) {cout<<"U";dfs(u1,u2);cout<<"D";}
        else if(v1-u1==-1) {cout<<"D";dfs(u1,u2);cout<<"U";}
        else if(v2-u2==-1) {cout<<"R";dfs(u1,u2);cout<<"L";}
        else {cout<<"L";dfs(u1,u2);cout<<"R";}
    }
    cout<<2;
}
int main(){
    fast_io
    int x,y;
    cin>>n>>x>>y;
    for1(n)for(int j=1;j<=n;j++) cin>>A[i][j];
    dfs2(x,y);
    bool o=1;
    //for1(n) {for(int j=1;j<=n;j++) cout<<A[i][j]<<" ";cout<<endl;}
    for1(n)for(int j=1;j<=n;j++) if(A[i][j]==1) o=0;
    if(!o)return cout<<"NO\n",0;
    cout<<"YES\n";
    dfs(x,y);
}
