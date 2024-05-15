/*
Author: chikien2009
*/

#include <map>
#include <set>
#include <cmath>
#include <array>
#include <stack>
#include <ctime>
#include <queue>
#include <cctype>
#include <bitset>
#include <vector>
#include <string>
#include <cstddef>
#include <cstring>
#include <iomanip>
#include <utility>
#include <climits>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

// INIT GLOBAL VARIABLES HERE

#define hcf(i1, i2) __gcd(i1, i2)
#define lcm(i1, i2) i1 *i2 / __gcd(i1, i2)
#define min3(i1, i2, i3) min(i1, min(i2, i3))
#define F first
#define S second
#define STR_END string::npos
#define inl inline

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, string> pis;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t, a;

// END

time_t st, et;

inl void start()
{
    st = clock();
}

inl void finish()
{
    et = clock();
    cout << "\nExecution time: " << et - st << "\n";
}

// INIT FUNCTIONS HERE

inl void setup()
{
#ifndef ONLINE_JUDGE
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

inl bool greater_second(const pii &ina, const pii &inb)
{
    return (ina.S != inb.S ? ina.S > inb.S : ina.F > inb.F);
}

inl bool smaller_second(const pii &ina, const pii &inb)
{
    return ina.S < inb.S;
}

inl ll power(ll base, int index)
{
    ll res = 1;
    do
    {
        res *= (index & 1 ? base : 1);
        base *= base;
    } while (index >>= 1);
    return res;
}

// END

int main()
{
    setup();
    // start();

    cin >> t;
    while (t--)
    {
        cin >> a;
        if (a == 1)
        {
            cout << 9;
        }
        else if (a == 2)
        {
            cout << 98;
        }
        else
        {
            cout << 989;
            for (int i = 0; i < a - 3; ++i)
            {
                cout << i % 10;
            }
        }
        cout << "\n";   
    }

    // finish();
    return 0;
}