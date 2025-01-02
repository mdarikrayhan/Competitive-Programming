#include<bits/stdc++.h>
#define P 1000000007
#define N 605
inline void fmo(int &x){
x+=(x>>31)&P;
}
inline int fp(int x,int k=P-2){
int res=1;
for(;k;k>>=1,x=1ll*x*x%P) if(k&1)
res=1ll*res*x%P;
return res;
}
int n,m,a[N];
int pw[N];
std::vector<int> A,B;
int f[N][N][2],g[N][N][2],s[N][2],h[N];
int ans;
int main(){
scanf("%d%d",&n,&m);
pw[0]=1;
for(int i=1;i<=n;i++)
fmo(pw[i]=pw[i-1]+pw[i-1]-P);
for(int i=1;i<=n;i++)
scanf("%d",&a[i]);
std::sort(a+1,a+n+1,[&](int i,int j){
return abs(i)<abs(j);
});
a[n+1]=-P,a[n+2]=P;
for(int i=1;i<=n;i++)
f[i][n+1+(a[i]<0)][a[i]<0]=abs(a[i]);
for(int o=2;o<=m;o++){
memset(s,0,sizeof(s));
for(int i=n;i;i--) for(int j=i+1;j<=n+2;j++) for(int k=0;k<2;k++){
fmo(s[i][k]+=f[i][j][k]-P);
fmo(f[i][j][k]+=f[i+1][j][k]-P);
}
for(int i=n;i;i--)
for(int j=i+1;j<=n+2;j++) if(1ll*a[i]*a[j]<0) for(int k=0;k<2;k++){
fmo(g[i][j][k]+=f[i+1][j][k^(a[i]<0)]-P);
fmo(g[i][j][k]+=s[j][k^(a[i]<0)]-P);
g[i][j][k]=1ll*abs(a[i])*g[i][j][k]%P;
}
for(int i=n;i;i--) for(int j=i+1;j<=n+2;j++) for(int k=0;k<2;k++)
f[i][j][k]=g[i][j][k],g[i][j][k]=0;
}
for(int i=1;i<=n+2;i++)
(a[i]>=0?A:B).emplace_back(i);
for(int i=1;i<=n;i++) for(int j=i+1;j<=n+2;j++) for(int k=0;k<2;k++) if(f[i][j][k]){
if(!k)
fmo(ans+=1ll*pw[i-1]*f[i][j][k]%P-P);
else{
if(j!=n+2)
fmo(ans-=f[i][j][k]);
int u=a[i],v=a[j];
if(u<0)
std::swap(u,v);
v=-v;
int iu=fp(u),iv=fp(v);
for(int l=1,x=0,y=0;l<i;l++)
if(A[x]<i&&(B[y]>=i||(j!=n+2&&1ll*a[A[x]]*u<=1ll*abs(a[B[y]])*v)))
fmo(ans+=1ll*pw[l-1]*f[i][j][k]%P*a[A[x]]%P*iv%P-P),x++;
else
fmo(ans+=1ll*pw[l-1]*f[i][j][k]%P*abs(a[B[y]])%P*iu%P-P),y++;
}
}
if(m&1){
for(int i=0;i<(int)B.size()-1;i++)
h[i]=abs(a[B[i]]);
for(int k=2;k<=m;k++)
for(int i=(int)B.size()-2;~i;i--){
h[i]=0;
for(int j=0;j<i;j++)
fmo(h[i]+=h[j]-P);
h[i]=1ll*h[i]*abs(a[B[i]])%P;
}
for(int i=0;i<(int)B.size()-1;i++)
fmo(ans-=1ll*h[i]*pw[(int)B.size()-2-i]%P);
}
printf("%d\n",ans);
}