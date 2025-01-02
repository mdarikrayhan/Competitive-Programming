#include <bits/stdc++.h>

#ifdef LOCAL
#define debug(x) cerr << (#x) << ": " << x << endl
#else
#define debug(x) ;
#endif

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n)-1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define print_pvector(v)                                  \
    for (int i = 0; i < n; i++)                           \
    {                                                     \
        cout << v[i].first << " " << v[i].second << "\n"; \
    }
using namespace std;

//for ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template <typename T>
using vt = vector<T>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

mt19937 rnd(0);

const int BIG = 1e9, LG = 30;
const ll INF = 1e18;
const int mod = 1e9+7;
vector<ll> fact(1e5+1,1);
void solve(){
    int n;cin>>n;
    ll ans=0;
    ans = (1LL* n*(n-1))%mod;
    ans = (ans * fact[n])%mod;
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    cin >> tt;
    for(int i=1;i<=1e5;i++){
        fact[i] = (1LL * fact[i-1] * i)%mod;
    }
    while (tt--){
        solve();
        cout<<"\n";
    }
    return 0;
}