#include <bits/stdc++.h>

std::mt19937 mt(48);
struct treap_node {
	std::array<treap_node*, 2> c{nullptr, nullptr};
	std::mt19937::result_type pri = mt();
	int64_t val = 0;
	int64_t lazy = 0;
	int sz = 1;
	bool is_immo = false;
	bool has_immo = false;

	void apply_lazy(int64_t l) {
		assert(!has_immo);
		val += l;
		lazy += l;
	}
	void downdate() {
		if (lazy) {
			if (c[0]) c[0]->apply_lazy(lazy);
			if (c[1]) c[1]->apply_lazy(lazy);
		}
		lazy = 0;
	}
	void update() {
		sz = 1 + (c[0] ? c[0]->sz : 0) + (c[1] ? c[1]->sz : 0);
		has_immo = is_immo || (c[0] && c[0]->has_immo) || (c[1] && c[1]->has_immo);
	}
};

int64_t get_last(treap_node* a) {
	assert(a);
	while (a->c[1]) {
		a->downdate();
		a = a->c[1];
	}
	return a->val;
}

int64_t get_first(treap_node* a) {
	assert(a);
	while (a->c[0]) {
		a->downdate();
		a = a->c[0];
	}
	return a->val;
}

treap_node* merge(treap_node* a, treap_node* b) {
	if (!a) return b;
	if (!b) return a;
	treap_node* r;
	if (a->pri < b->pri) {
		r = a;
		r->downdate();
		r->c[1] = merge(a->c[1], b);
		r->update();
	} else {
		r = b;
		r->downdate();
		r->c[0] = merge(a, b->c[0]);
		r->update();
	}
	return r;
}

std::pair<treap_node*, treap_node*> split_by_sz(treap_node* a, int lsz) {
	if (!a) {
		assert(lsz == 0);
		return {nullptr, nullptr};
	}
	assert(0 <= lsz && lsz <= a->sz);
	if (lsz == 0) return {nullptr, a};
	if (lsz == a->sz) return {a, nullptr};
	a->downdate();
	int c0sz = (a->c[0] ? a->c[0]->sz : 0);
	treap_node *x, *y;
	if (lsz <= c0sz) {
		y = a;
		std::tie(x, y->c[0]) = split_by_sz(a->c[0], lsz);
	} else {
		x = a;
		std::tie(x->c[1], y) = split_by_sz(a->c[1], lsz - c0sz - 1);
	}
	a->update();
	return {x, y};
}

// split into <=, no immo, and at most lsz
std::pair<treap_node*, treap_node*> split_by_pos_sz_immo(treap_node* a, int64_t pos, int lsz) {
	if (!a) {
		return {nullptr, nullptr};
	}
	a->downdate();
	int c0sz = (a->c[0] ? a->c[0]->sz : 0);
	treap_node *x, *y;
	if (!a->is_immo && !(a->c[0] && a->c[0]->has_immo) && 1 + c0sz <= lsz && a->val <= pos) {
		x = a;
		std::tie(x->c[1], y) = split_by_pos_sz_immo(a->c[1], pos, lsz - 1 - c0sz);
	} else {
		y = a;
		std::tie(x, y->c[0]) = split_by_pos_sz_immo(a->c[0], pos, lsz);
	}
	a->update();
	return {x, y};
}

