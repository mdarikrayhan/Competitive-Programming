#include<bits/stdc++.h>
using namespace std;
const int maxn=404,maxq=250000+10;
struct que{
	int l,r,ted,w;
}qu[maxq];
int dp[maxn][maxn],all[maxn],res[maxn],inf=1e9+5,n,q;
vector<int>allq[maxn];
pair<int,int>stf[maxn][maxn];
void clear(){
	for(int i=0;i<maxn;i++){
		for(int j=0;j<maxn;j++){
			dp[i][j]=0;
			stf[i][j].first=stf[i][j].second=0;
		}
	}
}

void vorod(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>all[i];
	}
	for(int i=0;i<q;i++){
		cin>>qu[i].l>>qu[i].r>>qu[i].w>>qu[i].ted;
		allq[qu[i].l].push_back(i);
	}
}

void dfs(int mxl,int r,int ted){
	if(r<mxl||ted>n){
		return ;
	}
	if(ted==0){
		dp[r][ted]=all[r]-all[mxl];
	}else{
		stf[r][ted].second=min(stf[r][ted].second,r-1);
		int wh=stf[r][ted].second,mn=inf;
		for(int i=stf[r][ted].second;i>=stf[r][ted].first;i--){
			if(max(dp[i][ted-1],all[r]-all[i])<mn){
				mn=max(dp[i][ted-1],all[r]-all[i]);
				wh=i;
			}
		}
		dp[r][ted]=min(mn,dp[r][ted-1]);
		stf[r-1][ted].second=wh;
		stf[r][ted+1].first=wh;
	}
	//cout<<mxl<<" "<<r<<" "<<ted<<" "<<dp[r][ted]<<" "<<stf[r][ted].first<<" "<<stf[r][ted].second<<"\n";
	dfs(mxl,r-1,ted);
	if(r==n){
		dfs(mxl,r,ted+1);
	}
}

void cal(int ind){
	clear();
	for(int i=0;i<=n;i++){
		stf[i][1].first=ind;
		stf[n][i].second=n;
	}
	dfs(ind,n,0);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vorod();
	long long mainres=0;
	for(int i=n;i>=1;i--){
		cal(i);
		for(auto x:allq[i]){
			mainres=max(mainres,1ll*dp[qu[x].r][qu[x].ted]*qu[x].w);
	//		if(1ll*dp[qu[x].r][qu[x].ted]*qu[x].w==60){
	//			cout<<qu[x].l<<" "<<qu[x].r<<" "<<qu[x].ted<<endl;
	//		}
		}
	}
	cout<<mainres<<"\n";
}