#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
#define maxn 200005
using namespace std;

int S,N,M,X,Y,a[305][305],b[305][305],c[maxn],p[605][605];
struct st
{
 int x,y,c;
 st(int _x=0,int _y=0,int _c=0) {x=_x,y=_y,c=_c;}
 bool operator <(const st&B) const {return p[x-X+N][y-Y+M]<p[B.x-X+N][B.y-Y+M];}
} q[maxn];
vector<st> V[maxn];
map<int,int> BG;

void init()
{
 scanf("%d%d",&N,&M),BG[0]=S=1;
 for (int i=1; i<=N; i++)
  for (int j=1,k; j<=M; j++) scanf("%d",&k),a[i][j]=(BG[k]?BG[k]:BG[k]=++S),c[a[i][j]]++;
 for (int i=1; i<=N; i++)
  for (int j=1,k; j<=M; j++)
  {
   scanf("%d",&k);
   if (k>-1) b[i][j]=(BG[k]?BG[k]:BG[k]=++S),V[a[i][j]].push_back(st(i,j,b[i][j]));
  }
 scanf("%d%d",&X,&Y),p[N][M]=1;
 for (int i=2,x=N-1,y=M-1,k=1; i<=600; i+=2,x--,y--)
 {
  for (int j=0; j<i; j++) p[x][++y]=++k;
  for (int j=0; j<i; j++) p[++x][y]=++k;
  for (int j=0; j<i; j++) p[x][--y]=++k;
  for (int j=0; j<i; j++) p[--x][y]=++k;
 }
}

void doit()
{
 long long ans=0;
 q[1]=st(X,Y,b[X][Y]);
 for (int l=1,r=1,k=a[X][Y],u; l<=r; l++,k=u) if (k>1&&(u=q[l].c)!=k&&c[k])
 {
  c[u]+=c[k],ans+=c[k],c[k]=0;
  X=q[l].x,Y=q[l].y,sort(V[k].begin(),V[k].end());
  for (st i:V[k]) q[++r]=i;
  V[k].clear();
 }
 printf("%I64d\n",ans);
}

int main()
{
 init();
 doit();
 return 0;
}