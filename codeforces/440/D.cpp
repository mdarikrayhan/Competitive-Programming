#include <bits/stdc++.h>
//#include <bits/debug.hpp>

#define ll long long
#define all(x) x.begin(), x.end()
#define Neco "Berland Federalization"
#define resp(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())
#define getbit(x,i) ((x >> i)&1)
#define _left id * 2, l, mid
#define _right id * 2 + 1, mid + 1, r
#define cntbit(x) __builtin_popcountll(x)
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define maxn (int) 401

using namespace std;

const ll mod = 1e9 + 7; //972663749
const ll base = 911382323;

int n, k;
int res = 1e9;
int Par[maxn], chose[maxn];
pair<int, int> E[maxn];
vector<pair<int, int>> edges[maxn];
vector<int> dp[maxn];
int Trace_[maxn][maxn];

vector<int> cb(const vector<int> &a, const vector<int> &b, int ed) {
    vector<int> ans(a.size() + b.size() - 1, 1e9);
    fi(i, 0, a.size() - 1) fi(j, 0, b.size() - 1)  {
        if(ans[i + j] > a[i] + b[j])
        {
            ans[i + j] = a[i] + b[j];
            Trace_[ed][i + j] = j;
        }
    }
    return ans;
}

void dfs(int u, int par) {
    dp[u] = {(int) 1e9, 0};
    for(auto [v, id] : edges[u]) if(v != par) {
        Par[v] = u, dfs(v, u);
        dp[u] = cb(dp[u], dp[v], id);
    }
    if(dp[u].size() > k) res = min(res, dp[u][k] + (Par[u] != 0));
    dp[u][0] = 1;
}

void Trace(int u, int Cur) {
    chose[u] = 1;
    fid(i, edges[u].size() - 1, 0) if(edges[u][i].first != Par[u]) {
        int v, id; tie(v, id) = edges[u][i];

        int x = Trace_[id][Cur];
        if(x) Trace(v, x);
        Cur -= x;
    }
}

void solve()
{

    cin >> n >> k;
    fi(i, 1, n - 1) {
        int x, y; cin >> x >> y;
        edges[x].push_back({y, i}), edges[y].push_back({x, i});

        E[i] = {x, y};
    }

    dfs(1, 0);

    fi(u, 1, n) if(dp[u].size() > k && dp[u][k] + (Par[u] != 0) == res) {
        Trace(u, k);
        break;
    }

    cout << res << '\n';
    fi(i, 1, n - 1) {
        int x, y; tie(x, y) = E[i];
        if(chose[x] + chose[y] == 1) cout << i << " ";
    }

}


int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if(fopen(Neco".inp", "r")) {
        freopen(Neco".inp", "r", stdin);
        freopen(Neco".out", "w", stdout);
    }


    int nTest = 1;
//    cin >> nTest;


    while(nTest--)
    {
        solve();
    }


    return 0;
}
