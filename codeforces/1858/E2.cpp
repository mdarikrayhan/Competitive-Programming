// അനശ്വർ
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ld long double
ll mod = 1e9 + 7;
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frr(i, a, b) for (ll i = a; i < b; i++)
#define fi(i, arr) for (auto i : arr)
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vvp vector<vector<pair<ll, ll>>>
#define vp vector<pair<ll, ll>>
#define vb vector<bool>
#define all(c) c.begin(), c.end()
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
class SegTree2 // range query point update
{
private:
    ll __query(ll a, ll b, ll k, ll x, ll y)
    {
        if (b < x || a > y)
        {
            return 0;
        }
        if (a <= x && b >= y)
        {
            return st[k];
        }
        ll d = (x + y) / 2;
        return __query(a, b, 2 * k + 1, x, d) + __query(a, b, 2 * k + 2, d + 1, y);
    }

public:
    vl st;
    ll n;
    SegTree2(vl &arr)
    {
        n = 1;
        while (n < arr.size())
        {
            n *= 2;
        }
        st = vl(2 * n - 1);
        fr(i, arr.size())
        {
            st[n + i - 1] = arr[i];
        }
        for (ll i = n - 2; i >= 0; i--)
        {
            st[i] = st[2 * i + 1] + st[2 * i + 2];
        }
    }
    ll query(ll start, ll end)
    {
        return __query(start, end, 0, 0, n - 1);
    }
    void update(ll ind, ll val)
    {
        ll i = ind + n - 1;
        st[i] += val;
        while (i > 0)
        {
            i = (i - 1) / 2;
            st[i] += val;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll q;
    cin >> q;
    vl b(1e6);
    SegTree2 st_b(b);
    vl a(1e6);
    vector<set<ll>> s(1e6 + 1);
    stack<pair<ll, ll>> st;
    ll r = -1;
    while (q--)
    {
        char c;
        cin >> c;
        if (c == '+')
        {
            ll x;
            cin >> x;
            r++;
            st.push({a[r], x});
            if (a[r] != 0)
            {
                if (s[a[r]].size())
                {
                    st_b.update(*(s[a[r]].begin()), -1);
                    s[a[r]].erase(r);
                }
                if (s[a[r]].size())
                {
                    st_b.update(*(s[a[r]].begin()), 1);
                }
            }
            if (s[x].size())
            {
                st_b.update(*(s[x].begin()), -1);
            }
            s[x].insert(r);
            if (s[x].size())
            {
                st_b.update(*(s[x].begin()), 1);
            }
            a[r] = x;
        }
        else if (c == '-')
        {
            ll k;
            cin >> k;
            r -= k;
            st.push({-1, k});
        }
        else if (c == '!')
        {
            auto ch = st.top();
            st.pop();
            if (ch.first == -1)
            {
                r += ch.second;
            }
            else
            {

                if (s[a[r]].size())
                {
                    st_b.update(*(s[a[r]].begin()), -1);
                    s[a[r]].erase(r);
                }
                if (s[a[r]].size())
                {
                    st_b.update(*(s[a[r]].begin()), 1);
                }

                a[r] = ch.first;
                if (a[r] != 0)
                {
                    if (s[a[r]].size())
                    {
                        st_b.update(*(s[a[r]].begin()), -1);
                    }
                    s[a[r]].insert(r);
                    if (s[a[r]].size())
                    {
                        st_b.update(*(s[a[r]].begin()), 1);
                    }
                }
                r--;
            }
        }
        else
        {
            if (r != -1)
                cout << st_b.query(0, r) << endl;
            else
                cout << 0 << endl;
        }
    }
}