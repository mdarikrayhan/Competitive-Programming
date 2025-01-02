#include<bits/stdc++.h>
#define LL long long
#define LLL __int128
#define uint unsigned
#define ldb long double
#define uLL unsigned long long
using namespace std;
int plen,ptop,pstk[40];
char rdc[1<<14],wtc[1<<23],*rS,*rT;
#define gc() (rS==rT?rT=(rS=rdc)+fread(rdc,1,1<<14,stdin),(rS==rT?EOF:*rS++):*rS++)
#define pc(x) wtc[plen++]=(x)
#define flush() fwrite(wtc,1,plen,stdout),plen=0
template<class T=int>inline T read(){
    T x=0;char ch;bool f=0;
    while(!isdigit(ch=gc()))if(ch=='-')f=!f;
    do x=(x<<1)+(x<<3)+(ch^48);while(isdigit(ch=gc()));
    return f?-x:x;
}
inline int read(char*const s){
    char ch,*t=s;
    while(!isgraph(ch=gc()));
    do *t++=ch;while(isgraph(ch=gc()));
    return (*t)=0,t-s;
}
template<class T>inline void write(T x){
    if(plen>=8000000)flush();
    if(!x)return pc('0'),void();
    if(x<0)pc('-'),x=-x;
    for(;x;x/=10)pstk[ptop++]=x%10;
    while(ptop)pc(pstk[--ptop]^48);
}
inline void write(const char*s){
    if(plen>=8000000)flush();
    for(int i=0;*(s+i);pc(*(s+(i++))));
}
inline void write(char*const s){
    if(plen>=8000000)flush();
    for(int i=0;*(s+i);pc(*(s+(i++))));
}
typedef pair<int,int> PII;
const int N=2e5+5;
const LL INF=1e18+7;
int n,H,W;
LL pre[N];
int B[N],C[N],Tp[N<<2],Ts[N<<2];
int prf[N],prg[N],suf[N],sug[N];
struct node{
    int x,y;
    node():x(0),y(0){}
    node(const int&_x,const int&_y):x(_x),y(_y){}
}A[N];
vector<node>T[N<<2];
inline node operator-(const node&x,const node&y){
    return node(x.x-y.x,x.y-y.y);
}
inline bool operator<(const node&x,const node&y){
    return x.x!=y.x?x.x<y.x:x.y<y.y;
}
inline LL cross(const node&x,const node&y){
    return (LL)x.x*y.y-(LL)x.y*y.x;
}
inline LL dot(const node&x,const node&y){
    return (LL)x.x*y.x+(LL)x.y*y.y;
}
inline LL solve_1(){
    LL res=INF;
    int l=W,r=0;
    sort(A+1,A+n+1);
    for(int i=1;i<=n;++i)
        l=min(l,A[i].y),r=max(r,A[i].y),
        pre[i]=(LL)A[i].x*(r-l);
    l=W,r=0;
    for(int i=n;i>=1;--i)
        l=min(l,A[i].y),r=max(r,A[i].y),
        res=min(res,(LL)(H-A[i].x)*(r-l)+pre[i-1]);
    return res;
}
LL solve1(){
    LL res=solve_1();
    for(int i=1;i<=n;++i)swap(A[i].x,A[i].y);
    return swap(H,W),min(res,solve_1());
}
inline LL solve_2(int l1,int r1,int l2,int r2){
    if(l1>r1||l2>r2)return INF;
    int mid=(l1+r1)>>1,p=l2;
    LL res=INF;
    for(int i=l2;i<=r2;++i){
        LL nw=(LL)W*(A[i].x-A[mid].x)+(LL)H*(max(prg[mid-1],sug[i+1])-min(prf[mid-1],suf[i+1]));
        if(nw<res)res=nw,p=i;
    }
    return min(res,min(solve_2(l1,mid-1,p,r2),solve_2(mid+1,r1,l2,p)));
}
LL solve2(){
    prf[0]=suf[n+1]=W,prg[0]=sug[n+1]=0;
    for(int i=1;i<=n;++i)
        prf[i]=min(prf[i-1],A[i].y),prg[i]=max(prg[i-1],A[i].y);
    for(int i=n;i>=1;--i)
        suf[i]=min(suf[i+1],A[i].y),sug[i]=max(sug[i+1],A[i].y);
    int l=0,r=0;
    for(int i=1;i<=n;++i){
        if(A[i].y==0)l=i;
        if(A[i].y==W)r=i;
    }
    return solve_2(2,min(l,r),max(l,r),n-1);
}
void build(int p,int l,int r){
    T[p].clear();
    if(l==r){
        T[p].emplace_back(A[C[l+1]].y,A[C[l]].x),Tp[p]=0;
        return;
    }
    int mid=(l+r)>>1,ls=p<<1,rs=p<<1|1;
    build(ls,l,mid),build(rs,mid+1,r);
    int sz=(T[p]=T[ls]).size();
    for(node i:T[rs]){
        for(;(sz>1&&cross(T[p][sz-1]-T[p][sz-2],i-T[p][sz-2])>=0)\
            ||(sz>0&&T[p][sz-1].y>=i.y);T[p].pop_back(),--sz);
        T[p].push_back(i),++sz;
    }
    Tp[p]=T[p].size()-1;
}
inline LL qry(int p,int l,int r,int x,int y,node z){
    if(x<=l&&r<=y){
        for(;Tp[p]&&dot(z,T[p][Tp[p]])>=dot(z,T[p][Tp[p]-1]);--Tp[p]);
        return dot(z,T[p][Tp[p]]);
    }
    int mid=(l+r)>>1;
    LL res=INF;
    if(x<=mid)res=min(res,qry(p<<1,l,mid,x,y,z));
    if(y>mid)res=min(res,qry(p<<1|1,mid+1,r,x,y,z));
    return res;
}
inline LL solve_3(){
    int mB=0,mC=0;
    for(int i=1,cur=W+1;i<=n;++i)
        if(cur>A[i].y)B[++mB]=i,cur=A[i].y;
    for(int i=n,cur=-1;i>=1;--i)
        if(cur<A[i].y)C[++mC]=i,cur=A[i].y;
    if(mB<2||mC<2)return INF;
    reverse(C+1,C+mC+1);
    build(1,1,mC-1);
    int l=1,r=0;
    LL res=INF;
    for(int i=1;i<mB;++i){
        int w=W-A[B[i]].y,h=H-A[B[i+1]].x;
        if(!w||w==W||!h||h==H)continue;
        for(;r<mC&&A[C[r+1]].y>=A[B[i]].y;++r);
        for(;l<=mC&&A[C[l]].x<A[B[i+1]].x;++l);
        if(l<r)res=min(res,qry(1,1,mC-1,l,r-1,node(h,w)));
    }
    return res;
}
LL solve3(){
    LL res=solve_3();
    for(int i=1;i<=n;++i)A[i].x=H-A[i].x;
    reverse(A+1,A+n+1);
    return min(res,solve_3());
}
inline void MAIN(){
    n=read(),H=W=1e9+7;
    for(int i=1;i<=n;++i)
        A[i].x=read(),A[i].y=read(),H=min(H,A[i].x),W=min(W,A[i].y);
    for(int i=1;i<=n;++i)A[i].x-=H,A[i].y-=W;
    H=W=0;
    for(int i=1;i<=n;++i)H=max(H,A[i].x),W=max(W,A[i].y);
    LL ans=solve1();
    ans=min(ans,solve2());
    ans=min(ans,solve3());
    write(ans),pc('\n');
}
signed main(){
#define MultiCase 1
    for(int T=MultiCase?read():1;T--;MAIN());
	return flush();
}
/*
*/