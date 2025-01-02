#include <bits/stdc++.h>
#define forn(i, n) for (tint i = 0; i < tint(n); i++)
#define forsn(i, s, n) for (tint i = s; i < tint(n); i++)
#define dforn(i, n) for (tint i = tint(n) - 1; i >= 0; i--)
#define dforsn(i, s, n) for (tint i = tint(n) - 1; i >= s; i--)
#define sz(x) tint(x.size())
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define DBG(x) cerr << #x << " = " << x << endl

using namespace std;

using tint = long long;
using vi = vector<tint>;
using pii = pair<tint, tint>;

inline void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

inline string YN(bool x, string y = "YES", string n = "NO") { return (x ? y : n); }

template <typename T>
inline void chmax(T &lhs, T rhs)
{
    lhs = max(lhs, rhs);
}

template <typename T>
inline void chmin(T &lhs, T rhs)
{
    lhs = min(lhs, rhs);
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p)
{
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << "[";
    forn(i, sz(v))
    {
        if (i > 0)
            os << ", ";
        os << v[i];
    }
    os << "]";
    return os;
}

template <typename T, size_t N>
ostream &operator<<(ostream &os, const array<T, N> &v)
{
    os << "[";
    forn(i, N)
    {
        if (i > 0)
            os << ", ";
        os << v[i];
    }
    os << "]";
    return os;
}
const tint MOD = 1e9 + 7;

vector<vi> I;

vector<vi> compose(vector<vi> &A, vector<vi> &B)
{
    tint n = sz(A);
    vector<vi> res(n, vi(n, 0));
    forn(i, n)
        forn(j, n)
            forn(l, n)
                res[i][j] = (res[i][j] + (A[i][l] * B[l][j]) % MOD) % MOD;
    return res;
}

vector<vi> binPow(vector<vi> &A, tint k)
{
    if (k == 0)
        return I;
    vector<vi> mid = binPow(A, k / 2);
    mid = compose(mid, mid);
    if (k % 2 == 1)
        mid = compose(mid, A);
    return mid;
}

int main()
{
    fastIO();
    tint m, n;
    cin >> m >> n;
    vi l(m), s(m);
    forn(i, m) cin >> s[i];
    forn(i, m) cin >> l[i];
    vi countBlock(4);
    tint sumShort = 0, sumLong = 0;
    forn(i, m)
    {
        sumShort += s[i], sumLong += l[i];
        countBlock[0] += (s[i] * s[i]) % MOD;
        countBlock[1] += (s[i] * l[i]) % MOD;
        countBlock[2] += (l[i] * l[i]) % MOD;
        countBlock[3] += (l[i] * s[i]) % MOD;
        forn(i, 4) countBlock[i] %= MOD;
    }
    vector<vi> AM(4, vi(4));
    // ss
    forn(i, 4) AM[0][i] = countBlock[i];
    // sl
    AM[1][0] = countBlock[0], AM[1][1] = countBlock[1];
    // ll
    AM[2][0] = countBlock[0], AM[2][1] = countBlock[1];
    // ls
    forn(i, 4) AM[3][i] = countBlock[i];
    I.resize(4, vi(4, 0));
    forn(i, 4) I[i][i] = 1;
    vector<vi> paths = binPow(AM, n - 2);
    tint ans = 0;
    forn(i, 4)
    {
        forn(j, 4)
        {
            paths[i][j] *= countBlock[i];
            paths[i][j] %= MOD;
            tint add = paths[i][j];
            if (i == 0 || i == 1)
                add = (add * ((s[0] + l[0]) % MOD)) % MOD;
            else
                add = (add * s[0]) % MOD;
            if (j == 0 || j == 3)
                add = (add * ((sumShort + sumLong) % MOD)) % MOD;
            else
                add = (add * sumShort) % MOD;
            ans = (ans + add) % MOD;
        }
    }
    cout << ans << "\n";
}