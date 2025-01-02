#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <map>
#include <fstream>
#include <unordered_map>
#include <numeric>
#include <functional>
#include <unordered_set>
#include <set>
#include <queue>
#define rg register
#define LL long long
#define i64 long long
#define ll long long
#define fo(a, b, c) for (int a = b; a <= c; ++a)
#define PII pair<int, int>
#define tI3 tuple<int, int, int>
#define mem(a, b) memset(a, b, sizeof(a))
#define tI4 tuple<int, int, int, int>
const ll prime1 = 10000000343, prime2 = 10000000601, prime3 = 1000000000000357, prime4 = 1000000000001269, prime5 = 1000000000000000079, prime6 = 1000000000000000031;
using namespace std;
inline int qread()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void qwrite(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        qwrite(x / 10);
    putchar(x % 10 + '0');
    return;
}

void solve()
{
    int n;
    cin >> n;
    set<ll> s;
    ll tmp = n;
    tmp = (1e9 + 1) * n;
    int f = 1;
    fo(i, 1, n)
    {
        ll t;
        cin >> t;
        if (s.find((t + i + tmp) % n) != s.end())
            f = 0;
        s.insert((t + i + tmp) % n);
    }
    if (f)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}