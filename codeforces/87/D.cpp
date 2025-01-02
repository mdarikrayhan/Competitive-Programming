// In the name of God
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define F first
#define S second
#define pii pair<int, int>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int maxn = 1e5 + 10;
int n, par[maxn], h[maxn], w[maxn];
ll siz[maxn], a[maxn], m;
vector <pair<int, pii>> v;
vector <int> g[maxn], ans;

int get_par(int x){
	return par[x] == x ? x : par[x] = get_par(par[x]);
}

void dfs(int x, int y){
	h[x] = h[y] + 1;
	for(int i : g[x]){
		if(i != y) dfs(i, x);
	}
}

bool comp(pair<int, pii> x, pair<int, pii> y){
	if(w[x.F] == w[y.F]){
		int m1 = max(h[x.S.F], h[x.S.S]), m2 = max(h[y.S.F], h[y.S.S]);
		return m1 > m2;
	}
	return w[x.F] < w[y.F];
}

int main(){
	FAST;
	cin >> n;
	for(int i = 1; i <= n; i++){
		par[i] = i;
		siz[i] = 1;
	} 
	for(int x, y, z, i = 1; i < n; i++){
		cin >> x >> y >> z;
		g[x].pb(y);
		g[y].pb(x);
		w[i] = z;
		v.pb({i, {x, y}});
	}
	dfs(1, 0);
	sort(v.begin(), v.end(), comp);
	
	vector <pair<pii, ll>> tmp;
	for(int i = 0; i < n - 1; i++){
		if(h[v[i].S.S] > h[v[i].S.F]) swap(v[i].S.S, v[i].S.F);
		int p1 = get_par(v[i].S.F), p2 = get_par(v[i].S.S);
		tmp.pb({{v[i].F, v[i].S.S}, siz[p1]});
		par[p1] = p2;
		siz[p2] += siz[p1];
		if((i < n - 2 && w[v[i].F] != w[v[i + 1].F]) || i == n - 2){
			for(auto j : tmp){
				a[j.F.F] = 2LL * j.S * (siz[get_par(j.F.S)] - j.S);
			}
			tmp.clear();
		}
	}
	
	for(int i = 1; i < n; i++){
		m = max(m, a[i]);
	}
	for(int i = 1; i < n; i++){
		if(a[i] == m) ans.pb(i);
	}
	cout << m << " " << ans.size() << "\n";
	for(int i : ans){
		cout << i << " ";
	}
	
	return 0;
}