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
const int maxn = 100005;
int a[maxn],b[maxn];

bool compare(int a, int b)
{
  return (a>b);
}
void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    loop(0,n) cin >> a[i];
    loop(0,m) cin >> b[i];
    sort(a,a+n,compare);
    sort(b,b+m,compare);
    loop(0,n)
    {
      if(a[i] > b[i])
      {
        cout << "YES" << endl;
        return;
      }
    }
    cout << "NO" << endl;
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
    solve();
    return 0;
}