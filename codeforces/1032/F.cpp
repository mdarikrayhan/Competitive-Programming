#include <bits/stdc++.h>

using namespace std;

#define TASK ""
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FOr(i,a,b) for (int i=a;i<b;++i)
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;

const int MOD=998244353;
const ll INF=(ll)1e18+7;

const int maxn=300005;

int dp[maxn][3];
vector<int> adj[maxn];

int power(int a,int b){
	int ret=1;
	for (;b;b>>=1,a=1ll*a*a%MOD) if (b&1) ret=1ll*ret*a%MOD;
	return ret;
}

void dfs(int u,int par) {
    dp[u][0]=1;
    dp[u][1]=1;
    dp[u][2]=0;
    int s=1;
    FOr(i,0,int(adj[u].size())) {
        int v=adj[u][i];
        if (v==par) continue;
        dfs(v, u);
        dp[u][1]=(1ll*dp[u][1]*(dp[v][0]+dp[v][2])%MOD)%MOD;
        s=1ll*s*((dp[v][0]+dp[v][2])%MOD)%MOD;
        dp[u][0]=(1ll*dp[u][0]*dp[v][0])%MOD;
    }
    FOr(i,0,int(adj[u].size())) {
        int v=adj[u][i];
        if (v==par) continue;
        int x=power((dp[v][0]+dp[v][2])%MOD,MOD-2);
        int y=(1ll*dp[v][1]*((1ll*s*x)%MOD))%MOD;
        (dp[u][0]+=y)%=MOD;
        (dp[u][2]+=y)%=MOD;
    }
}

void solve() {
    int n;
    cin>>n;
    FOr(i,1,n) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
//    FOR(u,1,n) cout<<dp[u][0]<<' '<<dp[u][1]<<' '<<dp[u][2]<<"\n";
    cout<<dp[1][0]<<"\n";
}

int main() {
    fastio();
    if (fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    int T;
//    cin >> T;
    T = 1;
    while (T--)
        solve();
    return 0;
}

//著者: ナティック
