// Problem: F1. Wrong Answer on test 233 (Easy Version)
// Contest: Codeforces - Technocup 2020 - Elimination Round 3
// Created: 2024-05-23 20:24:10
// 
// Powered by CP Editor

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

/*
	modpow
	Returns b ^ e % mod
*/

const ll mod = 998244353;

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

/*
	Binomial Coefficients
	n Choose k for all n < N, k <= n
*/

const int N = 2005;
int fact[N], invfact[N];

int inversemod(int p, int q){
	p %= q;
	if (p < 0) p += q;
	if (p == 1) return 1;
	int b = inversemod(q%p, p);
	int a = (1-1LL*b*q)/p % q;
	if (a < 0) a += q;
	return a;
}

void init_fact(){
	fact[0] = 1;
	for(int i=1; i<N; i++){
		fact[i] = 1LL*i*fact[i-1] % mod;
	}
	invfact[N-1] = inversemod(fact[N-1], mod);
	for(int i=N-1; i>=1; i--){
		invfact[i-1] = 1LL*i*invfact[i] % mod;
	}
}

int nCk(int n, int k){
	assert(n<N && k<N && fact[0]==1);
	if(k<0 || k>n) return 0;
	return fact[n] * (1LL*invfact[k]*invfact[n-k] % mod) % mod;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	init_fact();
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(auto &d : v) cin >> d;
	int m=0;
	for(int i=0; i<n; i++){
	    if(v[i] != v[(i+1)%n]) m++;
	}
	ll ans = 0;
	for(int c=0; c<=(k<=2 ? 0 : m); c++){
	    // c is number of indifferent pairs
	    for(int a=m-c, b=0; a>b; a--, b++){
	        // a is number of new pairs
	        // b is number of old pairs
	        ll res = 1ll * nCk(m, a) * nCk(m-a, b) % mod * modpow(k-2, c);
	        // cout << "new pairs: " << a << ", old pairs: " << b << ", indifferent: " << c << endl;
	        // cout << res << endl;
	        ans += 1ll * nCk(m, a) * nCk(m-a, b) % mod * modpow(k-2, c);
	        ans %= mod;
	    }
	}
	ans *= modpow(k, n-m);
	ans %= mod;
	cout << ans;
}