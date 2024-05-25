#include<bits/stdc++.h>
#define int long long
#define pb(x) push_back(x)
#define in(x) insert(x)
#define mid (l+r)/2
#define F first
#define S second
#define endl '\n'
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
const int M=1e9+7;
const int N=5e5+10;
using namespace std;
int dis[N] , par[N];
vector<int>adj[N];
int ans;
void bfs(int node)
{
    queue<int>q;
    dis[node] = 0;
    q.push(node);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(auto it:adj[v])
        {
            if(dis[it] == 1e16)
            {
                dis[it] = dis[v] + 1;
                par[it] = v;
                q.push(it);
            }
            else if(par[it] != v && par[v] != it)
                ans = min(ans , dis[v] + dis[it] + 1);
        }
    }
}
int32_t main()
{
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int n;
cin>>n;
int a[n+10] , cnt[61] = {0} , mx = 0;
vector<int>v;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
    for(int j=0;j<=60;j++)
    {
        if(a[i] & (1LL<<j)){
            cnt[j]++;
            mx = max(mx , cnt[j]);
        }
    }
    if(a[i])
        v.pb(a[i]);
}
if(mx > 2)
{
    cout<<3<<endl;
    return 0;
}
for(int i=0;i<v.size();i++)
{
    for(int j=i+1;j<v.size();j++)
    {
        if(v[i] & v[j])
        {
            adj[i+1].pb(j+1);
            adj[j+1].pb(i+1);
        }
    }
}
ans = 1e15;
for(int i=1;i<=v.size();i++)
{
    for(int j=1;j<=v.size();j++)
        dis[j] = 1e16;
    bfs(i);
}
if(ans == 1e15)
    ans = -1;
cout<<ans<<endl;
}
