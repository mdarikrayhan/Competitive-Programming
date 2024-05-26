#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using ld = long double;
using ull = unsigned long long;
#define pb  push_back
#define pf  push_front
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first
#define y second
const ll mod = 1e9 + 7;
const int N = 1e5;
const ll INF = 1e18;


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	ll n; cin >> n;
	vector<vll> g(2*n+1);
	vector<pll> a(n);
	for(ll i = 0; i < n; i++){
		cin >> a[i].x;
		a[i].y = i;
	}
	sort(rall(a));
	vll b(2*n+1, -1);
	for(ll i = 0; i < n; i++){
		ll j = a[i].y;
		b[i] = (2 * j);
		g[i + a[i].x].pb(2*j+1);
	}
	for(ll i = n; i < 2*n; i++){
		if(!g[i].empty()){
			b[i] = g[i].back();
			g[i].pop_back();
		}
		else{
			break;
		}
	}
	for(ll i = 1; i < 2*n; i++){
		if(b[i] == -1) break;
		else{
			cout << b[i-1] + 1<< " " << b[i] + 1 << '\n';
		}
	}
	for(ll i = 1; i < 2*n; i++){
		for(auto v : g[i]){
			cout << b[i-1] + 1 << " " << v + 1 << '\n';
		}
	}
	return 0;
}