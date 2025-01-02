#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

// Stream insertion operator for pairs
template<typename A, typename B>
ostream& operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

// Stream insertion operator for containers
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream& operator<<(ostream &os, const T_container &v) {
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}

// Debugging utilities
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}

#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

// Definition for ordered_set
template<typename T>
using ordered_set = tree<
        T,
        null_type,
        less<T>,
        rb_tree_tag,
        tree_order_statistics_node_update>;



int solve() {
    ll a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    ll output = b + 1;
    for (int i = 1; i < ceil(sqrt(2*b)) + 1; i++) {
        output = min(output, (i - 1) + a / i + (a % i ? 1 : 0) + b / i + (b % i ? 1 : 0));
    }
    cout << output << "\n";
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); // Speeds up the execution
    cin.tie(nullptr); // Untie cin from cout
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}