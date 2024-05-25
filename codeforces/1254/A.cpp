#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

ll modPow(ll base, ll exponent, ll modulus)
{
    ll result = 1;
    base %= modulus;
    while (exponent > 0)
    {
        if (exponent & 1)
            result = (result * base) % modulus;
        exponent >>= 1;
        base = (base * base) % modulus;
    }
    return result;
}

ll gcd(ll a, ll b)
{
    while (b)
    {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

ll factorial(ll n)
{
    ll result = 1;
    for (ll i = 2; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

ll nCr(ll n, ll r)
{
    ll result = 1;
    for (ll i = 1; i <= r; ++i)
    {
        result = result * (n - i + 1) / i;
    }
    return result;
}

ll nPr(ll n, ll r)
{
    ll result = 1;
    for (ll i = 0; i < r; ++i)
    {
        result *= (n - i);
    }
    return result;
}

bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
// ordered set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

void fastInput()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void fastOutput()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main()
{
    fastInput();
    fastOutput();
    // Your competitive programming logic here
    ll t;
    cin >> t;
    vector<char> pos;
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        pos.push_back(ch);
    }
    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        pos.push_back(ch);
    }
    for (char ch = '0'; ch <= '9'; ch++)
    {
        pos.push_back(ch);
    }
    pos.push_back(':');
    while (t--)
    {
        ll r, c, k;
        cin >> r >> c >> k;
        vector<vector<char>> vec(r, vector<char>(c, 0));
        ll ctp = 0;
        for (ll i = 0; i < r; i++)
        {
            for (ll j = 0; j < c; j++)
            {
                cin >> vec[i][j];
                if (vec[i][j] == 'R')
                {
                    ctp++;
                }
            }
        }
        ll rem = ctp % k;
        ctp = ctp / k;
        // cout << ctp << " " << rem << endl;
        vector<vector<char>> ans(r, vector<char>(c, '$'));
        ll ind = 0;
        ll num = 0;
        for (ll i = 0; i < r; i++)
        {
            if (i % 2 == 0)
            {
                for (ll j = 0; j < c; j++)
                {
                    if (vec[i][j] == 'R')
                    {
                        num++;
                    }
                    if (rem > 0 && num == ctp + 1)
                    {
                        ans[i][j] = pos[ind];
                        ind++;
                        num = 0;
                        rem--;
                    }
                    else if (rem == 0 && num == ctp)
                    {
                        ans[i][j] = pos[ind];
                        ind++;
                        num = 0;
                    }
                    else
                    {
                        ans[i][j] = pos[ind];
                    }
                }
            }
            else
            {
                for (ll j = c - 1; j >= 0; j--)
                {
                    if (vec[i][j] == 'R')
                    {
                        num++;
                    }
                    if (rem > 0 && num == ctp + 1)
                    {
                        ans[i][j] = pos[ind];
                        ind++;
                        num = 0;
                        rem--;
                    }
                    else if (rem == 0 && num == ctp)
                    {
                        ans[i][j] = pos[ind];
                        ind++;
                        num = 0;
                    }
                    else
                    {
                        ans[i][j] = pos[ind];
                    }
                }
            }
        }
        for (ll i = 0; i < r; i++)
        {
            for (ll j = 0; j < c; j++)
            {
                if (ans[i][j] == pos[k])
                {
                    ans[i][j] = pos[k - 1];
                }
            }
        }
        for (auto it : ans)
        {
            for (auto itt : it)
            {
                cout << itt << "";
            }
            cout << endl;
        }
    }

    return 0;
}