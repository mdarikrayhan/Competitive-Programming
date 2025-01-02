#include<iostream>
#include<cstdio>
#include<cstring>
#define N 210
#define M 50010
using namespace std;
int n,m,q,cnt,tot;
int head[M],a[M],b[M];
int c[N][N],id[N][N],nxt[M][12];
bool vis[N][N];
void dfs(int x,int y){
vis[x][y]=true;
int dx=x+a[c[x][y]],dy=y+b[c[x][y]];
if(dx<1||dx>n||dy<1||dy>m)dx=x,dy=y;
nxt[id[x][y]][c[x][y]]=id[dx][dy];
if(!vis[dx][dy])dfs(dx,dy);
for(int i=0;i<=9;i++)
if(i!=c[x][y])
nxt[id[x][y]][i]=nxt[id[dx][dy]][i];
}
int main(){
scanf("%d%d%d",&n,&m,&q);
for(int i=1;i<=n;i++){
char s[300];scanf("%s",s+1);
for(int j=1;j<=m;j++)
id[i][j]=++cnt,c[i][j]=s[j]-'0';
}
for(int i=0;i<=9;i++)scanf("%d%d",&a[i],&b[i]);
for(int i=1;i<=n;i++)
for(int j=1;j<=m;j++)
if(!vis[i][j]){
head[++tot]=id[i][j];
dfs(i,j);
}
while(q--){
char s[1000001];
scanf("%s",s+1);int len=strlen(s+1);
bool flag=false;
for(int i=1;i<=tot;i++){
int now=nxt[head[i]][s[1]-'0'],l=0;
while(l<len&&now!=0)
l++,now=nxt[now][s[l+1]-'0'];
if(l==len){
flag=true;break;
}
}
puts(flag?"YES":"NO");
}
return 0;
}