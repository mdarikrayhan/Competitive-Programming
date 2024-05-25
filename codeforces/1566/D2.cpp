// LUOGU_RID: 160006694
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100010;
int w[N],p[N];
int n,m;
vector<int> tr[N],lsh;
set<array<int,2>> s[N];
void add(vector<int> &tr,int x,int v)
{
    for (int i=x;i<=m;i+=i&-i) tr[i]+=v;
}
int query(vector<int> &tr,int x)
{
    int res=0;
    for (int i=x;i;i-=i&-i) res+=tr[i];
    return res;
}
int find(int x)
{
    return lower_bound(lsh.begin(),lsh.end(),x)-lsh.begin()+1;
}
void solve()
{
    lsh.clear();
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        tr[i].resize(m+1);
        for (int j=0;j<=m;j++) tr[i][j]=0;
    }
    for (int i=1;i<=n*m;i++) cin>>w[i],lsh.push_back(w[i]),s[i].clear();
    sort(lsh.begin(),lsh.end());
    lsh.erase(unique(lsh.begin(),lsh.end()));
    vector<array<int,2>> v;
    map<int,int> mp;
    for (int i=1;i<=n*m;i++)
    {
        w[i]=find(w[i]);
        mp[w[i]]++;
    }
    int cnt=0,ans=0;
    for (auto [x,y]:mp)
    {
        for (int i=1;i<=y;i++)
        {
            cnt++;
            int row=(cnt-1)/m+1,col=(cnt-1)%m+1;
            s[x].insert({row,-col});
        }
    }
    for (int i=1;i<=n*m;i++)
    {
        auto [x,y]=*s[w[i]].begin();
        s[w[i]].erase({x,y});
        y=-y;
        ans+=query(tr[x],y-1);
        add(tr[x],y,1);
    }
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}