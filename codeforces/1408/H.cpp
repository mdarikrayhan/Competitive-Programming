#include "bits/stdc++.h"
#ifdef DEBUG
#include "PrettyDebug.hpp"
#else
#define debug(...) [](){}()
#define debuga(...) [](){}()
#endif
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rev(i,a,b) for(int i=a;i>=b;i--)
#define Fin(file) freopen(file,"r",stdin)
#define Fout(file) freopen(file,"w",stdout)
#define fi first
#define se second
using namespace std; typedef long long ll;
constexpr int N=5e5+5; using pii = pair<int,int>;
pii operator+ (pii A,pii B) { return pii(min(A.fi,A.se+B.fi),A.se+B.se); }
class STree{
    int n; pii O[N<<2];
    #define k1 (k<<1)
    #define k2 (k<<1|1)
    void update(int k) { O[k]=O[k1]+O[k2]; }
    void build(int k,int l,int r,function<int(int)> F){
        if(l==r) return O[k]=pii(min(0,F(l)),F(l)),void();
        int mid=(l+r)>>1; build(k1,l,mid,F); build(k2,mid+1,r,F); update(k);
    }
    void modify(int k,int l,int r,int x,int y){
        if(l==r) return O[k]=pii(min(0,y),y),void();
        int mid=(l+r)>>1; x<=mid?modify(k1,l,mid,x,y):modify(k2,mid+1,r,x,y); update(k);
    }
    pii query(int k,int l,int r,int ql,int qr){
        if(ql<=l&&r<=qr) return O[k];
        int mid=(l+r)>>1;
        if(qr<=mid) return query(k1,l,mid,ql,qr);
        else if(mid+1<=ql) return query(k2,mid+1,r,ql,qr);
        else return query(k1,l,mid,ql,qr)+query(k2,mid+1,r,ql,qr);
    }
public:
    void init(int _n,function<int(int)> F) { n=_n; build(1,1,n,F); }
    void modify(int x,int y) { return modify(1,1,n,x,y); }
    int query(int l,int r) { return query(1,1,n,l,r).fi; }
}T;
int n,a[N],p[N],pcnt,id[N],qwq[N],lst[N];
void Mian(){
    cin>>n; For(i,1,n) cin>>a[i],qwq[i]=0;
    pcnt=0; For(i,1,n) if(a[i]==0) p[++pcnt]=i,id[i]=pcnt;
    For(i,pcnt-pcnt/2+1,pcnt) qwq[p[i]]=-1;
    T.init(n,[&](int x){return qwq[x];});
    For(i,1,n) lst[i]=0;; int ans=pcnt/2;
    Rev(i,n,1){
        if(a[i]){
            if(lst[a[i]]) T.modify(lst[a[i]],0);
            T.modify(i,1); lst[a[i]]=i;
        }
        else if(id[i]<=pcnt/2){
            int x=-T.query(id[i],n);
            int k=pcnt/2+id[i]-1-x;
            debug(i,x,k);
            ans=min(ans,k);
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    atexit([](){cerr<<"Time = "<<clock()<<" ms"<<endl;});
    ios::sync_with_stdio(0); cin.tie(0);
    int Ti; cin>>Ti; while(Ti--) Mian();
    return 0;
}

// CONTINUE, NON-STOPPING, FOR CHARLIEY
// START TYPING IF YOU DON'T KNOW WHAT TO DO
// STOP TYPING IF YOU DON'T KNOW WHAT YOU'RE DOING

// Started Coding On: May 01 Wed, 08 : 02 : 56