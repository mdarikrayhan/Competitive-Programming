#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define Mod 998244353
#define PI acos(-1);
#define MAXN 0x7fffffff
#define debug cout<<"debug:\t"
void fastread() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin.tie(0);
};
ll fa[210000];
ll dep[210000];
void init() {
    for (int i = 1; i <= 1000; i++) {
        fa[i] = i;
        dep[i] = 0;
    }
}
ll look(ll x) {
    return fa[x] == x ? x : fa[x] = look(fa[x]);
}
void merge(ll x, ll y) {
    ll xx = look(x);
    ll yy = look(y);
    if (xx == yy)return;
    if (dep[xx] < dep[yy]) {
        fa[xx] = yy;
    }
    else {
        fa[yy] = xx;
    }
    if (dep[xx] == dep[yy])dep[xx]++;
}
void solve() {
    ll n; cin >> n;
    string s1, s2; cin >> s1 >> s2;
    init();
    for (int i = 0; i < n; i++) {
        merge(s1[i], s2[i]);
    }
    vector<pair<char, char>>p;
    for (int i = 'a'; i <= 'z'; i++) {
        ll ii = look(i);
        if ( ii != i) {
            p.push_back({ ii,i });
        }
    }
    cout << p.size() << "\n";
    for (auto i : p) {
        cout << (char)i.first << " " << (char)i.second << "\n";
    }
}
int main() {
    fastread();
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}