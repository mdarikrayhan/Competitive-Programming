#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=23;
int n,m,a[N],dp[1<<N],pre[1<<N],ps[1<<N];
stack<int> s;
void dfs(int x){
	if(dp[x]==0) return ;
	s.push(pre[x]);
	dfs(ps[x]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(m==n*(n-1)/2){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		x--,y--;
		a[x]|=(1<<y);
		a[y]|=(1<<x);
	}
	int fl=0;
	for(int i=0;i<n;i++){
		if(a[i]!=((1<<n)-1)){
			fl=1;
			break;
		}
	}
	if(fl==0){
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<(1<<n);i++){
		dp[i]=1e9;
		pre[i]=-1;
	}
	for(int i=0;i<n;i++){
		dp[(1<<i)]=0;
		pre[i]=0;
	}
	for(int i=0;i<(1<<n);i++){
		if(dp[i]>=n) continue;
		for(int j=0;j<n;j++){
			if((i>>j&1)&&(dp[i|a[j]]>dp[i]+1)){
				dp[i|a[j]]=dp[i]+1;
				pre[i|a[j]]=j;
				ps[i|a[j]]=i;
			}
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
	dfs((1<<n)-1);
	while(!s.empty()){
		cout<<s.top()+1<<" ";
		s.pop();
	}
	return 0;
}