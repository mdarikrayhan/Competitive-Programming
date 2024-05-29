#include<cstdio>
#include<algorithm>
typedef long long ll;
const int maxn=500010,maxm=500010,mod=1000000007;
int n,m,k,fa[maxn];
ll c[maxn];
int find(int i){return fa[i]==i?i:fa[i]=find(fa[i]);}
struct edge{int u,v;ll w;bool operator<(const edge&e)const{return w<e.w;}}E[maxm];
int main(){
scanf("%d%d%d",&n,&m,&k);
int s=1;
for(int i=1;i<=n;i++)scanf("%lld",c+i),fa[i]=i,s=s*2%mod;
for(edge*i=E;i<E+m;i++)scanf("%d%d",&i->u,&i->v),i->w=c[i->u]^c[i->v];
std::sort(E,E+m);
int sum=(1ll<<k)%mod*s%mod;
for(edge*l=E,*r=E;l<E+m;){
int t=s;
for(;r<E+m&&l->w==r->w;r++)if(find(r->u)!=find(r->v)){
fa[find(r->u)]=find(r->v);
t=t&1?t+mod>>1:t>>1;
}
(sum+=t-s)%=mod;
for(;l<r;l++)fa[l->u]=l->u,fa[l->v]=l->v;
}
printf("%d\n",sum<0?sum+mod:sum);
}
