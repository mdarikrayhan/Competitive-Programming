// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC optimize("O3,unroll-loops")


#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// typedef tree<
//     int,
//     null_type,
//     less_equal<int>,
//     rb_tree_tag,
//     tree_order_statistics_node_update
// >
// ordered_set;
namespace __gnu_pbds{
          typedef tree<long long,
                       null_type,
                       less_equal<long long>,
                       rb_tree_tag,
                       tree_order_statistics_node_update> ordered_set;
}
using namespace __gnu_pbds;

#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;


 
void __print32_t(int32_t x) {cerr << x;}
void __print32_t(long x) {cerr << x;}
void __print32_t(long long x) {cerr << x;}
void __print32_t(unsigned x) {cerr << x;}
void __print32_t(unsigned long x) {cerr << x;}
void __print32_t(unsigned long long x) {cerr << x;}
void __print32_t(float x) {cerr << x;}
void __print32_t(double x) {cerr << x;}
void __print32_t(long double x) {cerr << x;}
void __print32_t(char x) {cerr << '\'' << x << '\'';}
void __print32_t(const char *x) {cerr << '\"' << x << '\"';}
void __print32_t(const string &x) {cerr << '\"' << x << '\"';}
void __print32_t(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print32_t(const pair<T, V> &x) {cerr << '{'; __print32_t(x.first); cerr << ','; __print32_t(x.second); cerr << '}';}
template<typename T>
void __print32_t(const T &x) {int32_t f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print32_t(i); cerr << "}";}
void _print32_t() {cerr << "]\n";}
template <typename T, typename... V>
void _print32_t(T t, V... v) {__print32_t(t); if (sizeof...(v)) cerr << ", "; _print32_t(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print32_t(x)
#else
#define debug(x...)
#endif
 
template<typename T> using minpq = priority_queue<T, vector<T>, greater<T>>;
#define rep(i,a,b) for(int32_t i = a; i < b; i ++)
#define ill long long int32_t
#define ll long long
#define int int64_t
#define nl "\n"
#define el endl
#define pb push_back
#define FOR(a,b,c) for (int32_t a = b; a < c; a++)
using namespace std;
 
 
// const int32_t N = 3e5+1;
const ll neg_inf = -2e7 + 2;    
const ll inf = 1e18 + 1;
// const int32_t mod = 998244353;
// const int32_t MOD = 1e9+7;
const int32_t MAXN = 4e6+1;
const int32_t eps = 1e-6;
const int N = 1e6+1;


ll runcases(ll qq)
{  

    int n;
    cin >> n;

    vector<int> v(n);

    for (auto &s : v) cin >> s;

    vector<int> prev(n,-1), nxt(n,-1);

    priority_queue<array<int,3>> pq;

    for (int i = 0; i < n; i++) {
        if (i+1 < n) {
            if (abs(v[i+1]-v[i]) == 1) {
                int ind = i,ind2 = i+1;
                if (v[i+1] > v[i]) {
                    ind = i+1;
                    ind2 = i;
                }
                pq.push({v[ind],ind,ind2});
            }
            nxt[i] = i+1;
        }
        if (i-1 >= 0) {
            prev[i] = i-1;
        }
    }

    map<int,int> done;

    int del = 0;
    while (!pq.empty()) {
        // debug(pq.size());
        auto tp = pq.top();
        pq.pop();
        if (done[tp[1]] == 1) continue;
        done[tp[1]] = 1;
        debug(tp);
        del++;
        int ind = tp[1];
        int ind2 = tp[2];
        if (ind < ind2) {
            prev[ind2] = prev[ind];
            if (prev[ind] != -1) {
                nxt[prev[ind]] = nxt[ind];
            }
        }
        else {
            nxt[ind2] = nxt[ind];
            if (nxt[ind] != -1) {
                prev[nxt[ind]] = prev[ind];
            }
        }
        if (nxt[ind2] != -1) {
            if (abs(v[ind2] - v[nxt[ind2]]) == 1) {
                int i1 = ind2, i2 = nxt[ind2];
                if (v[nxt[ind2]] > v[ind2]) {
                    swap(i1,i2);
                }
                pq.push({v[i1],i1,i2});
            }
        }
        if (prev[ind2] != -1) {
            if (abs(v[ind2] - v[prev[ind2]]) == 1) {
                int i1 = ind2, i2 = prev[ind2];
                if (v[prev[ind2]] > v[ind2]) {
                    swap(i1,i2);
                }
                pq.push({v[i1],i1,i2});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (done[i] == 0 && v[i] != 0) {
            cout << "NO" << nl;
            return 0;
        }
    }

    cout << (del == n-1 ? "YES" : "NO") << nl;

    return 0;
}

 
signed main()
{
    
    //..........Fast I/O.........//
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //..........................//


 

    ll t ;
 
    cin >> t;

    // debug(t);
    for (int32_t i = 1; i <= t; i ++) {
        runcases(i);
    }
    
    return 0;
 
}