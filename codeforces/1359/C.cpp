#include <iostream>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <stdio.h>
#include <stack>
#include <iterator>
#include <numeric>
#include <unordered_map>
#include <cstdlib> 
#include <ctime>
 
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define ll long long
#define ull unsigned long long
#define oo 1000000007
#define oooo 1000000000000000007
#define BLOCK 174
#define LOG 19
#define endl "\n"
#define iii pair<int, ii>
#define bitinc(x) (x & -x);
#define TIME cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << " secs \n"
 
#define maxN 400005
using namespace std;
// int a[maxN], st[maxN], en[maxN];
// int n, timer, q;
// int high[maxN], par[maxN][30];
// vi adj[maxN];
// ll bit[maxN];
// int XOR(int ind) {
// 	int xo = 0;
// 	while (ind > 0) {
// 		xo ^= bit[ind];
// 		ind -= bitinc(ind);
// 	}
// 	return xo;
// }
// void upd(int ind, int val) {
// 	while (ind <= timer) {
// 		bit[ind] ^= val;
// 		ind += bitinc(ind);
// 	}
// }
// void dfs(int u, int far){
// 	st[u] = timer++;
// 	for(int v: adj[u]) if (v != far) {
// 		high[v] = high[u]+1;
// 		par[v][0] = u;	
// 		dfs(v, u);
// 	}
// 	en[u] = timer++;
// }
// int lca(int u, int v){
// 	if (high[v] > high[u]) swap(u, v);

// 	for (int i = LOG; i >= 0; i--) if (high[par[u][i]] >= high[v]) u = par[u][i];
// 	if (u == v) return u;

// 	for (int i = LOG; i >= 0; i--) if (par[u][i] != par[v][i]) {
// 		u = par[u][i]; v = par[v][i];
// 	}
// 	return par[u][0];
// }
// void solve(){
// 	cin >> n >> q;
// 	fto(i, 1, n) cin >> a[i];
// 	fto(i, 1, n-1){
// 		int u, v; cin >> u >> v;
// 		adj[u].pb(v);
// 		adj[v].pb(u);
// 	}
// 	timer = 1;
// 	dfs(1, 0);
// 	for(int i = 1; i <= LOG; ++i) for(int j = 1; j <= n; ++j) par[i][j] = par[par[i][j-1]][j-1];
// 	high[0] = -1;
// 	fto(i, 1, n) {
// 		upd(st[i], a[i]);
// 		upd(en[i], a[i]);
// 	}

// 	while(q--){
// 		int t; cin >> t;
// 		if (t == 1){
// 			int u, v; cin >> u >> v;
// 			upd(st[u], a[u]);
// 			upd(en[u], a[u]);
// 			a[u] = v;
// 			upd(st[u], v);
// 			upd(en[u], v);
// 		}
// 		else{
// 			int u, v; cin >> u >> v;
// 			int z = lca(u, v);
// 			// cout << z << endl;
// 			cout << (XOR(st[u]) ^ XOR(st[v]) ^ a[z]) << endl;
// 		}
// 	}
// }
ll h, c;

void solve(){
	ll t; cin >> h >> c >> t;
	if (2*t <= h+c){
		cout << 2 << endl;
		return;
	}
	int a = h - t;
	int b = 2 * t - c - h;
	int k = 2 * (a / b) + 1;
	long long val1 = abs(k / 2 * 1ll * c + (k + 1) / 2 * 1ll * h - t * 1ll * k);
	long long val2 = abs((k + 2) / 2 * 1ll * c + (k + 3) / 2 * 1ll * h - t * 1ll * (k + 2));
	cout <<  (val1 * (k + 2) <= val2 * k ? k : k + 2) << endl;
}
int main() {
	srand(time(NULL));
 
	ios_base::sync_with_stdio(false); cin.tie(NULL); 

	#ifndef ONLINE_JUDGE
	freopen("test.inp", "r", stdin);
	// freopen("test.out", "w", stdout);
	#endif // ONLINE_JUDGE
	
	int t = 1; 
	cin >> t;
	while(t--){
		solve();
	}
	TIME;
	return 0;
}