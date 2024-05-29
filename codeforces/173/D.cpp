#include<bits/stdc++.h>
using namespace std;int n,m,k,q=2,h[100007],vis[100007],col[100007];vector<int>v[3],v2[3],G[100007];
void dfs(int x){
	v[col[x]].push_back(x);
	for(int i=0;i<G[x].size();++i)if(!col[G[x][i]])col[G[x][i]]=3-col[x],dfs(G[x][i]);
}
void findx(int x){
	memset(vis,0,sizeof(vis));for(int i=0;i<G[x].size();++i)vis[G[x][i]]=1;h[x]=(++q)/3;
	for(int i=1;i<=n;++i)if(!vis[i]&&col[x]+col[i]==3){h[i]=(++q)/3;if(q%3==2)return;}
}
int main(){
	scanf("%d%d",&n,&m);for(int x,y;m;m--)scanf("%d%d",&x,&y),G[x].push_back(y),G[y].push_back(x);
	for(int i=1;i<=n;++i)if(!col[i])col[i]=1,dfs(i);
	for(int i=1;i<=n;++i)if(G[i].size()<v[col[i]^3].size()-1)v2[col[i]].push_back(i);
	if(v[1].size()%3){k=v[1].size()%3;if(v2[k].size()>0)findx(v2[k][0]);
	else if(v2[k^3].size()>1)findx(v2[k^3][0]),findx(v2[k^3][1]);else{puts("NO");return 0;}}
	for(int j=1;j<3;++j)for(int i=1;i<=n;++i)if(!h[i]&&col[i]==j)h[i]=(++q)/3;
	puts("YES");for(int i=1;i<=n;++i)printf("%d ",h[i]);
}