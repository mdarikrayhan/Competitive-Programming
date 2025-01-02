#include <bits/stdc++.h>
using namespace std;
#define xi first
#define yi second
#define endl '\n'
#define MAX 100007
typedef long long ll;
typedef long double ld;
typedef long long ll;
const long long md = (ll)1e11 + 7;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return (a % b) ? gcd(b, a % b) : b;
}
int mst_sig_bit(long long num)
{
    int cnt = -1;
    while (num)num = num >> (ll)1, cnt++;
    return cnt;
}
long long fst_pow(long long a, long long N)
{
    if (N == 0)return 1;
    long long R = fst_pow(a, N / 2);
    if (N % 2) return ((R * R) % md * a) % md;
    else return (R * R) % md;
}
vector<vector<int>>adj;
vector<int>t[4*MAX];
int v[MAX];
int sbtr[MAX];
int cnt[MAX];
int id[MAX];
int u;
void dfs(int node, int p){
    sbtr[u++] = node;
    cnt[node] = 1;
    for(auto i:adj[node]){
        if(i==p) continue;
        dfs(i, node);
        cnt[node]+=cnt[i];
    }
}
void build(int e, int tl, int tr){
    if(tl==tr){
        t[e] = vector<int>(1, v[tl]);
        return ;
    }
    int tm = (tl+tr) / 2;
    build(2*e, tl, tm);
    build(2*e+1, tm+1, tr);
    int sz1 = t[2*e].size(), sz2 = t[2*e+1].size();
    t[e].resize(sz1+sz2);
    int i = 0, j = 0, c = 0;
    while(i<sz1&&j<sz2){
        if(t[2*e][i]<t[2*e+1][j]) t[e][c] = t[2*e][i], i++, c++;
        else t[e][c] = t[2*e+1][j], c++, j++;
    }
    while(i<sz1) t[e][c] = t[2*e][i], c++, i++;
    while(j<sz2) t[e][c] = t[2*e+1][j], c++, j++;
}
int qu(int e, int tl, int tr, int l, int r, int x){
    if(l>r) return MAX; 
    if(tl==l&&tr==r){
        auto it = lower_bound(t[e].begin(), t[e].end(), x);
        if(it==t[e].end()) return MAX;
        return *it; 
    }
    int tm = (tl+tr) / 2;
    return min(qu(2*e, tl, tm, l, min(r, tm), x),
    qu(2*e+1, tm+1, tr, max(l, tm+1), r, x));
}
int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tt;
    cin>>tt;
    while(tt--){
        int n, q;
        cin>>n>>q;
        u = 1;
        adj = vector<vector<int>>(n+1);
        for(int x=0;x<n-1;x++){
            int i, j;
            cin>>i>>j;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
        for(int x=1;x<=n;x++) cin>>v[x];
        dfs(1, 0);
        for(int x=1;x<=n;x++) id[sbtr[x]] = x;
        for(int x=1;x<=n;x++) v[x] = id[v[x]];
        build(1, 1, n);
        while(q--){
            int l , r, x;
            cin>>l>>r>>x;
            int mn = qu(1, 1, n, l, r, id[x]);
            if(mn<=id[x]+cnt[x]-1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}








