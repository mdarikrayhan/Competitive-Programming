#include<bits/stdc++.h>
#define id(x,y) ((x)*m-m+(y))
using namespace std;
const int N=2e5+5,M=4e5+5,T=2e6+5;
int dx[4]={1,-1,1,-1},dy[4]={1,1,-1,-1};
int n,m;char*s[N];
int L,R,stk[T],dis[M],from[M];
void ins(int x,int y,int k1){
if(x<1||x>n||y<1||y>m||(y>1&&s[x][y-1])||(y<m&&s[x][y+1])||
(x>1&&s[x-1][y])||(x<n&&s[x+1][y])||dis[id(x,y)]!=1e9)return;
int t=s[x][y]?--L:++R,k=id(x,y);
dis[k]=dis[from[stk[t]=k]=k1]+(!s[x][y]);
}
void xxx(){
scanf("%d%d",&n,&m);
for(int i=1;i<=n;i++){
s[i]=new char[m+5];
scanf("%s",s[i]+1);
for(int j=1;j<=m;j++){
s[i][j]=s[i][j]=='#';
int t=id(i,j);
dis[t]=1e9,from[t]=0;
}
}
int p=1;R=1e6;L=R+1;
for(int i=1;i<=n;i++)ins(i,1,0);
while(L<=R){
int k=stk[L++],x=(k-1)/m+1,y=k-x*m+m;
for(int o=0;o<4;o++)
ins(x+dx[o],y+dy[o],k);
}
for(int i=1;i<=n;i++)
if(dis[id(p,m)]>dis[id(i,m)])p=i;
if(dis[id(p,m)]==1e9){puts("NO");return;}
for(int k=id(p,m);k;){
int x=(k-1)/m+1,y=k-x*m+m;
s[x][y]=1;k=from[k];
}
puts("YES");
for(int i=1;i<=n;i++){
for(int j=1;j<=m;j++)
s[i][j]=s[i][j]?'#':'.';
printf("%s\n",s[i]+1);
delete s[i];
}
}
int main(){
int T;scanf("%d",&T);for(;T--;)
xxx();return 0;
}