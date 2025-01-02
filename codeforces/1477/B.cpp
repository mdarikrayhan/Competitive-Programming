#include <bits/stdc++.h>
 
#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
 
const int N = 2e5 + 5;
int tree[4 * N], lazy[4 * N];
 
void build(int i, int l, int r, const string &s) {
    lazy[i] = 0; // kms
    if(l == r) {
        tree[i] = (s[l] == '1' ? 1 : 0);
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m, s);
    build(2 * i + 2, m + 1, r, s);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}
void prop(int i, int l, int r) {
    if(lazy[i] == 0) return;
    if(lazy[i] == 1) tree[i] = 0;
    else tree[i] = r - l + 1;
    if(l < r) {
        lazy[2 * i + 1] = lazy[2 * i + 2] = lazy[i];
    }
    lazy[i] = 0;
}
int query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return 0;
    prop(i, l, r);
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return query(2 * i + 1, l, m, L, R) + query(2 * i + 2, m + 1, r, L, R);
}
void upd(int i, int l, int r, int L, int R, int val) {
    prop(i, l, r);
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        lazy[i] = val;
        prop(i, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, val);
    upd(2 * i + 2, m + 1, r, L, R, val);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
}
 
void solve() {
    int n, q;
    cin >> n >> q;
    string s, f;
    cin >> s >> f;
    vi l(q), r(q);
    rep(i, 0, q) {
        cin >> l[i] >> r[i];
        l[i]--; r[i]--;
    }
    reverse(all(l));
    reverse(all(r));
    build(0, 0, n - 1, f);
    rep(i, 0, q) {
        int c = query(0, 0, n - 1, l[i], r[i]);
        if(2 * c < r[i] - l[i] + 1) {
            // set to 0
            upd(0, 0, n - 1, l[i], r[i], 1);
        }else if(2 * (r[i] - l[i] + 1 - c) < r[i] - l[i] + 1) {
            // set to 1
            upd(0, 0, n - 1, l[i], r[i], 2);
        }else {
            cout << "NO\n";
            return;
        }
    }
    rep(i, 0, n) {
        char c = query(0, 0, n - 1, i, i) == 1 ? '1' : '0';
        if(s[i] != c) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}