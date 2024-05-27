#include <bits/stdc++.h>
#define F(i,x,y) for(int i=(x);i<=(y);i++)
#define DF(i,x,y) for(int i=(x);i>=(y);i--)
#define ms(x,y) memset(x,y,sizeof(x))
#define SZ(x) (int)x.size()-1
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int,int> pii;
template<typename T> void chkmax(T &x,T y){ x=max(x,y);}
template<typename T> void chkmin(T &x,T y){ x=min(x,y);}
template<typename T> void read(T &FF){
    FF=0;int RR=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') RR=-1;
    for(;isdigit(ch);ch=getchar()) FF=(FF<<1)+(FF<<3)+ch-48;
    FF*=RR;
}
const int N=100010,M=300010,V=1e9;
int n,m,a[N],ans[M],tmp=1;
vector<pii> qu[N];
struct SGT{
    int lc[N*30],rc[N*30],seg[N*30],cnt;
    void clr(){ ms(seg,0),ms(lc,0),ms(rc,0);cnt=1;}
    void ins(int l,int r,int &x,int pos,int v){
        if(!x) x=++cnt;
        if(l==r){ seg[x]=v;return;}
        int mid=(l+r)>>1;
        if(mid>=pos) ins(l,mid,lc[x],pos,v);else ins(mid+1,r,rc[x],pos,v);
        seg[x]=max(seg[lc[x]],seg[rc[x]]);
    }
    int qry(int l,int r,int x,int L,int R){
        if(!x) return 0;
        if(L<=l&&r<=R) return seg[x];
        int mid=(l+r)>>1;
        if(mid>=L&&mid<R) return max(qry(l,mid,lc[x],L,R),qry(mid+1,r,rc[x],L,R));
        if(mid>=L) return qry(l,mid,lc[x],L,R);
        return qry(mid+1,r,rc[x],L,R);
    }
}sgt;
struct SGT2{
    int seg[N<<2];
    void clr(){ ms(seg,0x3f);}
    void ins(int l,int r,int x,int pos,int v){
        if(l==r){ chkmin(seg[x],v);return;}
        int mid=(l+r)>>1;
        if(mid>=pos) ins(l,mid,x<<1,pos,v);
        else ins(mid+1,r,x<<1^1,pos,v);
        seg[x]=min(seg[x<<1],seg[x<<1^1]);
    }
    int qry(int l,int r,int x,int L,int R){
        if(L<=l&&r<=R) return seg[x];
        int mid=(l+r)>>1;
        if(mid>=L&&mid<R) return min(qry(l,mid,x<<1,L,R),qry(mid+1,r,x<<1^1,L,R));
        if(mid>=L) return qry(l,mid,x<<1,L,R);return qry(mid+1,r,x<<1^1,L,R);
    }
}sgt2;
void doit(){
    sgt.clr(),sgt2.clr();
    F(i,1,n){
        int lmt=0;
        while(true){
            int p=sgt.qry(0,V,1,lmt,a[i]);
            if(!p) break;
            sgt2.ins(1,n,1,p,a[i]-a[p]);
            if(a[p]==a[i]) break;
            lmt=(a[i]+a[p]-1)/2+1;
        }
        for(auto [j,id]:qu[i]) chkmin(ans[id],sgt2.qry(1,n,1,j,n));
        sgt.ins(0,V,tmp,a[i],i);
    }
}
int main(){
    read(n);
    F(i,1,n) read(a[i]);
    read(m);
    F(i,1,m){
        int l,r;read(l),read(r);
        qu[r].pb({l,i});
    }
    ms(ans,0x3f);
    doit();
    F(i,1,n) a[i]=V-a[i];
    doit();
    F(i,1,m) printf("%d\n",ans[i]);
    return 0;
}
