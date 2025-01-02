// Om Namah Shivaya
// Your imagination knows no bounds;
// There is nothing you can't think of.
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e12;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt;
    cin >> tt;
    const char zero = '0', one = '1';
    while (tt--)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << 0 << "\n";
            continue;
        }
        int cnt = count_if(b.begin(), b.end(), [&](auto &ele)
                           { return (ele == one); });
        int cnt2 = count_if(a.begin(), a.end(), [&](auto &ele)
                            { return (ele == one); });
        if (cnt == 0 || cnt2 == 0)
        {
            cout << "-1\n";
            continue;
        }
        int last_one = -1;
        for (int i = 0; i < n; i++)
        {
            if (b[i] == one)
                last_one = i;
        }
        int first_one = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == one && first_one == -1)
                first_one = i;
        }
        vector<int> cpy(n);
        vector<int> ans;
        auto do_op = [&](int k) -> void
        {
            ans.push_back(k);
            for (int i = 0; i < n; i++)
                cpy[i] = a[i];
            if (k > 0)
            {
                for (int i = 0, j = k; j < n; j++, i++)
                {
                    a[i] = (a[i] == cpy[j] ? zero : one);
                }
            }
            else
            {
                for (int j = 0, i = -k; i < n; j++, i++)
                {
                    a[i] = (a[i] == cpy[j] ? zero : one);
                }
            }
        };
        if (a[last_one] == zero)
        {
            do_op(first_one - last_one);
        }
        first_one = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == one && first_one == -1)
                first_one = i;
        }
        for (int i = last_one + 1; i < n; i++)
        {
            if (a[i] == one)
                do_op(first_one - i);
        }
        for (int i = last_one + 1; i < n; i++)
        {
            if (a[i] == one)
                do_op(first_one - i);
        }
        for (int i = last_one - 1; i >= 0; i--)
        {
            if (a[i] != b[i])
            {
                do_op(last_one - i);
            }
        }
        cout << ans.size() << "\n";
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << "\n";
    }
    return 0;
}