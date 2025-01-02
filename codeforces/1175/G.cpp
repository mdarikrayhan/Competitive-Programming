// 6th gen refresh
#include<iostream>
#include<cstring>
using namespace std;
namespace lly
{
    constexpr int N=2e4+5;using ll=long long;constexpr ll inf=1e18;
    struct line{ll k,b;inline ll operator()(ll x){return k*x+b;}}li[N<<1]={{0,inf}};
    int a[N];ll f[N],pf[N];
    namespace sgt
    {
        struct node{int lc,rc,id;}tree[N<<4];int tot=0;
        struct op{int ri,pv;}stk[N<<5];int top=0;
        #define now tree[ro]
        #define lsc now.lc
        #define rsc now.rc
        inline int nc(){++tot;tree[tot]=(node){0,0,0};return tot;}
        template<bool rec>
        inline void update(int&ro,int l,int r,int id)
        {
            ro=(ro?ro:nc());int mid=(l+r)>>1,pv=now.id;
            if(li[id](mid)<li[now.id](mid)) swap(id,now.id);
            if(li[id](l)<li[now.id](l)) update<rec>(lsc,l,mid,id);
            if(li[id](r)<li[now.id](r)) update<rec>(rsc,mid+1,r,id);
            if(rec&&now.id!=pv) stk[++top]=(op){ro,pv};
        }
        constexpr auto update_rb=update<true>,update_nrb=update<false>;
        inline void merge(int&ro,int y,int l,int r)
        {
            if(!ro||!y) return ro|=y,void();
            if(tree[y].id) update_nrb(ro,l,r,tree[y].id);
            int mid=(l+r)>>1;if(l==r) return;
            merge(lsc,tree[y].lc,l,mid);
            merge(rsc,tree[y].rc,mid+1,r);
        }
        inline ll query(int ro,int l,int r,int pos)
        {
            ll vl=li[now.id](pos);if(!ro||l==r) return vl;
            int mid=(l+r)>>1;ll vr=inf;
            if(pos<=mid) vr=query(lsc,l,mid,pos);
            else vr=query(rsc,mid+1,r,pos);
            return min(vr,vl);
        }
        inline void undo(int st){op t;while(top!=st) t=stk[top--],tree[t.ri].id=t.pv;}
        inline void clear(){tot=top=0;}
    }
    int stk[N],root[N],nst[N],n,m;
    inline void solve()
    {
        int ltc=0,top=0,grt=0;sgt::clear();
        for(int i=1;i<=n;i++)
        {
            int nrt=0;li[++ltc]=(line){-i+1,pf[i-1]};sgt::update_nrb(nrt,1,m,ltc);
            while(top&&a[stk[top]]<=a[i]) sgt::merge(nrt,root[top],1,m),sgt::undo(nst[top-1]),top--;
            li[++ltc]=(line){a[i],sgt::query(nrt,1,m,a[i])};sgt::update_rb(grt,1,n,ltc);
            stk[++top]=i;root[top]=nrt;nst[top]=sgt::top;f[i]=sgt::query(grt,1,n,i);
        }
        memcpy(pf,f,sizeof(f));
    }
    inline void work()
    {
        ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int k;cin>>n>>k;for(int i=1;i<=n;i++) cin>>a[i],m=max(m,a[i]);
        memset(pf,0x3f,sizeof(pf));pf[0]=0;for(int i=1;i<=k;i++) solve();
        cout<<pf[n]<<endl;
    }
}
int main()
{
    #ifdef llydebug
    freopen(".in","r",stdin);
    #endif
    lly::work();
    return 0;
}