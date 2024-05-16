#include <bits/stdc++.h>
using namespace std;

// Aliases
using ll = long long;
using lld = long double;
using ull = unsigned long long;

// Constants
const lld pi = 3.141592653589793238;
const ll INF = LONG_LONG_MAX;
const ll mod = 1000000007;

#define debug(x) cerr << #x << " " << x << endl;

#define cy cout << "YES\n"
#define cn cout << "NO\n"

// Things to keep in mind:
// 0. Use ll instead of int
// 1. Can we use binary search?
// 2. If Constraints are 10^9: Use O(log(n)) OR O(1)
void testcase()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<bool> m(26, false);
    int count = 0;
    for (auto &it : s)
    {
        if (m[it - 'A'] == false)
        {
            count += 2;
            m[it - 'A'] = true;
        }
        else
        {
            count++;
            m[it - 'A'] = true;
        }
    }
    cout << count << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--)
    {
        testcase();
    }
    return 0;
}