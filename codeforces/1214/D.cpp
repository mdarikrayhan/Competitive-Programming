#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pii> vii;
 #define INF 10000000000000000
#define inf 1000000000
// #define MOD  1000000007
// #define MOD 672804213107214
// #define MOD 998244353
#define PI 3.1415926535897932385
 #define pb push_back
#define bitc __builtin_popcountll
#define mp make_pair
#define all(ar) ar.begin(), ar.end()
#define fr(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i--)
#define frr(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define foreach(it, ar) for (auto it = ar.begin(); it != ar.end(); it++)
#define fil(ar, val) memset(ar, val, sizeof(ar))  // 0x3f for inf, 0x80 for -INF can also use with pairs
#define print(a) for(auto x : a) cout << x << " "; cout << endl
#define print1(a) for(auto x : a) cout << x.first << " " << x.second << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
 template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
   const char* comma = strchr (names + 1, ',');
   cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
void solve()
{
  //vector<int> sieve(N+1,0); //fill constructor
    //primeSieve(sieve);
    ll n,m;
    cin>>n>>m;
    char arr[n+2][m+2];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        cin>>arr[i][j];
    }
    vector<vector<ll>>visited(n+2,vector<ll>(m+2,0));
    queue<pair<ll,ll>>q;
    q.push({1,1});
    visited[1][1]=1;
    while(!q.empty())
    {
        pair<ll,ll>p=q.front();
        q.pop();
        ll x=p.first;
        ll y=p.second;
        if(x<n&&arr[x+1][y]=='.'&&!visited[x+1][y])
        {
            q.push({x+1,y});
            visited[x+1][y]=1;
        }
        if(y<m&&arr[x][y+1]=='.'&&!visited[x][y+1])
        {
            q.push({x,y+1});
            visited[x][y+1]=1;
        }
    }
    if(visited[n][m]==0)
    {
        cout<<"0\n";
        return;
    }
     vector<vector<ll>>visited2(n+2,vector<ll>(m+2,0));
    // queue<pair<ll,ll>>q;
    q.push({n,m});
    visited2[n][m]=1;
    while(!q.empty())
    {
        pair<ll,ll>p=q.front();
        q.pop();
        ll x=p.first;
        ll y=p.second;
        if(x>1&&arr[x-1][y]=='.'&&!visited2[x-1][y])
        {
            q.push({x-1,y});
            visited2[x-1][y]=1;
        }
        if(y>1&&arr[x][y-1]=='.'&&!visited2[x][y-1])
        {
            q.push({x,y-1});
            visited2[x][y-1]=1;
        }
    }
    // vector<vector<ll>>visited3(n+1,m+1,)
    vector<vector<ll>>dp1(n+2,vector<ll>(m+2,0));
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=m;j++)
        {
            dp1[i][j]=(dp1[i+1][j]|dp1[i][j-1])|(visited[i][j]&visited2[i][j]);
        }
    }
    vector<vector<ll>>dp2(n+2,vector<ll>(m+2,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            dp2[i][j]=(dp2[i-1][j]|dp2[i][j+1])|(visited[i][j]&visited2[i][j]);
        }
    }
    ll count=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if((i==1&&j==1)||(i==n&&j==m))
            continue;
            if((visited[i][j]&&visited2[i][j]))
            {ll x=dp1[i+1][j-1]|dp2[i-1][j+1];
            if(x==0)
            count++;
            }
        }
    }
    if(count)
    {
        cout<<"1";
    }
    else
    cout<<"2";
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);   cout<<fixed;
int t=1;
// cin>>t;
while(t--)
{
   solve();
}
}
