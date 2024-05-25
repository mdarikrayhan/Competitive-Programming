// LUOGU_RID: 160106280
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn],t1[maxn];
int fa[maxn],sz[maxn],ans[maxn];
int len=1;
bool vis[maxn];
int fi(int x)
{
    return fa[x]==x?x:fa[x]=fi(fa[x]);
}
void mer(int x,int y)
{
    int t1=fi(x),t2=fi(y);
    fa[t2]=t1;
    sz[t1]+=sz[t2];
    sz[t2]=0;
    len=max(len,sz[t1]);
}
map<int,int>mp;
vector<int>v;
vector<int>g[maxn];
int main()
{
    ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    int n,i,j,cnt=0,lst=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    for(i=0;i<v.size();i++)
    {
        if(!mp[v[i]])
        {
            cnt++;
            mp[v[i]]=cnt;
            t1[cnt]=v[i];
        }
    }
    for(i=1;i<=n;i++)
    {
        a[i]=mp[a[i]];
        g[a[i]].push_back(i);
    }
    for(i=1;i<=n;i++)
    {
        fa[i]=i;
        sz[i]=1;
    }
    for(i=n;i>=1;i--)
    {
        if(!g[i].size())
        {
            continue;
        }
        for(j=0;j<g[i].size();j++)
        {
            int t=g[i][j];
            if(t>1&&vis[t-1])
            {
                mer(t,t-1);
            }
            if(t<n&&vis[t+1])
            {
                mer(t,t+1);
            }
            vis[t]=1;
        }
        for(j=lst+1;j<=len;j++)
        {
            ans[j]=i;
        }
        lst=len;
    }
    for(i=1;i<=n;i++)
    {
        cout<<t1[ans[i]]<<' ';
    }
    cout<<endl;
    return 0;
}
