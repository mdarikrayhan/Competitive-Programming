// LUOGU_RID: 160013307
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int>ans,g[200001];
int w[200001],sum[200001];
int x[200001],y[200001];
int col[200001],vis[200001];
queue<int>q;
signed main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		cin>>x[i]>>y[i];
		sum[x[i]]++,sum[y[i]]++;
		g[x[i]].push_back(i);
		g[y[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(sum[i]<=w[i]){
			vis[i]=1;
			for(int j=0;j<g[i].size();j++){
				if(col[g[i][j]]==0){
					col[g[i][j]]=i,q.push(g[i][j]);
				}
			}
		}
	}
	int tot=0;
	while(!q.empty()){
		int i=q.front();
		q.pop();
		ans.push_back(i);
		tot++;
		if(col[i]==x[i]){
			sum[y[i]]--;
		}
		else if(col[i]==y[i]){
			sum[x[i]]--;
		}
		if(sum[x[i]]<=w[x[i]]&&vis[x[i]]==0){
			vis[x[i]]=1;
			for(int j=0;j<g[x[i]].size();j++){
				if(col[g[x[i]][j]]==0){
					col[g[x[i]][j]]=x[i],q.push(g[x[i]][j]);
				}
			}
		}
		if(sum[y[i]]<=w[y[i]]&&vis[y[i]]==0){
			vis[y[i]]=1;
			for(int j=0;j<g[y[i]].size();j++){
				if(col[g[y[i]][j]]==0){
					col[g[y[i]][j]]=y[i],q.push(g[y[i]][j]);
				}
			}
		}
	}
	if(tot<m){
		cout<<"DEAD"<<endl;
		return 0;
	}
	cout<<"ALIVE"<<endl;
	reverse(ans.begin(),ans.end());
	for(auto v:ans)cout<<v<<' ';
	cout<<endl;
}