// split into no immo, and at most lsz
std::pair<treap_node*, treap_node*> split_by_sz_immo(treap_node* a, int lsz) {
	if (!a) {
		return {nullptr, nullptr};
	}
	a->downdate();
	int c0sz = (a->c[0] ? a->c[0]->sz : 0);
	treap_node *x, *y;
	if (!a->is_immo && !(a->c[0] && a->c[0]->has_immo) && 1 + c0sz <= lsz) {
		x = a;
		std::tie(x->c[1], y) = split_by_sz_immo(a->c[1], lsz - 1 - c0sz);
	} else {
		y = a;
		std::tie(x, y->c[0]) = split_by_sz_immo(a->c[0], lsz);
	}
	a->update();
	return {x, y};
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; int64_t D; int Q; cin >> N >> D >> Q; D--;
	std::vector<int64_t> A(N);
	for (auto& a : A) cin >> a;
	std::string is_movable; cin >> is_movable;

	struct query_t {
		int64_t t;
		int idx;
		int q;
	};
	std::vector<query_t> queries(Q);
	for (auto& q : queries) {
		cin >> q.t >> q.idx; q.idx--;
	}
	for (int q = 0; q < Q; q++) queries[q].q = q;
	std::sort(queries.begin(), queries.end(), [&](auto a, auto b) -> bool {
		return a.t < b.t;
	});

	std::vector<treap_node> nodes(N);
	for (int i = 0; i < N; i++) {
		nodes[i].val = A[i];
		nodes[i].lazy = 0;
		nodes[i].is_immo = (is_movable[i] == '0');
		nodes[i].update();
	}

	std::vector<int64_t> pref; pref.reserve(N);
	treap_node* root = nullptr;
	int mcnt = 0;
	auto Ait = A.begin();

	auto query = [&](int idx) -> int64_t {
		assert(mcnt == (root ? root->sz : 0));
		if (idx < int(pref.size())) {
			return pref[idx];
		}
		if (idx >= int(pref.size()) + mcnt) {
			return A[idx];
		}
		idx -= int(pref.size());
		treap_node* cur = root;
		while (true) {
			assert(cur);
			cur->downdate();
			int lcnt = (cur->c[0] ? cur->c[0]->sz : 0);
			if (lcnt == idx) {
				return cur->val;
			} else if (idx < lcnt) {
				cur = cur->c[0];
			} else if (idx > lcnt) {
				idx -= (cur->c[0] ? cur->c[0]->sz : 0);
				idx --;
				cur = cur->c[1];
			}
		}
		assert(false);
	};

	std::vector<int64_t> ans(Q);

	int64_t cur_time = 0;
	for (auto q : queries) {
		while (cur_time < q.t) {
			int64_t delta_t = q.t - cur_time;
			// coords += d + sz every time
			assert(mcnt == (root ? root->sz : 0));
			if (!root) {
				assert(Ait != A.end());
				root = &nodes[Ait - A.begin()];
				++Ait;
				mcnt++;
				continue;
			}

			assert(root);

			// pop immo if possible
			{
				auto [x, y] = split_by_sz(root, 1);
				if (x->is_immo) {
					pref.push_back(x->val);
					root = y;
					mcnt--;
					continue;
				}
				root = merge(x, y);
			}

			assert(root);

			// try to add the next one
			if (Ait != A.end() && (*Ait - get_first(root)) <= (D + mcnt)) {
				// append the next one
				root = merge(root, &nodes[Ait - A.begin()]);
				mcnt++;
				++Ait;
				continue;
			}

			// first, try to do as many cycles as possible
			if (delta_t >= mcnt && !root->has_immo) {
				int64_t num_cycs = delta_t / mcnt;
				if (Ait != A.end()) {
					int64_t hi = get_last(root);
					int64_t max_full = (*Ait - 1 - hi) / (D + mcnt);
					num_cycs = std::min(num_cycs, max_full);
				}
				if (num_cycs > 0) {
					root->apply_lazy(num_cycs * (D + mcnt));
					cur_time += num_cycs * mcnt;
					continue;
				}
			}

			// otherwise, we can only do < mcnt for some reason or another
			if (Ait != A.end()) {
				auto [x, y] = split_by_pos_sz_immo(root, *Ait - 1 - (D + mcnt), int(std::min<int64_t>(mcnt, delta_t)));
				assert(x);
				x->apply_lazy(D + mcnt);
				cur_time += x->sz;
				root = merge(y, x);
				continue;
			} else {
				auto [x, y] = split_by_sz_immo(root, int(std::min<int64_t>(mcnt, delta_t)));
				assert(x);
				x->apply_lazy(D + mcnt);
				cur_time += x->sz;
				root = merge(y, x);
				continue;
			}
		}
		assert(cur_time == q.t);
		ans[q.q] = query(q.idx);
	}

	for (auto v : ans) cout << v << '\n';

	return 0;
}
