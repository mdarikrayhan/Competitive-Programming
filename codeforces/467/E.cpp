#include<bits/stdc++.h>
#define rep1(i, a, b) for(int i = a; i <= b; ++i)
#define rep2(i, a, b) for(int i = a; i >= b; --i)
#define pb push_back
#define pii pair <int, int>
#define ft first
#define sd second
#define ll long long
#define ptc putchar
#define debug puts("-------------------------")
const int N = 5e5 + 10, inf = -1e9;
using namespace std;
int n, a[N], b[N], lst[N], pre[N], nxt[N], idx[N], f[N], lst3[N];
struct sgmtree {
	#define ls x << 1
	#define rs x << 1 | 1
	int v[N << 2], pos[N << 2];
	void pushup(int x) {
		v[x] = inf; pos[x] = 0;
		if(v[x] < v[ls]) v[x] = v[ls], pos[x] = pos[ls];
		if(v[x] < v[rs]) v[x] = v[rs], pos[x] = pos[rs];
	}
	void build(int x = 1, int l = 1, int r = n) {
		if(l == r) return v[x] = inf, void();
		int mid = l + r >> 1;
		build(ls, l, mid); build(rs, mid + 1, r);
		pushup(x);
	}
	void add(int q, int k, int x = 1, int l = 1, int r = n) {
		if(l == r) return v[x] = k, pos[x] = l, void();
		int mid = l + r >> 1;
		if(q <= mid) add(q, k, ls, l, mid);
		else add(q, k, rs, mid + 1, r);
		pushup(x);
	}
	pii query(int ql, int qr, int x = 1, int l = 1, int r = n) {
		if(ql > qr) return {inf, 0};
		if(l >= ql && r <= qr) return {v[x], pos[x]};
		int mid = l + r >> 1, ans = inf, id = 0;
		if(ql <= mid) {
			pii val = query(ql, qr, ls, l, mid);
			if(ans < val.ft) ans = val.ft, id = val.sd;
		}
		if(qr > mid) {
			pii val = query(ql, qr, rs, mid + 1, r);
			if(ans < val.ft) ans = val.ft, id = val.sd;
		}
		return {ans, id};
	}
	#undef ls
	#undef rs
} t;
void dfs(int x) {
	if(x < 1) return ; if(lst[x] < 1) return ;
	x = lst[x]; dfs(idx[x] - 1);
	int v1 = b[a[idx[x]]], v2 = b[a[x]];
	cout << v1 << ' ' << v2 << ' ' << v1 << ' ' << v2 << ' ';
}
int main() {
	cin >> n;
	rep1(i, 1, n) cin >> a[i], b[i] = a[i];
	sort(b + 1, b + n + 1);
	int len = unique(b + 1, b + n + 1) - b;
	rep1(i, 1, n) {
		a[i] = lower_bound(b + 1, b + len, a[i]) - b;
		pre[i] = lst[a[i]]; nxt[pre[i]] = i; lst[a[i]] = i;
		if(lst3[pre[i]]) lst3[i] = nxt[lst3[pre[i]]];
		else {
			int nw = pre[i], num = 1;
			while(nw && num < 3) nw = pre[nw], num++;
			if(nw && num == 3) lst3[i] = nw;
		}
	} t.build();
	rep1(i, 1, n) {
		if(nxt[i]) t.add(nxt[i], f[i - 1]);
		if(f[i - 1] >= f[i]) f[i] = f[i - 1], lst[i] = lst[i - 1];
		if(lst3[i] && f[i] < f[lst3[i] - 1] + 1) f[i] = f[lst3[i] - 1] + 1, idx[i] = lst3[i], lst[i] = i;
		int suc = nxt[i]; pii val = t.query(i + 1, suc - 1);
		f[suc] = val.ft + 1, idx[suc] = pre[val.sd], lst[suc] = suc;
	} cout << f[n] * 4 << '\n';
	dfs(n); puts("");
	return 0;
}
		 	 	 	  	 	 	 		  		  				