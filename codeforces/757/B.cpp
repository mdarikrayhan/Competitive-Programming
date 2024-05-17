#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define code() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve()
{
    int n; cin>>n;
    vector<int>v(n);
    for(auto &x : v) cin>>x;

    map<int,int>mp;
    for(auto u : v)
    {
        for(int i=2; i*i<=u; i++)
        {
            if(u%i == 0)
            {
                while(u%i == 0) u /= i;
                mp[i]++;
            }
        }
        if(u>1) mp[u]++;
    }

    int ans = -1e9;
    for(auto [x,y] : mp) ans = max(y,ans);

    if(ans == -1e9) cout<<1<<endl;
    else cout<<ans<<endl;
}

int main()
{
    code();
    
    int tc = 1;
    // cin>>tc;

    while(tc--) solve();

    return 0;
}
		         			     		     	