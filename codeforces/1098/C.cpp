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
const int MX = 2e5+5;
const ll INF = 1e18;
const ld PI = 4*atan((ld)1);
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
const int N = 1e5 + 10;

 
 

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
 
int p[N];
int deg[N];

int main() {
    IOS;
    ll n, s;
    cin >> n >> s;
    if (s < n + (n - 1) || n * (n + 1) / 2 < s) {
        cout << "No\n";
        return 0;
    }
    int f = 1;
    while(f < n) {
        ll leaf = 1;
        ll cur_su = 1;

        ll used = 1;
        int lvl = 1;
        while(used < n) {
            ++lvl;
            ll tmp = leaf * f;
            if (tmp < n - used) {
                cur_su += tmp * lvl;
                leaf = tmp;
                used += tmp;
            }
            else {
                tmp = n - used;
                cur_su += tmp * lvl;
                break;
            }
        }
        if (cur_su <= s) {
            break;
        }
        ++f;
    }
    ll cur_s = 0;
    set<pii> v; //lvl, ver
    priority_queue<pair<int, int> > leaf; //{lvl, vert

    for (int i = 1; i < n; ++i) {
        v.insert({i, i - 1});
        deg[i - 1] = 1;

        p[i] = i - 1;
        cur_s += n - i + 1;
    }

    v.insert({n, n - 1});
    deg[n - 1] = 0;
    cur_s += 1;

    leaf.push({n, n - 1});

    while(cur_s > s) {
        auto it = v.begin();
        if (deg[(*it).se] == f) {
            v.erase(it);
            continue;
        }
        int up_lvl = (*it).fi;
        int up_ver = (*it).se;

        auto tmp = leaf.top();
        int down_lvl = tmp.fi;
        int down_ver = tmp.se;


        if (cur_s + up_lvl - down_lvl + 1 < s) {
            v.erase(it);
            continue;
        }

        leaf.pop();
        v.erase(v.find(tmp));
        v.insert({up_lvl + 1, down_ver});
        cur_s += up_lvl - down_lvl + 1;
        ++deg[up_ver];

        --deg[p[down_ver]];
        if (deg[p[down_ver]] == 0) {
            leaf.push({down_lvl - 1, p[down_ver]});
        }

        p[down_ver] = up_ver;
    }

    cout << "Yes\n";
    for (int i = 1; i < n; ++i) {
        cout << p[i] + 1 << ' ';
    }
    cout << '\n';
}
