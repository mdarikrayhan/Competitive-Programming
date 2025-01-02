#include <bits/stdc++.h>
using namespace std;
#define il inline
#define ptc putchar
#define pb push_back
#define R(i, l, r) for (int i = l; i <= r; ++i)
#define debug puts("--------------------------------------------")
typedef long long ll;
typedef pair<int, int> PII;
namespace ZeroTwo
{
    template <typename T>
    il void read(T &x) 
    { 
        x = 0; T f = 1; char ch;
        while (!isdigit(ch = getchar())) f -= (ch == '-') << 1;
        while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
        x *= f;
    }
    template <typename T, typename ...L>
    il void read(T &x, L &...y) {read(x); read(y...);}
    template <typename T>
    il void write(T x) 
    {
        if (x < 0) ptc('-'), x = -x;
        if (x > 9) write(x / 10);
        ptc(x % 10 + '0');
    }
    template <typename T, typename ...L>
    il void write(T &x, L &...y) {write(x), ptc(' '); write(y...);}
}
using namespace ZeroTwo;
const int N = 3e5 + 5;

signed main() 
{
    int n, m, x1, y1, x2, y2; cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    int a = abs(x1 - x2) + 1, b = abs(y1 - y2) + 1; if (a > b) swap(a, b);
    return puts(((a <= 3 && b <= 5) || (a == 4 && b == 4)) ? "First" : "Second"), 0;
    return 0;
}