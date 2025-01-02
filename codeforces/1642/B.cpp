#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define endl '\n' //comment for interactive
#define PI acos(-1.0)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<vector<ll>> vvll;
typedef pair<ll,ll> pll;

const ll mod=(ll)1000000007;

// My custom power function
ll powr(ll a,ll n)
{
    if(n==0)return 1LL;
    if(n%2==0)return powr(a*a%mod,n/2LL);
    else return a*powr(a,n-1LL)%mod;
}
ll inv(ll a,ll mod)
{
    return (powr(a,mod-2))%mod;
}

// Gets prime numbers upto sqrt(N)
void sieve(vector<ll>&answer,ll n)
{
    n=sqrtl(n)+2;
    vector<bool>prime(n + 1,true);
    for(int i=2;i*i<=n;i++)
    {
        if(prime[i])
        {
            for(int j=i*i;j<=n;j+=i)
            {
                prime[j]=false;
            }
        }
    }
    for(int i=2;i<n+1;i++)
    {
        if(prime[i])
        {
            answer.push_back(i);
        }
    } 
}
class DSU{
public:
    ll n;
    ll c;
    vll parent;
    vll rank;

    DSU(ll s)
    {
        n=s;
        c=n;
        parent=vll(n);
        rank=vll(n);
        for(ll i=0;i<n;i++) make_set(i);
    }

    void make_set(ll a)
    {
        parent[a]=a;
        rank[a]=0;
    }

    ll find_set(ll a)
    {
        if(a==parent[a]) return a;
        return parent[a] = find_set(parent[a]);
    }

    void union_set(ll a,ll b)
    {
        a=find_set(a),b=find_set(b);
        if(a!=b)
        {
            if(rank[a]<rank[b]) swap(a,b);
            parent[b]=a;
            if(rank[a]==rank[b]) rank[a]++;
            c--;
        }
    }
};
ll over=0;
vector<ll>path;
vector<vector<ll>>adj(200002);
DSU dsu(200002);
vector<ll>p(200002),sz(200002);
queue<ll>q;
void dfs1(ll a,ll b,ll dest)
{
    path.push_back(a);
    if(a==dest)
    {
        over=1;
        return;
    }
    for(auto&i:adj[a])
    {
        if(i==b)
        continue;
        dfs1(i,a,dest);
        if(over==1)
        return;
    }
    path.pop_back();
}
void solve()
{
    // ll n,x,y,z=0;
    // cin >> n;
    // for(ll i=0;i<n;i++)
    // {
    //     adj[i].clear();
    //     dsu.make_set(i);
    //     p[i]=-1;
    //     sz[i]=0;
    // }
    // for(ll i=0;i<n;i++)
    // {
    //     cin >> x >> y;
    //     x--,y--;
    //     if(z==0&&dsu.find_set(x)==dsu.find_set(y))
    //     {
    //         z=1;
    //         over=0;
    //         path.clear();
    //         dfs1(x,-1,y);
    //     }
    //     adj[x].push_back(y);
    //     adj[y].push_back(x);
    //     dsu.union_set(x,y);
    // }
    // ll ans=0,s,m=0;
    // s=path.size();
    // path.push_back(path[0]);
    // path.push_back(path[1]);
    // for(ll i=1;i<=s;i++)
    // {
    //     m++;
    //     for(auto&j:adj[path[i]])
    //     {
    //         if(j!=path[i-1]&&j!=path[i+1])
    //         {
    //             q.push(j);
    //             p[j]=path[i];
    //         }
    //     }
    // }
    // ans=s*(s-1);
    // while(!q.empty())
    // {
    //     ll a=q.front();
    //     q.pop();
    //     ans+=(m-sz[p[a]]-1)*2LL+sz[p[a]]+1;
    //     sz[p[a]]++;
    //     m++;
    //     for(auto&j:adj[a])
    //     {
    //         if(j==p[a])
    //         continue;
    //         p[j]=p[a];
    //         q.push(j);
    //     }
    // }
    // cout << ans << endl;
    ll n,r;
    cin >> n;
    set<ll>s;
    for(ll i=0;i<n;i++)
    {
        cin >> r;
        s.insert(r);
    }
    for(ll i=1;i<=n;i++)
    {
        cout << max(i,(ll)s.size()) <<" ";
    }
    cout << endl;
}
void solveTestcases()
{
    ll t=1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solveTestcases();
    return 0;
}