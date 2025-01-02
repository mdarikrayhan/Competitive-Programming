#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int MAXL = MAXN * 2;
const int LB = 19 + 2;
const int inf = 0x3f3f3f3f;

namespace Fast
{
	const int SIZ = 1<<23;
	char buf1[SIZ], *s1 = buf1, *t1 = buf1;
	char buf2[SIZ], *s2 = buf2, *t2 = buf2;
	inline char gc(void)
	{
		if (s1 == t1)
		{
			t1 = (s1 = buf1) + fread(buf1,1,SIZ,stdin);
			if (s1 == t1) return EOF;
		}
		return *s1++;
	}
	void pc(char c)
	{
	    *t2++ = c;
	    if (t2 - s2 == SIZ)
	        fwrite(buf2, 1, SIZ, stdout), t2 = buf2;
	}
	void flush()
	{
		fwrite(buf2, 1, t2 - s2, stdout); 
	}
	inline int read(void)
	{
		int res=0;
		char c=gc();
		while(c<'0'||c>'9') c=gc();
		while(c>='0'&&c<='9') res=res*10+c-'0', c=gc();
		return res;
	}
	inline void write(int x)
	{
		if(x>=10) write(x / 10);
		pc(x % 10 + '0');
	}
} using Fast::read; using Fast::write;

namespace Hash
{
	mt19937 rnd((unsigned long long)new char ^ time(0));
	const int mod = 1e9 + 7;
	const int base = (rnd()>>1) % (mod / 10) + (mod / 10);
	
	ll h[MAXL], pwb[MAXL];
	void build(char s[],int n)
	{
		pwb[0] = 1;
		for(int i=1; i<=n; ++i) pwb[i] = pwb[i-1] * base %mod;
		for(int i=1; i<=n; ++i) h[i+1] = (h[i] * base + s[i]) %mod;
	}
	inline bool eq(int x,int y,int k)
	{
		int t = h[x+k] - h[y+k];
		return (t<0? t+mod: t) == (h[x] - h[y] + mod) * pwb[k] %mod;
	}
}

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXN], etot=0;
inline void add_edge(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot;
}

int n;
char s[MAXN];

int anc[MAXN], dep[MAXN], siz[MAXN], son[MAXN], mxl[MAXN];
void dfs_tree(int u,int fa)
{
	anc[u] = fa;
	dep[u] = dep[fa] + 1;
	siz[u] = 1; son[u] = -1;
	mxl[u] = s[u] == s[fa]? mxl[fa] + 1: 1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs_tree(v,u);
		siz[u] += siz[v];
		if(son[u] == -1 || siz[v] > siz[son[u]]) son[u] = v;
	}
}

char ss[MAXL];
int dfn[MAXN], seq[MAXN], curdfn = 0, top[MAXN];
void dfs_dfn(int u,int fa,int tp)
{
	top[u] = tp;
	dfn[u] = ++curdfn; seq[curdfn] = u;
	ss[curdfn] = ss[2*n-curdfn+1] = s[u];
	if(son[u] != -1)
	{
		dfs_dfn(son[u], u, tp);
		for(int i=head[u]; i; i=e[i].next)
		{
			int v = e[i].to;
			if(v == fa || v == son[u]) continue;
			dfs_dfn(v, u, v);
		}
	}
}

struct Seg
{
	int l,r;
	Seg(void){}
	Seg(int _l,int _r): l(_l), r(_r) {}
};

inline int lca(int u,int v)
{
	while(top[u] != top[v]) dep[top[u]] > dep[top[v]]? u = anc[top[u]]: v = anc[top[v]];
	return dep[u] < dep[v]? u: v;
}
inline int dist(int u,int v)
{
	return dep[u] + dep[v] - 2 * dep[lca(u,v)];
}
inline Seg* getseg(int u,int v,Seg* res,int &lcadep)
{
	static Seg res2[20];
	int len2 = 0;
	
	int nn = 2 * n + 1;
	int tu = top[u], tv = top[v];
	while(top[u] != top[v])
	{
		if(dep[tu] > dep[tv])
		{
			*res++ = Seg(nn-dfn[u], nn-dfn[tu]);
			u = anc[tu]; tu = top[u];
		}
		else
		{
			res2[++len2] = Seg(dfn[tv], dfn[v]);
			v = anc[tv]; tv = top[v];
		}
	}
	if(dep[u] < dep[v])
		*res++ = Seg(dfn[u], dfn[v]);
	else
		*res++ = Seg(nn-dfn[u], nn-dfn[v]);
	for(int i=len2; i>=1; --i)
		*res++ = res2[i];
	lcadep = min(dep[u], dep[v]);
	return res;
}

int main(void)
{
	n = read();
	for(int i=1; i<=n; ++i) s[i] = Fast::gc();
	for(int i=1; i<n; ++i)
	{
		int u = read(), v = read();
		add_edge(u,v); add_edge(v, u);
	}
	
	bool allsame = 1;
	for(int i=1; i<=n; ++i)
		if(s[i] != s[1])
		{
			allsame = 0;
			break;
		}
	
	dep[0] = -1;
	dfs_tree(1,0);
	dfs_dfn(1,0,1);
	if(!allsame) Hash::build(ss, 2*n);
	
	int Q = read();
	while(Q--)
	{
		int u1 = read(), v1 = read(), u2 = read(), v2 = read();
		if(s[u1] != s[u2])
		{
			Fast::pc('0');
			Fast::pc('\n');
			continue;
		}
		if(allsame)
		{
			write(min(dist(u1, v1), dist(u2, v2)) + 1);
			Fast::pc('\n');
			continue;
		}
		
		static Seg A[40], B[40];
		int k1, k2;
		int Alen = getseg(u1, v1, A, k1) - A, Blen = getseg(u2, v2, B, k2) - B;
		
		int skip = min({dep[u1] - k1 + 1, dep[u2] - k2 + 1, mxl[u1], mxl[u2]});
		
		int i = 0, ip = A[0].l;
		int j = 0, jp = B[0].l;
		int ans = 0;
		while(i<Alen && j<Blen)
		{
			int step = min(A[i].r - ip + 1, B[j].r - jp + 1);
			if(ans+step > skip && !Hash::eq(ip, jp, step))
				break;
			
			ans += step;
			ip += step; jp += step;
			if(ip > A[i].r) ip = A[++i].l;
			if(jp > B[j].r) jp = B[++j].l;
		}
		if(i<Alen && j<Blen)
		{
			int step = min(A[i].r - ip + 1, B[j].r - jp + 1);
			int k = 1;
			for(; k<=step && Hash::eq(ip, jp, k); k<<=1);
			int l = k >> 1, r = min(step, k);
			while(l<r)
			{
				int mid = (l+r+1)>>1;
				if(Hash::eq(ip, jp, mid))
					l = mid;
				else
					r = mid-1;
			}
			ans += l;
		}
		
		write(ans);
		Fast::pc('\n');
	}
	Fast::flush();
	return 0;
}