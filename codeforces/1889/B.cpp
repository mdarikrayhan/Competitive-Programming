#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
const ll mod = 998244353;
using dbl = long double;

ll add(ll a, ll b) {
	return (a % mod + b % mod) % mod;
}

ll mul(ll a, ll b) {
	return ((a % mod) * (b % mod)) % mod;
}

ll sub(ll a, ll b) {
	return (a - b + mod) % mod;
}

ll hcf(ll a, ll b){
	if(b==0LL) return a;
	return hcf(b, a%b);
}


void solve(int tc) {
	int n; ll c; cin>>n>>c;
	vector<ll> a(n+1);
	vector<pair<ll,int>> p(n+1);
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		p[i] = { a[i] - i*c, i }; // Correct Sort
	}
	auto cmp = [](pair<ll,int>& x, pair<ll,int>& y) {
		if(x.first == y.first) return x.second < y.second;
		return x.first > y.first;
		};
	sort(p.begin()+2, p.end(), cmp);
	ll sum=a[1];
	for(int i=2; i<=n; i++) {
		ll idx = p[i].second;
		ll aVal = a[idx];
		if(aVal + sum < idx * c) {
			cout << "No" << endl;
			return;
		}
		sum += aVal;
	}
	cout << "Yes" << endl;
}

int main() {
	/*freopen("talent.in", "r", stdin);
	freopen("talent.out", "w", stdout);*/
	int t = 1;
	bool multi = true;
	if (multi)
		cin >> t;
	for (int i = 0; i < t; i++) {
		solve(i);
	}
}