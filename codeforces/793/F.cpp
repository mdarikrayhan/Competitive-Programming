// LUOGU_RID: 160541259
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define pb emplace_back
#define sz(a) int(a.size())

const int N = 100005;
int n, m, q, ans[N];
vector<pair<int, int>> vec[N];
vector<int> fr[N];

#define mid ((L + R) >> 1)
#define Ls rt << 1, L, mid
#define Rs rt << 1 | 1, mid + 1, R

int fmx[N << 2], smx[N << 2], ls[N << 2];

inline void upd(int rt, int x)
{
	ls[rt] = ls[rt] ? ls[rt] : fmx[rt];
	fmx[rt] = x;
}

void push(int rt)
{
	if (ls[rt]) {
		for (auto v : {rt << 1, rt << 1 | 1}) {
			if (fmx[v] == ls[rt]) {
				upd(v, fmx[rt]);
			}
		}
		ls[rt] = 0;
	}
}

void pull(int rt)
{
	fmx[rt] = max(fmx[rt << 1], fmx[rt << 1 | 1]);
	smx[rt] = max(smx[rt << 1], smx[rt << 1 | 1]);
	if (fmx[rt] != fmx[rt << 1]) {
		smx[rt] = max(smx[rt], fmx[rt << 1]);
	}
	if (fmx[rt] != fmx[rt << 1 | 1]) {
		smx[rt] = max(smx[rt], fmx[rt << 1 | 1]);
	}
}

void change(int l, int r, int x, int y, int rt = 1, int L = 1, int R = n)
{
	if (fmx[rt] < x) {
		return ;
	}
	if (l <= L && R <= r) {
		if (smx[rt] < x) {
			return upd(rt, y);
		}
	}
	push(rt);
	if (l <= mid) {
		change(l, r, x, y, Ls);
	}
	if (r > mid) {
		change(l, r, x, y, Rs);
	}
	pull(rt);
}

int ask(int p, int rt = 1, int L = 1, int R = n)
{
	if (L == R) {
		return fmx[rt];
	}
	push(rt);
	return p <= mid ? ask(p, Ls) : ask(p, Rs);
}

void build(int rt = 1, int L = 1, int R = n)
{
	if (L == R) {
		fmx[rt] = L, smx[rt] = 0;
		return ;
	}
	build(Ls), build(Rs), pull(rt);
}

#undef mid
#undef Ls
#undef Rs

signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v, fr[v].pb(u);
	}
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		int l, r;
		cin >> l >> r, vec[r].pb(l, i);
	}
	build();
	for (int i = 1; i <= n; ++i) {
		for (auto v : fr[i]) {
			change(1, v, v, i);
		}
		for (auto [l, id] : vec[i]) {
			ans[id] = ask(l);
		}
	}
	for (int i = 1; i <= q; ++i) {
		cout << ans[i] << '\n';
	}
	return 0;
}
