#include <bits/stdc++.h>
using namespace std;

typedef long long       ll;
typedef long double     ld;
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pll;

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
const int MXN = 1e6 + 23;
const int LOG = 23;

struct SuffixArray {
    int n, sa[MXN], rnk[LOG][MXN], p[MXN], ps[MXN];
    void radix(int x) {
        fill(ps, ps+n, 0);
        for(int i=0; i<n; i++) ps[rnk[x][(i+(1<<x))%n]+1]++;
        partial_sum(ps, ps+n, ps);
        for(int i=0; i<n; i++) p[ps[rnk[x][(i+(1<<x))%n]]++] = i;
        fill(ps, ps+n, 0);
        for(int i=0; i<n; i++) ps[rnk[x][p[i]]+1]++;
        partial_sum(ps, ps+n, ps);
        for(int i=0; i<n; i++) sa[ps[rnk[x][p[i]]]++] = p[i];
        rnk[x+1][sa[0]] = 0;
        for(int i=1; i<n; i++)
            rnk[x+1][sa[i]] = rnk[x+1][sa[i-1]] + (Mp(rnk[x][sa[i]], rnk[x][(sa[i]+(1<<x))%n]) != Mp(rnk[x][sa[i-1]], rnk[x][(sa[i-1]+(1<<x))%n]));
    }
    int lcp(int x, int y) {
        if(x == y) return n-x+1;
        int res=0;
        for(int i=LOG-1; i>=0; i--)
            if(rnk[i][x] == rnk[i][y]) {
                x += 1<<i;
                y += 1<<i;
                res += 1<<i;
            }
        return res;
    }
    SuffixArray(string s) {
        n = SZ(s);
        iota(sa, sa+n, 0);
        sort(sa, sa+n, [&](int x, int y) { return s[x] < s[y]; });
        rnk[0][sa[0]] = 0;
        for(int i=1; i<n; i++) rnk[0][sa[i]] = rnk[0][sa[i-1]] + (s[sa[i-1]] != s[sa[i]]);
        for(int i=0; i<LOG-1; i++) radix(i);
    }
};

int n, ps[MXN], mn[MXN];
bool ok[MXN];
string s;

void Main() {
    cin >> s;
    n = SZ(s);
    for(int i=0; i<n; i++)
        ps[i+1] = ps[i] + (s[i] == '(' ? +1 : -1);
    mn[n] = ps[n];
    for(int i=n-1; i>=0; i--)
        mn[i] = min(mn[i+1], ps[i]);
    int mnp=INF;
    for(int i=0; i<n; i++) {
        int mns = min(mn[i+1]-ps[i], ps[n]-ps[i]+mins(mnp, ps[i]));
        if(mns >= min(0, ps[n])) ok[i] = 1;
    }
    SuffixArray SA(s);
    pii ans = {INF, 0};
    for(int i=0; i<n; i++)
        if(ok[i])
            mins(ans, Mp(SA.rnk[LOG-1][i], i));
    int pt = ans.Y;
    if(ps[n] < 0) cout << string(-ps[n], '(');
    for(int j=pt; j<n; j++) cout << s[j];
    for(int j=0; j<pt; j++) cout << s[j];
    if(ps[n] > 0) cout << string(ps[n], ')');
    cout << '\n';
    return;
}

int32_t main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    while(T--) Main();
    return 0;
}