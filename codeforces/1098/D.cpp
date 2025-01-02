#pragma GCC optimize("O3")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define IOS ios::sync_with_stdio(false); cin.tie(0)
#define ll long long
#define ld long double
#define mp(a, b) make_pair(a, b)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define fi first
#define se second
 
 
const int MOD = 1e9+7; // 998244353; // = (119<<23)+1
const int N = 5e5+5;
const int INF = 1e9 + 10;
const ld PI = 4*atan((ld)1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
 
 
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 

struct seg_tree {
    vector<ll> tree;
    int size;
    int shift;
 
    seg_tree(int n) {
        shift = (1 << (int(log2(n)) + 1));
        size = shift * 2;
        tree.assign(size, 0); //neutral
    }

    void set(int i, ll val) {
        tree[i += shift] = val;
        while (i /= 2)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
 
    ll get(int l, int r) {
        if (r < 0) {
            return 0;
        }

        l += shift, r += shift;
        ll res = 0;

        while(l <= r) {
            if (l & 1)
                res += tree[l];

            if (!(r & 1))
                res += tree[r];

            l = (l + 1) / 2;
            r = (r - 1) / 2;
        }
        return res;
    }
}; 

int main() {
    IOS;
    int m;
    cin >> m;
    vector<pair<char, int> > q(m);

    vector<pii> v;

    for (int i = 0; i < m; ++i) {
        cin >> q[i].fi >> q[i].se;
        if (q[i].fi == '+') {
            v.push_back({q[i].se, i});
        }
    }

    sort(v.begin(), v.end());

    vector<int> ind(m);
    for (int j = 0; j < v.size(); ++j) {
        ind[v[j].se] = j;
    }

    set<pii> s; //val and index
    set<pii> bad; //bad in s

    int sz = 0;
    struct seg_tree tr(m);

    for (int i = 0; i < q.size(); ++i) {
        char t = q[i].fi;
        int f = q[i].se;

        if (t == '+'){
            auto it = s.upper_bound({f, i});
            if (it!=s.end() && (*it).fi <= 2 * f && bad.count(*it)) {
                bad.erase(bad.find(*it));
            }
            if (it != s.begin()) {
                --it;
                if (f > (*it).fi * 2) {
                    bad.insert({f, i});
                }
            }
            else {
                bad.insert({f, i});
            }
            s.insert({f, i});
            tr.set(ind[i], f);

            ++sz;
        }
        else {
            auto jt = s.lower_bound({f, 0}); // val, ind
            auto it = jt;
            auto kt = jt;

            ++jt;

            if (bad.count(*it)) {
                bad.erase(bad.find(*it));
            }
            if (jt != s.end() && bad.count(*jt)) {
                bad.erase(*jt);
            }
            if (it != s.begin() && jt != s.end()) {
                --kt;
                if ((*kt).fi * 2 < (*jt).fi) {
                    bad.insert(*jt);
                }
            }
            else if (it == s.begin() && jt != s.end()) {
                bad.insert(*jt);
            }

            tr.set(ind[(*it).se], 0);
            s.erase(it);

            --sz;
        }

        int res = sz - bad.size();

        for (auto [val, i] : bad) {
            if (val <= 2 * tr.get(0, ind[i] - 1)) {
                ++res;
            }
        }

        cout << res << '\n';
    }

}
