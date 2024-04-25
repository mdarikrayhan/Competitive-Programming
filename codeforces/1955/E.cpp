#include <bits/stdc++.h>
#define pii pair<int, int>
#define int long long
#define ull unsigned long long
#define endl '\n'

using namespace std;

const int N = 1e6 + 10, inf = 2e18, p = 1331;

//int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
//int qpow(int a, int b, int mod) { int res = 1; for (; b; b >>= 1, a = 1ll * a * a % mod) if (b & 1) res = 1ll * res * a % mod; return res; }
//int lcm(int a, int b) { return a / gcd(a, b) * b; }
char s[N];
int n;

int d[N];

bool check(int x)
{
    for (int i = 0; i <= n; ++ i) d[i] = 0;
    int ok = 1;
    for (int i = 1; i <= n; ++ i)
    {
        d[i] ^= d[i - 1];
        if ((s[i] ^ d[i]) != '1')
        {
            if (i + x - 1 > n)
            {
                ok = 0;
                break;
            }
            d[i] ^= 1;
            d[i + x] ^= 1;
        }
    }
    if (ok) return true;
    else return false;
}

void solve()
{
    cin >> n >> s + 1;
    int ans = -1;
    for (int i = n; i >= 1; -- i)
        if (check(i))
        {
            cout << i << endl;
            return;
        }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ ; cin >> _;
    while (_ -- ) solve();
    return 0;
}
	 	 		 		   		 	   		 	  			 	