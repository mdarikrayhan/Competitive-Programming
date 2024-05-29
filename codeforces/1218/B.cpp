// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx,avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define lowbit(x) ((x) & -(x))
#define ml(a, b) ((1ll * (a) * (b)) % M)
#define tml(a, b) (a) = ((1ll * (a) * (b)) % M)
#define ad(a, b) ((0ll + (a) + (b)) % M)
#define tad(a, b) (a) = ((0ll + (a) + (b)) % M)
#define mi(a, b) ((0ll + M + (a) - (b)) % M)
#define tmi(a, b) (a) = ((0ll + M + (a) - (b)) % M)
#define tmin(a, b) (a) = min((a), (b))
#define tmax(a, b) (a) = max((a), (b))
#define iter(a) (a).begin(), (a).end()
#define riter(a) (a).rbegin(), (a).rend()
#define init(a, b) memset((a), (b), sizeof(a))
#define cpy(a, b) memcpy((a), (b), sizeof(a))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define size(x) (int)x.size()
#define pb emplace_back
#define mpr make_pair
#define ls(i) ((i) << 1)
#define rs(i) ((i) << 1 | 1)
#define INF 0x3f3f3f3f
#define NIF 0xc0c0c0c0
#define eps 1e-9
#define F first
#define S second
#define AC cin.tie(0)->sync_with_stdio(0)
using namespace std;
typedef long long llt;
typedef __int128_t lll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<llt, llt> pll;
typedef complex<double> cd;
typedef complex<llt> cll;
// const int M = 998244353;

// random_device rm;
// mt19937 rg(rm());
// default_random_engine rg(rm());
// uniform_int_distribution<int> rd(INT_MIN, INT_MAX);
// uniform_real_distribution<double> rd(0, M_PI);

void db() { cerr << "\n"; }
template <class T, class... U>
void db(T a, U... b) { cerr << a << " ", db(b...); }

inline char gc()
{
    const static int SZ = 1 << 16;
    static char buf[SZ], *p1, *p2;
    if (p1 == p2 && (p2 = buf + fread(p1 = buf, 1, SZ, stdin), p1 == p2))
        return -1;
    return *p1++;
}
void rd() {}
template <typename T, typename... U>
void rd(T &x, U &...y)
{
    x = 0;
    bool f = 0;
    char c = gc();
    while (!isdigit(c))
        f ^= !(c ^ 45), c = gc();
    while (isdigit(c))
        x = (x << 1) + (x << 3) + (c ^ 48), c = gc();
    f && (x = -x), rd(y...);
}

template <typename T>
void prt(T x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        prt(x / 10);
    putchar((x % 10) ^ 48);
}
#define x real()
#define y imag()
typedef double dl;

dl operator^(const cd &a, const cd &b)
{
    return a.x * b.y - a.y * b.x;
}

inline int ori(const cd &a, const cd &b, const cd &c)
{
    dl tp = (b - a) ^ (c - a);
    if (tp < -eps)
        return -1;
    if (tp > eps)
        return 1;
    return 0;
}

bool cmp1(const cd &a, const cd &b)
{
    if (!(a ^ b))
        return norm(a) < norm(b);
    return (a ^ b) > 0;
}

inline bool ud(const cd &a)
{
    if (a.y < -eps)
        return 0;
    if (a.y > eps)
        return 1;
    return a.x > eps;
}

bool cmp2(const cd &a, const cd &b)
{
    bool b1 = ud(a), b2 = ud(b);
    if (b1 ^ b2)
        return b1;
    return cmp1(a, b);
}

const int N = 1e4 + 5;
vector<cd> p1[N], p2[N];
cd pr1[N], pr2[N], pi[N], po[N], tp1, tp2;
int sz[N], pt1[N], pt2[N], n, cp;
dl ans = 0;

struct cmp
{
    bool operator()(const int &a, const int &b) const
    {
        return ori(pi[a], po[a], pi[b]) < 0 || ori(pi[a], po[a], po[b]) < 0;
    }
};
set<int, cmp> st;

