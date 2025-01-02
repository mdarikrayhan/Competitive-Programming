#include<bits/stdc++.h>

using namespace std;
#define all(x)     (x).begin(),(x).end()
#define allr(x)    (x).rbegin(),(x).rend()
#define sz(x)      ((int)x.size())
#define AbdElmawla std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef long double ld;
int dx[] = {-1, 0, 1, 0, 1, -1, 1, -1, 0};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1, 0};

void files() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

const int mxN = 2e5 + 10, mod = 1e9 + 7;
ll seg[mxN * 4];
int idx, val;
bool add;
int x, y;

void update(int n, int l, int r) {
    if (l == r) {
        if (add)
            seg[n] += val;
        else seg[n] = val;
        seg[n] %= mod;
        return;
    }
    if (idx <= (l + r) / 2)update(n * 2, l, (l + r) / 2);
    else update(2 * n + 1, (l + r) / 2 + 1, r);
    seg[n] = (seg[n * 2] + seg[n * 2 + 1] + mod) % mod;
}

ll ans(int n, int l, int r) {
    if (l > y || r < x)return 0;
    if (l >= x && r <= y) {
        return seg[n];
    }
    return (ans(n * 2, l, (l + r) / 2) + ans(n * 2 + 1, (l + r) / 2 + 1, r) + mod) % mod;
}

vector<int> vals;

void update(int _idx, int _val, bool _add) {
    idx = _idx, val = _val, add = _add;
    update(1, 0, sz(vals) + 1);
}

ll ans(int _l, int _r) {
    x = _l, y = _r;
    return ans(1, 0, sz(vals) + 1);
}

int get_indx(int x) {
    return lower_bound(all(vals), x) - vals.begin();
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(m);
    for (auto &it: v)cin >> it.first >> it.second, vals.push_back(it.first), vals.push_back(it.second);
    vals.push_back(0);
    vals.push_back(n);
    sort(all(v), [&](const pair<int, int> &a, const pair<int, int> &b) {
        if (a.second == b.second)return a.first < b.first;
        return a.second < b.second;
    });
    sort(all(vals));
    vals.resize(unique(all(vals)) - vals.begin());
    update(0, 1, false);
    for (auto &[a, b]: v) {
        update(get_indx(b), (ans(get_indx(a), get_indx(b)) - ans(get_indx(b), get_indx(b)) + mod) % mod, true);
    }
    cout << ans(get_indx(n), get_indx(n));
}


int main() {
    AbdElmawla
    files();
/*---------------------------------------*/
    int t = 1;
    //cin>>t;
    for (int i = 1; i <= t; i++) {
        solve();
        // cout << '\n';
    }
    return 0;
}

	  		  	 	 			  	  		  	 		   	