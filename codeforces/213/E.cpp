#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long 
#define pii pair<int,int>
#define pb push_back
using namespace std;
const int N=3e5+10;
int n,m,T,idx,h[N];
int a[N],b[N],pos[N];
const int P=131,mod=998244353;//或者13331
ull x,q[N]={1},tot;
struct {
    ull res;
    int l,r,sum;
}tr[N<<2];
void build(int u,int l,int r){
    tr[u].l=l,tr[u].r=r;
    if(l==r){
        return;
    }
    int mid=tr[u].l+tr[u].r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
}
void pushup(int u){
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
    tr[u].res=tr[u<<1].res*q[tr[u<<1|1].sum]+tr[u<<1|1].res;
}
void modify(int u,int x,int val){
    if(tr[u].l==tr[u].r){
        tr[u].sum+=(val?1:-1);
        tr[u].res=val;
        return;
    }
    int mid=tr[u].l+tr[u].r>>1;
    if(x<=mid) modify(u<<1,x,val);
    else modify(u<<1|1,x,val);
    pushup(u);  
}
void solve()
{   
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x=x*P+a[i];
        q[i]=q[i-1]*P;
        tot+=q[i-1];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        pos[b[i]]=i;
    }
    build(1,1,m);
    int ans=0;
    for(int i=1;i<=m;i++){
        if(i>n) modify(1,pos[i-n],0);
        modify(1,pos[i],i);
        int d=i-n;
        if(d>=0&&tr[1].res==d*tot+x) ans++;
    }
    cout<<ans<<'\n';
}    
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
/*
8
5 5
7 1
1 5
1 8
8 3
7 2
8 6
3 4
*/