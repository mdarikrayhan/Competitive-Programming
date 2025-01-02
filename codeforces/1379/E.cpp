#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

using uint = unsigned int;
using ull = unsigned long long;

template<typename C> struct rge{C l, r;};
template<typename C> rge<C> range(C i, C j) { return rge<C>{i, j}; }
template<typename C> ostream& operator<<(ostream &os, rge<C> r) { os << '{'; for(auto it = r.l; it != r.r; it++) os << "," + (it == r.l) << *it; os << '}'; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '{' << p.first << "," << p.second << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ","; return os << '}'; }
void dbg_out() { cerr << ']' << endl; }
template<typename A> void dbg_out(A H) { cerr << H; dbg_out(); }
template<typename A, typename B, typename... C> void dbg_out(A H, B G, C... T) { cerr << H << ","; dbg_out(G, T...); }
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

vi ans;
int nc = 0;

vb good;

bool possible(int n, int k) {
    if(n == 1) {
        return k == 0;
    }
    if(k >= n/2) {
        return false;
    }
    if(n == 9 && k == 2) {
        return false;
    }
    if(good[n]) {
        return k != 1;
    }
    return k != 0;
}

void build(int rt, int n, int k) {
    assert(possible(n, k));
    int u = nc++;
    ans[u] = rt;

    // special cases
    if(n == 1) {
        return;
    }
    if(n == 11 && k == 3) {
        build(u, 3, 0);
        build(u, 7, 2);
        return;
    }
    if(good[n-2] && k == 2) {
        build(u, 3, 0);
        build(u, n - 4, 1);
        return;
    }
    if(k >= 2) {
        build(u, 1, 0);
        build(u, n - 2, k - 1);
        return;
    }
    if(k == 0) {
        build(u, n / 2, 0);
        build(u, n / 2, 0);
        return;
    }
    assert(k == 1);
    int b = 1;
    while(b < n) {
        b = b * 2 + 1;
    }
    b /= 2;
    int a = b / 2;
    if(a + b < n-1) {
        build(u, n - b - 1, 1);
        build(u, b, 0);
    } else if(a + b == n-1) {
        build(u, a, 0);
        build(u, b, 0);
    } else {
        build(u, a, 0);
        build(u, n - a - 1, 1);
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    if(n % 2 == 0) {
        cout << "NO" << endl;
        return;
    }
    good.assign(n+1, false);
    int c = 1;
    while(c <= n) {
        good[c] = true;
        c = c * 2 + 1;
    }

    if(!possible(n, k)) {
        cout << "NO" << endl;
        return;
    }

    ans.assign(n, -1);

    build(-1, n, k);

    cout << "YES" << endl;
    for(int i : ans) {
        cout << i+1 << ' ';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
