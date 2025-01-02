#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool rec(ll p, ll q, vector<ll> &v){
	if(v.size() == 1)
		return ((__int128) p == ((__int128) q * v.back()));
	ll gc = gcd(p, q);
	p /= gc, q /= gc;
	if((__int128) p <= ((__int128) q * v.back()))
		return 0;
	ll a = v.back();
	v.pop_back();
	return rec(q, p - (a * q), v);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0); 

	ll p, q, n; cin >> p >> q >> n;
	vector<ll> v(n);
	for(ll &i : v)
		cin >> i;
	reverse(v.begin(), v.end());
	if(rec(p, q, v) && cout << "YES\n")
		return 0;
	cout << "NO\n";
}