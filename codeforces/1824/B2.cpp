#include <bits/stdc++.h>
#define FOR(i,p,k) for(int i=(p);i<=(k);++i)
#define REP(i,n) FOR(i,0,(n)-1)
#define ssize(x) (int((x).size()))
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define inf 1000000000
#define infll 1000000000000000000ll
#define fi first
#define se second
#define mod 1000000007ll
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

ll pot(ll a, ll b = mod-2ll){
	ll ret = 1ll;
	for(; b; b>>=1, a=(a*a)%mod) if(b&1ll) ret = (ret*a)%mod;
	return ret;
}

void solve(){
	int n, k;
	scanf("%d%d", &n, &k);
	vector<vector<int>> g(n+1);
	REP(i, n-1){
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	
	if(k&1) return printf("1\n"), void();
	
	vector<ll> sil(n+1, 1ll), odwsil(n+1, 1ll);
	FOR(i, 1, n) sil[i] = (sil[i-1]*ll(i))%mod;
	odwsil[n] = pot(sil[n]);
	for(int i = n; --i;) odwsil[i] = (odwsil[i+1]*ll(i+1))%mod;
	auto dwumian = [&](int N, int K){
		if(K < 0 || K > N) return 0ll;
		return (((sil[N]*odwsil[K])%mod)*odwsil[N-K])%mod;
	};
	
	ll wyn = 0ll;
	
	vector<int> pdd(n+1, 1);
	function<void(int, int)> dfs = [&](int w, int o){
		for(int i : g[w]) if(i != o) dfs(i, w), pdd[w] += pdd[i];
		
		wyn += 1ll*dwumian(pdd[w], k/2)*dwumian(n-pdd[w], k/2);
		wyn %= mod;
	};
	dfs(1, 0);
	
	wyn = (wyn*pot(dwumian(n, k)))%mod;
	wyn = (wyn+1ll)%mod;
	printf("%lld\n", wyn);
}

int main(){
	int t = 1;
	//~ scanf("%d", &t);
	while(t--) solve();
	return 0;
}
