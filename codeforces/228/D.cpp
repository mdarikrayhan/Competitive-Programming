#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

struct op
{
    int type, l, r, z, id;
};

struct segtree
{
    int tsz;
    vector<ll> vals;

    segtree (const int n) : tsz(n), vals(2 * n) {}

    void change (int pos, const int what)
    {
        vals[pos += tsz] = what;
        for (pos >>= 1; pos > 0; pos >>= 1)
            vals[pos] = vals[2 * pos] + vals[2 * pos + 1];
    }

    ll getsum (int l, int r)
    {
        ll ans = 0;
        for (l += tsz, r += tsz; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                ans += vals[l++];
            if (r & 1)
                ans += vals[--r];
        }
        return ans;
    }
};

void solve_fixed (const vector<int> &a, const vector<op> &ops, const int z,
                  vector<ll> &ans)
{
    const int period = 2 * (z - 1);
    const int actual = int(a.size()) / period + 1;
    vector<segtree> info(period, segtree(actual));
    for (int i = 0; i < int(a.size()); i++)
        info[i % period].change(i / period, a[i]);

    for (const auto &it : ops)
    {
        if (it.type == 1)
            info[it.l % period].change(it.l / period, it.r);
        else if (it.z == z)
        {
            ll cur = 0;
            for (int i = 0; i < period; i++)
            {
                const ll coef = ll(1 + min(i, period - i));
                const int rem = (it.l + i) % period;

                int l = it.l, r = it.r;
                const int cl = l % period;
                l += (rem - cl);
                if (cl > rem)
                    l += period;
                const int cr = r % period;
                r += (rem - cr);
                if (cr > rem)
                    r += period;

                cur += coef * info[rem].getsum(l / period, r / period);
            }
            ans[it.id] = cur;
        }
    }
}

void solve_test(istream &cin = std::cin, ostream &cout = std::cout)
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &it : a)
        cin >> it;

    int m;
    cin >> m;

    vector<op> ops(m);
    int cur_id = 0;

    for (auto &it : ops)
    {
        cin >> it.type;
        cin >> it.l >> it.r;
        --it.l;
        if (it.type == 2)
        {
            cin >> it.z;
            it.id = cur_id++;
        }
        assert(it.type == 1 || it.type == 2);
    }

    vector<ll> ans(cur_id, -1LL);
    for (int z = 2; z <= 6; z++)
        solve_fixed(a, ops, z, ans);

    for (const auto &it : ans)
        cout << it << "\n";
}

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
    solve_test(cin, cout);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed;

#ifdef LOCAL
    auto st = clock();

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    do
    {
        solve(fin, fout);

        fout << "===" << endl;

        string str;
        while (getline(fin, str) && str != string(max(1, (int) str.size()), '='));
    }
    while (fin);

    cout << setprecision(6) << "clock: " << double(clock() - st) / CLOCKS_PER_SEC << endl;
#else
    solve();
#endif

    return 0;
}
