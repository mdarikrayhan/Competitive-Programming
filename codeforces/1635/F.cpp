#include<bits/stdc++.h>
#define x first
#define y second
#define int long long 
#define pb push_back
using namespace std;
typedef pair<int,int>PII;
const int N=3e5+5,M=1e5+5,P=LLONG_MAX;
int n,k,m,ans[N],x[N],w[N],tt,stk[N],l[N],r[N];
vector<PII>qu[N];
vector<int>d[N];
struct Node
{
    int l,r,mi;
}t[N<<2];
void up(int u)
{
    t[u].mi=min(t[u<<1].mi,t[u<<1|1].mi);
}
void build(int u,int l,int r)
{
    t[u]={l,r,P};
    if(l==r)return ;
    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    up(u);
}
void modify(int u,int x,int w)
{
    if(t[u].l==t[u].r)
    {    
        t[u].mi=min(t[u].mi,w);
        return ;
    }
    int mid=t[u].l+t[u].r>>1;
    if(x<=mid)modify(u<<1,x,w);
    if(x>mid)modify(u<<1|1,x,w);
    up(u);
}
int query(int u,int l,int r)
{
    if(l<=t[u].l&&t[u].r<=r)return t[u].mi;
    int mid=t[u].l+t[u].r>>1,res=P;
    if(l<=mid)res=min(res,query(u<<1,l,r));
    if(r>mid)res=min(res,query(u<<1|1,l,r));
    return res;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>x[i]>>w[i];
    for(int i=1;i<=n;i++)
    {
        while(tt&&w[stk[tt]]>w[i])tt--;
        l[i]=stk[tt];
        stk[++tt]=i;
    }
    tt=0;
    for(int i=n;i>0;i--)
    {
        while(tt&&w[stk[tt]]>w[i])tt--;
        r[i]=stk[tt];
        stk[++tt]=i;
    }
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        qu[b].pb({a,i});
    }
    for(int i=1;i<=n;i++)
    {
        if(l[i])d[i].pb(l[i]);
        if(r[i])d[r[i]].pb(i);
    }
    build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        for(int a:d[i])modify(1,a,abs(x[i]-x[a])*(w[i]+w[a]));
        for(auto [l,id]:qu[i])ans[id]=query(1,l,i);
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<"\n";
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	// int T;cin>>T;
	// while(T--)
	solve();
	return 0;
}