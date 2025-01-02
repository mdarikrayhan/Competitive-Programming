#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LLvector vector<LL>
#define intvector vector<int>
#define nl cout << "\n";
#define pb push_back
#define f first
#define s second
#define yes cout << "Yes\n"
#define no cout << "No\n"
#define forr(n) for (ll i = 0; i < n; i++)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    // t = 1;
    map<int, int> mp;
    while (t--)
    {
        int n;
        cin >> n;
        mp[n]++;
    }

    bool flag = 0;
    for (auto it : mp)
        if (it.s % 2)
        {
            flag = 1;
            break;
        }

    if (flag)
        cout << "Conan\n";
    else
        cout << "Agasa\n";
}






