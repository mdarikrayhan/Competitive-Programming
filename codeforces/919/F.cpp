// LUOGU_RID: 160069399
#include<bits/stdc++.h>
using namespace std;
const int NN=504;
map<vector<int>,int>mp;
vector<int>id[NN],now;
vector<pair<int,int> >g[NN][NN];
int du[NN][NN],ans[NN][NN],idx;
void dfs(int u,int cnt)
{
	if(u==5)
	{
		if(cnt)
			return;
		mp[now]=++idx;
		id[idx]=now;
		return;
	}
	for(int i=0;i<=cnt;i++)
	{
		now.push_back(i);
		dfs(u+1,cnt-i);
		now.pop_back();
	}
}
int main()
{
	dfs(0,8);
	for(int i=1;i<=idx;i++)
		for(int j=1;j<=idx;j++)
			for(int k=1;k<5;k++)
				for(int l=1;l<5;l++)
					if(id[i][k]&&id[j][l])
					{
						vector<int>t=id[i];
						t[(k+l)%5]++,t[k]--;
						g[j][mp[t]].push_back({i,j});
						du[i][j]++;
					}
	vector<int>t;
	t.resize(5);
	t[0]=8;
	queue<pair<int,int> >q;
	for(int i=1;i<=idx;i++)
		if(i!=mp[t])
		{
			ans[mp[t]][i]=1;
			ans[i][mp[t]]=2;
			q.push({mp[t],i});
			q.push({i,mp[t]});
		}
	while(q.size())
	{
		pair<int,int>u=q.front();
		q.pop();
		for(int i=0;i<g[u.first][u.second].size();i++)
		{
			pair<int,int>v=g[u.first][u.second][i];
			if(ans[v.first][v.second])
				continue;
			if(ans[u.first][u.second]==2)
			{
				ans[v.first][v.second]=1;
				q.push(v);
			}
			else
			{
				du[v.first][v.second]--;
				if(!du[v.first][v.second])
				{
					ans[v.first][v.second]=2;
					q.push(v);
				}
			}
		}
	}
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int w;
		scanf("%d",&w);
		vector<int>cnt[2];
		cnt[0].resize(5),cnt[1].resize(5);
		for(int i=1;i<=8;i++)
		{
			int x;
			scanf("%d",&x);
			cnt[0][x]++;
		}
		for(int i=1;i<=8;i++)
		{
			int x;
			scanf("%d",&x);
			cnt[1][x]++;
		}
		char str[3][14]={"Deal\n","Alice\n","Bob\n"};
		if(w==1)
			swap(str[1],str[2]),swap(cnt[0],cnt[1]);
		printf(str[ans[mp[cnt[0]]][mp[cnt[1]]]]);
	}
	return 0;
}