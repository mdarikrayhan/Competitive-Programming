// LUOGU_RID: 160571456
#include <bits/stdc++.h>
using namespace std;
#define clo 1000.*clock()/CLOCKS_PER_SEC
#ifndef xxzx
#define endl '\n'
#endif
using ll=long long;
using PII=pair<int,int>;
const int N=2e5+10;
const int INF=1e6;   
bool memory1;
struct SegmentTree {
    int mn[N<<2],lz[N<<2];
    #define ls (id<<1)
    #define rs (id<<1|1)
    void Build(int n) { for(int i=1;i<=(n<<2);i++) mn[i]=INF,lz[i]=0; }
    void update(int id) { mn[id]=min(mn[ls],mn[rs]); }
    void pushdown(int id) {
        if(!lz[id]) return;
        int val=lz[id]; lz[id]=0;
        mn[ls]+=val,lz[ls]+=val;
        mn[rs]+=val,lz[rs]+=val;
    }
    void Modify(int id,int l,int r,int x,int y,int val) {
        // if(l==1&&r==4) cerr<<"Modify "<<x<<" "<<y<<" "<<val<<endl;
        if(x<=l&&y>=r) return mn[id]+=val,lz[id]+=val, void();
        int mid=(l+r)>>1; pushdown(id);
        if(x<=mid) Modify(ls,l,mid,x,y,val);
        if(y>mid) Modify(rs,mid+1,r,x,y,val);
        update(id);
    }
    int Query(int id,int l,int r,int val) {
        if(l==r) return l;
        int mid=(l+r)>>1; pushdown(id);
        if(mn[ls]<=val) return Query(ls,l,mid,val);
        else return Query(rs,mid+1,r,val);
    }
}seg;
int n,k,d,a[N],b[N],m;
int s1[N],top1,s2[N],top2,L=1,R;
map<int,int> pos;
void sol(int l,int r) {
    // cerr<<"sol "<<l<<" "<<r<<endl;
    m=top1=top2=0;
    for(int i=l;i<=r;i++) b[++m]=a[i]/d;
    seg.Build(m);
    pos.clear();
    s1[++top1]=s2[++top2]=0;
    for(int i=1,p=0;i<=m;i++) {
        int Pos=pos[b[i]]; pos[b[i]]=i;
        if(Pos&&Pos>p) seg.Modify(1,1,m,p+1,Pos,INF),p=Pos;
        seg.Modify(1,1,m,i,i,-INF+i);
        while(top1>1&&b[s1[top1]]<b[i]) seg.Modify(1,1,m,s1[top1-1]+1,s1[top1],-b[s1[top1]]+b[i]),top1--;
        while(top2>1&&b[s2[top2]]>b[i]) seg.Modify(1,1,m,s2[top2-1]+1,s2[top2],+b[s2[top2]]-b[i]),top2--;
        s1[++top1]=s2[++top2]=i;
        Pos=seg.Query(1,1,m,k+i);
        // if(i==3) cerr<<"Pos3 "<<Pos<<endl;
        if(i-Pos>R-L) L=Pos+l-1,R=i+l-1;
    }
}
bool memory2;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin>>n>>k>>d;
    int mn=INT_MAX;
    for(int i=1;i<=n;i++) cin>>a[i],mn=min(mn,a[i]);
    for(int i=1;i<=n;i++) a[i]-=mn;
    if(d==0) {
        a[n+1]=INT_MAX;
        for(int i=1,lst=1;i<=n+1;i++) {
            if(a[lst]!=a[i]) {
                if(i-1-lst>R-L) L=lst,R=i-1;
                lst=i;
            }
        }
        cout<<L<<" "<<R<<endl;
        return 0;   
    }
    for(int i=1,lst=1;i<=n;i++) {
        if(a[lst]%d!=a[i]%d) sol(lst,i-1),lst=i;
        if(i==n) sol(lst,i);
    }
    cout<<L<<" "<<R<<endl;

    #ifdef xxzx
    cerr<<"Time: "<<clo<<"MS"<<endl;
    cerr<<"Memory: "<<abs(&memory1-&memory2)/1024./1024.<<"MB"<<endl;
    #endif
    return 0;
}