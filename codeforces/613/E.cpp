// LUOGU_RID: 158873633
#include<bits/stdc++.h>
#define ull HASH
#define int long long
const int N = 2e3 + 10, mod = 998244353, Mod = 1e9 + 7;
using namespace std;
char s[3][N], w[N];
int n, m, f[3][N][N], g[3][N][N], ans, res;
int add(int a, int b){return (a + b) % mod;}
int mul(int a, int b){return 1ll * a * b % mod;}
int sub(int a, int b){return (a - b + mod) % mod;}
struct HASH{
	int fi, se;
	HASH operator * (const HASH &x) const{return {mul(fi, x.fi), mul(se, x.se)};}
	HASH operator + (const HASH &x) const{return {add(fi, x.fi), add(se, x.se)};}
	HASH operator + (const int &x) const{return {add(fi, x), add(se, x)};}
	HASH operator - (const HASH &x) const{return {sub(fi, x.fi), sub(se, x.se)};}
	HASH operator - (const int &x) const{return {sub(fi, x), sub(se, x)};}
	bool operator == (const HASH &x) const{return fi == x.fi && se == x.se;}
}Hash1[3][N], Hash2[3][N], Hashw[N];
HASH base = {131, 1331}, F[N] = {1, 1};
ull Get_pre(int l, int r, ull (&H)[N]){return H[r] - H[l - 1] * F[r - l + 1];}
ull Get_suf(int l, int r, ull (&H)[N]){return H[l] - H[r + 1] * (F[r - l + 1]);}
ull Merge(ull H1, ull H2, int len){return H2 + H1 * F[len];}
void work(){
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
	for(int i = 1; i <= m; i++) Hashw[i] = Hashw[i - 1] * base + w[i] - 'a' + 1;
	for(int i = 1; i <= 2; i++){
		for(int j = 1; j <= n; j++){
			for(int k = j; k >= 1; k--){
				int len = (j - k + 1) * 2;
				if(len > m) continue;
				ull HA = Get_pre(k, j, Hash1[i]);
				ull HB = Get_suf(k, j, Hash2[3 - i]);
				ull HH = Hashw[len];
				if(Merge(HB, HA, len / 2) == HH){
					if(len == m) res++, res %= Mod;
					else g[i][j][len] = 1;
				}
			}
		}
	}
	
	for(int i = 1; i <= 2; i++){
		for(int j = 1; j <= n; j++){
			if(s[i][j] == w[1]) g[i][j][1] = 1;
		}
	}
	for(int i = m; i >= 1; i--) Hashw[i] = Hashw[i + 1] * base + w[i] - 'a' + 1;
	for(int k = 1; k <= m; k++){
		for(int i = 1; i <= 2; i++){
			for(int j = 1; j <= n; j++){
				if(j < n && s[i][j + 1] == w[k + 1])
					f[i][j + 1][k + 1] += f[i][j][k] + g[i][j][k], f[i][j + 1][k + 1] %= Mod;
				if(s[3 - i][j] == w[k + 1])
					g[3 - i][j][k + 1] += f[i][j][k], g[3 - i][j][k + 1] %= Mod;
			}
		}
	}
	for(int i = 1; i <= 2; i++){
		for(int j = 1; j <= n; j++){
			if(s[i][j] == w[m]){
				if(m == 1) ans++;
				ans += f[i][j - 1][m - 1];
				ans += g[i][j - 1][m - 1];
				ans %= Mod;
			}
			for(int k = j; k <= n; k++){
				int len = (k - j + 1) * 2;
				if(len > m) continue;
				ull HA = Get_pre(j, k, Hash1[3 - i]);
				ull HB = Get_suf(j, k, Hash2[i]);
				ull HH = Hashw[m - len + 1];
				if(Merge(HA, HB, len / 2) == HH){
					if(len == m && m != 2) res++, res %= Mod;
					else{
						ans += f[i][j - 1][m - len];
						ans += g[i][j - 1][m - len];
						ans %= Mod;
					}
				}
			}
		}
	}
}
signed main(){
//	freopen("D.in", "r", stdin);
//	freopen("D.out", "w", stdout);
	scanf(" %s", s[1] + 1);
	scanf(" %s", s[2] + 1);
	scanf(" %s", w + 1);
	n = strlen(s[1] + 1), m = strlen(w + 1);
	for(int i = 1; i <= max(n, m); i++) F[i] = F[i - 1] * base;
	for(int i = 1; i <= 2; i++){
		for(int j = 1; j <= n; j++)
			Hash1[i][j] = Hash1[i][j - 1] * base + s[i][j] - 'a' + 1;
		for(int j = n; j >= 1; j--)
			Hash2[i][j] = Hash2[i][j + 1] * base + s[i][j] - 'a' + 1;
	}
	work();
	reverse(w + 1, w + 1 + m);
	work();
	ans += res / 2;
	if(m == 1) ans /= 2;
	printf("%lld", ans);
	return 0;
}