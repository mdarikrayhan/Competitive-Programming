/* 
You are always optional, aren't you?
*/
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
 
#include <bits/stdc++.h>
 
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template<typename T> using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template <class K,class V> using omap = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define int long long
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define f first
#define s second
#define pb push_back
#define pii pair<int,int>
#define lb lower_bound
#define ub upper_bound
#define Checkbit(a,i) (((a)>>(i))&1)
#define Setbit(a,i) ((a)^=1LL<<(i))

const int mod = 1e9 + 7;
class BIT
{
public:
    vector<int> tree;
    int n;
    BIT(int sz, int val = 0) {
        tree.assign(sz + 5, val);
        n = sz;
    }
    void update(int pos, int val) {
        while (pos <= n) {
            tree[pos] += val;
            pos += pos & -pos;
        }
    }
    void update(int l, int r, int val) {
        update(l, val);
        update(r + 1, -val);
    }
    int query(int l) {
        int sum = 0;
        while (l > 0) {
            sum += tree[l];
            l -= l & -l;
        }
        return sum;
    }
    int query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};
const int N = 1e5;

void testcase()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> c(n + 1), d(n + 1);

    map<int,int> cm;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        cm[c[i]];
    }
    int id = 0;
    for (auto &it : cm) {
        it.s = ++id;
    }
    for (int i = 1; i <= n; i++) {
        int tmp = c[i];
        c[i] = cm[c[i]];
        d[c[i]] = tmp;
    }
    cm.clear();

    int N;
    cin >> N;
    vector<int> like(n + 1);
    for (int i = 1; i <= N; i++) {
        int h;
        cin >> h;
        like[h] = 1;
    }
    int M;
    cin >> M;
    for (int i = 1; i <= M; i++) {
        int h;
        cin >> h;
        if (like[h] == 0) like[h] = 2;
        else like[h] = 3;
    }
    vector<int> one, two, both, none;
    for (int i = 1; i <= n; i++) {
        if (like[i] == 1) {
            one.pb(c[i]);
        }
        else if (like[i] == 2) {
            two.pb(c[i]);
        }
        else if (like[i] == 3) {
            both.pb(c[i]);
        }
        else {
            none.pb(c[i]);
        }
    }

    sort(all(one));
    sort(all(two));
    sort(all(both));
    sort(rall(none));

    // debug(one);
    // debug(two);
    // debug(both);
    // debug(none);

    BIT t(n), count(n);

    for (auto i : none) {
        count.update(i, 1);
        t.update(i, d[i]);
    }

    int mn = min({one.size(), two.size(), (size_t)k});

    for (int i = mn; i < one.size(); i++) {
        count.update(one[i], 1);
        t.update(one[i], d[one[i]]);
    }
    for (int i = mn; i < two.size(); i++) {
        count.update(two[i], 1);
        t.update(two[i], d[two[i]]);
    }
    for (int i = k - mn; i < both.size(); i++) {
        count.update(both[i], 1);
        t.update(both[i], d[both[i]]);
    }
    if (k - mn > both.size()) {
        cout << "-1\n";
        return;
    }

    vector<int> pre(n + 1), pre2(n + 1);
    for (int i = 0; i < mn; i++) {
        pre[i + 1] = pre[i] + d[one[i]] + d[two[i]];
    }

    for (int i = 0; i < both.size(); i++) {
        pre2[i + 1] = pre2[i] + d[both[i]];
    }

    int ans = 1e18;

    int tot = pre[mn];
    int len = k + mn;
    for (int i = 0; i < k - mn; i++) {
        tot += d[both[i]];
    }
    if (len > m) {
        tot = 0;
        len = 0;
    }
    else if (len < m) {
        int need = m - len;
        int lo = 1;
        int hi = n;
        int target = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (count.query(mid) >= need) {
                target = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        int exist = count.query(target);
        tot += t.query(target) - (exist - need) * target;
        ans = min(ans, tot);
    }
    else {
        ans = min(ans, tot);
    }
    for (int i = k - mn; i < both.size(); i++) {
        count.update(both[i], -1);
        t.update(both[i], -d[both[i]]);
        tot = pre2[i + 1];
        if (mn > 0) {
            count.update(one[mn - 1], 1);
            t.update(one[mn - 1], d[one[mn - 1]]);
            count.update(two[mn - 1], 1);
            t.update(two[mn - 1], d[two[mn - 1]]);
            tot += pre[mn - 1];
        }
        mn = max(0ll, --mn);
        int need = m - (i + 1 + mn * 2);
        if (need < 0) {
            continue;
        }
        if (need > 0) {
            int lo = 1;
            int hi = n;
            int target = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (count.query(mid) >= need) {
                    target = mid;
                    hi = mid - 1;
                }
                else {
                    lo = mid + 1;
                }
            }

            assert(target != -1);
            int exist = count.query(target);
            tot += t.query(target) - (exist - need) * target;
            ans = min(ans, tot);
        }
        else {
            ans = min(ans, tot);
        }
    }

    if (ans == 1e18) {
        cout << "-1\n";
    }
    else {
        cout << ans << "\n";
    }
}
 
signed main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    int cs = 1;
    while (t--) {
        //cout << "Case " << cs++ << ":" << " ";
        testcase();
    }
}