// Author: 989
// Created: 14.05.2024 13:57:12

#pragma GCC optimize("03")

#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
#define str string

#define all(v)  v.begin(), v.end()
#define fi      first
#define se      second
#define pb      push_back
#define ent     cout << "\n";
#define sz(v)   ll(v.size())

using namespace std;

const long long MOD = 1e9+7, inf = 1e18;

void run() {
	ll n;
	cin >> n;
	
	ll a[n+17];
	
	vector <ll> v;
	
	ll k = 0;
	
	for (ll i=1; i<=n; i++) {
		cin >> a[i];
	}
	
	for (ll i=1; i<=n; i++) {
		if (a[i] == a[n/2+1]) {
			v.pb(k);
			k = 0;
			break;
		}
		
		if (i == 1 || a[i] == a[i-1]) {
			k ++;
		}else {
			v.pb(k);
			k = 1;
		}
	}
	
	if (v.size() >= 3) {
		ll s1 = 0, s2 = 0, j = 0;
		
		for (ll i=1; i<sz(v); i++) {
			s1 += v[i];
			
			if (s1 > v[0]) {
				j = i;
				break;
			}
		}
		
		if (s1 <= v[0]) {
			cout << "0 0 0\n";
			return;
		}
		
		for (ll i=j+1; i<sz(v); i++) {
			s2 += v[i];
		}
		if (s2 <= v[0]) {
			cout << "0 0 0\n";
			return;
		}
		
		cout << v[0] << ' ' << s1 << ' ' << s2 << '\n'; 
	}
	else {
		cout << "0 0 0\n";
	}
}

int32_t main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    ll ttest=1;
    cin >> ttest;

    for (ll test_number=1; test_number<=ttest; test_number++) {
        run();
    }

    return 0;
}
