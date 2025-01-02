#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl "\n"
#define input(x) for (auto &it : x) cin >> it;
#define output(x) for (auto &it : x) cout << it << ' ';
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int INF = 0x3f3f3f3f3f;
const long double PI = acos(-1);
const int MAX = 5e5 + 10;


void solve()
{
    int n;
    cin >> n;
    vi v(n);
    input(v);
    vi psum(n,0);
    vi dp(n);
    psum[0]=v[0];
    for(int i = 1; i < n; i++)
    {
        psum[i] = v[i] + psum[i-1];
    }
    // for(auto x : psum) cout << x << " ";
    // cout << endl;
    dp[n-1] = psum[n-1];
    for(int i = n-2; i >= 0; i--)
    {
        dp[i] = max(dp[i+1], psum[i] - dp[i+1]);

    }
    cout << dp[1] << '\n';

    return;
}

int32_t main()
{
    int t = 1;
    while(t--)
    {
        solve();
    }
    return 0;
}