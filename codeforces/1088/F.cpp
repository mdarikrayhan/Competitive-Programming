// LUOGU_RID: 160484559
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define rpe(i,x) for(int i=_he[x];i;i=_ne[i])
using namespace std;
typedef long long LL;
typedef pair<LL,int>pli;
const int N=5e5+10,MOD=998244353;
const LL INF=0x3f3f3f3f3f3f3f3f;

int _ve[N<<1],_ne[N<<1],_he[N],_tot;
void _add(int x,int y){_ve[++_tot]=y,_ne[_tot]=_he[x],_he[x]=_tot;}
int fa[20][N],n;
LL a[N],ans;
pli root={INF,0};

void dfs(int x,int fat)
{
	rpe(i,x)
	{
		int y=_ve[i];if(y==fat)continue;
		fa[0][y]=x;
		rep(j,1,19)fa[j][y]=fa[j-1][fa[j-1][y]];
		LL tmp=INF;
		rep(j,0,19)
		{
			int gf=fa[j][y]?fa[j][y]:root.second;
			tmp=min(tmp,a[gf]*(j+1));
		}
		ans+=tmp+a[y];
		dfs(y,x);
	}
}


int main()
{
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",&a[i]),root=min(root,{a[i],i});
	for(int i=2,x,y;i<=n;i++)scanf("%d%d",&x,&y),_add(x,y),_add(y,x);
	dfs(root.second,0);
	printf("%lld\n",ans);
	return 0;
}