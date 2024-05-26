#pragma GCC optimize(3)
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>
#define YES puts("YES")
#define Yes puts("Yes")
#define NO puts("NO")
#define No puts("No")
#define b_i __int128
#define ll long long
#define ull unsigned long long
#define x first
#define y second
#define pr pair
#define dl double
#define pll pr<ll, ll>
#define pii pr<int, int>
#define pdd pr<dl, dl>
#define ld long dl
#define vc vector
#define vci vc<int>
#define vcl vc<ll>
#define vcd vc<dl>
#define vcs vc<string>
#define vcp vc<pii >
#define ps push
#define pp pop
#define frt front
#define bck back
#define psf push_front
#define psb push_back
#define ppb pop_back
#define ppf pop_front
#define bgn begin
using namespace std;
const ll md = 998244353;
const ll mod = 1e9 + 7;
const dl esp = 1e-12;
const int inf = 2e9;
const ll INF = 2e18;
inline int read(){
	char c = getchar();
	int ans = 0, cnt = 1;
	while(c < '0' || c > '9'){
		if(c == '-') cnt = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		ans *= 10;
		ans += (c - '0');
		c = getchar();
	}
	return ans * cnt;
}
inline void write(int x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
ll ksm(ll a, ll b, ll md){
	ll ans = 1;
	while(b){
		if(b % 2) ans = ans * a % md;
		a = a * a % md;
		b /= 2;
	}
	return ans;
}
int rnd(int l, int r){
	return l + rand() % (r - l + 1);
}
int n, m, q, ans[200005], op[200005], x[200005], y[200005], res;
vci g[200005];
bitset<1005> a[1005], cnt;
void dfs(int u){
	bool fl = 0;
	if(op[u] == 1 && !a[x[u]][y[u]]){
		fl = 1;
		a[x[u]][y[u]] = 1;
		res++;
	}
	if(op[u] == 2 && a[x[u]][y[u]]){
		fl = 1;
		a[x[u]][y[u]] = 0;
		res--;
	}
	if(op[u] == 3){
		fl = 1;
		res -= a[x[u]].count();
		a[x[u]] ^= cnt;
		res += a[x[u]].count();
	}
	ans[u] = res;
//	cout << u << ' ' << res << endl;
//	for(int i = 1; i <= n; i++) cout << a[i] << endl;
	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		dfs(v);
	}
	if(fl){
		if(op[u] == 1){
			a[x[u]][y[u]] = 0;
			res--;
		}
		if(op[u] == 2){
			a[x[u]][y[u]] = 1;
			res++;
		}
		if(op[u] == 3){
			res -= a[x[u]].count();
			a[x[u]] ^= cnt;
			res += a[x[u]].count();
		}
	}
}
signed main(){
	//ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
	srand(time(0));
	memset(ans, -1, sizeof(ans));
	cin >> n >> m >> q;
	for(int i = 1; i <= m; i++) cnt.set(i);
	for(int i = 1; i <= q; i++){
		cin >> op[i] >> x[i];
		if(op[i] == 4) g[x[i]].psb(i);
		else if(op[i] < 3) cin >> y[i];
		if(op[i] < 4) g[i - 1].psb(i);
	}
	dfs(0);
	for(int i = 1; i <= q; i++) cout << ans[i] << endl;
	return 0;
}
		     				   	  	 			  			 	 	