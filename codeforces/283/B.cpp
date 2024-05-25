#include <bits/stdc++.h>
#define ull unsigned long long
#define db double
#define fi first
#define se second
#define PB push_back
#define ll long long
//#define int long long
#define ii pair<int, int>
#define pli pair<ll, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define  rep(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define rrep(i, b, a) for (int i = (b), _a = (a); i >= _a; --i)
#define FOR rep
#define FORD rrep
#define FORV(v, H) for(auto &v: H)
#define reset(c, x) memset(c, x, sizeof(c))
#define MASK(i) (1LL << (i))
#define BIT(mask, i) ((mask >> i) & 1)
#define ONBIT(mask, i) (mask | (1LL << (i)))
#define OFFBIT(mask, i) (mask &~ (1LL << (i)))
#define REV(mask, i) (mask ^ (1LL << (i)))
#define CNTBIT __builtin_popcountll
#define lwb lower_bound
#define upb upper_bound
#define all(v) v.begin(), v.end()
#define SZ(v) (int) v.size()
#define special(v) v.erase(unique(all(v)), v.end())
#define sp ' '
#define nl '\n'
#define pyes print("YES")
#define pno print("NO")

using namespace std;

const string task = "283B";

const long long oo = 1e18 + 7;
const int INF      = INT_MAX;
const int MAXN     = 2e5 + 7;
const int MOD      = 1e9 + 7;
const int MAXV     = 1e6 + 7;
const int base     = 311;

template <class X, class Y> bool maximize(X &a, const Y &b) {
    if(a < b) return a = b, true;
    return false;
}

template <class X, class Y> bool minimize(X &a, const Y &b) {
    if(a > b) return a = b, true;
    return false;
}

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

template <class... T>
void print(T&&... n) {
    using exp = int[];
    exp{0, (cout << n << sp, 0)...};
    cout << endl;
}

int N;
int a[MAXN];
ll dp[MAXN][2];
bool vis[MAXN][2];
void DFS(int x, int j) {
    if(vis[x][j])
    {
        return;
    }
    vis[x][j] = 1;
    int y = j ? x + a[x] : x - a[x];
    if(y < 1 || y > N) dp[x][j] = a[x];
    else
    {
        DFS(y, j ^ 1);
        if(dp[y][j ^ 1] != -1) dp[x][j] = dp[y][j ^ 1] + a[x];
    }
}

void iamtainguyen() {

    reset(dp, -1);

    cin >> N;

    rep(i, 2, N)
    {
        cin >> a[i];
    }

    rep(i, 2, N)
    {
        DFS(i, 0);
    }

    rep(i, 2, N)
    {
        if(dp[i][0] != -1)
        {
            print(dp[i][0] + i - 1);
        }
        else print(-1);
    }

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    if(fopen((task + ".inp").c_str(), "r")) {
        freopen((task + ".inp").c_str(), "r", stdin);
        freopen((task + ".out").c_str(), "w", stdout);
    }

    iamtainguyen();



    cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";

    return 0;
}
