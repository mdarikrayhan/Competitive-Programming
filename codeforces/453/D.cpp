// LUOGU_RID: 155294317
// LUOGU_RID: 133854493
#include <bits/stdc++.h>
using namespace std;
#define _rep(i_,a_,b_) for(int i_ = (a_); i_ <= (b_); ++i_)
#define mid ((L+R) >> 1)
#define multiCase() int testCnt = in(); _rep(curCase,1,testCnt)
#ifdef ONLINE_JUDGE
#define debug(...) 0
#else
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#endif
using ll = long long;
using pii = pair<int,int>;

int in(void) { int x; scanf("%d", &x); return x; } ll inl(void) { ll x; scanf("%lld", &x); return x; }
void out(int x) { printf("%d ", x); } void outln(int x) { printf("%d\n", x); }
void out(ll x) { printf("%lld ", x); } void outln(ll x) { printf("%lld\n", x); }
template<typename T> void chkmax(T &a, const T &b) { a = max(a, b); } 
template<typename T> void chkmin(T &a, const T &b) { a = min(a, b); } 
int m = in(); ll t = inl(); ll p = in() * (1ll << m);
ll a[1 << 20], b[1 << 20], c[23];
void FWT(ll *a, int f) {
	for(int i = 2, h = 1; i <= (1 << m); i <<= 1, h <<= 1)
		for(int j = 0; j < (1 << m); j += i) _rep(k,0,h - 1) {
			ll x = a[j + k], y = a[j + k + h];
			// if(f) 
			a[j + k] = (x + y) % p, a[j + k + h] = (x - y + p) % p;
			// else a[j + k] = (x + y) / 2, a[j + k + h] = (x - y) / 2; 
		} 
}
ll fpm(ll a, ll b) {
	ll r = 1;
	for(;b;b >>= 1, a = (__int128_t) a * a % p) if(b & 1) r = (__int128_t) r * a % p;
	return r;
}
int main() { 
	_rep(i,0,(1 << m) - 1) a[i] = in();
	_rep(i,0,m) c[i] = in();
	_rep(i,0,(1 << m) - 1) b[i] = c[__builtin_popcount(i)];
	FWT(a, 1), FWT(b, 1);
	_rep(i,0,(1 << m) - 1) b[i] = fpm(b[i], t); 
	_rep(i,0,(1 << m) - 1) a[i] = (__int128_t) a[i] * b[i] % p;
	FWT(a, 0);
	_rep(i,0,(1 << m) - 1) outln(a[i] / (1 << m));
	return 0;
}

/* 
a list of keywords
clear empty push_back pop_back push pop top front back
emplace_back emplace push_front pop_front insert erase
find count set reset bitset map vector string multiset
first second iterator prev next deque multimap reverse
sort begin end list modify query init check calc prime
putchar getchar puts scanf printf max min swap replace
make_pair make_tuple numeric_limits auto function null
*/