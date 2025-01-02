#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(long long i=a;i<=b;i++)
#define FORR(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define piii pair<int, pii>
#define pb push_back
#define F first
#define S second
#define SZ(x) (int)x.size()
//#define int long long

const ll 
            MX = 10010,
            inf = 1e9+5,
            infl = 1e18+5;

ll n, m, N=0, M=0, flpar[MX];
vector<int> adj[MX];
int c[MX], p[MX];


struct edge {
    ll u, v, cap, f;
    edge () {

    }
    edge(int u1, int v1, int cap1){
        u = u1;
        v = v1;
        cap = cap1;
        f = 0;
    }
};
edge ed[MX];

void add_e(int u, int v, int cap=1) {
	ed[M++] = edge(u, v, cap);
	adj[u].pb(M-1);
	ed[M++] = edge(v, u, 0);
	adj[v].pb(M-1);
}

void push_flow_edge(int i) {
	ed[i].f += 1;
	ed[i^1].f -= 1;
}

void push_flow(int u, int v) {
	int i = flpar[v];
	while(i>=0) {
		push_flow_edge(i);
		v = ed[i].u;
		i = flpar[v];
	}
}

int dfs(int u) {
	int ans = -1;
	int cnt = 0;
	for(int i:adj[u]) if(flpar[ed[i].v] == -1 and ed[i].cap - ed[i].f > 0) {
		cnt++;
		flpar[ed[i].v] = i;
		ans = max(ans, dfs(ed[i].v));
	}
	if(u < 5000 or cnt==0) ans = max(ans, u);
	return ans;
}

int remove_e(int i) {
	int ans = -1;
	i*=2;
	if(ed[i].cap == 0) cout<<"FUCK\n";
	//cout<<ed[i].u<<' '<<ed[i].v<<'\n';
	if(ed[i].f != 0) ans = min(ed[i].u, ed[i].v);
	ed[i].f = 0;
	ed[i].cap = 0;
	ed[i^1].f = 0;
	ed[i^1].cap = 0;
	return ans;
}

int32_t main(){
    iostream::sync_with_stdio(0);
    cin>>n>>m;
    N = m+5000;
    FOR(i, 1, n) cin>>p[i];
    FOR(i, 1, n) cin>>c[i];
    FOR(i, 1, n) {
    	add_e(p[i], c[i]+5000);
    }
    int n1 = 5000;
    int ans = 0;
    FOR(i, 0, n1-1) {
    	FOR(j, 0, N) flpar[j] = -1;
    	flpar[i] = -2;
    	int x = dfs(i);
    	if(x<=i) break;
    	ans = i+1;
    	push_flow(i, x);
    }
    //cout<<"GG"<<ans<<'\n';
    int d, k;
    cin>>d;
    while(d--) {
    	cin>>k;
    	int u = remove_e(k-1);
    	if(u != -1 and u<=ans) {
    		FOR(j, 0, N) flpar[j] = -1;
    		flpar[u] = -2;
    		int x = dfs(u);
    		//cout<<u<<' '<<x<<'\n';
    		//if(x <= u) cout<<"GG1\n";
    		//else if(x <= ans) cout<<"GG2\n";
    		if(x <= u) ans = u;
    		else if(x <= ans) ans = x;
    		push_flow(u, x);
    	}
    	cout<<ans<<'\n';
    }
}