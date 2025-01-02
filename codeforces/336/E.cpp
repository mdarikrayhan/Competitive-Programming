#include<cstdio>
#include<cstdlib>
#define LL long long
using namespace std;
const LL pri=1000000007;
int C[205][205],n,m;
LL f[205][205][5];
LL dfs(int x,int y,int z)
{
if(z*(3*x-2)<y)return 0;
if(!y)return 1;
if(y<0)return 0;
LL&ret=f[x][y][z];
if(ret)return ret;
for(int i=0;i<=y;i++)
for(int j=0;j<=z-(z!=4)&&j<=i;j++)
ret=(ret+dfs(x-1,y-i,z)*C[3*z-2*j][i-j]*C[z-(z!=4)][j])%pri;
if(z==1)
return ret=ret+(y==1);
if(z==2)
return ret=(ret+dfs(x,y-1,1)*2-(y==2)+(y==1))%pri;
if(z==3)
{
ret=ret+dfs(x,y-1,2)*2;
for(int i=0;i<y;i++)
ret=(ret+(LL)dfs(x,i,1)*dfs(x,y-1-i,1))%pri;
ret=ret-dfs(x,y-2,1)*3+pri*3+(y==3);
ret=(ret+dfs(x,y-1,1)*2+pri-(y==2)*2)%pri;
}
if(z==4)
{
ret=ret+dfs(x,y-1,3)*4-dfs(x,y-2,2)*4;
for(int i=0;i<y-1;i++)
ret=ret-(LL)dfs(x,i,1)*dfs(x,y-2-i,1)*2%pri+pri;
ret=ret+dfs(x,y-3,1)*4-(y==4)+pri+(y==3)*4;
ret=(ret+dfs(x,y-1,2)*4-dfs(x,y-2,1)*8-(y==2)*2+pri*8)%pri;
}
return ret;
}
int main()
{
for(int i=0;i<=12;i++)
{
C[i][0]=1;
for(int j=1;j<=i;j++)
C[i][j]=C[i-1][j]+C[i-1][j-1];
}
scanf("%d%d",&n,&m);
int q=dfs(n+1,m,4);
for(int i=2;i<=m;i++)
q=(LL)q*i%pri;
printf("%d\n",q);
}