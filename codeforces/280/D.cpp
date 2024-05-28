// LUOGU_RID: 160017411
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lson (pos<<1)
#define rson (pos<<1|1)
#define pii pair<int,int> 
#define fr first
#define sc second 
#define mk make_pair
#define pb push_back
#define yjbakioi true
#define inx int i=h[u],w=edge[i].w,v=edge[i].v;i;i=edge[i].nx,v=edge[i].v,w=edge[i].w
#define x1 lylakioi
#define y1 gczakioi
inline int read(){int x=0,f=1;char c=getchar();while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}x=c-'0';c=getchar();while(c<='9'&&c>='0'){x*=10;x+=c-'0';c=getchar();}return x*f;}
const int MAXN=200010,N=310,base=131,Mod=1011451423,Mod2=999911659,ie6=50000000,inf=1000'000'000'000'000,B=1000;
int n,m,a[MAXN];
struct node{
    int l,r,mx,lmx,lx,rmx,rx,sm;
    void prt(){
        cout<<mx<<":"<<l<<" "<<r<<"  "<<lmx<<":"<<lx<<" "<<rmx<<":"<<rx<<"  "<<sm<<endl;
    }
    node operator*(const node&G)const{
        node res;
        res.sm=sm+G.sm;
        if(lmx>sm+G.lmx)res.lmx=lmx,res.lx=lx;
        else res.lmx=sm+G.lmx,res.lx=G.lx;
        if(G.rmx>G.sm+rmx)res.rmx=G.rmx,res.rx=G.rx;
        else res.rmx=G.sm+rmx,res.rx=rx;
        int tmp=max(rmx+G.lmx,max(G.mx,mx));
        res.mx=tmp;
        if(tmp==rmx+G.lmx){
            res.l=rx;res.r=G.lx;
        }
        if(tmp==G.mx){
            res.l=G.l,res.r=G.r;
        }
        if(tmp==mx){
            res.l=l,res.r=r;
        }
        return res;
    }
};
struct TREE{
    node pri,neg;
    int lz;
}t[MAXN<<2];
void pushup(int pos){
    t[pos].pri=t[lson].pri*t[rson].pri;
    t[pos].neg=t[lson].neg*t[rson].neg;
}
void pushdown(int pos){
    if(t[pos].lz){
        swap(t[lson].pri,t[lson].neg);
        swap(t[rson].pri,t[rson].neg);
        t[lson].lz^=1;t[rson].lz^=1;
        t[pos].lz=0;
    }
}
void build(int pos,int l,int r){
    if(l==r){
        t[pos]={{l,l,a[l],a[l],l,a[l],l,a[l]},{l,l,-a[l],-a[l],l,-a[l],l,-a[l]},0};
        return;
    }
    int mid=(l+r)>>1;
    build(lson,l,mid);
    build(rson,mid+1,r);
    pushup(pos);
}
void upd(int pos,int l,int r,int x,int y){
    if(l==r){
        t[pos]={{l,l,y,y,l,y,l,y},{l,l,-y,-y,l,-y,l,-y},0};
        return;
    }
    pushdown(pos);
    int mid=(l+r)>>1;
    if(x<=mid)upd(lson,l,mid,x,y);
    if(x>mid)upd(rson,mid+1,r,x,y);
    pushup(pos);
}
void update(int pos,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r){
        swap(t[pos].pri,t[pos].neg);
        t[pos].lz^=1;
        return;
    }
    pushdown(pos);
    int mid=(l+r)>>1;
    if(ql<=mid)update(lson,l,mid,ql,qr);
    if(qr>mid)update(rson,mid+1,r,ql,qr);
    pushup(pos);
}
node query(int pos,int l,int r,int ql,int qr){
    if(ql<=l&&qr>=r){
        return t[pos].pri;
    }
    pushdown(pos);
    int mid=(l+r)>>1;node res={0,0,-inf,-inf,0,-inf,0,-inf};
    if(ql<=mid)res=query(lson,l,mid,ql,qr);
    if(qr>mid)res=res*query(rson,mid+1,r,ql,qr);
    return res;
}
void asking(int pos,int l,int r){
    cout<<l<<" "<<r<<endl;t[pos].pri.prt();t[pos].neg.prt();
    if(l==r)return;
    int mid=(l+r)>>1;
    asking(lson,l,mid);asking(rson,mid+1,r);
    pushup(pos);
}
node cg[MAXN];
void slv(){
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    build(1,1,n);
    // asking(1,1,n);
    m=read();
    while(m--){
        if(read()){
            int l=read(),r=read(),k=read(),ans=0,sum=0;
            // cout<<l<<" "<<r<<" "<<k<<endl;
            for(int i=1;i<=k;i++){
                cg[i]=query(1,1,n,l,r);
                sum+=cg[i].mx;
                ans=max(ans,sum);
                // cg[i].prt();
                update(1,1,n,cg[i].l,cg[i].r);
                // asking(1,1,n);
            }
            for(int i=k;i;i--){
                update(1,1,n,cg[i].l,cg[i].r);
            }
            printf("%lld\n",ans);
        }
        else{
            int x=read(),y=read();
            upd(1,1,n,x,y);
        }
        // asking(1,1,n);cout<<endl<<endl;
    }
}
signed main(){
// 	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    // int _=read();while(_--)
	slv();
    cerr<<clock()*1.0/CLOCKS_PER_SEC<<"s\n";
    return 0;
} 	