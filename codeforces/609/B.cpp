// LUOGU_RID: 159033853
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ma make_pair
#define int long long
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define fup(x, l, r) for (int x = (l), eNd = (r); x <= eNd; ++ x )
#define fdw(x, r, l) for (int x = (r), eNd = (l); x >= eNd; -- x )
typedef long long ll;
typedef unsigned long long LL;
typedef pair<int, int> PII;

struct fastread {
    template <typename T>
    fastread& operator >>(T& x) {
        x = 0; bool flg = false; char c = getchar();
        while (c < '0' || c > '9') flg |= (c == '-'), c = getchar();
        while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
        if (flg) x = -x; return *this;
    }
    template <typename T>
    fastread& operator >>(vector<T>& x) {
        for (auto it = x.begin(); it != x.end(); ++ it ) (*this) >> *it;
        return *this;
    }
}fin;

struct fastwrite {
    template <typename T>
    fastwrite& operator <<(T x) {
        if (x < 0) x = -x, putchar('-');
        static int buf[35]; int top = 0;
        do buf[top ++ ] = x % 10, x /= 10; while (x);
        while (top) putchar(buf[ -- top] + '0');
        return *this;
    }
    fastwrite& operator <<(char x) {
        putchar(x); return *this;
    }
    template <typename T>
    fastwrite& operator <<(vector<T> x) {
        for (auto it = x.begin(); it != x.end(); ++ it ) (*this) << *it, putchar(' ');
        putchar('\n');
        return *this;
    }
}fout;

const int N = 1e6 + 10;
const int mod = 998244353;

int n, m;
int a[N];
map< int, int > t;
int ans;
signed main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fin >> n >> m;
    fup(i, 1, n) fin >> a[i], t[a[i]]++;
    fup(i, 1, m)
    {
        fup(j, i + 1, m)
        {
            ans += t[i] * t[j];
        }
    }
    fout << ans << '\n';
    return 0;
}


