// LUOGU_RID: 159425369
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;
const int N=600010,INF=1e9;
struct Node
{
    int l,r;
    int cnt,sum;
}tr[N<<2];
vector<int> lsh;
array<int,2> Q[N];
int find(int x)
{
    return lower_bound(lsh.begin(),lsh.end(),x)-lsh.begin()+1;
}
void pushup(int u)
{
    tr[u].cnt=tr[u<<1].cnt+tr[u<<1|1].cnt;
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}
void build(int u,int l,int r)
{
    if (l==r) tr[u]={l,r};
    else
    {
        tr[u]={l,r};
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    }
}
void modify(int u,int x,int v)
{
    if (tr[u].l==tr[u].r)
    {
        tr[u].cnt+=v;
        tr[u].sum=tr[u].cnt*lsh[x-1];
    }
    else
    {
        int mid=tr[u].l+tr[u].r>>1;
        if (x<=mid) modify(u<<1,x,v);
        else modify(u<<1|1,x,v);
        pushup(u);
    }
}
int query(int u,int k)
{
    if (tr[u].l==tr[u].r) return k*lsh[tr[u].l-1];
    int cnt=tr[u<<1|1].cnt;
    if (cnt>=k) return query(u<<1|1,k);
    else return tr[u<<1|1].sum+query(u<<1,k-cnt);
}
void solve()
{  
    int q;
    cin>>q;
    for (int i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        Q[i]={a,b};
        lsh.push_back(abs(b));
    }
    sort(lsh.begin(),lsh.end());
    lsh.erase(unique(lsh.begin(),lsh.end()),lsh.end());
    build(1,1,lsh.size());
    set<int> s1,s2;
    int sum=0;
    for (int i=0;i<q;i++)
    {
        auto [tp,d]=Q[i];
        sum+=d;
        if (tp==0)
        {
            if (d<0) s1.erase(-d),modify(1,find(-d),-1);
            else s1.insert(d),modify(1,find(d),1);
        }
        else
        {
            if (d<0) s2.erase(-d),modify(1,find(-d),-1);
            else s2.insert(d),modify(1,find(d),1);
        }
        int ans=sum;
        if (!s1.size()&&!s2.size()) ;
        else if (!s1.size()) ans+=query(1,s2.size()-1);
        else if (s1.size()&&s2.size())
        {
            int x=*s2.begin(),res=0;
            modify(1,find(x),-1);
            ans+=query(1,s2.size());
            modify(1,find(x),1);
        }
        cout<<ans<<"\n";
    }
}
signed main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    solve();
    return 0;
}