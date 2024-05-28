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

		ll lcm(ll a, ll b)
		{
			if (a == 0)
				return b;
			return a*(b/gcd(a, b));
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
			ll n;
			cin >> n;
			vector<ll> a(n), spos(n), epos(n);
			arrinp(a, n);
			loop(n){
				if(a[i]){
					if((i+1) % (a[i]+1)) spos[i] = (i+1 + a[i]) / (a[i]+1);
					else spos[i] = (i+1) / (a[i]+1) + 1;
					epos[i] = (i+1)/a[i];
				}
				else{
					spos[i] = i+2;
					epos[i] = n;
				}
				if(spos[i] == 0) spos[i] = 1;
			}

			// printelems(spos);
			// printelems(epos);
			vector<set<ll>> endshere(n), startshere(n);
			loop(n){
				startshere[spos[i]-1].insert(i+1);
				// endshere[epos[i]-1].insert(i+1);
			}
			vector<ll> ans, fans(n);

			set<pair<ll,ll>> s;
			loop(n){
				for(ll j : startshere[i]){
					s.insert({epos[j-1],j});
				}
				pair<ll,ll> cur = *(s.begin());
				s.erase(s.begin());
				ans.push_back(cur.second);
			}
			loop(n){
				fans[ans[i]-1] = i+1;
			}
			printelems(fans);



			
			
		}

				
		// int main(){
		//     solve();	
		// }

		int main(){ 
			ll t;
			cin >> t;
			for (ll _ = 0; _ < t; ++_) {
				solve();
			}
			return 0;
		}