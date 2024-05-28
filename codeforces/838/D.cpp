// Problem: Airplane Arrangements
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF838D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// start time: 2024-05-18 21:20:04

#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
// const int maxn = ;
const int mod = 1e9 + 7 ;
ll qpow(ll a,ll b) {
	ll ans = 1;
	while(b) {
		if(b&1) ans = ans * a % mod ;
		a = a * a % mod; 
		b >>= 1 ;
	}
	return ans ;
}
ll n ,m ;

signed main() {
	ios::sync_with_stdio(false) ;
	cin.tie(nullptr); 
 	cin >> n >> m ;
 	cout << 1ll * (n + 1 - m) * qpow(n + 1,mod - 2) % mod * qpow(2 * (n + 1) , m) % mod << '\n' ; 
 	return 0;
}