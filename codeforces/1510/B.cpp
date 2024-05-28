// LUOGU_RID: 159911860
#include<bits/stdc++.h>
#define ll long long
#define lll __int128
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll rint(ll l,ll r){return uniform_int_distribution<ll>(l,r)(rnd);}
const int maxn=1050,N=1<<11,M=2e5+10;
int d,n,a[maxn],h[maxn],S,T,cnt,fir[N],dis[N],pre[N],Flow,Cost,to[maxn];
bool ind[maxn];
deque<int> q;
struct edge
{
    int u,v,w,c,next,op;
}e[M];
void add_edge(int u,int v,int w,int c)
{
    cnt++,e[cnt].u=u,e[cnt].v=v,e[cnt].w=w,e[cnt].c=c,e[cnt].next=fir[u],fir[u]=cnt;
    cnt++,e[cnt].u=v,e[cnt].v=u,e[cnt].w=0,e[cnt].c=-c,e[cnt].next=fir[v],fir[v]=cnt;
    e[fir[u]].op=fir[v],e[fir[v]].op=fir[u];
}
bool spfa()
{
    memset(dis+1,0x3f,sizeof(dis[1])*T),dis[S]=0,q.push_back(S),pre[T]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop_front();
        for(int i=fir[x];i;i=e[i].next)
        {
            if(e[i].w&&dis[e[i].v]>dis[x]+e[i].c)
            {
                dis[e[i].v]=dis[x]+e[i].c,pre[e[i].v]=i;
                if(q.empty()==0&&dis[e[i].v]<=dis[q.front()]) q.push_front(e[i].v);
                else q.push_back(e[i].v);
            }
        }
    }
    return pre[T];
}
void dfs()
{
    int x=T,mf=1e9;
    while(x!=S) mf=min(mf,e[pre[x]].w),x=e[pre[x]].u;
    Flow+=mf,Cost+=mf*dis[T],x=T;
    while(x!=S) e[pre[x]].w-=mf,e[e[pre[x]].op].w+=mf,x=e[pre[x]].u;
}
void dinic()
{
    while(spfa()) dfs();
}
int read2()
{
    int res=0,bas=1;
    char cr=getchar();
    while(cr!='0'&&cr!='1') cr=getchar();
    while(cr=='0'||cr=='1') res=res+(cr-'0')*bas,bas<<=1,cr=getchar();
    return res;
}
int main()
{
//	freopen("1.in","r",stdin);
//	freopen(".out","w",stdout);
    scanf("%d%d",&d,&n);
    for(int i=1;i<=n;i++) a[i]=read2(),h[a[i]]=i;
    S=(n<<1)+1,T=S+1;
    for(int i=1;i<=n;i++)
    {
        add_edge(S,i,1,__builtin_popcount(a[i]));
        add_edge(i,T,1,1);
        add_edge(i+n,T,1,0);
        for(int j=(a[i]-1)&a[i];j;j=(j-1)&a[i])
            if(h[j])
                add_edge(h[j],i+n,1,-__builtin_popcount(j));
    }
    dinic();
    for(int i=1;i<=cnt;i++)
        if(e[i].u<=n&&n<e[i].v&&e[i].v<=(n<<1)&&e[i].w==0)
            to[e[i].u]=e[i].v-n,ind[e[i].v-n]=1;
    printf("%d\n",Cost-1);
    bool flag=0;
    for(int i=1;i<=n;i++)
    {
        if(!ind[i])
        {
            if(flag) printf("R ");
            flag=1;
            int x=i,las=0;
            while(x)
            {
                for(int j=0;j<d;j++)
                    if((((las>>j)&1)==0)&&((a[x]>>j)&1))
                        printf("%d ",j);
                las=a[x],x=to[x];
            }
        }
    }
	return 0;
}
