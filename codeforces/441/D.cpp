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
vll p;
vector<bool> vis;
void cycle(ll v){
	for(ll i = v; !vis[i]; i = p[i]){
		vis[i] = true;
	}
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	ll n; cin >> n;
	vis = vector<bool>(n, false);
	p = vll(n);
	for(ll i = 0; i < n; i++){
		cin >> p[i];
		p[i]--;
	}
	ll m; cin >> m; 
	m = n - m;
	ll k = 0;
	for(ll i = 0; i < n; i++){
		if(!vis[i]){
			k++;
			cycle(i);
		}
	}
	vis = vector<bool>(n, false);
	cout << abs(k - m) << '\n';
	if(k > m){
		cycle(0);
		for(ll i = 1; i < n && k > m; i++){
			if(!vis[i]){
				cout << 1 << " " << i + 1 << '\n';
				k--;
				cycle(i);
			}
		}
	}
	if(k < m){
		for(ll i = 0; i < n && k < m; i++){
			vll pos(n, -1);
			ll cur = 0;
			for(ll j = p[i]; j != i; j = p[j]){
				pos[j] = cur++;
			}
			pos[i] = cur;
			cur = 0;
			for(ll j = i+1; j < n && k < m; j++){
				if(pos[j] >= cur){
					cout << i + 1 << " " << j + 1 << '\n';
					k++;
					cur = pos[j] + 1;
					swap(p[i], p[j]);
				}
			}
		}
	}
	return 0;
}