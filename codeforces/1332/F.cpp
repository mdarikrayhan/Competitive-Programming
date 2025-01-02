#include<bits/stdc++.h>
/*
 @@@@@@@@@@   @@@@@@@@  @@@  @@@  @@@@@@@    @@@@@@   @@@@@@@
 @@@@@@@@@@@  @@@@@@@@  @@@  @@@  @@@@@@@@  @@@@@@@@  @@@@@@@@
 @@! @@! @@!  @@!       @@!  @@@  @@!  @@@  @@!  @@@  @@!  @@@
 !@! !@! !@!  !@!       !@!  @!@  !@!  @!@  !@!  @!@  !@!  @!@
 @!! !!@ @!@  @!!!:!    @!@!@!@!  @!@!!@!   @!@!@!@!  @!@  !@!
 !@!   ! !@!  !!!!!:    !!!@!!!!  !!@!@!    !!!@!!!!  !@!  !!!
 !!:     !!:  !!:       !!:  !!!  !!: :!!   !!:  !!!  !!:  !!!
 :!:     :!:  :!:       :!:  !:!  :!:  !:!  :!:  !:!  :!:  !:!
 :::     ::    :: ::::  ::   :::  ::   :::  ::   :::   :::: ::
  :      :    : :: ::    :   : :   :   : :   :   : :  :: :  :

 */
using namespace std;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define all(v) v.begin(),v.end()
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define SZ(x) int(x.size())
#define MP make_pair
#define pb push_back
#define S second
#define F first
#define pss ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define kill(a) {cout<<a<<'\n';return;}
typedef long long ll;
typedef double dbl;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef pair<ld,ld> pdd;
typedef pair<int,long long> pil;
typedef pair<long long,int> pli;
const int xn=3e5+2,mod=998244353,inf=2e9;
ll dp[xn][2],n,m,tmp[xn];
vector<int> adj[xn];
void dfs(int v,int p){
    if(SZ(adj[v])==1 && v!=1){
        tmp[v]=dp[v][0]=1;
        return;
    }
    tmp[v]=1;
    dp[v][0]=dp[v][1]=1;
    for(int u:adj[v]){
        if(u==p)continue;
        dfs(u,v);
        dp[v][1]=dp[v][1]*(dp[u][0]+dp[u][0]+dp[u][1]) %mod;
        dp[v][0]=dp[v][0]*((2*((dp[u][0]+dp[u][1])%mod)+tmp[u])%mod) %mod;
        tmp[v]=tmp[v] * ((dp[u][0]+dp[u][1])%mod) %mod;
    }
    dp[v][1]=(dp[v][1]-tmp[v]+mod)%mod;
}
int main(){
    pss
    cin>>n;
    int u,v;
    f(i,1,n)cin>>u>>v,adj[u].pb(v),adj[v].pb(u);
    dfs(1,0);
    cout<<(dp[1][1]+dp[1][0]-1+mod)%mod<<'\n';
    return 0;
}