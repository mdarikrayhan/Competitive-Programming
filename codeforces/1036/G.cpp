#include <bits/stdc++.h>
const int N=1000005;
std::vector<int> e[N];
int a[N],n,m,x,y,r[N],c[N],id[N],cnt,cnt2,s[N],vis[N];
void dfs(int x){
	if (vis[x]) return;
	vis[x]=1;
	for (auto u:e[x]){
		dfs(u);
		a[x]|=a[u];
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		r[y]++;c[x]++;
	}
	for (int i=1;i<=n;i++)
		if (!c[i]) a[i]=1<<cnt,id[i]=cnt++;
	for (int i=1;i<=n;i++)
		if (!r[i]){
			dfs(i);
			s[cnt2++]=a[i];
		}
	for (int i=1;i<(1<<cnt)-1;i++){
		int t=0,S=0,t2=0;
		for (int j=0;j<cnt;j++)
			if (i&(1<<j)) t++,S|=s[j];
		for (int j=0;j<cnt;j++)
			if (S&(1<<j)) t2++;
		if (t2<=t){
			puts("NO");
			return 0;
		}
	}	
	puts("YES");
	return 0;		
}