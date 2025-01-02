#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// less_equal here isn't related to order_of_key, but to how elements are stored
// swapping here works like this : ors1.swap(ors2);
// NOTE : default order is ascending with no repetition.
template<typename K, typename V, typename Comp = less<K>>
using order_statistic_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;

template<typename K, typename Comp = less<K>>
using order_statistic_set = order_statistic_map<K, null_type, Comp>;

#define int long long
#define ld long double
#define el '\n'
#define fi first
#define se second

#define Nine_seconds ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

// pen and paper, dip shit
// sample cases, corner cases

void run_case(int tc) {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    order_statistic_set<int, less_equal<>> ors;
    map<int, int> vis;
    for (int i = 0; i < n; i++) {
        int sm = ors.order_of_key(b[i]);
        int bg = ors.size() - sm - vis[b[i]];

        if (!vis[b[i]])
            ors.insert(b[i]), vis[b[i]] += 1;
        if (sm > bg) {
            if (sm - bg > 2)
                return cout << "NO" << el, void();
            if (sm - bg == 2)
                ors.insert(1e9), ors.insert(1e9);
            else
                ors.insert(1e9);
        } else if (bg > sm) {
            if (bg - sm > 2)
                return cout << "NO" << el, void();
            if (bg - sm == 2)
                ors.insert(-1e9), ors.insert(-1e9);
            else
                ors.insert(-1e9);
        }
    }

    cout << "YES" << el;
}


int32_t main() {
    Nine_seconds        /*Turn Off for Interactive Problems*/

    int _t = 1;
    cin >> _t;
    for (int i = 1; i <= _t; i++) {
        run_case(i);
    }
}