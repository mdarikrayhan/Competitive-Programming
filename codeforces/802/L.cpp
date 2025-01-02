// LUOGU_RID: 160487295
#include <bits/stdc++.h>
#define N 100005
#define p 1000000007
using namespace std;
int n, cnt;
int head[N], deg[N], k[N], b[N], out[N];
struct Edge{
	int to, then, w;
}e[N << 1];

int add(int x, int y){return (x + y >= p)? x - p + y : x + y;}
int sub(int x, int y){return (x < y)? x + p - y : x - y;}
int mul(int x, int y){return 1ll * x * y % p;}
int qpow(int x, int k){
	int res = 1;
	for(; k; k >>= 1){
		if(k & 1) res = mul(res, x);
		x = mul(x, x);
	}
	return res;
}

void Add(int a, int b, int c){
	e[++cnt].then = head[a];
	head[a] = cnt;
	e[cnt].to = b;
	e[cnt].w = c;
	out[a] = add(out[a], c);
}

void dfs(int u, int f){
	int sumk = 0, sumb = 0;
	if(deg[u] == 1) return;
	for(int i = head[u]; i; i = e[i].then){
		int v = e[i].to;
		if(v == f) continue;
		dfs(v, u);
		sumk = add(sumk, k[v]);
		sumb = add(sumb, b[v]);
	}
	k[u] = qpow(sub(deg[u], sumk), p - 2);
	b[u] = mul(k[u], add(sumb, out[u]));
}

inline int read(){
	char ch = getchar(); int x = 0, f = 1;
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * f;
}

int main(){
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = read();
	for(int i = 1; i < n; i++){
		int u = read() + 1, v = read() + 1, w = read();
		Add(u, v, w);
		Add(v, u, w);
		++deg[u], ++deg[v]; 
	}
	dfs(1, 0);
	printf("%d", b[1]);
	return 0;
}