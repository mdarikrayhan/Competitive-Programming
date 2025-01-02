#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define fr(i, b) for (int i = 0; i < (int)(b); i++)
#define rf(i, a, b) for (int i = b; i > (int)(a); i--)
#define fr2(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

void solve()
{
    int n;
    cin >> n;

    vi odd, even;
    fr(i, n)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
        {
            even.push_back(x);
        }
        else
        {
            odd.push_back(x);
        }
    }

    sort(all(even));
    sort(all(odd));

    bool aliceChance = true;

    int alice = 0, bob = 0;

    while (even.size() > 0 && odd.size() > 0)
    {
        if (aliceChance)
        {
            if (even[even.size() - 1] >= odd[odd.size() - 1])
            {
                alice += even[even.size() - 1];
                even.pop_back();
            }
            else
            {
                odd.pop_back();
            }
        }
        else
        {
            if (even[even.size() - 1] >= odd[odd.size() - 1])
            {
                even.pop_back();
            }
            else
            {
                bob += odd[odd.size() - 1];
                odd.pop_back();
            }
        }

        aliceChance = !aliceChance;
    }

    int esize = even.size(), osize = odd.size();

    for (int i = 0; i < esize; i++)
    {
        if (aliceChance)
        {
            alice += even[even.size() - 1];
        }
        even.pop_back();
        aliceChance = !aliceChance;
    }
    for (int i = 0; i < osize; i++)
    {
        if (!aliceChance)
        {
            bob += odd[odd.size() - 1];
        }
        odd.pop_back();
        aliceChance = !aliceChance;
    }

    if (alice > bob)
    {
        cout << "Alice" << endl;
    }
    else if (alice == bob)
    {
        cout << "Tie" << endl;
    }
    else
    {
        cout << "Bob" << endl;
    }
}

signed main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}