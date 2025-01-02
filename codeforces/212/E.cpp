#include <bits/stdc++.h>
using namespace std;
vector<int> Map[5003];
int n, x, y, sontree[5003], cnt, ans[5003];
bool dp[5003], mark[5003];

void dfs(int x, int fa){
	sontree[x]=1;
	for(int i=0;i<Map[x].size();i++){
		if(Map[x][i]==fa)continue;
		dfs(Map[x][i],x);
		sontree[x]+=sontree[Map[x][i]];
	}
}

void treedp(int x){
	for(int i=0;i<Map[x].size();i++){
		for(int j=n-1;j>=sontree[Map[x][i]];j--)dp[j]|=dp[j-sontree[Map[x][i]]];
	}
}

int main() {
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		Map[x].push_back(y);
		Map[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		memset(sontree,0,sizeof sontree);
		memset(dp,0,sizeof dp);
		dp[0]=1;
		dfs(i,0);
		treedp(i);
		for(int j=1;j<=n-2;j++){
			if(dp[j]==true)mark[j]=true;
		}
	}
	for(int i=1;i<=n-2;i++){
		if(mark[i]==true)ans[++cnt]=i;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++){
		printf("%d %d\n",ans[i],n-1-ans[i]);
	}
	return 0;
}
       	 		 				     		 		 		