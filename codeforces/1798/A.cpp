#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cfloat>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <array>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <bit>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <iterator>
#include <ctime>
#include <tuple>
#include <numeric>
using namespace std;
#define int long long
#define loop(start, limit) for (int i = start; i < limit; i++)
#define sz(a) int(a.size())
#define all(c) c.begin(), c.end()
#define pb push_back

int log2_floor(unsigned long long i)
{
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}
int min(int a, int b)
{
    return (a < b) ? a : b;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int gcd(int a, int b)
{
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do
    {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    loop(0, n) cin >> a[i];
    vector<int> b(n);
    loop(0,n) cin >> b[i];
    loop(0,n)
    {
        if(a[n-1] >= a[i] && b[n-1] >= b[i])
        {
            continue;
        }
        else if(a[n-1] >= b[i] && b[n-1] >= a[i])
        {
            continue;
        }
        else
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes\n";
    return;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    while (n > 0)
    {
        solve();
        n--;
    }
    return 0;
}
