#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define pb push_back
#define R(i,l,r)for(int i=l;i<r;i++)
struct P{long long x,y;int id;}p[1600],s;
int i,n,u,v,ans[2000],S[2000],A[2000];vector<int>E[2000];
bool cmp(P a,P b){return(a.x-s.x)*(b.y-s.y)-(b.x-s.x)*(a.y-s.y)<0;}
int dfs(int u,int f){S[u]=1;R(j,0,E[u].size())if(E[u][j]!=f)
S[u]+=dfs(E[u][j],u);return S[u];}
void dfs2(int u,int f,int l){
s=p[l];ans[u]=l;R(j,l+1,l+S[u])
if(p[j].x<s.x||(p[j].x==s.x&&p[j].y<s.y))s=p[j],ans[u]=j;
swap(p[l],p[ans[u]]);ans[u]=p[l].id;sort(p+l+1,p+l+S[u],cmp);
R(j,0,E[u].size())if(E[u][j]!=f)dfs2(E[u][j],u,l+1),l+=S[E[u][j]];
}
int main(){
scanf("%d",&n);R(i,1,n)scanf("%d%d",&u,&v),E[--u].pb(--v),E[v].pb(u);
R(i,0,n)scanf("%I64d%I64d",&p[i].x,&p[i].y),p[i].id=i;
dfs(0,-1);dfs2(0,-1,0);R(i,0,n)A[ans[i]]=i;
R(i,0,n)printf("%d\n",A[i]+1);
}