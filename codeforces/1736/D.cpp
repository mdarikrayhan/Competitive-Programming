#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int) (x).size())
#define pb push_back
#define mp make_pair
#define int long long

using namespace std;
using namespace __gnu_pbds;

template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> inline bool umin(T &a, const T &b) { if(a > b) { a = b; return 1; } return 0; }
template <typename T> inline bool umax(T &a, const T &b) { if(a < b) { a = b; return 1; } return 0; }

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;
const ll base = 1e6 + 9;
const ll inf = 1e18;
const int MAX = 2e5 + 42;
const int LG = 20;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<ll> dis(1, inf);

/*
1
5
0110001010
*/

void solve() {
    int n;
    cin >> n; n <<= 1;
    string s;
    for(int i = 0; i < n; i++) s.pb(char('0' + dis(gen) % 2));
    cin >> s;
    int sum = 0; for(auto &i : s) i &= 1; for(auto i : s) sum += i;
    if(sum & 1) {
        cout << "-1\n";
        return;
    }
    vector<int> pos;
    int x = 0;
    for(int i = 0; i < n; i += 2) {
        if(s[i] == s[i + 1]) continue;
        if(s[i] == x) pos.pb(i);
        else pos.pb(i + 1);
        x ^= 1;
    }
    cout << sz(pos) << " "; for(auto i : pos) cout << i + 1 << " "; cout << '\n'; for(int i = 0; i < n; i += 2) cout << i + 1 << " "; cout << '\n';
}

/*
1
6
111000110001
*/

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while(ttt--) {
        solve();
    }
}