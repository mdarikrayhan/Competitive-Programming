#include <bits/stdc++.h>
//#include <bits/debug.hpp>

#define ll long long
#define all(x) x.begin(), x.end()
#define Neco "Ostap and Tree"
#define resp(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())
#define getbit(x,i) ((x >> i)&1)
#define _left id * 2, l, mid
#define _right id * 2 + 1, mid + 1, r
#define cntbit(x) __builtin_popcountll(x)
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define fid(i, a, b) for(int i = a; i >= b; i--)
#define maxn (int) 100 + 7

using namespace std;

const ll mod = 1e9 + 7; //972663749
const ll base = 911382323;

int n, k;
ll f[maxn];
ll dp[maxn][maxn]; /// i <= k thi la thoa man, i > k thi la ko thoa man
/// i <= k, j <= k --> min(i, j + 1)
/// i <= k, j > k , i + (j + 1) - k + 1 <= k -> i + j <= 2 * k --> i
/// i <= k, j > k, i + (j + 1) - k + 1 > k -> i + j > 2 * k --> j + 1
/// i > k, j > k --> max(i, j + 1)

vector<int> edges[maxn];

void dfs(int u, int par) {
    dp[u][0] = dp[u][k + 1] = 1;
    for(int v : edges[u]) if(v != par) {
        dfs(v, u);

        fi(i, 0, 2 * k) f[i] = 0;
        fi(i, 0, 2 * k) fi(j, 0, 2 * k) {
            int x = i + j <= 2 * k ? min(i, j + 1) : max(i, j + 1);
            f[x] = (f[x] + dp[u][i] * dp[v][j]) % mod;
        }

        fi(i, 0, 2 * k) dp[u][i] = f[i];
    }
}

void solve()
{

    cin >> n >> k;
    fi(i, 1, n - 1) {
        int x, y; cin >> x >> y;
        edges[x].push_back(y), edges[y].push_back(x);
    }

    dfs(1, 0);
    ll ans = 0;

    fi(i, 0, k) ans = (ans + dp[1][i]) % mod;
    cout << ans;


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
