#include <bits/stdc++.h>
// #include <atcoder/scc>
//  #include <atcoder/segtree>
//    #include <atcoder/dsu>
//   #include <atcoder/twosat>
using namespace std;
// using namespace atcoder;
#define lol 1000000007
#define fol 1000000000
#define all(c) c.begin(), c.end()
#define vi vector<ll>
#define vvi vector<vi>
#define fi first
#define se second
#define mod1 998244353
#define MAXN 2000005
typedef long long ll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
ll expo(ll n, ll k, ll mod)
{

    if (k == 0)
        return 1 % mod;
    ll u = expo(n, k / 2, mod);
    u = (u * u) % mod;
    if (k % 2 != 0)
        u = (u * n) % mod;
    return u;
}

ll msqrt(ll n)
{
    if (n < 0)
        return -1;
    ll L = 0, R = 2000000000;
    while (L < R)
    {
        ll mid = (L + R) / 2;
        if (mid * mid >= n)
            R = mid;
        else
            L = mid + 1;
    }
    return L;
}

ll factorial(ll n)
{

    return (n == 1 || n == 0) ? 1 : ll(n) * factorial(n - 1);
}

vector<ll> manacher(const string &s)
{
    string t;
    for (auto &c : s)
    {
        t.push_back(c);
        t.push_back('$');
    }
    t.pop_back();
    ll i = 0, j = 0, n = t.size();
    vector<ll> res(n);
    while (i < n)
    {
        while (i - j >= 0 and i + j < n and t[i - j] == t[i + j])
            j++;
        res[i] = j;
        ll k = 1;
        while (i - k >= 0 and i + k < n and k + res[i - k] < j)
        {
            res[i + k] = res[i - k];
            k++;
        }
        i += k;
        j -= k;
    }
    for (ll i = 0; i < n; i++)
    {
        if (i & 1)
            res[i] = (res[i] / 2) * 2;
        else
            res[i] = ((res[i] + 1) / 2) * 2 - 1;
    }
    return res;
}

ll op1(ll a, ll b)
{
    return max(a, b);
}
ll op2(ll a, ll b)
{
    return min(a, b);
}

ll e2()
{
    return (ll)(10e18);
}
ll e1()
{
    return 0;
}

const ll MOD = 998244353;

struct mi
{
    ll v;
    explicit operator ll() const { return v; }
    mi() { v = 0; }
    mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};

mi &operator+=(mi &a, mi b)
{
    if ((a.v += b.v) >= MOD)
        a.v -= MOD;
    return a;
}
mi &operator-=(mi &a, mi b)
{
    if ((a.v -= b.v) < 0)
        a.v += MOD;
    return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p)
{
    assert(p >= 0);
    return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a)
{
    assert(a.v != 0);
    return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*freopen("herding.in","r",stdin);
    freopen("herding.out","w",stdout); */
    ll f = 1;
    cin >> f;
    while (f--)
    {
        ll n;
        cin >> n;
        ll pos = 0;
        ll neg = 0;
        ll arr[n + 1] = {0};
        ll i1 = n;
        ll i2 = n;

        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] > 0)
            {
                pos++;
                if (arr[i] > arr[i1])
                    i1 = i;
            }
            else if (arr[i] < 0)
            {
                neg++;
                if (arr[i] < arr[i2])
                    i2 = i;
            }
        }

        vector<pair<ll, ll>> ans;
        if ((pos < neg - 4) || ((pos <= neg + 4) && abs(arr[i2]) >= abs(arr[i1])))
        {
            if (i2 == n)
                i2--;
            if (i1 == n)
                i1--;

            if (pos < neg - 4)
            {
                for (ll i = 0; i < 5; i++)
                {
                    ans.push_back({i2 + 1, i2 + 1});
                }
            }
            for (ll i = 0; i < n; i++)
            {
                if (arr[i] > 0)
                {
                    ans.push_back({i + 1, i2 + 1});
                }
            }
            for (ll i = n - 2; i >= 0; i--)
            {
                ans.push_back({i + 1, i + 2});
            }
        }
        else
        {
            if (i2 == n)
                i2--;
            if (i1 == n)
                i1--;
            if (neg < pos - 4)
            {
                for (ll i = 0; i < 5; i++)
                {
                    ans.push_back({i1 + 1, i1 + 1});
                }
            }
            for (ll i = 0; i < n; i++)
            {
                if (arr[i] < 0)
                {
                    ans.push_back({i + 1, i1 + 1});
                }
            }
            for (ll i = 1; i < n; i++)
            {
                ans.push_back({i + 1, i});
            }
        }
        cout << ans.size() << "\n";
        for (ll i = 0; i < ans.size(); i++)
        {
            cout << ans[i].fi << " " << ans[i].se << "\n";
        }
    }
}