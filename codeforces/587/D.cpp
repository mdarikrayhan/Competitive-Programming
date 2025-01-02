// LUOGU_RID: 160506344
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=4e5+10;
int n,m;
bool flag=1;
unordered_map<int,int>mp[N];
struct node{
    int u,v,c,t,id;
}bg[N];
int cnt[N];
bool vis[N],vis2[N];
vector<int>res;
vector<int>tmp[N],to[N];
int deg[N],tot;
void add(int u,int v){
    to[u].push_back(v);
}
int dfn[N],low[N],Col,col[N],tot2;
int stk[N],cnt2;
bool instk[N];
void tarjan(int u)
{
	dfn[u]=low[u]=++tot2;
	stk[++cnt2]=u;instk[u]=1;
	for(int v:to[u])
	{
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		if(instk[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		int x,c=++Col;
		do
		{
			x=stk[cnt2--];
			col[x]=c;
			instk[x]=0;
		}while(x!=u);
	}
}
bool check(int x){
    memset(vis2,0,sizeof vis2);
    memset(deg,0,sizeof deg);
    memset(dfn,0,sizeof dfn);
    res.clear();
    for(int i=1;i<=tot;i++)to[i].clear(),tmp[i].clear();
    tot=2*m;tot2=cnt2=0;
    for(int i=1;i<=m;i++){
        if(bg[i].t>x)continue;
        int u=bg[i].u,v=bg[i].v;
        if((mp[u][bg[i].c]>1&&mp[v][bg[i].c]>1)||(mp[u][bg[i].c]>1&&!vis[v])||(mp[v][bg[i].c]>1&&!vis[u]))
        {
            vis2[bg[i].id]=1;
            tmp[u].push_back(bg[i].id);
            tmp[v].push_back(bg[i].id);
            deg[u]++;deg[v]++;
        }
    }
    for(int u=1;u<=n;u++){
        if(vis[u]){
            if(tmp[u].size()==0)return 0;
            else if(tmp[u].size()==1)add(tmp[u][0]+m,tmp[u][0]);
            else{
                add(tmp[u][1]+m,tmp[u][0]);
                add(tmp[u][0]+m,tmp[u][1]);
            }
        }
        int len=tmp[u].size();tot++;
        for(int i=0;i<len;i++)
        {
            add(tmp[u][i],tot);
            add(tot+1,tot);
            add(tot+1,tmp[u][i]+m);
            tot++;
        }
        tot++;
        for(int i=len-1;i>=0;i--)
        {
            add(tmp[u][i],tot);
            add(tot+1,tot);
            add(tot+1,tmp[u][i]+m);
            tot++;
        }
    }
    for(int i=1;i<=tot;i++)
        if(!dfn[i])tarjan(i);
    for(int i=1;i<=m;i++)if(col[i]==col[i+m])return 0;
	for(int i=1;i<=m;i++)
		if(col[i]<col[i+m]&&vis2[i])
			res.push_back(i);
    return 1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v,c,t;
        scanf("%d%d%d%d",&u,&v,&c,&t);
        bg[i]={u,v,c,t,i};
        mp[u][c]++,mp[v][c]++;
        if(mp[u][c]>=2)cnt[u]++;
        if(mp[v][c]>=2)cnt[v]++;
    }
    for(int i=1;i<=n;i++)
        if(cnt[i]>=2)flag=0;
        else if(cnt[i])vis[i]=1;
    if(!flag)
    {
        printf("No\n");
        return 0;
    }
    int l=0,r=1e9+1;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    if(l==1e9+1){
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    check(l);
    printf("%d %d\n",l,(int)res.size());
    for(int x:res)
        printf("%d ",x);
    return 0;
}