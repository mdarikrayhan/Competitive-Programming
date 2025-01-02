/*
    in the name of god
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long 
using namespace __gnu_pbds;
using namespace std;

typedef pair<int,int> pii;
typedef pair<long long ,long long> pll;
typedef long long ll ;

#define ord_set(T)    tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>
#define min_heap(X)   priority_queue<X,vector<X>,greater<X>>
#define max_heap(X)   priority_queue<X>
#define File          freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define loop(i,f,d)   for(int i = f;i<d;i++)
#define loop2(j,f,d)  for(int j = f;j>=d;j--)
#define len(V)        (int)(V.size())
#define sep           ' '
#define endl          '\n'
#define pb(x)         push_back(x)
#define debug(x)      cerr  << "bug " << x << endl;
#define migmig        cin.tie(NULL);ios_base::sync_with_stdio(false);
#define fi            first
#define sec           second
#define popcount(x)   __builtin_popcount(x)
#define md(x)         (((x%MD)+MD)%MD)
#define all(V)        V.begin(),V.end()
#define Mp(a,b)       make_pair(a,b)
#define gaws(a,b)     (((b-a+1LL)*(a+b))/2LL)
#define vvi           vector<vector<int>>
#define setprec(x)    fixed << setprecision(x)
#define lid           u<<1
#define rid           (u<<1)|1
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll N = 2e5 + 10,SQ=320,LOG=31, MD = 1e9 + 7;
const ll inf = 2e9 , riz = -2e9;
int n ;
struct tmp{
    int a,b,c,d,i;
};
bool cmp(tmp a,tmp b){
    if(a.a < b.a ) return 1;
    if(a.a > b.a) return 0;
    if(a.b < b.b) return 1;
    if(a.b > b.b) return 0;
    if(a.c > b.c) return 0;
    if(a.c < b.c) return 1;
    return (a.d < b.d);
}
tmp arr[N];
int par[N],dis[N];
struct node{
    int mx,ind; 
    node(int m,int i){mx = m,ind=i;}
    node(){}
};
node seg[N<<2];
node merge(node a,node b){
    if(a.mx < b.mx) return a;
    return b;
}
void build(int u=1,int l=1,int r=n+1){
    if(r-l==1){
        seg[u].mx = arr[l].b;
        seg[u].ind = l;
        return;
    }
    int mid = (l+r)>>1;
    build(lid,l,mid);
    build(rid,mid,r);
    seg[u] = merge(seg[lid],seg[rid]);
}
void update(int ind,int v,int u=1,int l=1,int r=n+1){
    if(r-l==1){
        seg[u].mx = v;
        return ;
    }
    int mid = (l+r)>>1;
    if(ind < mid) update(ind,v,lid,l,mid);
    else update(ind,v,rid,mid,r);
    seg[u] = merge(seg[lid],seg[rid]);
}
node get(int s,int e,int u=1,int l=1,int r=n+1){
    if(e <= s) return node(inf,0);
    if(s <= l and r <= e ) return seg[u];
    int mid = (l+r)>>1;
    if(e <= mid) return get(s,e,lid,l,mid);
    if(s >= mid) return get(s,e,rid,mid,r);
    return merge(get(s,e,lid,l,mid),get(s,e,rid,mid,r));
}
int bs(int k){
    if(k < arr[1].a) return 0;
    int l = 1,r = n+1;
    while(r-l>1){
        int mid = (l+r)>>1;
        if(arr[mid].a <= k) l = mid;
        else r = mid;
    }
    return l;
}
queue<int> q;
void bfs(int u){
    q.push(u);
    fill(dis,dis+n+1,inf);
    dis[u] = 0;
    while(!q.empty()){
        u = q.front();q.pop();
        int l = bs(arr[u].c);
        node p = get(1,l+1);
        while(p.mx <= arr[u].d){
            q.push(p.ind);
            dis[p.ind] = dis[u] + 1;
            par[p.ind] = u;
            update(p.ind,inf);
            p = get(1,l+1);
        }
    }
}
int32_t main() {
    migmig
    cin >> n ;
    loop(i,1,n+1){
        cin >> arr[i].a >> arr[i].b >> arr[i].c >> arr[i].d;
        arr[i].i = i;
    }
    sort(arr+1,arr+n+1,cmp);
    build();
    arr[0].c = arr[0].d = 0;
    bfs(0);
    int t = 0;
    loop(i,1,n+1){
        if(arr[i].i == n) t = i;
    }
    if(dis[t] == inf){
        cout << -1 << endl;
        return 0;
    }
    int v = t;
    vector<int> ans;
    while(v != 0){
        ans.pb(arr[v].i);
        v = par[v];
    }
    reverse(all(ans));
    cout << dis[t] << endl;
    for(auto h : ans) cout << h << sep;
    cout << endl;
    return 0;
}