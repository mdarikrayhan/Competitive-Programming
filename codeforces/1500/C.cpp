#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define endl '\n'
#define debug(x) cout << __FUNCTION__ << ": " << #x " = " << (x) << endl
using ll = long long;

const int maxn = 5e5 + 10;
const int maxm = 4 * maxn;
const ll INF = 3e18;
const int mod = 998244353;
int n, m, k;

void kkkyyyhhh() {
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int> (m + 1)), b(a);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }
    vector<int> ans, q, down(m + 1), ok(n + 1);
    vector<vector<int>> g(n + 1);
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i < n; i++) {
            if (b[i][j] > b[i + 1][j]) {
                down[j]++;
                g[i].push_back(j);
            }
        }
        if (down[j] == 0) {
            q.push_back(j);
        }
    }
    for (int i = 0; i < q.size(); i++) {
        int x = q[i];
        for (int i = 0; i < n; i++) {
            if (!ok[i] && b[i][x] < b[i + 1][x]) {
                ok[i] = 1;
                for (int v : g[i]) {
                    down[v]--;
                    if (!down[v]) q.push_back(v);
                }
            }
        }
    } 
    reverse(q.begin(), q.end());
    vector<int> p(n + 1);
    iota(p.begin() + 1, p.end(), 1);
    for (auto c : q) {
        vector<int> cnt(n + 1);
        for (int i = 1; i <= n; i++) {
            cnt[a[i][c]]++;
        }
        for (int i = 1; i <= n; i++) {
            cnt[i] += cnt[i - 1];
        }
        vector<int> t(n + 1);
        for (int i = n; i >= 1; i--) {
            t[--cnt[a[p[i]][c]] + 1] = p[i];
        }
        p = t;
    }
    for (int i = 1; i <= n; i++) {
        if (a[p[i]] != b[i]) {
            cout << -1 << endl;
            return;
        }
    }
    cout << q.size() << endl;
    for (auto x : q) {
        cout << x << " ";
    }
    cout << endl;
}     

signed main() {
    IOS;
    int w_ = 1;
  //  cin >> w_;
    while (w_--) kkkyyyhhh();
    return 0;
} 