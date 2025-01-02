#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void files() {
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
}
#define AhmedAbdelhamid ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define endl '\n'
#define ll long long
#define ld long double
#define binRep(num, n) bitset<n>(num).to_string()
#define ONES(n) __builtin_popcount(n)
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define sz(v) ((int)v.size())
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) x.rbegin(), (x).rend()
#define print(v) for (auto &i : v) cout << i << ' '; cout << endl
#define debug(v) for (auto &i : v) cout << i << '|'
#define print2d(v) for(auto &i:v) {for(auto &j:i) cout << j << ' '; cout << endl; }
#define printmp(mp) for(auto &it:mp) cout << it.F << ' ' << it.S << endl;
#define input(v) for (auto &i : v) cin >> i
#define rv(x) return (void(cout << x << endl))
#define pi pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pi>
#define vbl vector<bool>
#define vvi vector<vi>
#define vvll vector<vll>
#define vvpi vector<vpi>
#define OO 1e18
#define rp(i,st,ed) for(int i=st; i<ed; i++)
int dx[] = {+0, +0, -1, +1, -1, -1, +1, +1};
int dy[] = {+1, -1, +0, +0, +1, -1, +1, -1};

int n,m;
vpi seg;
vi a;
bool valid(int mid) {
    vi calc(n);
    rp(i,0,mid) {
        calc[a[i]] = 1;
    }
    rp(i,1,n) {
        calc[i] += calc[i-1];
    }
    for(auto [l,r] : seg) {
        int ones = calc[r];
        if(l) ones -= calc[l-1];
        int zeros = (r-l+1) - ones;
        if(ones > zeros) return 1;
    }
    return 0;
}

void solve(int T) {
    cin >> n >> m;
    seg = vpi(m);
    rp(i,0,m) {
        cin >> seg[i].F >> seg[i].S;
        seg[i].F--, seg[i].S--;
    }
    int q; cin >> q;
    a = vi(q);
    rp(i,0,q) {
        cin >> a[i];
        a[i]--;
    }
    int l=1, r=q, ans=-1;
    while(l<=r) {
        int mid = (l+r)/2;
        if(valid(mid)) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    rv(ans);
}

int32_t main() {
//    files();
    AhmedAbdelhamid
    int T = 1;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve(i);
    }
}