#include <bits/stdc++.h>
#include <queue>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define bigInt __int128
#define dl double long
#define fl float
#define all(s) s.begin(), s.end()
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pob_front
#define ins insert
#define F first
#define S second
#define len length
const int N = 100000;
const int M = 201;
const int LN = 131072;
const int INF = 9000000000000000000;
const int MOD = 998244353;
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a;
            res %= MOD;
        }
        a = a * a;
        a %= MOD;
        b >>= 1;
    }
    return res;
}
int MMI(int a) {
    int ret = binpow(a, MOD - 2);
    return ret;
}
int mdiv(int a, int b) {
    int ret = a*MMI(b);
    ret %= MOD;
    return ret;
}
int mmul(int a, int b) {
    int ret = (a % MOD) * (b % MOD);
    ret %= MOD;
    return ret;
}
int madd(int a, int b) {
    int ret = (a % MOD) + (b % MOD);
    ret %= MOD;
    return ret;
}
int msub(int a, int b) {
    int ret = (a % MOD) - (b % MOD);
    ret += MOD;
    ret %= MOD;
    return ret;
}
int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return GCD(b, a % b);
}
struct pqComp
{
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const
    {
        return (p1.F < p2.F) || (p1.F == p2.F && p1.S < p2.S);
    }
};
bool pCompF(pair<int, int>& p1, pair<int, int>& p2)
{
    return p1.F < p2.F;
}
bool pCompS(pair<int, int>& p1, pair<int, int>& p2)
{
    return p1.S > p2.S;
}
bool pCompFS(pair<int, int>& p1, pair<int, int>& p2)
{
    return (p1.F < p2.F) || (p1.F == p2.F && p1.S > p2.S);
}
vector <pair<int, int>> DS {{1, 0}, {0, 1}};//{{0, -1}, {1, 0}, {0, 1}, {-1, 0}};//, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int get(int n, int r) {
    vector<int> v;
    for (int i = 2; i*i <= n; ++i) {
        if (n % i) {
            continue;
        }
        v.pub(i);
        while (n % i == 0) {
            n /= i;
        }
    }
    if (n > 1) {
        v.pub(n);
    }
    int ans = 0, m = v.size();
    for (int mask = 0; mask < (1 << m); ++mask) {
        int c = 1;
        for (int i = 0; i < m; ++i) {
            if ((mask >> i) & 1) {
                c *= v[i];
            }
        }
        if (__builtin_popcount(mask) % 2) {
            ans -= r / c;
        }
        else {
            ans += r / c;
        }
    }
    return ans;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int ok = 1;
    for (int i = 2; i <= n; ++i) {
        ok &= (a[i - 1] % a[i] == 0);
    }
    if (!ok) {
        cout << "0\n";
        return;
    }
    int ans = 1;
    for (int i = 2; i <= n; ++i) {
        ans = mmul(ans, get(a[i - 1] / a[i], m / a[i]));
    }
    cout << ans << '\n';
}

signed main() {
    speed;
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}
/*
НЕ ЗАХОДИТ РЕШЕНИЕ?
1) ПРОВЕРЬ НА ОЧЕВИДНЫЕ ОШИБКИ В КОДЕ
2) ПРОВЕРЬ НА ПЕРЕПОЛНЕНИЯ
3) УБЕДИСЬ В ПРАВИЛЬНОСТИ АЛГОРИТМА
*/