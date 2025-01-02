#include<bits/stdc++.h>
using namespace std;
typedef long double db;
const db eps=1e-10;
const int mod=998244353;
struct Query{int h,x,id;}Q[100005];
struct point{db x,y,z;}a[100005];
vector<int> g[100005],trian[100005];
int n,m,q,fa[100005],pl[100005],X[100005],Y[100005],Z[100005];
int act[100005];
db sk[100005][3],ans[100005],lstk[100005][3];
point operator *(point x,point y){
return (point){x.y*y.z-x.z*y.y,x.x*y.z-y.x*x.z,x.x*y.y-x.y*y.x};
}
db len(point a){
return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}
point operator -(point x,point y){
return (point){x.x-y.x,x.y-y.y,x.z-y.z};
}
db Area(point a,point b,point c){
return len((b-a)*(c-a));
}
int gf(int x){
return x==fa[x]?x:fa[x]=gf(fa[x]);
}
void Merge(int x,int y){
x=gf(x),y=gf(y);
if(x==y)return ;
fa[y]=x,sk[x][0]+=sk[y][0],sk[x][1]+=sk[y][1],sk[x][2]+=sk[y][2];
}
int main(){
scanf("%d",&n);
for(int i=1;i<=n;i++){
db x,y,z;
scanf("%Lf%Lf%Lf",&x,&y,&z);
a[i]={x,y,z},pl[i]=i,fa[i]=i;
}
scanf("%d",&m);
for(int i=1,x,y,z;i<=m;i++){
scanf("%d%d%d",&x,&y,&z);
if(a[x].z>a[z].z+eps||(fabs(a[x].z-a[z].z)<eps&&x>z))swap(x,z);
if(a[y].z>a[z].z+eps||(fabs(a[y].z-a[z].z)<eps&&y>z))swap(y,z);
if(a[x].z>a[y].z+eps||(fabs(a[x].z-a[y].z)<eps&&x>y))swap(x,y);
trian[z].push_back(i);
trian[y].push_back(i);
trian[x].push_back(i);
X[i]=x,Y[i]=y,Z[i]=z;
g[x].push_back(y);
g[y].push_back(x);
g[x].push_back(z);
g[z].push_back(x);
g[y].push_back(z);
g[z].push_back(y);
}
scanf("%d",&q);
for(int i=1,x,y;i<=q;i++){
scanf("%d%d",&x,&y),Q[i]={x,y,i};
}
sort(pl+1,pl+n+1,[](int x,int y){return fabs(a[x].z-a[y].z)<eps?x>y:a[x].z>a[y].z;});
sort(Q+1,Q+q+1,[](Query x,Query y){return x.h>y.h;});
int j=1;
for(int i=1;i<=n;i++){
int x=pl[i];
while(j<=q&&Q[j].h>=a[x].z-eps){
//cout<<"PP:"<<Q[j].id<<'\n';
if(a[Q[j].x].z<=Q[j].h+eps){
ans[Q[j].id]=-1,j++;
continue;
}
int p=gf(Q[j].x);
ans[Q[j].id]=sk[p][2]*Q[j].h*Q[j].h+sk[p][1]*Q[j].h+sk[p][0];
j++;
}
//cout<<"ACTIVATE"<<x<<'\n';
act[x]=1;
for(int y:g[x]){
if(!act[y])continue;
Merge(x,y);
}
int u=gf(x);
for(int id:trian[x]){
if(x==Z[id]){
if(fabs(a[x].z-a[Y[id]].z)<eps)continue;
db o=Area(a[X[id]],a[Y[id]],a[Z[id]])/(a[Z[id]].z-a[X[id]].z)/(a[Z[id]].z-a[Y[id]].z);
db p,q,r;
p=o;
q=-2*o*a[x].z;
r=o*a[x].z*a[x].z;
sk[u][2]+=p,sk[u][1]+=q,sk[u][0]+=r;
lstk[id][2]=p,lstk[id][1]=q,lstk[id][0]=r;
//printf("%d as Z\n",x);
}
if(x==Y[id]){
if(fabs(a[x].z-a[X[id]].z)<eps)continue;
sk[u][0]-=lstk[id][0],sk[u][1]-=lstk[id][1],sk[u][2]-=lstk[id][2];
db all=Area(a[X[id]],a[Y[id]],a[Z[id]]);
db o=all/(a[Z[id]].z-a[X[id]].z)/(a[Y[id]].z-a[X[id]].z);
db p,q,r;
p=-o;
q=2*o*a[X[id]].z;
r=all-o*a[X[id]].z*a[X[id]].z;
sk[u][2]+=p,sk[u][1]+=q,sk[u][0]+=r;
lstk[id][2]=p,lstk[id][1]=q,lstk[id][0]=r;
//printf("%d as Y\n",x);
//cout<<sk[u][2]<<' '<<sk[u][1]<<' '<<sk[u][0]<<' '<<all<<'\n';
}
if(x==X[id]){
sk[u][0]-=lstk[id][0],sk[u][1]-=lstk[id][1],sk[u][2]-=lstk[id][2];
db all=Area(a[X[id]],a[Y[id]],a[Z[id]]);
sk[u][0]+=all;
//printf("%d as X\n",x);
}
}
}
while(j<=q){
if(a[Q[j].x].z<=Q[j].h+eps){
ans[Q[j].id]=-1,j++;
continue;
}
int p=gf(Q[j].x);
ans[Q[j].id]=sk[p][2]*Q[j].h*Q[j].h+sk[p][1]*Q[j].h+sk[p][0];
j++;
}
for(int i=1;i<=q;i++){
if(ans[i]>-eps)printf("%.15Lf\n",ans[i]/2);
else puts("-1");
}
}