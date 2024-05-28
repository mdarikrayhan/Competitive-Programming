/*
    CC: Tridipta Mishra
*/

#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("unroll-loops")
#pragma gcc optimize("Ofast")
#pragma GCC optimization("Ofast")
#pragma optimize(Ofast)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define ll long long
#define pb push_back
#define eb emplace_back
#define srt(v) sort(v.begin(), v.end())
#define f(i,a,b) for(ll i = a;i<b;i++)
#define fc(i,a,b,c) for(ll i = a;i<b;i+=c)
#define fi(i,a,b) for(ll i = a;i>=b;i--)
#define vi vector<ll>
#define pii pair<ll,ll>
#define vpi vector<pair<ll,ll>>
#define vvi vector<vector<ll>>
#define lcm(a,b) (a*b)/__gcd(a,b)
#define in(v) f(i,0,v.size()) cin>>v[i];
#define outs(v) f(i,0,v.size()) cout<<v[i]<<" ";
#define outl(v) f(i,0,v.size()) cout<<v[i]<<endl;
#define all(x) x.begin(),x.end()
#define mp make_pair
#define be begin()
#define en end()
#define lb lower_bound
#define ub upper_bound
#define pq priority_queue<ll>
#define pqr priority_queue<ll,vector<ll>,greater<ll>>
#define endl '\n'

const ll MOD = 1e9+7;
const double pi = 3.141597653;
const int INF = 2e9 + 1;

using namespace std;
using namespace __gnu_pbds;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_mset;

void updateSt(set<pair<int, int>> &st, set<pair<int, int>> &fr, int &sum, int need) {
    need = max(need, 0);
    while (true) {
        bool useful = false;
        while (st.size() > need) {
            sum -= st.rbegin()->first;
            fr.insert(*st.rbegin());
            st.erase(prev(st.end()));
            useful = true;
        }
        while (st.size() < need && !fr.empty()) {
            sum += fr.begin()->first;
            st.insert(*fr.begin());
            fr.erase(fr.begin());
            useful = true;
        }
        while (!st.empty() && !fr.empty() && fr.begin()->first < st.rbegin()->first) {
            sum -= st.rbegin()->first;
            sum += fr.begin()->first;
            fr.insert(*st.rbegin());
            st.erase(prev(st.end()));
            st.insert(*fr.begin());
            fr.erase(fr.begin());
            useful = true;
        }
        if (!useful) break;
    }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> times[4];
    vector<int> sums[4];
    for (int i = 0; i < n; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        times[a * 2 + b].push_back({t, i});
    }
    for (int i = 0; i < 4; ++i) {
        sort(times[i].begin(), times[i].end());
        sums[i].push_back(0);
        for (auto it : times[i]) {
            sums[i].push_back(sums[i].back() + it.first);
        }
    }

    int ans = INF;
    int pos = INF;
    set<pair<int, int>> st;
    set<pair<int, int>> fr;
    int sum = 0;
    vector<int> res;
    for (int iter = 0; iter < 2; ++iter) {
        st.clear();
        fr.clear();
        sum = 0;
        int start = 0;
        while (k - start >= (int)sums[1].size() || k - start >= (int)sums[2].size() || m - start - (k - start) * 2 < 0) {
            ++start;
        }
        if (start >= (int)sums[3].size()) {
            cout << -1 << endl;
            return;
        }
        int need = m - start - (k - start) * 2;
        for (int i = 0; i < 3; ++i) {
            for (int p = (int)times[i].size() - 1; p >= (i == 0 ? 0 : k - start); --p) {
                fr.insert(times[i][p]);
            }
        }
        updateSt(st, fr, sum, need);
        for (int cnt = start; cnt < (iter == 0 ? (int)sums[3].size() : pos); ++cnt) {
            if (k - cnt >= 0) {
                if (cnt + (k - cnt) * 2 + st.size() == m) {
                    if (ans > sums[3][cnt] + sums[1][k - cnt] + sums[2][k - cnt] + sum) {
                        ans = sums[3][cnt] + sums[1][k - cnt] + sums[2][k - cnt] + sum;
                        pos = cnt + 1;
                    }
                }
            } else {
                if (cnt + st.size() == m) {
                    if (ans > sums[3][cnt] + sum) {
                        ans = sums[3][cnt] + sum;
                        pos = cnt + 1;
                    }
                }
            }
            if (iter == 1 && cnt + 1 == pos) break;
            need -= 1;
            if (k - cnt > 0) {
                need += 2;
                fr.insert(times[1][k - cnt - 1]);
                fr.insert(times[2][k - cnt - 1]);
            }
            updateSt(st, fr, sum, need);
        }
        if (iter == 1) {
            for (int i = 0; i + 1 < pos; ++i) res.push_back(times[3][i].second);
            for (int i = 0; i <= k - pos; ++i) {
                res.push_back(times[1][i].second);
                res.push_back(times[2][i].second);
            }
            for (auto [value, position] : st) res.push_back(position);
        }
    }

    cout << ans << endl;
    for (auto it : res) cout << it + 1 << " ";
    cout << endl;
}


int main()
{
    #ifndef ONLINE_JUDGE
      clock_t tm = clock();
    #endif
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

