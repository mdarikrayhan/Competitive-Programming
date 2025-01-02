#include <bits/stdc++.h>
#define int long long
#define fn for (int i = 0; i < n; i++)
#define f(i, a, n) for (int i = a; i < n; i++)
#define all(v) v.begin(), v.end()
#define sort(a) sort(a.begin(), a.end())
#define fr(i, a, b) for (int i = n - 1; i >= b; i--)
#define rev(v) reverse(v.begin(), v.end())
#define vi vector<int> v
#define min_element *min_element(v.begin(), v.end())
#define max_element *max_element(v.begin(), v.end())
using namespace std;
bool p_check(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int power(int a, int b)
{
    if (b == 0)
        return 1;
    else if (b == 1)
        return a;
    int ans = power(a, b / 2);
    if (b % 2 == 0)
        return ans * ans;
    else
        return ans * ans * a;
}
int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    int ans = (a * b) / (gcd(a, b));
    return ans;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a, b;
    fn
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    fn
    {
        int x;
        cin >> x;
        b.push_back(x);
    }
    vector<int> c;
    fn
    {
        c.push_back(a[i] - b[i]);
    }
    sort(c);
    int ct = 0;
    fn
    {
        auto it = upper_bound(c.begin() + i + 1, c.end(), -c[i]);
        int ss = c.end() - it;
        ct += ss;
    }
    cout << ct << endl;
}