// LUOGU_RID: 160423316
#include<bits/stdc++.h>
using namespace std;
const int N=10005; 
const int inf=1e9+7;
int n,m;
int cnt=1;
int fir[N],nex[50*N],to[50*N];
long long w[50*N];
long long ww[50*N];
long long dis[N],h[N];
bool vis[N];
struct edge
{
    int u,id;
}pre[N];
int dd[N],s,t;
long long ans=0;
void insert(int u,int v,int c,long long cc)
{
	nex[++cnt]=fir[u];
	fir[u]=cnt;
	to[cnt]=v;
	w[cnt]=c;
	ww[cnt]=cc;
}
void add(int u,int v,int c,long long ww)
{
	insert(u,v,c,ww);
	insert(v,u,0,-ww);
	//cerr<<u<<' '<<v<<' '<<c<<"\n";
	
}
 void spfa()
 {
     memset(vis,0,sizeof(vis));
     memset(h,63,sizeof(h));
     queue<int>q;
     q.push(s);
     h[s]=0;
     while(!q.empty())
     {
         int u=q.front();
         q.pop();
         vis[u]=0;
         //cerr<<u<<"??\n";
         for(int i=fir[u];i;i=nex[i])
         {
             int v=to[i];
			 long long c=ww[i];
             //cerr<<ww[i]<<"???\n";
             if(w[i]&&h[v]>h[u]+c)
             {
                 h[v]=h[u]+c;
                 if(vis[v]==0)
                 {
                     vis[v]=1;
                     q.push(v);
                 }
             }
         }
     }
 }
bool dij()
{
    for(int i=s;i<=t;i++)dis[i]=inf;
    memset(vis,0,sizeof(vis));
    priority_queue<pair<int,int > ,vector<pair<int,int> >,greater<pair<int,int> > >q;
    q.push({0,s});
    dis[s]=0;

    while(!q.empty())
    {
        
        int u=q.top().second;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int i=fir[u];i;i=nex[i])
        {
            int v=to[i],c=ww[i]+h[u]-h[v];
            //cerr<<dis[v]<<' '<<c<<"??\n";
            
            if(w[i]&&dis[v]>dis[u]+c)
            {

                dis[v]=dis[u]+c;
                pre[v]={u,i};
                if(!vis[v])q.push({dis[v],v});
            }
        }
    }
    //cerr<<dis[t]<<"??\n";
    return dis[t]!=inf;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v,c,f;
		cin>>u>>v>>c>>f;
		dd[u]+=f;
		dd[v]-=f;
		if(f<=c)
		{
			add(v,u,f,1);
			add(u,v,c-f,1);
			
		}
		else
		{
			ans+=f-c;
			add(v,u,f-c,0);
			add(v,u,c,1);

		}
        add(u,v,inf,2);
	}
	
	t=(n+1);
	add(n,1,inf,0);
//	cerr<<s<<' '<<t<<"??\n";
	for(int i=1;i<=n;i++)
	{
		if(dd[i]>0)
		{
			add(i,t,dd[i],0);
		}
		else if(dd[i]<0)
		{
			add(s,i,-dd[i],0);
		}
	}
	spfa();
	while(dij())
    {
        //cerr<<"??\n";
        for(int i=s;i<=t;i++)
        {
            h[i]+=dis[i];
        }
        long long flow=inf;
        for(int u=t;u!=s;u=pre[u].u)
        {
            flow=min(flow,w[pre[u].id]);
            //cerr<<u<<' '<<pre[u].id<<"??\n";
        }
        for(int u=t;u!=s;u=pre[u].u)
        {
            w[pre[u].id]-=flow;
            w[pre[u].id^1]+=flow;
        }
        //cerr<<flow<<"??\n";
        ans+=h[t]*flow;
    }
    cout<<ans;
} 