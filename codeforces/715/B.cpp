// LUOGU_RID: 159979088
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,int> PLI;
constexpr int N=1005,M=20005;
constexpr LL INF=1e18;

int n,m,s;
int he[N],ne[M],to[M];
LL co[M],dis[N];

void add(int a,int b,LL c,int idx)
{
    to[idx]=b,co[idx]=c;
    ne[idx]=he[a],he[a]=idx;
}

void dijkstra(int s)
{
    static priority_queue<PLI,vector<PLI>,greater<PLI>> q;
    for(int i=0;i<n;i++)dis[i]=i==s?0:INF;
    q.push({0,s});
    while(!q.empty())
    {
        auto [d,u]=q.top();q.pop();
        if(d>dis[u])continue;
        for(int i=he[u],v=to[i];i;i=ne[i],v=to[i])
            if(dis[v]>d+co[i])q.push({dis[v]=d+co[i],v});
    }
}

void print()
{
    puts("YES");
    for(int i=1;i<=m;i++)printf("%d %d %lld\n",to[i<<1|1],to[i<<1],co[i<<1]);
}

int main()
{
    int l,s,t;
    scanf("%d%d%d%d%d",&n,&m,&l,&s,&t);
    for(int i=1;i<=m;i++)
    {
        int a,b;LL c;
        scanf("%d%d%lld",&a,&b,&c);
        if(!c)c=INF;
        add(a,b,c,i<<1),add(b,a,c,i<<1|1);
    }

    dijkstra(s);
    if(dis[t]<l)return puts("NO"),0;
    if(dis[t]==l)return print(),0;

    for(int i=1;i<=m;i++)
    {
        if(co[i<<1]!=INF)continue;
        co[i<<1]=co[i<<1|1]=1;
        dijkstra(s);
        if(dis[t]>l)continue;
        co[i<<1]=co[i<<1|1]=l-dis[t]+1;
        return print(),0;
    }
    puts("NO");

    return 0;
}