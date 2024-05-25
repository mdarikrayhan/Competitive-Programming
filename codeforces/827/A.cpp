#include <bits/stdc++.h>

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define fix(a, k) ((a % k) + k) % k
#define sz(s) (int)(s).size()
#define all(s) s.begin(), s.end()
#define ll long long
using namespace std;
void File() // low l r high
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solve()
{
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    vector<int> idx;
    vector<string> ss;
    for (int i = 0; i < n; i++)
    {
        string s;
        int sz;
        cin >> s >> sz;
        ss.push_back(s);
        while (sz--)
        {
            int x;
            cin >> x;
            if (mp.find(x) == mp.end())
            {
                idx.push_back(x);
                mp[x] = i;
            }
            else
            {
                if (sz(ss[mp[x]]) < sz(s))
                    mp[x] = i;
            }
        }
    }
    sort(all(idx));
    string ans = "";
    for (int i = 0; i < sz(idx); i++)
    {
        while (sz(ans) + 1 < idx[i])
        {
            ans.push_back('a');
        }
        int k = i;
        for (int j = i; j < sz(idx) and sz(ss[mp[idx[i]]]) + idx[i] >= sz(ss[mp[idx[j]]]) + idx[j]; j++)
        {
            k = j;
        }
        int s = sz(ans) - idx[i] + 1;
        while (s < sz(ss[mp[idx[i]]]))
        {
            ans += ss[mp[idx[i]]][s];
            s++;
        }
        i = k;
    }
    cout << ans << '\n';
}

int main()
{
    IOS;
    File();
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
		  		  	  					  	     		    	