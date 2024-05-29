// LUOGU_RID: 157678916
#include<bits/stdc++.h>
#define within :
#define LJY main
using namespace std;
typedef long long ll;
const int N=3e5+5;
inline int read(){
  char ch=getchar();int x=0;
  while(ch<'0'||ch>'9') ch=getchar();
  while(ch>='0'&&ch<='9')
    x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
  return x;
}
int n,p[N],a[N];
struct Node{int mn,cf,cs,tg;}T[N<<2];
void build(int l=1,int r=n,int rt=1){
  T[rt].cf=r-l+1;if(l==r)return;
  int mid=(l+r)>>1;
  build(l,mid,rt<<1);build(mid+1,r,rt<<1|1);
}
void pushup(int rt){
  T[rt].mn=min(T[rt<<1].mn,T[rt<<1|1].mn);T[rt].cf=T[rt].cs=0;
  if(T[rt].mn==T[rt<<1].mn) T[rt].cf+=T[rt<<1].cf,T[rt].cs+=T[rt<<1].cs;
  else if(T[rt].mn+1==T[rt<<1].mn) T[rt].cs+=T[rt<<1].cf;
  if(T[rt].mn==T[rt<<1|1].mn) T[rt].cf+=T[rt<<1|1].cf,T[rt].cs+=T[rt<<1|1].cs;
  else if(T[rt].mn+1==T[rt<<1|1].mn) T[rt].cs+=T[rt<<1|1].cf;
}
void PutTag(int rt,int C){
  T[rt].tg+=C;T[rt].mn+=C;
}
void pushdown(int rt){
  if(T[rt].tg) PutTag(rt<<1,T[rt].tg),PutTag(rt<<1|1,T[rt].tg),T[rt].tg=0;
}
void add(int L,int R,int C,int l=1,int r=n,int rt=1){
  if(L>R) return;
  if(L==l&&r==R) return PutTag(rt,C);
  int mid=(l+r)>>1;pushdown(rt);
  if(R<=mid) add(L,R,C,l,mid,rt<<1);
  else if(L>mid) add(L,R,C,mid+1,r,rt<<1|1);
  else add(L,mid,C,l,mid,rt<<1),add(mid+1,R,C,mid+1,r,rt<<1|1);
  pushup(rt);
}
int qry(int L,int R,int l=1,int r=n,int rt=1){
  if(L==l&&r==R){
    if(T[rt].mn==1) return T[rt].cf+T[rt].cs;
    else return T[rt].cf*(T[rt].mn==2);
  }
  int mid=(l+r)>>1;pushdown(rt);
  if(R<=mid) return qry(L,R,l,mid,rt<<1);
  if(L>mid) return qry(L,R,mid+1,r,rt<<1|1);
  return qry(L,mid,l,mid,rt<<1)+qry(mid+1,R,mid+1,r,rt<<1|1);
}
signed LJY(){
  n=read();for(int i=1;i<=n;i++) a[p[i]=read()]=i;
  build();ll ans=0;
  for(int i=1;i<=n;i++){
    add(1,i,1);
    if(p[a[i]-1]<i) add(1,p[a[i]-1],-1);
    if(p[a[i]+1]<i) add(1,p[a[i]+1],-1);
    if(i-1) ans+=qry(1,i-1);
  }printf("%lld",ans);
  return 0;
}