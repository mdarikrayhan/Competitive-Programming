#include <iostream>
#include <cstdio>

using namespace std;
typedef long long i64;

i64 gcd(i64 a, i64 b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

struct Node {
	int l, r;
	i64 value;
} nodes[514514 * 4];
i64 a[514514];

void build(int p, int l, int r) {
	nodes[p].l = l;
	nodes[p].r = r;
	if (l != r) {
		int mid = (l + r) / 2;
		build(p * 2, l, mid);
		build(p * 2 + 1, mid + 1, r);
		nodes[p].value = gcd(nodes[p * 2].value, nodes[p * 2 + 1].value);
	} else {
		nodes[p].value = a[l];
	}
}

void modify(int p, int i, i64 x) {
	if (nodes[p].l == nodes[p].r) {
		nodes[p].value = x;
	} else {
		int mid = (nodes[p].l + nodes[p].r) / 2;
		if (i <= mid)
			modify(p * 2, i, x);
		else
			modify(p * 2 + 1, i, x);
		nodes[p].value = gcd(nodes[p * 2].value, nodes[p * 2 + 1].value);
	}
}

bool query(i64 *ans, int p, int l, int r, i64 target) {
	if (l <= nodes[p].l && r >= nodes[p].r) {
		*ans = nodes[p].value;
		if (nodes[p].l == nodes[p].r || *ans % target == 0) {
			return true;
		}
		i64 a = nodes[p * 2].value;
		i64 b = nodes[p * 2 + 1].value;
		if (a % target != 0 && b % target != 0)
			return false;
		if (a % target == 0) {
			if (query(&b, p * 2 + 1, l, r, target))
				return true;
		}
		if (b % target == 0) {
			if (query(&a, p * 2, l, r, target))
				return true;
		}
		return false;
	}
	int mid = (nodes[p].l + nodes[p].r) / 2;
	if (l <= mid && r > mid) {
		i64 a, b;
		bool q1 = query(&a, p * 2, l, r, target);
		bool q2 = query(&b, p * 2 + 1, l, r, target);
		*ans = gcd(a, b);
		if (a % target != 0 && b % target != 0)
			return false;
		if (a % target == 0 && q2)
			return true;
		if (b % target == 0 && q1)
			return true;
		return false;
	} else if (l <= mid) {
		return query(ans, p * 2, l, r, target);
	} else {
		return query(ans, p * 2 + 1, l, r, target);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	int q; cin >> q;
	while (q--) {
		int op; cin >> op;
		if (op == 1) {
			int l, r;
			i64 x;
			cin >> l >> r >> x;
			i64 a;
			bool ans = query(&a, 1, l, r, x);
			cout << (ans ? "YES" : "NO") << '\n';
		} else if (op == 2) {
			int i;
			i64 x;
			cin >> i >> x;
			modify(1, i, x);
		}
	}
}







	 	  	 		   	 	 	  	  	   	 		