#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
#define FOR(i, a) for (int i=0; i<(a); i++)
#define all(x) x.begin(), x.end()
#define gcd __gcd
#define pll pair<ll, ll>
#define pii pair<int, int>
#define fi first
#define se second
//const int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};

const int N = 1505;
const int INF = 1e9 + 69;
int dp[N][N], a[N], s[N], bst[N];

int n, ss, m, k;

int cost(int l, int r){
    return s[r] - s[l - 1];
}

bool check(int x){
    for(int i = 1; i <= n; ++i)
        s[i] = s[i - 1] + (a[i] <= x);

    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= m; ++j)
            dp[i][j] = (j == 0? 0 : -1);

    for(int r = 1; r <= n; ++r){
        int l = bst[r];
        if(l != INF){
            for(int i = 1; i <= m; ++i){
                if(dp[l - 1][i - 1] != -1)
                    dp[r][i] = dp[l - 1][i - 1] + cost(l, r);
            }
        }
        for(int i = 1; i <= m; ++i)
            dp[r][i] = max(dp[r][i], dp[r - 1][i]);
    }

    int ans = 0;
    for(int i = 1; i <= m; ++i) ans = max(ans, dp[n][i]);
    return ans >= k;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> ss >> m >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        bst[i] = INF;
    }

    FOR(i, ss){
        int l, r; cin >> l >> r;
        for(int j = l; j <= r; ++j)
            bst[j] = min(bst[j], l);
    }

    int lo = 1, hi = 1e9, ans = -1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(check(mid)){
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << ans;

    return 0;
}