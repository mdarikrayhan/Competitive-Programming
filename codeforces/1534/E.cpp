// LUOGU_RID: 159788618
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans,dis[505],pre[505],vis[505],viss[505],x;
queue<int>qu;
vector<int>ve;
signed main(){
	cin>>n>>k,dis[0]=1,pre[0]=-1;
	qu.push(0);
	while(!qu.empty()){
		int ft=qu.front();qu.pop(); 
		for(int i=0;i<=k;i++){
			int now=ft+k-2*i;
			if(i>ft||ft+k-i>n||now<0||dis[now])continue;
			dis[now]=dis[ft]+1,pre[now]=ft,qu.push(now);
		}
	}
	if(!dis[n])cout<<-1<<endl,exit(0);
	int now=n;
	while(~now)ve.emplace_back(now),now=pre[now];
	reverse(ve.begin(),ve.end());
	for(int i=1;i<ve.size();i++){
		int nw=(ve[i-1]+k-ve[i])/2,cnt1=0,cnt2=0;
		vector<int>ve2;memcpy(viss,vis,sizeof vis);
		for(int j=1;j<=n;j++){
			if(cnt1==nw)break;
			if(vis[j])ve2.emplace_back(j),cnt1++,viss[j]=0;
		}
		for(int j=1;j<=n;j++){
			if(cnt2==k-nw)break;
			if(!vis[j])ve2.emplace_back(j),cnt2++,viss[j]=1;
		}
		memcpy(vis,viss,sizeof viss);
		sort(ve2.begin(),ve2.end());
		cout<<"? ";
		for(int v:ve2)cout<<v<<" ";cout<<endl,cin>>x,ans^=x;
	}
	cout<<"! "<<ans<<endl;
	return 0;
}