// LUOGU_RID: 160590486
#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
#define _for(i, a, b) for (int i = (a); i <= (b); i++)
#define _pfor(i, a, b) for (int i = (a); i >= (b); i--)
#define int long long
const int N = 4e5 + 5;

int n, p[N], bl[N], res, idx, root[N];

int find(int x) {
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

struct edge {
	int l, r, sz, sum;
}tree[N * 30];

void push_up(int p) {
	tree[p].sz = tree[tree[p].l].sz + tree[tree[p].r].sz;
	tree[p].sum = tree[tree[p].l].sum + tree[tree[p].r].sum;
}

void insert(int &p, int L, int R, int v) {
	if (!p) p = ++idx;
	if (L == R) {
		tree[p].sz = 1;
		tree[p].sum = v;
		return;
	}
	int mid = (L + R) >> 1;
	if (v <= mid) {
		insert(tree[p].l, L, mid, v);
	}
	else {
		insert(tree[p].r, mid + 1, R, v);
	}
	push_up(p);
}

int merge(int p, int q, int L, int R) {
	if (!p || !q) return p+q;
	if (L == R) {
		return p;
	}
	res -= tree[tree[p].l].sum * tree[tree[p].r].sz + tree[tree[q].l].sum * tree[tree[q].r].sz;
	int mid = (L + R) >> 1;
	tree[p].l = merge(tree[p].l, tree[q].l, L, mid);
	tree[p].r = merge(tree[p].r, tree[q].r, mid + 1, R);
	res += tree[tree[p].l].sum * tree[tree[p].r].sz;
	push_up(p);
	return p;
}

void link(int a, int b) {
	a = find(a), b = find(b);
	p[b] = a;
	res -= tree[root[a]].sum * a + tree[root[b]].sum * b;
	root[a] = merge(root[a], root[b], 1, n);
	res += tree[root[a]].sum * a; bl[a] = bl[b];
}

signed main() {
	cin >> n;
	_for(i, 1, N - 5) p[i] = bl[i] = i;
	_for(i, 1, n) {
		int a, b;
		cin >> a >> b;
		int y = root[a] ? bl[find(a)] + 1 : a;
		res += (y - a) * b;
//		cout << res << endl;
		insert(root[y], 1, n, b);
		if (root[y - 1]) link(y - 1, y);
		if (root[y + 1]) link(y, y + 1);
//		_for(j, 1, n) cout << root[j] << ' ';
//		puts("");
		cout << res << endl;
	}
}