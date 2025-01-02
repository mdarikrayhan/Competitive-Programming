// LUOGU_RID: 159079385
#include <bits/stdc++.h>
using namespace std;
using ui = unsigned;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,l,r) for(int i=(l);i>=(r);--i)
#define repn(i,n)  for(int i=0;i<(n);++i)
#define sizc(x) ((int)x.size())
#define allc(x) x.begin(),x.end()
#define fir first
#define sec second
namespace KnownError_{
    constexpr int N = 3e5+5;
    int n,a[N],p[N];
    struct jxt{
        int mx[N],se[N],cm[N],co[N],tg1[N],tg2[N];
        ll sum[N];
        void build(){
            fill(mx+1,mx+2*n,-1e9);
            fill(se+1,se+2*n,-1e9);
        }
        void pu(int u,int ls,int rs){
            if(mx[ls]>mx[rs]){
                mx[u]=mx[ls];
                se[u]=max(se[ls],mx[rs]);
                cm[u]=cm[ls];
                co[u]=co[ls]+cm[rs]+co[rs];
            }
            if(mx[ls]<mx[rs]){
                mx[u]=mx[rs];
                se[u]=max(mx[ls],se[rs]);
                cm[u]=cm[rs];
                co[u]=co[ls]+cm[ls]+co[rs];
            }
            if(mx[ls]==mx[rs]){
                mx[u]=mx[ls];
                se[u]=max(se[ls],se[rs]);
                cm[u]=cm[ls]+cm[rs];
                co[u]=co[ls]+co[rs];
            }
            sum[u]=sum[ls]+sum[rs];
        }
        void mt(int u,int t1,int t2){
            mx[u]+=t1,tg1[u]+=t1;
            se[u]+=t2,tg2[u]+=t2;
            sum[u]+=(ll)t1*cm[u]+(ll)t2*co[u];
        }
        void pd(int u,int ls,int rs){
            bool tl=mx[ls]>=mx[rs],tr=mx[rs]>=mx[ls];
            mt(ls,tl?tg1[u]:tg2[u],tg2[u]);
            mt(rs,tr?tg1[u]:tg2[u],tg2[u]);
            tg1[u]=tg2[u]=0;
        }
        void add(int u,int L,int R,int l,int r,int x){
            if(r<L||R<l||r<l||!cm[u])return;
            if(l<=L&&R<=r){mt(u,x,x);return;}
            int M=L+R>>1,ls=M<<1,rs=M<<1|1;
            pd(u,ls,rs);
            add(ls,L,M,l,r,x),add(rs,M+1,R,l,r,x);
            pu(u,ls,rs);
        }
        void upd(int u,int L,int R,int l,int r,int x){
            if(r<L||R<l||r<l||!cm[u]||mx[u]<=x)return;
            if(l<=L&&R<=r&&se[u]<x){mt(u,x-mx[u],0);return;}
            int M=L+R>>1,ls=M<<1,rs=M<<1|1;
            pd(u,ls,rs);
            upd(ls,L,M,l,r,x),upd(rs,M+1,R,l,r,x);
            pu(u,ls,rs);
        }
        void ins(int u,int L,int R,int x,int k){
            if(L==R){sum[u]=mx[u]=k;cm[u]=1;return;}
            int M=L+R>>1,ls=M<<1,rs=M<<1|1;
            pd(u,ls,rs);
            if(x<=M)ins(ls,L,M,x,k);
            else ins(rs,M+1,R,x,k);
            pu(u,ls,rs);
        }
    }t1,t2;
    struct fenwick{
        int c[N];
        int sum(int x){int ret=0;while(x)ret+=c[x],x^=x&-x;return ret;}
        void add(int x,int k){while(x<=n)c[x]+=k,x+=x&-x;}
    }t;
    void main(){
    	cin>>n;
        rep(i,1,n)cin>>a[i],p[a[i]]=i;
        t1.build(),t2.build();
        rep(i,1,n){
            t.add(p[i],1);
            int c=t.sum(p[i]);
            t1.ins(1,1,n,p[i],i+1);
            t1.upd(1,1,n,1,p[i]-1,c);
            t1.add(1,1,n,p[i]+1,n,1);
            t2.ins(1,1,n,p[i],0);
            t2.upd(1,1,n,p[i]+1,n,-c+1);
            t2.add(1,1,n,p[i]+1,n,-1);
            cout<<t1.sum[1]+t2.sum[1]-i<<'\n';
        }
    }
}
signed main(){
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    KnownError_::main();
}