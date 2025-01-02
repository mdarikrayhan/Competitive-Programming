#include<bits/stdc++.h>
#define ll long long
#define int long long
#define nl '\n'
#define yes cout<<"YES"
#define no cout<<"NO"
#define fi first
#define se second
#define bgn begin()
#define end end()
#define one cout<<"1"
#define mone cout<<"-1"
#define zero cout<<"0"
#define fori for(i=0;i<n;i++)
#define fori1 for(i=1;i<=n;i++)
#define forj for(j=0;j<n;j++)
#define fork for(k=0;k<n;k++)
#define forilen for(i=0;i<len;i++)
#define forim for(i=0;i<m;i++)
#define forjm for(j=0;j<m;j++)
#define forkm for(k=0;k<m;k++)
#define cn cin>>
#define lmx LLONG_MAX
#define lmn LLONG_MIN
#define imx INT_MAX
#define imn INT_MIN
#define re return
#define pb push_back
#define vl vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
using namespace std;


char s[105][105];
ll dist[105][105], n;

void floyd()
{
    ll i, j, k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }
}


void solve()
{
    ll i=0, j=0, k=0, m=0, x=0;
    cn n;
    fori
    {
        forj
        {
            cn s[i][j];
            if(i==j) dist[i][j] = 0;
            else if(s[i][j]=='1') dist[i][j] = 1;
            else dist[i][j] = 1e9;
        }
    }
    floyd();
    cn k;
    vl v(k);
    for(i=0;i<k;i++)
    {
        cn v[i];
        v[i]--;
    }
    deque <ll> ans;
    ans.pb(v[0]);
    ll sz = 0;
    for(i=2;i<k;i++)
    {
        sz++;
        ll last = ans.back();
        if(dist[last][v[i]]<=sz)
        {
            ans.pb(v[i-1]);
            sz = 0;
        }
    }
    ans.pb(v[k-1]);
    cout<<ans.size()<<nl;
    while(!ans.empty())
    {
        cout<<ans.front()+1<<' ';
        ans.pop_front();
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}


