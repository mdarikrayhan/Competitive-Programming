// LUOGU_RID: 160607472
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define pr pair<int,int>
#define mp make_pair
#define x first
#define y second
#define prt(A) printf("%d %d\n",A.x,A.y)
#define N 100005
int v[N],son[N],ed[N],nt[N],fa[N],s[N],g[N],n,w,len,root;
pr e[N],o[N],f[N][2],ans;
pr operator +(pr A,pr B){return mp(A.x+B.x,A.y+B.y);}
pr operator -(pr A,pr B){return mp(A.x-B.x,A.y-B.y);}
void dfs(int x)
{
v[x]=1,f[x][1]=f[x][0]=mp(0,0),g[x]=0;
for (int y=son[x];y;y=nt[y]) if (y-root){
dfs(y),f[x][0]=f[x][0]+f[y][1]; pr t=f[y][0]+mp(1,s[x]^s[y])-f[y][1];
if (t>f[x][1]) f[x][1]=t,g[x]=y;
}
f[x][1]=f[x][1]+f[x][0];
}
void get(int x,int flag)
{
for (int y=son[x];y;y=nt[y]) if (y-root)
if (flag && g[x]==y) e[w++]=mp(x,y),get(y,0); else get(y,1);
}
void match(int x)
{
for (;!v[x];x=fa[x]) v[x]=1; pr res(0,0);
for (int T=2;T;T--,x=fa[x]){
root=x,dfs(x); if (f[x][1]>res) res=f[x][1],w=0,get(x,1);
}
ans=ans+res; for (int i=0;i<w;i++) o[len++]=e[i];
}
int main()
{
scanf("%d",&n);
for (int i=1;i<=n;i++)
scanf("%d%d",fa+i,s+i),s[i]--,nt[i]=son[fa[i]],son[fa[i]]=i;
for (int i=1;i<=n;i++) if (!v[i]) match(i); prt(ans);
for (int i=0;i<len;i++) prt(o[i]); return 0;
}