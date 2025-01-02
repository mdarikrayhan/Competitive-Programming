#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INT_MAX LONG_LONG_MAX
#define double long double
#define all(x) x.begin(), x.end()
#define rev(x) x.rbegin(), x.rend()
#define el cout << "\n";
#define YES cout << "YES" << endl;
#define Yes cout << "Yes" << endl;
#define NO cout << "NO" << endl;
#define No cout << "No" << endl;
#define vi vector<int>
#define vv vector<vector<int>> //--------> DON'T name ANY variable as vv
#define pii pair<int, int>
#define vii vector<pair<int, int>>

// Don't forget to call in int main()
// Look out for perfect squares like i*i == n (for divisors)

vector<bool> sieve(10000001, 1); // assign it as global variable
void create_Sieve()
{
    sieve[0] = false, sieve[1] = false;
    for (int i = 2; i * i <= 10000000; i++)
    {
        if (sieve[i] == true)
            for (int j = i * i; j <= 10000000; j += i)
            {
                sieve[j] = false;
            }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    create_Sieve();
    int p, y;
    cin >> p >> y;

    int a = sqrtl(y);
    vi cmp;
    for (int i = 2; i <= min(a, p); i++)
    {
        if (sieve[i])
        {
            cmp.push_back(i);
        }
    }

    for (int i = y; i > p; i--)
    {
        int chk = 1;
        for (auto &j : cmp)
        {
            if (!(i % j))
            {
                chk = 0;
                break;
            }
        }

        if (chk)
        {
            cout << i;
            return 0;
        }
    }

    cout << -1;
}