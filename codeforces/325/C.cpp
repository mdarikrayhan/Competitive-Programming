#include<bits/stdc++.h>
#define int long long
#define inf 314000000LL
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int tsl[100005],fsl[100005];
int zy[100005];
vector<int>v[100005];
vector<int>cx[100005];
int rd[100005];
int mind[100005],maxd[100005];
priority_queue<pair<int,int> >pq;
queue<int>que;
bool bk[100005];
signed main()
{
	int n,m,x,y;
	m=read();
	n=read();
	for(int i=1;i<=m;i++)
	{
		zy[i]=read();
		rd[zy[i]]++;
		x=read();
		for(int j=1;j<=x;j++)
		{
			y=read();
			if(y!=-1)tsl[i]++;
			else fsl[i]++;
			v[i].push_back(y);
			if(y!=-1)cx[y].push_back(i); 
		}
	}
	for(int i=1;i<=n;i++)mind[i]=2*inf;
	for(int i=1;i<=m;i++)if(tsl[i]==0)
	{
		if(fsl[i]<mind[zy[i]])
		{ 
			mind[zy[i]]=fsl[i];
			pq.push(make_pair(-mind[zy[i]],zy[i]));
		}
	}
	while(!pq.empty())
	{
		x=pq.top().second;
		//printf("%lld %lld %lld\n",pq.top().first,mind[x],pq.top().second);
		if(mind[x]!=-pq.top().first)
		{
			pq.pop();
			continue;
		}
		pq.pop();
		for(int j=0;j<cx[x].size();j++)
		{
			tsl[cx[x][j]]--;
			fsl[cx[x][j]]+=mind[x];
			fsl[cx[x][j]]=min(fsl[cx[x][j]],inf);
			if(tsl[cx[x][j]]==0)
			{
				if(fsl[cx[x][j]]<mind[zy[cx[x][j]]])
				{
					mind[zy[cx[x][j]]]=fsl[cx[x][j]];
					pq.push(make_pair(-mind[zy[cx[x][j]]],zy[cx[x][j]]));
				}
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		tsl[i]=0;
		fsl[i]=0;
		for(int j=0;j<v[i].size();j++)
		{
			if(v[i][j]!=-1)tsl[i]++;
			else fsl[i]++;
		}
		//printf("%lld %lld %lld\n",i,tsl[i],fsl[i]);
		if(tsl[i]==0)
		{
			maxd[zy[i]]=max(maxd[zy[i]],fsl[i]);
			rd[zy[i]]--;
		}
	}
	for(int i=1;i<=m;i++)
	{
		bool flag=false;
		for(int j=0;j<v[i].size();j++)
		{
			if(v[i][j]!=-1&&mind[v[i][j]]>inf)flag=true;
		}
		if(flag==true)
		{
			rd[zy[i]]--;
			bk[i]=true;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(mind[i]>inf)continue;
		if(rd[i]==0)
		{
			que.push(i);
		}
	}
	while(!que.empty())
	{
		x=que.front();
		que.pop();
		for(int j=0;j<cx[x].size();j++)
		{
			if(bk[cx[x][j]])continue;
			tsl[cx[x][j]]--;
			fsl[cx[x][j]]+=maxd[x];
			fsl[cx[x][j]]=min(fsl[cx[x][j]],inf);
			if(tsl[cx[x][j]]==0)
			{
				maxd[zy[cx[x][j]]]=max(fsl[cx[x][j]],maxd[zy[cx[x][j]]]);
				rd[zy[cx[x][j]]]--;
				if(rd[zy[cx[x][j]]]==0&&mind[zy[cx[x][j]]]<=inf)que.push(zy[cx[x][j]]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(mind[i]>inf)
		{
			printf("-1 -1\n");
			continue;
		}
		if(rd[i]>0)
		{
			printf("%lld -2\n",mind[i]);
			continue;
		}
		printf("%lld %lld\n",mind[i],maxd[i]);
	}
}