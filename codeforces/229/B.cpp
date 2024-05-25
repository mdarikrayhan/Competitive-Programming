#include<bits/stdc++.h>
using namespace std;
map<int,bool> mp1[100010];
int n,m;
vector<pair<int,int>> mp[100010];
void add(int u,int v,int w)
{
    mp[u].push_back(make_pair(v,w));
}
int dis[100010];
bool vis[100010];
void spfa()
{
    for(int i=0;i<=n;i++)
    {
        dis[i]=2e9;
    }
    deque<int> q;
    q.push_back(1);
    dis[1]=0;
    while(!q.empty())
    {
        int t=q.front();
        q.pop_front();
        vis[t]=0;
        int d=dis[t];
        while(mp1[t][d])
        {
            d++;
        }
        for(auto i:mp[t])
        {
            int v=i.first,val=i.second;
            if(dis[v]>d+val)
            {
                dis[v]=d+val;
                if(!vis[v])
                {
                    vis[v]=1;
                    if(!q.empty()&&dis[v]<=dis[q.front()])
                    {
                        q.push_front(v);
                    }
                    else
                    {
                        q.push_back(v);
                    }
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    for(int i=1;i<=n;i++)
    {
        int c;
        scanf("%d",&c);
        for(int j=1;j<=c;j++)
        {
            int x;
            scanf("%d",&x);
            mp1[i][x]=1;
        }
    }
    spfa();
    if(dis[n]==dis[0])
    {
        printf("-1");
    }
    else
    {
        printf("%d",dis[n]);
    }
    return 0;
}
	   	  		     	 		   	 					  	