#include <bits/stdc++.h>
using namespace std;
long long c,x,y,z,n,m,t,kq,kq1,u,v;
int i,j,k;
bool d[1000001];
vector<int>a[1000001],b[1000001];
long long f[1000001],g[1000001];
bool ok;
queue<int>q;
void bfs()
{
    q.push(g[t]);
    d[g[t]]=1;
    while (q.size()!=0)
    {
        int u=q.front();
        q.pop();
        for (int i=0;i<b[u].size();i++)
        {
            int v=b[u][i];
            if (d[v]==0)
            {
                d[v]=1;
                f[v]=f[u]+1;
                q.push(v);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>x>>y;
        a[x].push_back(y);
        b[y].push_back(x);
    }
    cin>>t;
    for (int i=1;i<=t;i++)
    {
        cin>>g[i];
    }
    bfs();
    for (int i=1;i<=t-1;i++)
    {
        u=g[i];
        y=g[i+1];
        if (f[u]-1<f[y])
        {
            kq=kq+1; kq1=kq1+1;
        } else
        {
            ok=false;
        for (int j=0;j<a[u].size();j++)
        {
            v=a[u][j];
            if (v!=y && f[v]==f[y])
            {
                ok=true; break;
            }
        }
        if (ok==true) kq1+=1;
        }
    }
    cout<<kq<<" "<<kq1;
}
