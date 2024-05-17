#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
// log 10 base 2 = 3.322
ll mod = 1e9 + 7;
ll power(ll x, ll y){
	ll res = 1;
	while(y > 0){
		if(y%2) res = (res*x)%mod;
		y /= 2;
		x = (x*x)%mod;
	}
	return res;
}

vector<ll>f;

int main(){
	ll t;
	cin>>t;
	while(t--){
		ll l, r;
		cin>>l>>r;
		vector<ll>a(r - l + 1);
		int n = r - l + 1;
		for(ll i = 0; i < n;i++){
			cin>>a[i];
		}
		ll x = 0;
		for(ll i = 0; i < 17; i++){
			ll set_bits = 0;
			for(ll j = 0; j < n; j++){
				if(a[j] & (1<<i)) set_bits++;
			}
			if(set_bits > n - set_bits) x += (1<<i);
		}
		cout<<x<<endl;
	}
	return 0;
}