// LUOGU_RID: 159975848
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll INF = 1e15;
const int N = 5e5;
inline int read() {
	int s = 0,f = 1;char ch = getchar();
	while (!isdigit(ch)) f = ch == '-' ? -1 : 1, ch = getchar();
	while (isdigit(ch)) s = (s << 3) + (s << 1) + ch - '0', ch = getchar();
	return s*f;
}
const int mod = 998244353;
int getmod(int x) {
	return x - (x >= mod) * mod;
}
int qpow(int a,int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % mod;
		b >>= 1, a = 1ll * a * a % mod;
	}
	return res;
}
struct edge {
	int v,nxt;
}ed[N * 2 + 10];
int head[N + 10],cnt;
void add(int u,int v) {
	ed[++cnt] = {v,head[u]};
	head[u] = cnt;
}
typedef vector<int> poly;
namespace Poly {
	const int G = 3,invG = qpow(G,mod - 2);
	poly ro,w;
	int tn;
	void init(int n) {
		if (n == tn) return;
		tn = n;
		if (ro.size() < n) ro.resize(n);
		for (int i = 0;i < n;i ++ ) {
			ro[i] = (ro[i >> 1] >> 1) | (i & 1 ? n / 2 : 0);
		}
	}
	typedef unsigned long long ull;
	void NTT(poly &f,bool fl,int n) {
		vector<ull> g;
		g.resize(n);
		for (int i = 0;i < n;i ++ ) g[i] = f[ro[i]];
		for (int len = 1;len < n;len <<= 1) {
			int w0 = qpow(fl ? G : invG,(mod - 1) / 2 / len);w[0] = 1;
			for (int j = 1;j < len;j ++ ) w[j] = 1ll * w[j - 1] * w0 % mod;
			for (int j = 0;j < n;j += 2 * len)
				for (int k = j;k < j + len;k ++ ) {
					ull g0 = g[k],g1 = g[k + len];
					g[k] = (g0 + 1ll * w[k - j] * g1 % mod);
					g[k + len] = (g0 - 1ll * w[k - j] * g1 % mod + mod);
				}
			if (len == 1 << 17)
				for (int j = 0;j < n;j ++ ) g[j] %= mod;
		}
		if (!fl) {
			int inv = qpow(n,mod - 2);
			for (int i = 0;i < n;i ++ ) f[i] = g[i] % mod * inv % mod;
		}
		else for (int i = 0;i < n;i ++ ) f[i] = g[i] % mod;
	}
	poly operator * (poly x,poly y) {
		int n = x.size(),m = y.size(),lim;
		for (lim = 1;lim < n + m - 1;lim <<= 1);
		init(lim);
		x.resize(lim), y.resize(lim); w.resize(lim);
		NTT(x,1,lim), NTT(y,1,lim);
		for (int i = 0;i < lim;i ++ ) x[i] = 1ll * x[i] * y[i] % mod;
		NTT(x,0,lim);
		x.resize(n + m - 1);
		return x;
	}
	poly operator + (const poly &x,const poly &y) {
		poly t = x;
		t.resize(max(x.size(),y.size()));
		for (int i = 0;i < y.size();i ++ ) t[i] = getmod(t[i] + y[i]);
		return t;
	}
	poly operator - (const poly &x,const poly &y) {
		poly t = x;
		t.resize(max(x.size(),y.size()));
		for (int i = 0;i < y.size();i ++ ) t[i] = getmod(t[i] - y[i] + mod);
		return t;
	}
	poly operator * (poly x,const int &y) {
		for (int &i : x) i = 1ll * i * y % mod;
		return x;
	}
	poly inv(poly x) {
		poly y = {qpow(x[0],mod - 2)};
		int n = x.size(),lim;
		for (int i = 1;y.size() < n;i ++ ) {
			poly tx(x.begin(),x.begin() + min(n,(1 << i)));
			lim = 1 << i + 1;
			init(lim);
			y.resize(lim), tx.resize(lim); w.resize(lim);
			NTT(y,1,lim), NTT(tx,1,lim);
			for (int j = 0;j < lim;j ++ ) y[j] = 1ll * y[j] * (2 - 1ll * y[j] * tx[j] % mod + mod) % mod;
			NTT(y,0,lim);
			y.resize(1 << i);
		}
		y.resize(n);
		return y;
	}
	poly operator / (poly x,poly y) {
		int n = x.size(),m = y.size();
		reverse(x.begin(),x.end()), reverse(y.begin(),y.end());
		x.resize(n - m + 1), y.resize(n - m + 1);
		poly tq = x * inv(y);tq.resize(n - m + 1);
		reverse(tq.begin(),tq.end());
		return tq;
	}
	poly operator % (poly x,poly y) {
		return x - (x / y) * y;
	}
	poly sqrt(poly x) {
		poly y = {1};
		int n = x.size();
		for (int i = 1;y.size() < n * 2;i ++ ) {
			y = (x + y * y) * inv(y * 2);
			y.resize(1 << i);
		}
		y.resize(n);
		return y;
	}
	poly der(poly x) {
		for (int i = 0;i < x.size() - 1;i ++ ) x[i] = (i + 1ll) * x[i + 1] % mod;
		x.pop_back();
		return x;
	}
	poly integ(poly x) {
		x.push_back(0);
		int n = x.size();
		poly inv;inv.resize(n + 2);
		inv[0] = inv[1] = 1;
		for (int i = 2;i <= n + 1;i ++ ) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
		for (int i = n - 1;i;i -- ) x[i] = 1ll * inv[i] * x[i - 1] % mod;
		x[0] = 0;
		return x;
	}
	poly ln(const poly &x) {
//		assert(x[0] == 1);
		poly y = integ(der(x) * inv(x));
		return {y.begin(),y.begin() + x.size()};
	}
	poly exp(poly x) {
		poly y = {1};
		int n = x.size();
		for (int i = 1;(1 << i - 1) < n * 2;i ++ ) {
			y = y - (y * (ln(y) - x));
			y.resize(1 << i);
		}
		y.resize(n);
		return y;
	}
	poly ppow(poly x,int k,int k2) {
		int t = x[0];
		return exp(ln(x * qpow(t,mod - 2)) * k) * qpow(t,k2);
	}
}using namespace Poly;
/*
每日看错题。不对！是想错了！那更倒闭了！
 
先假设只有 G 操作！好思路！第二类斯特林数！ 

然后加上 F ！发现差不多！加个容斥！ 
*/
int jc[N + 10],ivjc[N + 10];
int n,k,h[N + 10],a[N + 10],b[N + 10];
poly S;
int main() {
	n = read(), k = read();
	if (n == 1 || k == 1) {
		cout << 1;
		return 0;
	}
	poly f,g;
	jc[0] = ivjc[0] = 1;
	for (int i = 1;i <= n;i ++ ) jc[i] = 1ll * jc[i - 1] * i % mod;
	ivjc[n] = qpow(jc[n],mod - 2);
	for (int i = n - 1;~i;i -- ) ivjc[i] = (i + 1ll) * ivjc[i + 1] % mod;
	for (int i = 1;i <= n;i ++ )
	 {
		if (i > 1 && (n + i - 1) / i == (n + i - 2) / (i - 1)) {
			continue;
		}
		int tn = (n + i - 1) / i;
		f.clear(), g.clear();
		for (int j = 0;j <= min(tn,k);j ++ ) f.push_back(1ll * qpow(j,tn) * ivjc[j] % mod), g.push_back(1ll * (j & 1 ? (mod - 1) : 1) * ivjc[j] % mod);
		f = f * g;
		int res = 0;
		for (int j = 2;j <= min(tn,k);j ++ ) res = getmod(res + f[j]);
		h[tn] = res;
//		cout << "!!" << tn << ' ' << res << endl;
	}
	for (int i = 1;i <= n;i ++ ) b[i] = h[(n + i - 1) / i];
	for (int i = n;i;i -- )
		for (int j = i * 2;j <= n;j += i) b[i] = getmod(b[i] - b[j] + mod);
	cout << b[1];
	return 0;
}
