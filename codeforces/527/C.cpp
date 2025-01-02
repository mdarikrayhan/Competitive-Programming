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
void del(set<int> &ms, multiset<ll> &diff, ll x)
{
    int nxt = *ms.upper_bound(x);
    int bef = *(--ms.lower_bound(x));
    diff.erase(diff.find(x - bef));
    diff.erase(diff.find(nxt - x));
    diff.insert(nxt - bef);
    ms.erase(x);
}
void solve()
{
    int w, h, n;
    cin >> w >> h >> n;
    vector<pair<char, int>> v(n);
    set<int> hei, wid;
    hei.insert(0);
    hei.insert(h);
    wid.insert(0);
    wid.insert(w);
    for (auto &it : v)
    {
        cin >> it.first >> it.second;
        if (it.first == 'H')
            hei.insert(it.second);
        else
            wid.insert(it.second);
    }
    multiset<ll> diffsheight, diffswid;
    ll lst = 0;
    for (auto &it : wid)
    {
        diffswid.insert(it - lst);
        lst = it;
    }
    lst = 0;
    for (auto &it : hei)
    {
        diffsheight.insert(it - lst);
        lst = it;
    }
    vector<ll> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = *diffsheight.rbegin() * *diffswid.rbegin();
        if (v[i].first == 'V')
        {
            del(wid, diffswid, v[i].second);
        }
        else
        {
            del(hei, diffsheight, v[i].second);
        }
    }
    for (auto &it : ans)
        cout << it << '\n';
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
	 		 	    	   	 	 	  	  				  	