// Problem: C. Meaningless Operations
// Contest: Codeforces - Codeforces Global Round 1
// URL: https://codeforces.com/contest/1110/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Math Proof:
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define endl '\n'
#define wp ' '
#define forn for (int i = 0; i < n; i++)
#define form for (int j = 0; j < m; j++)
#define fork for (int i = 0; i < k; i++)
#define pb push_back
#define ull unsigned long long
#define pi pair<int, int>
#define sz size()
// je m appelle Alvaro j ai 21 ans.

using namespace std;

ull mcd(ull a, ull b)
{
    if (a < b)
    {
        return mcd(b, a);
    }
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return mcd(b, a % b);
    }
}

void Solve()
{
    ull n;
    cin >> n;
    ull lptwo = 1;
    while (lptwo <= n)
    {
        lptwo *= 2;
        if (n == lptwo - 1)
        {
            ull ans = 1;
            for (ull i = 2; i * i <= n; i++)
            {
                if (n % i == 0)
                {
                    if (i < n)
                        ans = max(ans, i);
                    if (n / i < n)
                        ans = max(ans, n/i);
                }
            }
            cout << gcd(n ^ ans, n & ans) << endl;
            return;
        }
    }
    cout << gcd(n ^ (lptwo - 1 - n), n & (lptwo - 1 - n)) << endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_cases;
    cin >> test_cases;
    while (test_cases-- > 0)
    {
        Solve();
    }
    return 0;
}
