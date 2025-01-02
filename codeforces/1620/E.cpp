#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<list>

#define ll long long int
#define loop(n) for(ll i = 0; i < n; i++)
#define looop(n) for(ll j = 0; j < n; j++)
#define arrinp(a, n) loop(n) {cin >> a[i];}
#define printelems(a) for(auto i : a) cout << i << ' '; cout << endl;
#define mod 1000000007
#define sort(a) sort(a.begin(), a.end());
using namespace std;


	// ll fast_pow(ll b, ll e){
	// 	ll res = 1;
	// 	while(e > 0){
	// 		if(e % 2 == 1){
	// 			res = res * b % mod;
	// 		}
	// 		b = b * b % mod;
	// 		e /= 2;
	// 	}
	// 	return res;
	// }
	
	ll gcd(ll a, ll b)
	{
		if (a == 0)
			return b;
		return gcd(b % a, a);
	}
	
	// ll powerwithmod(ll x, ll y, ll p){
	// 	ll res = 1;
	// 	x = x % p; 
	// 	while (y > 0){
	// 		if (y & 1)
	// 			res = (res * x) % p;
	// 		y = y >> 1;
	// 		x = (x * x) % p;
	// 	}
	// 	return res;
	// }
	
	// ll modInverse(ll n, ll p){
	// 	return powerwithmod(n, p - 2, p);
	// }
	
	// ll nCrModPFermat(ll n, ll r, ll p){
	// 	if (n < r) return 0;
	// 	if (r == 0) return 1;
	// 	vector<unsigned long long> fac(n + 1);
	// 	fac[0] = 1;
	// 	for (int i = 1; i <= n; i++)
	// 		fac[i] = (fac[i - 1] * i) % p;
	// 	return (fac[n] * modInverse(fac[r], p) % p
	// 			* modInverse(fac[n - r], p) % p)
	// 		% p;
	// }

	

	void solve(){
		ll n, m; 
		cin >> n;
		int choice, op1, op2;
		vector<ll> a;
		vector<pair<pair<ll,ll>, ll>> query;
		map<ll,ll> mapping;
		loop(n){
			cin >> choice;
			if(choice == 1){
				cin >> op1;
				a.push_back(op1);
			}
			else{
				cin >> op1 >> op2;
				query.push_back({{op1, op2}, a.size()});
			}
		}
		if(query.size() == 0){
		    printelems(a);
		    return;
		}
		ll cur = query.size() - 1;
		for(ll i = a.size() - 1; i >= 0; i--){
			while(query[cur].second == i+1){
				if(mapping[query[cur].first.second]) mapping[query[cur].first.first] = mapping[query[cur].first.second];
				else mapping[query[cur].first.first] = query[cur].first.second;
				cur--;
			}
			if(mapping[a[i]]) a[i] = mapping[a[i]]; 
		}

		printelems(a);
	}
			

    
	int main(){
	    solve();
	}

	// int main(){ 
	// 	ll t;
	// 	cin >> t;
	// 	for (ll _ = 0; _ < t; ++_) {
	// 		solve();
	// 	}
	// 	return 0;
	// }