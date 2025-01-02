#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+10;
ll down1[maxn],down2[maxn],path[maxn],ans;
vector<int> e[maxn];
int n,a[maxn];
void dfs(int cur, int pr)
{
    down1[cur]=path[cur]=a[cur];
    ll bestpathsofar=0;
    for(int x:e[cur])
    {
	    if(x!=pr)
	    {
	        dfs(x,cur);
	        ans=max({ans,path[cur]+path[x],down2[x]+down1[cur],down1[x]+down2[cur]});
	        down2[cur]=max({down2[cur],down2[x]+a[cur],path[x]+down1[cur],bestpathsofar+down1[x]+a[cur]});
	        path[cur]=max({path[cur],path[x],down1[cur]+down1[x]});
	        bestpathsofar=max(bestpathsofar,path[x]);
	        down1[cur]=max(down1[cur],down1[x]+a[cur]);
	    }
	}
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y),x--,y--,e[x].push_back(y),e[y].push_back(x);
    }
    dfs(0,-1);
    printf("%lld\n",ans);
    return 0;
}