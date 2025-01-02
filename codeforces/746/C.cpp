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
    int s,x1,x2;
    cin >> s >> x1 >> x2;
    int t1,t2;
    cin >> t1 >> t2;
    int p,d;
    cin >> p >> d;
    if(t2 < t1)
    {
      cout << abs(x2 - x1)*t2 << endl;
      return;
    }
    int a1 = abs(x2 - x1)*t2;
    int a2 = 0;
    if(x2 > x1)
    {
      if(p <= x1)
      {
        a2 = abs(x2 - d*p)*t1;
        cout << min(a1, a2) << endl;
        return;
      }
      else
      {
        if(d == 1)
        {
          a2 = (s-p)*t1 + s*t1 + x2*t1;
          cout << min(a1, a2) << endl;
          return;
        }
        else
        {
          a2 = (p)*t1 + x2*t1;
          cout << min(a1, a2) << endl;
          return;
        }
      }
    }
    else
    {
      
      if(p < x1 && d == -1)
      {
        a2 = p*t1 + s*t1+(s-x2)*t1;
        cout << min(a1, a2) << endl;
        return;
      }
      else if (p >= x1 && d == -1)
      {
        a2 = (p-x2)*t1;
        cout << min(a1, a2) << endl;
        return;
      }
      else if(p <= x1 && d == 1)
      {
        a2 = (s-p)*t1 + (s-x2)*t1;
        cout << min(a1, a2) << endl;
        return;
      }
      else
      {
        a2 = (s-p)*t1 + (s-x2)*t1;
        cout << min(a1, a2) << endl;
        return;
      }
    }

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
    n = 1;
    while (n > 0)
    {
        solve();
        n--;
    }
    return 0;
}