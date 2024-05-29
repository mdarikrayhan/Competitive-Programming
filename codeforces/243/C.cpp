#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,q,cntx,cnty,tx[2003],ty[2003],x[1003],y[1003],vis[2003][2003],ans;
char c;
void dfs(int x,int y){
if(vis[x][y]||x<1||x>n+1||y<1||y>m+1) return;
vis[x][y]=1;
dfs(x-1,y);
dfs(x,y-1);
dfs(x+1,y);
dfs(x,y+1);
}
signed main(){
scanf("%lld",&q);
tx[++cntx]=-1;
tx[++cntx]=0;
ty[++cnty]=-1;
ty[++cnty]=0;
for(int i=1,j;i<=q;i++){
scanf("\n%c%lld",&c,&j);
x[i]=x[i-1],y[i]=y[i-1];
if(c=='U') x[i]+=j;
if(c=='D') x[i]-=j;
if(c=='R') y[i]+=j;
if(c=='L') y[i]-=j;
tx[++cntx]=x[i]-1;
tx[++cntx]=x[i];
ty[++cnty]=y[i]-1;
ty[++cnty]=y[i];
}
sort(tx+1,tx+cntx+1);
sort(ty+1,ty+cnty+1);
n=unique(tx+1,tx+cntx+1)-tx-1;
m=unique(ty+1,ty+cnty+1)-ty-1;
x[0]=lower_bound(tx+1,tx+n+1,0ll)-tx;
y[0]=lower_bound(ty+1,ty+m+1,0ll)-ty;
for(int i=1;i<=q;i++){
x[i]=lower_bound(tx+1,tx+n+1,x[i])-tx;
y[i]=lower_bound(ty+1,ty+m+1,y[i])-ty;
if(x[i-1]==x[i]) for(int j=min(y[i-1],y[i]);j<=max(y[i-1],y[i]);j++) vis[x[i]][j]=2;
else for(int j=min(x[i-1],x[i]);j<=max(x[i-1],x[i]);j++) vis[j][y[i]]=2;
}
dfs(1,1);
for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(vis[i][j]!=1) ans+=(tx[i]-tx[i-1])*(ty[j]-ty[j-1]);
printf("%lld",ans);
return 0;
}//////