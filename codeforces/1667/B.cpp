/*    _   __   ___    _   ____    _    _        _____    ___     _____
     | | / /  / _ \  | | |  _ \  | |  | |      |___  |  / _ \   |  ___|
     | |/ /  | |_| | | | | |_| | |  \/  |         / /  | |_| |  | |__
     |   /   |  _  | | | |  _ /  | |\/| |        / /   |  _  |  |  __|
     | |\ \  | | | | | | | | \ \ | |  | |       / /__  | | | |  | |
     |_| \_\ |_| |_| |_| |_| |_| |_|  |_|      |_____| |_| |_|  |_|      */
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
#ifndef ONLINE_JUDGE

#include "debug.cpp"

#else
#define kar(...)
#endif
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define int ll
#define endl '\n'

const int N = 3e5 + 30, mod = 1e9 + 7, INF = 1e18 + 10;

template<class T>
struct Seg {  /*CHANGE THE ID YA KARIM !!*/
    const T ID = -INF; /**/ int n;/**/ vector<T> seg;/**/
    T comb(T a, T b) { return max(a, b); } // Function
    void build(int _n) { n = _n, seg.assign(2 * n, ID); } /**/
    void pull(int p) { seg[p] = comb(seg[2 * p], seg[2 * p + 1]); }/**/
    void upd(int p, T val) { seg[p += n] = val;/**/for (p /= 2; p; p /= 2)pull(p);/**/}/**/
    T query(int l, int r) {/**/T ra = ID, rb = ID;/**/for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1)ra = comb(ra, seg[l++]);/**/if (r & 1)rb = comb(seg[--r], rb);
        }/**/return comb(ra, rb);
    }/**/void print(int i = -1) {/**/while (++i < n)
            cout << (i == 0 ? "sg : " : "") << query(i, i) << (i == n - 1 ? "\n" : " ");/**/}
};


void Solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1), pref(n + 5), calc(n + 4, -INF), comp, zero(n+10,-INF);
    Seg<int> sg;
    sg.build(n + 10);

    auto dp = [&](int pos) { return sg.query(pos, pos); };
    auto get = [&](int x) { return lower_bound(all(comp), x) - comp.begin() + 2; };

    for (int i = 1; i <= n; i++)cin >> v[i];
    for (int i = 1; i <= n; i++)pref[i] = pref[i - 1] + v[i];
    comp = pref;
    sort(all(comp));


    sg.upd(get(0),0);
    calc[0]=0;
    for (int i = 1; i <= n; i++) {
        int val = 0;
        if (v[i] < 0) val = -1;
        else if (v[i] > 0) val = 1;
        calc[i] = calc[i - 1] + val;

        int p = pref[i];

        int curr = i + sg.query(0, get(p) - 1);

        calc[i] = max(calc[i], curr);
        calc[i] = max(calc[i], zero[get(p)]);
        // when = 0 ;
        sg.upd(get(p), max(dp(get(p)), calc[i] - i));
        zero[get(p)]= max (zero[get(p)], calc[i]);
    }
    
    cout << calc[n] << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int Test_case = 1;
    cin >> Test_case;
    while (Test_case--) Solve();
}