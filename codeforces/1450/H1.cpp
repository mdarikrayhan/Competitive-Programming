// LUOGU_RID: 158546999
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
LL C(int x, int y) {
	if(x < 0 || y < 0 || x < y) return 0;
	return jc[x] * inv[y] % Mod * inv[x - y] % Mod;
}
int main() {
	scanf("%d%d%s", &n, &m, s + 1); int k1 = 0, k2 = 0, t = 0; jc[0] = 1;
	for(int i = 1; i <= n; i ++) jc[i] = jc[i - 1] * i % Mod;
	inv[n] = Qpow(jc[n], Mod - 2);
	for(int i = n - 1; i >= 0; i --) inv[i] = inv[i + 1] * (i + 1) % Mod;
	for(int i = 1; i <= n; i ++) {
		if(s[i] == '?') {
			if(i & 1) k1 ++;
			else k2 ++;
		}
		if(s[i] == 'b') {
			if(i & 1) t ++;
			else t --; 
		}
	}
	if(n % 2) {
		printf("0"); return 0;
	}
	LL ans = 0, base = 0;// printf("?%d %d %d?", k1, k2, t);
	for(int i = 0; i <= k1 + k2; i ++) {
		if((t - k2 + i) & 1) continue;
		ans = (ans + (abs(t - k2 + i) / 2) * C(k1 + k2, i)) % Mod;
		base = (base + C(k1 + k2, i)) % Mod;
	}
	printf("%lld", ans * Qpow(base, Mod - 2) % Mod);
	return 0;
}
