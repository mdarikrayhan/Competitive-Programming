#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int tr[N*31][2],mx[N*31][2],tot=1;
int a[N],dp[N];
void insert(int x,int val){
	int now=1,p=a[x]^(x-1); 
	for(int j=30;j>=0;j--){

		bool bitp=p&(1<<j),bitx=(x-1)&(1<<j); 
		if(!tr[now][bitp]) tr[now][bitp]=++tot; 
		mx[tr[now][bitp]][bitx]=max(mx[tr[now][bitp]][bitx],val);
		now=tr[now][bitp];
	}
}
int query(int x){
	int now=1,p=a[x]^(x-1),ans=0; 
	for(int j=30;j>=0;j--){

		bool bitp=p&(1<<j),bitx=a[x]&(1<<j); 
		if(tr[now][!bitp]) ans=max(ans,mx[tr[now][!bitp]][!bitx]); 
		if(tr[now][bitp]) now=tr[now][bitp];
		else break;
	}
	return ans;
}
int main(){
	int T; cin>>T;
	while(T--){
		int n,maxn=-1e9; cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			dp[i]=query(i)+1; 
			insert(i,dp[i]);
			maxn=max(maxn,dp[i]); 
		}
		cout<<maxn<<endl;
		for(int i=1;i<=tot;i++){
			tr[i][0]=tr[i][1]=0;
			mx[i][0]=mx[i][1]=0;
		}tot=1;
	}
	return 0;
}
  			   			 	 	 	  	  		  		 	