cd itp(const cd &a, const cd &b, const cd &c)
{
    dl ab = a ^ b, ac = a ^ c;
    if (fabs(ab) < eps && fabs(ac) < eps)
        return norm(b) < norm(c) ? b : c;
    return (ab * c - ac * b) / (ab - ac);
}

signed main()
{
    rd(n);
    vector<pair<cd, int>> ar;
    for (int i = 1; i <= n; i++)
    {
        rd(sz[i]), p1[i].resize(sz[i]);
        int a, b;
        for (int j = sz[i] - 1; j >= 0; j--)
            // for (int j = 0; j < sz[i]; j++)
            rd(a, b), p1[i][j] = cd(a, b);
        rotate(p1[i].begin(), min_element(iter(p1[i]), cmp1), p1[i].end());
        auto it = max_element(iter(p1[i]), cmp1);
        p2[i] = vector<cd>(it, p1[i].end());
        p2[i].pb(p1[i][0]), p1[i].resize(it - p1[i].begin() + 1);
        pi[i] = p1[i][0], po[i] = p2[i][0], reverse(iter(p2[i]));
        rotate(p1[i].begin(), min_element(iter(p1[i]), cmp2), p1[i].end());
        rotate(p2[i].begin(), min_element(iter(p2[i]), cmp2), p2[i].end());
        if (p1[i][0] != pi[i])
            st.insert(i), pr1[i] = p1[i].back(), pr2[i] = p2[i].back();
        else
            pr1[i] = p1[i][0], pr2[i] = p2[i][0];
        for (cd &p : p1[i])
            ar.pb(p, i);
        for (cd &p : p2[i])
            ar.pb(p, -i);
        p1[i].pb(p1[i][0]), p2[i].pb(p2[i][0]);
        // db(i);
        // for (auto p : p1[i])
        //     db(p.x, p.y);
        // db(-i);
        // for (auto p : p2[i])
        //     db(p.x, p.y);
        // db("-----------");
    }
    if (!st.empty())
    {
        cp = *st.begin();
        tp1 = itp(cd(1, 0), p1[cp][0], p1[cp][size(p1[cp]) - 2]);
        tp2 = itp(cd(1, 0), p2[cp][0], p2[cp][size(p2[cp]) - 2]);
    }
    sort(iter(ar), [&](const auto &a, const auto &b)
         { return cmp2(a.F, b.F); });
    ar.pb(cd(1, 0), 0);
    for (auto cr : ar)
    {
        // puts("w18ey82");
        // db(cr.F.x, cr.F.y, cr.S);
        if (!st.empty())
        {
            cd pp1 = itp(cr.F, p1[cp][pt1[cp]], pr1[cp]);
            cd pp2 = itp(cr.F, p2[cp][pt2[cp]], pr2[cp]);
            // db(pp2.x, pp2.y, tp2.x, tp2.y, pp1.x, pp1.y, tp1.x, tp1.y);
            ans += fabs((tp1 - pp1) ^ (pp2 - pp1)) +
                   fabs((tp1 - tp2) ^ (pp2 - tp2));
            // db(ans);
        }
        if (!cr.S)
            break;
        if (cr.S > 0)
        {
            pr1[cr.S] = p1[cr.S][pt1[cr.S]++];
            if (cr.F == pi[cr.S])
                st.insert(cr.S);
            if (cr.F == po[cr.S])
                st.erase(cr.S);
        }
        else
        {
            cr.S *= -1;
            pr2[cr.S] = p2[cr.S][pt2[cr.S]++];
            if (cr.F == pi[cr.S])
                st.insert(cr.S);
            if (cr.F == po[cr.S])
                st.erase(cr.S);
        }
        if (!st.empty())
        {
            cp = *st.begin();
            // db(cp, cr.F.x, cr.F.y);
            tp1 = itp(cr.F, p1[cp][pt1[cp]], pr1[cp]);
            tp2 = itp(cr.F, p2[cp][pt2[cp]], pr2[cp]);
            // db(p2[cp][pt2[cp]].x, p2[cp][pt2[cp]].y, cp);
            // db(tp1.x, tp1.y, tp2.x, tp2.y, "qspihd2p");
        }
    }
    printf("%.10lf\n", ans / 2);
}