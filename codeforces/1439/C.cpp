#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define random(l, r) (l + rand() % (r - l + 1))
#define int long long
#define maxn 300005
#define bit(x, i) ((x >> i) & 1)
#define pii pair<int, int>
#define MOD 1000000007
#define Task "SHOPPING"
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
int n,q,a[maxn],Tree[4 * maxn],minn[4 * maxn],d[4 * maxn];
ordered_set st[10105];
void Add(int &a,int b){
    a += b;
    if(a >= MOD)a -= MOD;
    if(a < 0)a += MOD;
}
void build(int node,int l,int r){
    if(l > r)return;
    if(l == r){
       Tree[node] = a[l];
       minn[node] = a[l];
       return;
    }
    int mid = (l + r) / 2;
    build(node * 2,l,mid);
    build(node * 2 + 1,mid + 1,r);
    Tree[node] = Tree[node * 2] + Tree[node * 2 + 1];
    minn[node] = min(minn[node * 2],minn[node * 2 + 1]);
}
void Lazy(int node,int l,int r,int mid){
    if (d[node] > 0)
    {
        d[node * 2] = d[node];
        d[node * 2 + 1] = d[node];
        Tree[node * 2] = d[node] * (mid - l + 1);
        Tree[node * 2 + 1] = d[node] * (r - mid);
        minn[node * 2] = d[node];
        minn[node * 2 + 1] = d[node];
        d[node] = 0;
    }
}
int Get_min(int node,int l,int r,int u,int v,int val){
    if(l > v || r < u)return MOD;
    int mid = (l + r) / 2;
    Lazy(node,l,r,mid);
    if(l >= u && r <= v){
       //cout << node << " " << l << " " << r << " " << minn[node] << " " << val <<  '\n';
       if(minn[node] > val)return MOD;
       if(l == r)return l;
       if(minn[node * 2] <= val)return Get_min(node * 2,l,mid,u,v,val);
       else return Get_min(node * 2 + 1,mid + 1,r,u,v,val);
    }
    return min(Get_min(node * 2,l,mid,u,v,val),Get_min(node * 2 + 1,mid + 1,r,u,v,val));
}
void Update(int node,int l,int r,int u,int v,int w){
    if (r < u || l > v) return;
	if (r <= v && l >= u){
		d[node] = w;
		Tree[node] = (r - l + 1) * w;
		minn[node] = w;
		return;
    }
	int mid = (l + r)/2;
	Lazy(node,l,r,mid);
	Update(node*2, l, mid, u, v, w);
	Update(node*2+1, mid + 1, r, u, v, w);
	Tree[node] = (Tree[node*2] +  Tree[node*2+1]);
	minn[node] = min(minn[node * 2],minn[node * 2 + 1]);
}
int Get(int node,int l,int r,int u,int v,int &val){
    if (r < u || l > v || minn[node] > val) return 0;
	if (r <= v && l >= u && Tree[node] <= val){
        val -= Tree[node];
        return (r - l + 1);
	}
	int mid = (l + r)/2;
	Lazy(node,l,r,mid);
	int ans = 0;
	ans += Get(node*2, l, mid, u, v,val);
	ans += Get(node*2+1, mid + 1, r, u, v,val);
	return ans;
}

void solve(){
    while(q--){
        int type,x,y;
        cin >> type >> x >> y;
        if(type == 1){
           int pos = Get_min(1,1,n,1,x,y);
           //cout << pos;
           if(pos <= x)Update(1,1,n,pos,x,y);
        }
        else cout << Get(1,1,n,x,n,y) << '\n';

    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> q;
    for(int i = 1;i <= n;i++)cin >> a[i];
    build(1,1,n);
    solve();
}
