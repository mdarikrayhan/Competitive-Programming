// LUOGU_RID: 160126860
#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn=2e5+5;

struct treearray
{
    #define N 2e5
    ll ts[maxn];
    inline int lowbit(int x){return x&(-x);}
    inline void updata(int x,ll y){for(;x<=N;x+=lowbit(x)) ts[x]+=y;}
    inline ll getsum(int x){ll sum=0;for(;x;x-=lowbit(x)) sum+=ts[x];return sum;}
}T0,T1;
struct node
{
    int l,r,v;
    node(int a=-1,int b=-1,int c=0){l=a,r=b,v=c;}
    inline bool operator<(const node&a)const{return l<a.l;}
};
set<node>s[maxn],st;

int n,m,cnt;
int a[maxn];

unordered_map<int,int>col;

inline int rcol()
{
    int x;
    scanf("%d",&x);
    if(!col[x]) col[x]=++cnt;
    return col[x];
}
inline void ins(node t)
{
    int nxt=s[t.v].upper_bound(t)->l,pre=(--s[t.v].lower_bound(t))->r;
    T0.updata(nxt-pre-1,-1),T1.updata(nxt-pre-1,-nxt+pre+1);
    if(pre+1!=t.l) T0.updata(t.l-pre-1,1),T1.updata(t.l-pre-1,t.l-pre-1);
    if(nxt-1!=t.r) T0.updata(nxt-t.r-1,1),T1.updata(nxt-t.r-1,nxt-t.r-1);
    s[t.v].insert(t);
}
inline void del(node t)
{
    int nxt=s[t.v].upper_bound(t)->l,pre=(--s[t.v].lower_bound(t))->r;
    T0.updata(nxt-pre-1,1),T1.updata(nxt-pre-1,nxt-pre-1);
    if(pre+1!=t.l) T0.updata(t.l-pre-1,-1),T1.updata(t.l-pre-1,-t.l+pre+1);
    if(nxt-1!=t.r) T0.updata(nxt-t.r-1,-1),T1.updata(nxt-t.r-1,-nxt+t.r+1);
    s[t.v].erase(t);
}
auto spilt(int p)
{
    auto it=st.lower_bound({p,0,0});
    if(it->l==p) return it;
    it--;
    if(it->r<p) return st.end();
    int l=it->l,r=it->r,v=it->v;
    s[v].erase(node(l,r,v)),s[v].insert(node(l,p-1,v)),s[v].insert(node(p,r,v));
    st.erase(it),st.insert(node(l,p-1,v));return st.insert(node(p,r,v)).first;
}
inline void assign(int l,int r,int x)
{
    auto itr=spilt(r+1),itl=spilt(l);
    for(auto it=itl;it!=itr;it++) del(*it);
    st.erase(itl,itr),st.insert(node(l,r,x)),ins({l,r,x});
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) s[i].insert(node(-1,0)),s[i].insert(node(n+1,n+2));
    st.insert(node(-1,0,0)),st.insert(node(n+1,n+2,0));
    T0.updata(n,n),T1.updata(n,1ll*n*n);
    for(int i=1,r;i<=n;i++) r=rcol(),st.insert(node(i,i,r)),ins(node(i,i,r));
    for(int op,l,r,x;m;m--)
    {
        scanf("%d",&op);
        if(op==1) scanf("%d%d",&l,&r),x=rcol(),assign(l,r,x);
        else scanf("%d",&x),printf("%lld\n",1ll*n*(n-x+1)-T1.getsum(n)+T1.getsum(x-1)+1ll*(T0.getsum(n)-T0.getsum(x-1))*(x-1));
    }
}