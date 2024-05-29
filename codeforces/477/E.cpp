#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5,I=1<<30;
int n,a[N],i,j,q,sx,sy,tx,ty,ans[N];
int f[20][N],lo[N],st[N],w;
inline int getmin(int x,int y){
if(x>y)swap(x,y);int l=lo[y-x+1];
return min(f[l][x],f[l][y-(1<<l)+1]);
}
struct node{
int p,q,k,w,*v;
inline int F(const int&i){return k*i+(a[i]>q)+abs(p-a[i]);}
inline void upd(const int&i){*v=min(*v,F(i)+w);}
};
vector<node>qu[N][2];
inline int G(const int&x){return x<0?-x:a[x];}
inline bool cmp(const int&x,const int&y){return G(x)<G(y);}
inline void work(node&u,int o){
int l=1,r=u.q>I?lower_bound(st+1,st+w+1,I-u.q,cmp)-st:w,m1,m2,dt;
if(u.q>I)l=r,r=w;
for(;r-l>9;){
dt=(r-l)/3;m1=l+dt;m2=r-dt;
if(u.F(st[m1])>u.F(st[m2]))l=m1;else r=m2;
}
for(;l<=r;++l)u.upd(st[l]);
}
inline void solve(int o){
int i=o==0?1:n;w=0;
for(;i>=1&&i<=n;i+=o==0?1:-1){
for(;w&&a[st[w]]>=a[i];--w);st[++w]=i;
for(node u:qu[i][o])work(u,o);
}
}
int main(){
for(i=2;i<N;++i)lo[i]=lo[i>>1]+1;
ios::sync_with_stdio(0);cin.tie(0);
cin>>n;for(i=1;i<=n;++i)cin>>a[i],f[0][i]=a[i];
for(i=1;i<=lo[n];++i)for(j=1;j+(1<<i)-1<=n;++j)
f[i][j]=min(f[i-1][j],f[i-1][j+(1<<(i-1))]);
for(cin>>q,j=1;j<=q;++j){
int z,ff,u,v;ans[j]=I;
cin>>sx>>sy>>tx>>ty;ff=min(getmin(sx,tx),sy);
ans[j]=abs(sx-tx)+min(min(ty+1,a[tx]-ty+1),abs(ty-ff));
if(sx>=tx){
ff=getmin(sx,tx);if(ff>=ty)qu[sx+1][1].push_back((node){ty,sy,2,-tx-sx,ans+j});
qu[tx][1].push_back((node){ty,I+ff,0,abs(sx-tx)+1,ans+j});
ff=min(getmin(sx,tx),sy);qu[tx][0].push_back((node){ty,ff,-2,tx+sx,ans+j});
}
if(sx<=tx){
ff=getmin(sx,tx);if(ff>=ty)qu[sx-1][0].push_back((node){ty,sy,-2,tx+sx,ans+j});
qu[tx][0].push_back((node){ty,I+ff,0,abs(sx-tx)+1,ans+j});
ff=min(getmin(sx,tx),sy);qu[tx][1].push_back((node){ty,ff,2,-tx-sx,ans+j});
}
}
solve(0);solve(1);
for(i=1;i<=q;++i)cout<<ans[i]<<'\n';
return 0;
}