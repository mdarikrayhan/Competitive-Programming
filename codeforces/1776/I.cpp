#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
using ull = unsigned long long;
using ll = long long;
// #define endl '\n'
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int maxn = 2e5 + 10;
const int mod = 1000000007;
#define inl inline
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define ford(i, a, b) for (int i = a; i >= b; i--)
#define forall(i, a) for (auto &i : a)

/**
   ____         ___ _____
  / ___| _   _ / _ \___ /
  \___ \| | | | | | ||_ \
   ___) | |_| | |_| |__) |
  |____/ \__, |\___/____/
         |___/
*/
istream &operator>>(istream &in, vector<int> &v)
{
    for (auto &i : v)
        in >> i;
    return in;
}
ostream &operator<<(ostream &out, vector<int> &v)
{
    for (auto &i : v)
        out << i << " ";
    return out;
}
bool _output = 0;

#define int ll
struct point
{
    int x, y, id;
    point operator-(point &b)
    {
        return {x - b.x, y - b.y};
    }
};

int cross(point a, point b)
{
    return a.x * b.y - a.y * b.x;
};

void solve()
{
    int n;
    cin >> n;
    vector<point> ps(n);
    for (auto i = 0; i < n; i++)
    {
        cin >> ps[i].x >> ps[i].y;
        ps[i].id = i + 1;
    }
    auto del = [&](int id)
    {
        for (auto it = ps.begin(); it != ps.end(); it++)
        {
            if (it->id == id)
            {
                ps.erase(it);
                return;
            }
        }
    };
    if (n & 1)
    {
        cout << "Beatrice" << endl;
        int x;
        cin >> x;
        del(x);
    }
    else
    {
        cout << "Alberto" << endl;
    }
    auto make = [&]()
    {
        int sz = ps.size();
        int ar = cross(ps[1] - ps[0], ps[sz - 1] - ps[0]);
        int t_id = ps[0].id;
        for (int i = 1; i < sz; i++)
        {
            int t_ar = cross(ps[(i + 1) % sz] - ps[i], ps[(i - 1) % sz] - ps[i]);
            if (t_ar < ar)
            {
                ar = t_ar;
                t_id = ps[i].id;
            }
        }
        cout << t_id << endl;
        del(t_id);
        int x;
        cin >> x;
        del(x);
    };
    while (1)
    {
        make();
        if (ps.size() <= 2)
        {
            break;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _ = 1;
    if (_output)
        cin >> _;
    while (_--)
        solve();
    return 0;
}