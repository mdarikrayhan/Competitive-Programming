// LUOGU_RID: 157174004
#include <bits/stdc++.h>
#define int long long

#define F(i, a, b) for (int i = (a); i <= (b); i++)
#define dF(i, a, b) for (int i = (a); i >= (b); i--)
using namespace std;

typedef long long ll;
typedef pair<int, int> Pair;

const int N = 200005, M = (N << 1), inf = 1e16, mod = 1e9 + 7;
int n, k, w[N];
mt19937 tnnd(time(0));
int rnd(int l, int r) { return tnnd() % (r - l + 1) + l; }
int ask(vector<int> a, vector<int> b) {
    cout << "? " << a.size() << ' ' << b.size() << endl;
    for (auto i : a)
        cout << i << ' ';
    cout << endl;
    for (auto i : b)
        cout << i << ' ';
    cout << endl;
    string res;
    cin >> res;
    if (res == "FIRST")
        return 1;
    else if (res == "SECOND")
        return -1;
    return 0;
}
int calc(int x, int y) {
    int l = x, r = y, res = -1;
	while (l <= r){
        int mid = l + r >> 1;
        vector<int> a, b;
        F(i, 1, mid - x + 1) a.push_back(i);
        F(i, x, mid) b.push_back(i);
		if (ask(a, b)) r = mid - 1, res = mid;
		else l = mid + 1;
	}
	return res;
}
void solve() {
    cin >> n >> k;
    F(i, 1, n) w[i] = -1;
    int x = 1, y = 2;
    vector<bool> vis(n + 1);
    F(i, 1, min(25ll, n - 1)) {
        y = rnd(2, n);
        while (vis[y]) y = rnd(2, n);
        vis[y] = 1;
        int res = ask({1}, {y});
        if (res == -1) {
            cout << "! " << "1" << endl;
            return;
        }
    }
    int len = 1, ans = 0;
    while (1) {
        if (len * 2 > n) {
            int ans = calc(len + 1, n);
            cout << "! " << ans << endl;
            return;
        }
        vector<int> a, b;
        F(i, 1, len) a.push_back(i);
        F(i, len + 1, len * 2) b.push_back(i);
        if (ask(a, b)) {
            int ans = calc(len + 1, len * 2);
            cout << "! " << ans << endl;
            return;
        }
        len = len * 2;
    }
}
signed main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
