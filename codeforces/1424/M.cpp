#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
//std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 998244353;
const int N = 1e3 + 5;

int n, k, p[N], vis[30];
vector<string> dic;
int deg[N], G[30][30], q[N];
void MAIN() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        q[p[i]] = (i - 1) * k;
        string t;
        for (int j = 1; j <= k; j++) cin >> t, dic.push_back(t);
        for (auto ch : t) vis[ch - 'a'] = 1;
    }
    //for (auto x : dic) cout << x.fi << '\n';
    vector<int> id;
    for (int kk = 0; kk < n; kk++)
        for (int i = q[kk]; i < q[kk] + k; i++) id.push_back(i);
    for (int tt = 1; tt < k * n; tt++) {
            string &s = dic[id[tt]];
            int m = s.size();
            string &t = dic[id[tt - 1]];
            m = min(m, (int)t.size());
            int diff = 0;
            for (int j = 0; j < m; j++) if (s[j] != t[j]) {
                G[t[j] - 'a'][s[j] - 'a'] = 1;
                diff = 1;
                break;
            }
            if (!diff && s.size() < t.size()) return cout << "IMPOSSIBLE\n", void();
        }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) deg[j] += G[i][j];
    }
    queue<int> q;
    for (int i = 0; i < 26; i++) if (!deg[i] && vis[i]) q.push(i);
    vector<char> ans;
    int sum = 0;
    for (int i = 0; i < 26; i++) sum += vis[i];
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans.push_back(u + 'a');
        for (int v = 0; v < 26; v++) if (G[u][v]) {
            deg[v]--;
            if (!deg[v]) q.push(v);
        }
    }
    if (sum != ans.size()) cout << "IMPOSSIBLE\n";
    else for (char x : ans) cout << x;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) MAIN();
    return 0;
}