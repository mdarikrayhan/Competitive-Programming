#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define ll long long
#define st first
#define nd second
#define pb push_back
#define all(x) x.begin(), x.end()
#define ones(n) __builtin_popcount(n)
#define last(n) __builtin_clz(n)

const int N = 2e5 + 5, M = 1e3 + 5, LOG = 30;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-6, PI = acos(-1);

int n, sqr, ans[N];
bool on[N];
unordered_set<int> adj[N];

bool heavy[N];
unordered_set<int> Hadj[N];

void flip(int u) {
    for (int v: Hadj[u])
        ans[v] += on[u] ? -1 : 1;
    on[u] ^= 1;
}

void add(int u, int v) {
    adj[u].insert(v);
    adj[v].insert(u);
    if (heavy[u]) {
        Hadj[v].insert(u);
        ans[u] += on[v];
    }
    if (heavy[v]) {
        Hadj[u].insert(v);
        ans[v] += on[u];
    }
    if (adj[u].size() == sqr) {
        heavy[u] = true;
        ans[u] = 0;
        for (int w: adj[u]) {
            Hadj[w].insert(u);
            ans[u] += on[w];
        }
    }
    if (adj[v].size() == sqr) {
        heavy[v] = true;
        ans[v] = 0;
        for (int w: adj[v]) {
            Hadj[w].insert(v);
            ans[v] += on[w];
        }
    }
}

void del(int u, int v) {
    adj[u].erase(v);
    adj[v].erase(u);
    if (heavy[u]) {
        Hadj[v].erase(u);
        ans[u] -= on[v];
    }
    if (heavy[v]) {
        Hadj[u].erase(v);
        ans[v] -= on[u];
    }
    if (u == sqr - 1) {
        heavy[u] = false;
        for (int w: adj[u]) {
            Hadj[w].erase(u);
        }
    }
    if (v == sqr - 1) {
        heavy[v] = false;
        for (int w: adj[v]) {
            Hadj[w].erase(v);
        }
    }
}

int cnt(int u) {
    if (heavy[u])
        return ans[u];
    int res = 0;
    for (int v: adj[u])
        res += on[v];
    return res;
}

void testCase() {
    int m, q;
    cin >> n >> m >> q;
    sqr = ceil(sqrt(n));
    int o;
    cin >> o;
    while (o--) {
        int u;
        cin >> u;
        on[u] = true;
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for (int u = 1; u <= n; u++)
        heavy[u] = adj[u].size() >= sqr;
    for (int u = 1; u <= n; u++)
        for (int v: adj[u])
            if (heavy[v]) {
                Hadj[u].insert(v);
                if (on[u])
                    ans[v]++;
            }

    while (q--) {
        char t;
        cin >> t;
        if (t == 'O' || t == 'F') {
            int u;
            cin >> u;
            flip(u);
        } else if (t == 'A') {
            int u, v;
            cin >> u >> v;
            add(u, v);
        } else if (t == 'D') {
            int u, v;
            cin >> u >> v;
            del(u, v);
        } else {
            int u;
            cin >> u;
            cout << cnt(u) << '\n';
        }
    }
}


int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int tc = 1;
//    cin >> tc;
    for (int TC = 1; TC <= tc; TC++) {
        testCase();
    }
}

/*




*/
 		      							 	  	 	  		 	