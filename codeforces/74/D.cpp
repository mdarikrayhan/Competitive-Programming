/*
BuzzyBeez
15:00 UTC+7
09/04/2024 
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

map<int, int> pos;

struct __query {
	char op; int l, r, i;
	__query() {}
	__query(char c, int _l, int _r) : op(c), l(_l), r(_r) {}
	__query(char c, int _i) : op(c), i(_i) {}
} query[100008];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, q, x, l, r, mid; cin >> n >> q;
	set<pair<int, pair<int, int>>, greater<pair<int, pair<int, int>>>> IT1; IT1.insert({n, make_pair(1, n)});
	set<pair<int, int>> IT2; IT2.insert({1, n}); set<pair<int, int>>::iterator it;
	pair<int, int> p, pl, pr;
	for (int i = 1; i <= q; ++i) {
		cin >> x;
		if (x) {
			if (!pos[x]) {
				p = (*IT1.begin()).second; l = p.first; r = p.second; mid = (l + r + 1) / 2;
				IT1.erase(IT1.begin()); IT2.erase(p);
				if (l < mid) IT1.insert({mid - l, make_pair(l, mid - 1)}), IT2.insert({l, mid - 1});
				if (mid < r) IT1.insert({r - mid, make_pair(mid + 1, r)}), IT2.insert({mid + 1, r});
				query[i] = __query('+', mid); pos[x] = mid;
			}
			else {
				mid = pos[x]; pos[x] = 0; pl = pr = {-1, -1};
				it = IT2.lower_bound({mid, 0});
				if (it != IT2.end()) pr = *it;
				if (it != IT2.begin()) pl = *(--it);
				if (pl.second != mid - 1) pl = {mid, mid};
				if (pr.first != mid + 1) pr = {mid, mid};
				IT2.erase(pl); IT2.erase(pr);
				IT1.erase({pl.second - pl.first + 1, pl}); IT1.erase({pr.second - pr.first + 1, pr});
				IT2.insert({pl.first, pr.second}); 
				IT1.insert({pr.second - pl.first + 1, make_pair(pl.first, pr.second)});
				query[i] = __query('-', mid);
			}
		}
		else {
			cin >> l >> r;
			query[i] = __query('?', l, r);
		}
	}
	ordered_set<int> st;
	for (int i = 1; i <= q; ++i) 
		if (query[i].op == '+') st.insert(query[i].i);
		else if (query[i].op == '-') st.erase(query[i].i);
		else {
			l = query[i].l; r = query[i].r;
			cout << st.order_of_key(r + 1) - st.order_of_key(l) << '\n';
		}
}