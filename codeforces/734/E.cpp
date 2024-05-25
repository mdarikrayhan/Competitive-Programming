#include<bits/stdc++.h>
using namespace std;

#define int long long
#define eb emplace_back
#define pb push_back
#define forin(i , a , b) for(int i = (a) ; i <= (b) ; i ++)
#define forint(i , a,  b) for(int i = (a) ; i >= (b) ; i --)
#define fi first
#define se second
#define pii pair<int,int>
#define endl "\n"
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int maxn = 5e5 + 9 ;

int n, a[maxn];
vector <int> adj[maxn], edge[maxn];
int mx = 0, pos = 0;
void nen(int u, int pr, int root)
{
    if (a[u] != a[pr])
    {
        edge[u].pb(root);
        edge[root].pb(u);
        root = u;
    }
    for(auto v : adj[u])
    {
        if (v == pr) continue;
        nen(v, u, root);
    }
}

void dfs(int u, int pr, int d)
{
   // cout <<  u << " ";
    if (d > mx)
    {
        mx = d;
        pos = u;
    }
    for(auto v : edge[u])
    {
        if(v == pr) continue;
        dfs(v, u, d + 1);
    }
}

void Solve()
{
    nen(1, 1, 1);
    dfs(1, 1, 1);
   // cout << pos << " ";
   mx = 0 ;
    dfs(pos, pos, 0);
    cout << (mx + 1) / 2 << endl;
}

void Read()
{
    cin >> n;
    forin(i, 1, n) cin >> a[i];
    forin(i, 1, n - 1)
    {
      int u, v;
      cin >> u >> v;
      adj[u].pb(v);
      adj[v].pb(u);
    }
}
signed main ()
{
    #define TASK "task"
    if (fopen(TASK".INP" , "r"))
    {
        freopen(TASK".INP" , "r" , stdin);
        freopen(TASK".OUT" , "w" , stdout);
    }
    fast ;
    Read();
    int startTime = 1000 * clock() / CLOCKS_PER_SEC;
   // cout << "lala";
    Solve();
    int endTime = 1000 * clock() / CLOCKS_PER_SEC;
    cerr << "\nTime elapsed: " << endTime - startTime << "ms\n";

}
