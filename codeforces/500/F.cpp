#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;
typedef long double     ld;
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pll;

#define deb(x)          cout << x
#define X               first
#define Y               second
#define SZ(x)           int(x.size())
#define all(x)          x.begin(), x.end()
#define mins(a,b)       (a = min(a,b))
#define maxs(a,b)       (a = max(a,b))
#define pb              push_back
#define Mp              make_pair
#define kill(x)         {cout << (x) << '\n'; exit(0);}
#define killt(x)        {cout << (x) << '\n'; return;}
#define md(x)           ((((x)%MOD)+MOD)%MOD)
#define lc              id<<1
#define rc              lc|1
#define mid             ((l+r)/2)
mt19937_64              rng(chrono::steady_clock::now().time_since_epoch().count());

const ll  INF = 1e9 + 23;
const ll  MOD = 1e9 + 7;
const int MXN = 4023;
const int LOG = 23;

int n, p, q, ans[20005];
vector<pair<int, pii>> L[MXN], Q[20005];
pair<int, pii> a[MXN];
int dp[MXN][MXN];

void dnq(int l=1, int r=n+1) {
    if(r-l == 1) {
        for(auto qu : L[l])
            ans[qu.Y.Y] = (qu.Y.X >= a[l].Y.X ? a[l].Y.Y : 0);
        return;
    }
    dnq(l, mid);
    dnq(mid, r);

    fill(dp[mid-1], dp[mid-1]+a[mid-1].Y.X, 0);
    fill(dp[mid-1]+a[mid-1].Y.X, dp[mid-1]+MXN, a[mid-1].Y.Y);
    for(int i=mid-2; i>=l; i--)
        for(int j=0; j<MXN; j++)
            dp[i][j] = max(dp[i+1][j], (j>=a[i].Y.X ? dp[i+1][j-a[i].Y.X]+a[i].Y.Y : 0));

    fill(dp[mid], dp[mid]+a[mid].Y.X, 0);
    fill(dp[mid]+a[mid].Y.X, dp[mid]+MXN, a[mid].Y.Y);
    for(int i=mid+1; i<=r; i++)
        for(int j=0; j<MXN; j++)
            dp[i][j] = max(dp[i-1][j], (j>=a[i].Y.X ? dp[i-1][j-a[i].Y.X]+a[i].Y.Y : 0));
    
    for(int i=l; i<mid; i++)
        for(auto qu : L[i])
            if(qu.X >= mid)
                for(int j=0; j<=qu.Y.X; j++)
                    maxs(ans[qu.Y.Y], dp[i][j]+dp[qu.X][qu.Y.X-j]);
}

void Main() {
    cin >> n >> p;
    for(int i=1; i<=n; i++)
        cin >> a[i].Y.X >> a[i].Y.Y >> a[i].X;
    sort(a+1, a+n+1);
    cin >> q;
    for(int i=1, a,b; i<=q; i++) {
        cin >> a >> b;
        Q[a].pb(Mp(0, Mp(b, i)));
    }
    queue<int> qu;
    int l=1;
    for(int i=1; i<=20000; i++) {
        while(l<=n && a[l].X==i) qu.push(l++);
        while(SZ(qu) && a[qu.front()].X+p-1<i) qu.pop();
        for(auto _ : Q[i]) {
            if(qu.empty())
                ans[_.Y.Y] = 0;
            else
                L[qu.front()].pb(Mp(qu.back(), _.Y));
        }
    }
    dnq();
    for(int i=1; i<=q; i++)
        cout << ans[i] << '\n';
}

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while(T--) Main();
    return 0;
}