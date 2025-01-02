// LUOGU_RID: 158621665
/*
世界の果てさえ
【世界的尽头在何处】
仆らは知らない
【我们也无从知晓】
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <random>
#include <ctime>
#define pr pair <int, int>
#define mr make_pair
#define LL long long
#define ls tree[p].L
#define rs tree[p].R
using namespace std;
const int MAXN = 2e5 + 5, Mod = 998244353;
struct node {
	int A, B;
	LL ans;
	node() { A = B = 0; ans = 1; }
}a, b, c, d;
int n, m;
LL jc[MAXN], inv[MAXN];
char s[MAXN];
void read(int &x) {
	x = 0; bool f = 1; char C = getchar();
	for(; C < '0' || C > '9'; C = getchar()) if(C == '-') f = 0;
	for(; C >= '0' && C <= '9'; C = getchar()) x = (x << 1) + (x << 3) + (C ^ 48);
	x = (f ? x : -x);
}
LL Qpow(LL x, int y) {
	LL ans = 1;
	for(; y; y >>= 1) {
		if(y & 1) ans = ans * x % Mod;
		x = x * x % Mod;
	}
	return ans;
}
LL inv2 = Qpow(2, Mod - 2);
LL C(int x, int y) {
	if(x < 0 || y < 0 || x < y) return 0;
	return jc[x] * inv[y] % Mod * inv[x - y] % Mod;
}
void addl(node &x) {
	x.A ++;
	if(x.A < 0 || x.B < 0) { x.ans = 0; return; }
	x.ans = (x.ans + C(x.B, x.A)) % Mod;
}
void dell(node &x) {
	x.A --;
	if(x.A < 0 || x.B < 0) { x.ans = 0; return; }
	x.ans = (x.ans - C(x.B, x.A + 1)) % Mod;
}
void addr(node &x) {
	x.B ++;
	if(x.A < 0 || x.B < 0) { x.ans = 0; return; }
	if(x.B == 0) { x.ans = 1; return; }
	x.ans = (2 * x.ans - C(x.B - 1, x.A)) % Mod;
}
void delr(node &x) {
	x.B --;
	if(x.A < 0 || x.B < 0) { x.ans = 0; return; }
	if(x.B == 0) { x.ans = 1; return; }
	x.ans = (x.ans + C(x.B, x.A)) * inv2 % Mod;
}
int K, cnt;
void addk() {
	K ++; dell(a); dell(b);
}
void delk() {
	K --; addl(a); addl(b);
}
void addcnt() {
	cnt ++; addr(a); addr(b); addl(c); addr(c); addl(d); addr(d);
//	printf("?%d?", c.ans);
}
void delcnt() {
	cnt --; delr(a); delr(b); dell(c); delr(c); dell(d); delr(d);
}
char op[5];
LL query() {
	LL ans = 0;
	if(cnt < 2) {
		for(int i = 0; i <= cnt; i ++) {
//			printf("?%d %d %d?", i, cnt, K);
			if((K + i) % 2 == 0) ans = (ans + abs(K + i) * C(cnt, i)) % Mod;
		}
		return ans;
	} 
	ans = (-2ll * K * a.ans) % Mod; ans = (ans - 2ll * cnt * b.ans) % Mod;
//	printf("|%lld %lld %lld %d %d|", ans, c.ans, d.ans, K, cnt);
	ans = (ans + 1ll * K * c.ans % Mod * inv2) % Mod; ans = (ans + 1ll * cnt * d.ans % Mod * inv2) % Mod;
//	printf("|%lld|", ans);
	return (ans + Mod) % Mod;
}
int main() {
	scanf("%d%d%s", &n, &m, s + 1); int x, k1 = 0, k2 = 0, t = 0; jc[0] = 1; LL base = 1;
	for(int i = 1; i <= n; i ++) if(s[i] == '?') base = base * inv2 % Mod;
	for(int i = 1; i <= n; i ++) jc[i] = jc[i - 1] * i % Mod;
	inv[n] = Qpow(jc[n], Mod - 2);
	for(int i = n - 1; i >= 0; i --) inv[i] = inv[i + 1] * (i + 1) % Mod;
	delr(a); delr(b); delr(b); dell(b);
	dell(d); delr(d);
	for(int i = 1; i <= n; i ++) {
		if(s[i] == '?') {
			if(i & 1) addcnt();
			else addcnt(), delk();
		}
		if(s[i] == 'b') {
			if(i & 1) addk();
			else delk();
		}
	}
	if(n & 1) printf("0\n");
	else printf("%lld\n", query() * base % Mod); 
	while(m --) {
		scanf("%d%s", &x, op + 1);
		if(n & 1) { printf("0\n"); continue; }
		if(s[x] == '?') {
			base = base * 2 % Mod;
			if(x & 1) delcnt();
			else delcnt(), addk();
		}
		if(s[x] == 'b') {
			if(x & 1) delk();
			else addk();
		}
		s[x] = op[1];
		if(s[x] == '?') {
			base = base * inv2 % Mod;
			if(x & 1) addcnt();
			else addcnt(), delk();
		}
		if(s[x] == 'b') {
			if(x & 1) addk();
			else delk();
		}
		printf("%lld\n", query() * base % Mod);
	}
	return 0;
}
/*
4 0
??bb
*/