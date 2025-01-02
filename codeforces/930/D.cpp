// LUOGU_RID: 159726252
#include <bits/stdc++.h>
#define ll long long
#define enl putchar('\n')
#define all(x) (x).begin(),(x).end()
#define debug(x) printf(" "#x":%d\n",x);
using namespace std;
const int MAXN = 2e5 + 5;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
typedef pair<int, int> pii;
char buf[1 << 21], * p1 = buf, * p2 = buf, obuf[1 << 21], * o = obuf, of[35];
#define gc()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline ll qpow(ll a, ll n) { ll res = 1; while (n) { if (n & 1)res = res * a % mod; n >>= 1; a = a * a % mod; }return res; }
template <class T = int>inline T read() { T s = 0, f = 1; char c = gc(); for (; !isdigit(c); c = gc())if (c == '-')f = -1; for (; isdigit(c); c = gc())s = s * 10 + c - '0'; return s * f; }
inline void read(int* a, int n) { for (int i = 1; i <= n; ++i)a[i] = read(); }
inline int inal(char* s) { int n = 0; for (s[0] = gc(); !isalpha(s[0]); s[0] = gc()); for (; isalpha(s[n]); s[++n] = gc()); return s[n] = 0, n; }
inline void outd(int* a, int n) { for (int i = 1; i <= n; ++i)printf("%d ", a[i]); enl; }
int n, m;
const int bas = 1e5 + 1, rf = bas + bas + 1;
pii suf[MAXN], pre[MAXN];
ll work(vector<pii>& v) {
    sort(all(v));
    pre[0] = suf[rf] = { inf,0 };
    for (int i = 1, j = 0; i < rf; ++i) {
        pre[i] = pre[i - 1];
        while (j < v.size() && v[j].first == i) {
            pre[i].first = min(pre[i].first, v[j].second);
            pre[i].second = max(pre[i].second, v[j].second);
            ++j;
        }
    }
    for (int i = rf - 1, j = v.size() - 1; i >= 1; --i) {
        suf[i] = suf[i + 1];
        while (j >= 0 && v[j].first == i) {
            suf[i].first = min(suf[i].first, v[j].second);
            suf[i].second = max(suf[i].second, v[j].second);
            --j;
        }
    }
    ll res = 0;
    for (int i = 1; i < rf; ++i) {
        int l = max(pre[i].first, suf[i + 1].first),
            r = min(pre[i].second, suf[i + 1].second);
        res += max(0, r - l);
    }
    return res;
}
vector<pii>p, q;
void solve() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        int x = read(), y = read();
        if ((x + y) & 1)
            p.push_back({ (x + y + 1) / 2 + bas,(x - y + 1) / 2 + bas });
        else
            q.push_back({ (x + y) / 2 + bas,(x - y) / 2 + bas });
    }
    printf("%lld\n", work(p) + work(q));
}
signed main(signed argc, char const* argv[]) {
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    //=============================================================
    int resubmit2;
    int TxT = 1;
    while (TxT--)
        solve();
    //=============================================================
#ifdef LOCAL
    end :
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}