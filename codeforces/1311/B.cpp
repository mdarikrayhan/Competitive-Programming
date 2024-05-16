#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
typedef pair<int,int> PII;
const int N=200010,INF=1e9;
int n,m,a[N],w[N],p[N];
vector<array<int,2>> v[N];
int ans[N];
int find(int x)
{
    if (x!=p[x]) p[x]=find(p[x]);
    return p[x];
}
void solve()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>w[i],p[i]=i;
        v[i].clear();
    }
    for (int i=1;i<=m;i++) cin>>a[i];
    for (int i=1;i<=m;i++)
    {
        int pa=find(a[i]),pb=find(a[i]+1);
        p[pa]=pb;
    }
    for (int i=1;i<=n;i++) v[find(i)].push_back({w[i],i});
    for (int i=1;i<=n;i++)
    {
        sort(v[i].begin(),v[i].end());
        vector<int> vid;
        for (auto [val,id]:v[i]) vid.push_back(id);
        sort(vid.begin(),vid.end());
        for (int j=0;j<vid.size();j++) ans[vid[j]]=v[i][j][0];
    }
    for (int i=2;i<=n;i++)
        if (ans[i]<ans[i-1])
        {
            cout<<"NO\n";
            return ;
        } 
    cout<<"YES\n";
}   
signed main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}