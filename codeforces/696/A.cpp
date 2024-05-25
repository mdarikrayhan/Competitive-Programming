#include <bits/stdc++.h>
using namespace std;
#define  ll long long 
#define  all(v) ((v).begin()),((v).end())
#define  rall(v) ((v).rbegin()),((v).rend())
#define Fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define close(n) return cout<<n,0;
const int dx[] = { -1,0,1,0,1,-1,1,-1 };
const int dy[] = { 0,1,0,-1,1,-1,-1,1 };
const int di[] = { 'U','R','D','L' };
int countbit(ll n) { return (n > 1 ? (n & 1) + countbit(n >> 1) : n); }
ll gcd(ll x, ll y) { if (!y)return x; return gcd(y, x % y); }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }
const int N = 5e5 + 3, mod = 1e9 + 7;
map<ll, ll>m;
ll LCA(ll v,ll u,ll w=-1) {
	ll cost = 0;
	while (v ^ u) {
		if (v < u)
			swap(v, u);
		if (~w)
			m[v] += w;
		else cost += m[v];
		v >>= 1;
	}
	return cost;
}
void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll t, u, v, w;
		cin >> t>>v>>u;
		if (t == 1) {
			cin >> w;
			LCA(v, u, w);
		}
		else cout << LCA(v, u)<<'\n';
	}
}
int main()
{
	Fast;
	int T = 1;
	//cin >> T;
	while (T--) {
		solve();
	}
}