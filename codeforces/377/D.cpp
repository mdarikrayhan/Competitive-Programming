// LUOGU_RID: 160516881
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5 + 5;
const int V = 3e5;

int n, l[N], v[N], r[N];

vector <int> vec1[N], vec2[N];

int tree[N << 2], tag[N << 2];

inline void push_up(int i) {
	tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
}

inline void push_down(int i) {
	if (!tag[i]) {
		return;
	}
	tree[i << 1] += tag[i], tree[i << 1 | 1] += tag[i];
	tag[i << 1] += tag[i], tag[i << 1 | 1] += tag[i];
	tag[i] = 0;
}

inline void update(int ql, int qr, int i, int l, int r, int k) {
	if (ql <= l && r <= qr) {
		tree[i] += k, tag[i] += k;
		return;
	}
	push_down(i);
	int mid = (l + r) >> 1;
	if (ql <= mid) {
		update(ql, qr, i << 1, l, mid, k);
	}
	if (qr > mid) {
		update(ql, qr, i << 1 | 1, mid + 1, r, k);
	}
	push_up(i);
}

inline int get_pos(int i, int l, int r) {
	if (l == r) {
		return l;
	}
	push_down(i);
	int mid = (l + r) >> 1;
	if (tree[i << 1] == tree[i]) {
		return get_pos(i << 1, l, mid);
	}
	return get_pos(i << 1 | 1, mid + 1, r);
}

int ans, pos1, pos2;

int main() {
	#ifdef LOCAL
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> l[i] >> v[i] >> r[i];
		vec1[l[i]].emplace_back(i);
		vec2[v[i] + 1].emplace_back(i);
	}
	for (int i = 1; i <= V; ++i) {
		for (auto j: vec1[i]) {
			update(v[j], r[j], 1, 1, V, 1);
		}
		for (auto j: vec2[i]) {
			update(v[j], r[j], 1, 1, V, -1);
		}
		if (tree[1] > ans) {
			ans = tree[1];
			pos1 = i, pos2 = get_pos(1, 1, V);
		}
	}
	cout << ans << "\n";
	for (int i = 1; i <= n; ++i) {
		if (l[i] <= pos1 && pos1 <= v[i] && v[i] <= pos2 && pos2 <= r[i]) {
			cout << i << " ";
		}
	}
	cout << "\n";
	return 0;
}