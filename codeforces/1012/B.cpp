# include <iostream>
# include <vector>
# include <algorithm>
# include <cassert>
using namespace std;

const int MAX=2e5+11;
int c[MAX];
bool used[MAX];
vector<int> col[MAX];
vector<int> row[MAX];
vector<int> adj[MAX];
int br_comp=0;
int d[MAX];
bool vis[MAX];
int n,m,q;

void Read()
{
    cin>>n>>m>>q;
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;

        c[y]++;
        used[x]=1;
        row[x].push_back(y);
        col[y].push_back(x);
    }
}

void dfs(int curr)
{
    vis[curr]=1;
    d[br_comp]=max(d[br_comp],c[curr]);
    for(int nxt: adj[curr])
    {
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}

void Make_adj()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<(int)row[i].size()-1;j++)
        {
            int x=row[i][j];
            int y=row[i][j+1];

            //cout<<"->"<<x<<" "<<y<<endl;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }

    //cout<<"Here"<<endl;

    for(int i=1;i<=m;i++)
    {
        if(!vis[i])
        {
            br_comp++;
            dfs(i);
        }
    }
}

void Solve()
{
    ///Corner case
    if(n==1) {cout<<m-q<<"\n";return ;}
    if(q==0) {cout<<n+m-1<<"\n";return ;}
    ///

    Make_adj();

    int ans=0;
    int r=0;
    for(int i=1; i<=br_comp; i++)
    {
        if(d[i]>0) r++;
    }

    ans+=r-1;
    bool f2=0;
    for(int i=1;i<=n;i++) if(!used[i]) ans++;f2=1;
    for(int i=1;i<=br_comp;i++) if(d[i]==0) ans++;

    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    Read();
    Solve();

    return 0;
}