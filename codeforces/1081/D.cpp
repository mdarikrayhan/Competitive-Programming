/*
     The moment you give up is the moment you let someone else win.
*/

#include <bits/stdc++.h>

using namespace std;

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
const int MOD = 1e9+7;
inline int power(int a, int b)
{
	int x = 1;
	while (b)
	{
		if (b & 1) x *= a;
		a *= a;
		b >>= 1;
	}
	return x;
}
unordered_set<int> s;
class DisjointSet
{
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
    vector<int> s_vertex;
public:
    DisjointSet(int n)
    {
        // we are doing 1 based indexing here as it can accomodate both 1 and 0
        rank.resize(n + 1, 0);
        size.resize(n+1,1);
        parent.resize(n + 1);
        s_vertex.resize(n + 1,0);
        for(auto it=s.begin();it!=s.end();it++)
        {
            s_vertex[*it]=1;
        }
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    /*
    This is the normal log n function we need the path compression one
    int findUPar(int node)
    {
        if(parent[node]==node)
        return node;
        else
        return findUPar(parent[node]);
    }*/
    int findUPar(int node)
    {
        if (parent[node] == node)
            return node;
        else
        {
            parent[node] = findUPar(parent[node]); // path compression
            return parent[node];
        }
    }
    void union_by_rank(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) // i.e they belong to the same component so we dont need to do anything
            return;
        int ru = rank[pu];
        int rv = rank[pv];
        // smaller gets attached to bigger so no change in rank , rank only changes if two of same rank gets attached
        if (ru < rv)
        {
            parent[pu] = pv;
        }
        else if (ru > rv)
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    void union_by_size(int u, int v)
    {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) // i.e they belong to the same component so we dont need to do anything
            return;
        int size_u=size[u];
        int size_v=size[v];
        if(size_u<size_v)
        {
            parent[pu]=pv;
            size[pv]+=size[pu];
            s_vertex[pv]+=s_vertex[pu];
        }
        else 
        {
            parent[pv]=pu;
            size[pu]+=size[pv];
            s_vertex[pu]+=s_vertex[pv];
        }
    }
    int get_size(int u)
    {
        int p=findUPar(u);
        return size[p];
    }
    int get_s_vertex(int u)
    {
        int p=findUPar(u);
        return s_vertex[p];
    }
    void print_s_vertex()
    {
        for(int i=1;i<s_vertex.size();i++)
        {
            cout<<s_vertex[i]<<endl;
        }
    }
};
void solve()
{
   int n,m,k;
   cin>>n>>m>>k;
   for(int i=0;i<k;i++)
   {
    int node;
    cin>>node;
    s.insert(node);
   }
   vector<pair<int,pair<int,int>>> edges;
   for(int i=0;i<m;i++)
   {
    int u,v,w;
    cin>>u>>v>>w;
    edges.pb({w,{u,v}});
   }
   DisjointSet ds(n);
   //ds.print_s_vertex();
   sort(edges.begin(),edges.end());
  /* for(int i=0;i<m;i++)
   {
    cout<<edges[i].F<<" "<<edges[i].S.F<<" "<<edges[i].S.S<<endl;
   }*/
   for(int i=0;i<m;i++)
   {
    auto x=edges[i];
    int w=x.F;
    int node=x.S.F;
    int parent=x.S.S;
    //cout<<w<<" "<<ds.get_s_vertex(node)<<" "<<ds.get_s_vertex(parent)<<endl;
    if(ds.get_s_vertex(node)+ds.get_s_vertex(parent)==k&&ds.findUPar(node)!=ds.findUPar(parent))
    {
        for(int i=0;i<k;i++)
        cout<<w<<" ";
        return;
    }
    if(ds.findUPar(node)!=ds.findUPar(parent))
    {
        ds.union_by_size(node,parent);
    }
   }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{1};
    //cin>>t;
    while(t--)
    solve();
    return 0;
}