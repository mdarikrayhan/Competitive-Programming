// https://codeforces.com/problemset/problem/620/E

#include<bits/stdc++.h>
using namespace std;
int n,q,t = 0;
vector<vector<int>> g;
vector<int> col, pre, post, lt;
vector<long long int> tree,lazy;

void dfs(int nn, int pp)
{
    pre[nn] = ++t;
    lt[t] = col[nn];
    for(auto v:g[nn]){
        if(v!=pp){
            dfs(v,nn);
        }
    }
    post[nn] = t;
}
int cnt(long long int x){
    int c = 0;
    while(x>0){
        c += x%2;
        x/=2;
    }
    return c;
}
void build(int node,int st,int en)
{
    if(st==en){
        tree[node] = (1ll<<lt[st]);
        return;
    }
    int mid = (st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);
    tree[node] = (tree[2*node]|tree[2*node+1]);
    return;
}

void update(int node,int st,int en,int l, int r,int col)
{
    if(lazy[node]!=0)
    {
        tree[node] = (1ll<<lazy[node]);
        if(st!=en){
            lazy[2*node]  = lazy[node];
            lazy[2*node+1] = lazy[node];
        }
        lazy[node] = 0;
    }

    if(r<st || l>en) return;

    if(st>=l && en<=r)
    {
        tree[node] = (1ll<<col);
        if(st!=en){
            lazy[2*node] = col;
            lazy[2*node+1] = col;
        }
        return;
    }

    int mid = (st+en)/2;
    update(2*node,st,mid,l,r,col);
    update(2*node+1,mid+1,en,l,r,col);

    tree[node] = (tree[2*node]|tree[2*node+1]);
    return;
}

long long int query(int node,int st,int en,int l,int r)
{
    if(lazy[node]!=0)
    {
        tree[node] = (1ll<<lazy[node]);
        if(st!=en){
            lazy[2*node]  = lazy[node];
            lazy[2*node+1] = lazy[node];
        }
        lazy[node] = 0;
    }
    if(r<st || l>en) return 0;

    if(st>=l && en<=r) return tree[node];

    int mid = (st+en)/2;
    return (query(2*node,st,mid,l,r)|query(2*node+1,mid+1,en,l,r));
}

void solve()
{
    cin>>n>>q;

    col.resize(n+1); g.resize(n+1);
    pre.resize(n+1); post.resize(n+1); lt.resize(n+1);
    tree.resize(4*n); lazy.assign(4*n,0);

    for(int i=1;i<=n;i++) {
        cin>>col[i]; 
    }

    for(int i=0;i+1<n;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); 
        g[v].push_back(u);
    }
    dfs(1,0);
    build(1,1,n);
    while(q--){
        int t,v,col; cin>>t>>v;
        if(t==1){
            cin>>col;
            int l = pre[v],r = post[v];
            update(1,1,n,l,r,col);
        }
        else{
            int l = pre[v],r = post[v];
            long long int mask = query(1,1,n,l,r);
            cout<<cnt(mask)<<'\n';
        }
    }
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    solve();
}