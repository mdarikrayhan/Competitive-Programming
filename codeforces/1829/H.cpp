// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#ifndef ONLINE_JUDGE
#include "cptemp.h"
#define println(x) cout << x << endl
#define print(x) cout << x
#define ln endl
#else
#include <bits/stdc++.h>
#define print(x) //nothing x 
#define println(x) //nothing x
#define dbg(...)
#define dbgArr(...)
#define ln "\n"
#endif

#define pii pair<int,int>
#define ff first
#define ss second
#define rep(a,b,c) for(int a=b; a<=c; ++a)
#define rrep(a,b,c) for(int a=b; a>=c; --a)
#define v vector
#define all(x) x.begin(),x.end()
#define int long long

using namespace std;
const int m = 1e9 + 7;
const int MAXN = 2e5;
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// .order_of_key(x) -> returns ordinal number of x. If not present, return size + 1, I guess.
// .find_by_order(k) -> return kth number in the ordered set. 
/*------------------------------------------------------------------------------------------------------------------------------*/
/* 								// COMBINATORICS andu MODS
long long inverse(long long a) {
	// calculate modular inverse of integer a wrt some prime modulus.
	long long m = mod;
	return a <= 1 ? a : m - (long long)(m/a) * inverse(m % a) % m;
}

v<int> factorial(MAXN, 0);
void pre_factorial(){
	long long m = mod;
	factorial[0] = 1;
	for (long long i = 1; i <= MAXN; i++) {
    	factorial[i] = factorial[i - 1] * i % m;
	}
}

long long ncr(int n, int k) {
	long long m = mod;
    return factorial[n] * inverse(factorial[k] * factorial[n - k] % m) % m;
}

uint64_t sum(const uint64_t x, const uint64_t y, const uint64_t m) {
	// helper for binary multiplication. Idk how it works.
	uint64_t ans = x + y;
	if (ans < x || ans >= m)
		ans -= m;
	return ans;
}
uint64_t prod_binary(const uint64_t x, const uint64_t y, const uint64_t m) {
	// Binary modular multiplication algorithm.
	// Sometimes int variable = (a * b) % mod isn't good enough to prevent overflow.
	// For eg: When intermediate temporary value is moret than 64bit.
	if (y <= 1)
		return y ? x : 0;
	uint64_t ans = prod_binary(x, y >> 1, m);
	ans = sum(ans, ans, m);
	if (y & 1)
		ans = sum(ans, x, m);
	return ans;
} */
/*---------------------------------------------------------------------------------------------------------------------------*/
/* 							// DOUBLE HASHING FXNs.
long long moda = (1ll << 61ll) - 1ll;
long long modb = (1ll << 31ll) - 1ll;
long long ba = 0;
long long bb = 0;

//double hash = pair of integers (two hash values)
 
inline pii getHash(char const& ch, long long const& pos,
				   v<long long> const& powa,v<long long> const& powb){
	long long resa = ch - 'a' + 1;
	long long resb = ch - 'a' + 1;
	resa = prod_binary(resa, powa[pos], moda);
	resb = prod_binary(resb, powb[pos], modb);
	return {resa, resb};
}
 
inline pii add(pii const& l, pii const& r){
	pii res = {0,0};
	res.ff = (l.ff + r.ff) % moda;
	res.ss = (l.ss + r.ss) % modb;
	return res;
}
 
inline pii sub(pii const& l, pii const& r){
	pii res = {0,0};
	res.ff = ((l.ff - r.ff) % moda + moda) % moda;
	res.ss = ((l.ss - r.ss) % modb + modb) % modb;
	return res;
}
 
bool compare(pii const& l, pii const& r){
	if(l.ff != r.ff) return false;
	else if(l.ss != r.ss) return false;
	else return true;
}
 */
/*---------------------------------------------------------------------------------------------------------------------------------------------*/

long long binpow(long long b) {
	int a = 2;
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve(int& tc){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i,1,n) cin >> a[i-1];

	int limandu = 1ll << 7ll; limandu -= 1;
	v<v<int>> dp(n, v<int>(limandu, 0));
	if(a[n-1] != 0) dp[n-1][a[n-1]-1] = 1;
	
	rrep(i,n-1,1){
		rep(andu,1,limandu){
			dp[i-1][andu-1] = dp[i][andu-1];
		}

		if(a[i-1] != 0) dp[i-1][a[i-1]-1] = (dp[i-1][a[i-1]-1] + 1ll) % m;
		
		rep(andu,1,limandu){
			int handu = a[i-1] & andu;
			if(handu == 0) continue;
			dp[i-1][handu-1] = (dp[i-1][handu-1] + dp[i][andu-1]) % m;
		}
	}
	
	if(k == 0){
		int fullsum = 0;
		for(auto x:dp[0]){
			fullsum = (fullsum + x) % m;
		}
		
		int ans = ((binpow(n) - 1ll) + m) % m;
		ans = (ans - fullsum + m) % m;
		cout << ans;
		return;
	}
	
	int ans = 0;
	rep(andu,1,limandu){
		int ppcnt = __builtin_popcountll(andu);
		if(ppcnt != k) continue;
		ans = (ans + dp[0][andu-1]) % m;
	}
	
	cout << ans;
	return;



}

int32_t main(){
	ios_base::sync_with_stdio(false) ;
	cin.tie(NULL) ;
	int t=1;
	cin >>t;
	for(int i=1;i<=t;++i){
		print("----------TEST CASE");
		print(i);
		println("-------------------------------------");
		solve(i);
		if(i != t) cout << ln;
	}
	return 0;
}

