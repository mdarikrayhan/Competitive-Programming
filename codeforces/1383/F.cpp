#include<bits/stdc++.h>
using namespace std;
#define int unsigned
#define sh short
#define rint register int
#define rsh register sh
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
bool be;
constexpr sh N = 1e4 + 2, M = 2e4 + 3, inf = 25;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
using namespace fastio;
sh n, m, k, w[12], _lg[N], cnt = 1;
sh que[N], fr, bk, dep[N], hed[N], pre[N], g[1 << 10], u[N], v[N], c[N], p[N];
int q, sum[1 << 10];
struct edge {
	sh v, c, nxt;
}e[M], E[1 << 10][M];
inline void add(sh u, sh v, sh c)
{
	e[++cnt] = {v, c, hed[u]};
	hed[u] = cnt;
}
inline void link(sh u, sh v, sh c)
{
	e[++cnt] = {v, c, hed[u]}; 
	hed[u] = cnt;
	e[++cnt] = {u, 0, hed[v]};
	hed[v] = cnt;
}
bool bfs()
{
	fr = bk = 0;
	memset(dep + 1, -1, n * sizeof(sh));
	dep[1] = 0;
	que[++bk] = 1;
	while (fr < bk) {
		rsh u = que[++fr];
		for (rint i = hed[u]; i; i = e[i].nxt) {
			if (e[i].c && dep[e[i].v] == -1) {
				dep[e[i].v] = dep[u] + 1;
				que[++bk] = e[i].v;
			}
		}
	}
	return dep[n] != -1;
}
sh bfs_2()
{
	fr = bk = 0;
	memset(dep + 1, -1, n * sizeof(sh));
	dep[1] = 0;
	que[++bk] = 1;
	while (fr < bk) {
		rsh u = que[++fr];
		for (rsh i = hed[u]; i; i = e[i].nxt) {
			if (e[i].c && dep[e[i].v] == -1) {
				dep[e[i].v] = dep[u] + 1;
				pre[e[i].v] = i;
				que[++bk] = e[i].v;
				if (e[i].v == n) break;
			}
		}
		if (dep[n] != -1) break;
	}
	if (dep[n] == -1) return 0;
	rsh mf = inf;
	for (int i = n; i != 1; i = e[pre[i] ^ 1].v) {
		mf = min(mf, e[pre[i]].c);
	}
	for (int i = n; i != 1; i = e[pre[i] ^ 1].v) {
		e[pre[i]].c -= mf;
		e[pre[i] ^ 1].c += mf;
	}
	return mf;
}
sh dfs(rsh u, rsh flow)
{
	if (u == n) return flow;
	rsh sum = 0;
	for (rsh i = hed[u]; i; i = e[i].nxt) {
		if (dep[e[i].v] == dep[u] + 1 && e[i].c) {
			rsh f = dfs(e[i].v, min(flow, e[i].c));
			sum += f;
			flow -= f;
			e[i].c -= f;
			e[i ^ 1].c += f;
			if (!flow) break;
		}
	}
	if (sum == 0) dep[u] = -1;
	return sum;
}
int solve()
{
	rint ans = 0;
	while (bfs()) {
		ans += dfs(1, inf);
	}
	return ans;
}
int solve_2()
{
	rint ans = 0, d = 0;
	while ((d = bfs_2())) {
		ans += d;
	}
	return ans;
}
bool en;
signed main()
{
	cerr << (&be - &en) / 1024.0 / 1024 << " MB\n--------------------------------" << endl;
#ifdef IAKIOI
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	read(n), read(m), read(k), read(q);
	for (rsh i = 1; i <= m; ++i) {
		rsh u, v, c;
		read(u), read(v), read(c);
		link(u, v, c);
	}
	for (rsh i = 1; i < 1 << k; ++i) {
		_lg[i] = _lg[i >> 1] + 1;
	}
	sum[0] = solve();
	for (int o = 2; o <= cnt; ++o) E[0][o] = e[o];
	for (rsh S = 1; S < 1 << k; ++S) {
		rsh x = S & -S, T = S ^ x;
		for (int o = 2; o <= cnt; ++o) e[o] = E[T][o];
		x = _lg[x];
		e[x * 2].c = inf;
		sum[S] = sum[T] + solve_2();
		for (int o = 2; o <= cnt; ++o) E[S][o] = e[o];
	}
	while (q--) {
		for (rsh i = 1; i <= k; ++i) {
			read(w[i]);
		}
		g[0] = 0;
		for (rsh S = 1; S < 1 << k; ++S) {
			rsh x = S & -S, T = S ^ x;
			g[S] = g[T] + w[_lg[x]];
		}
		int ans = INT_MAX;
		for (rsh S = 0; S < 1 << k; ++S) {
			ans = min(ans, sum[S] + g[((1 << k) - 1) ^ S]);
		}
		print(ans);
		putc('\n');
	}
	print_final();
	return 0;
}
  	 				 		 	   	 		 	  	    	