#pragma GCC optimize(3,"Ofast","inline")
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<ctime>
using namespace std;
#define ll long long
const int N=524299;
const ll mod=998244353;
ll qpow(ll a,ll b){
	ll ans=1;
	if(b==0)
	return 1;
	if(b%2)
	ans=a;
	ll t=qpow(a,b/2);
	return t*t%mod*ans%mod;
}
ll inv(ll a){
	return qpow(a,mod-2);
}
struct nd{
	vector<int>a;
	vector<int>b;
	int la;
	int lb;
	int swaptp;
	void ndswap(){
		swaptp=1-swaptp;
		swap(la,lb);
		swap(a,b);
	}
};
vector<int>csum(vector<int>a){
	int sz=a.size();
	vector<int>ans(sz);
	for(int i=0;i<sz;i++){
		ans[i]=a[i];
	}
	for(int j=0;(1<<j)<sz;j++){
		for(int i=0;i<sz;i++){
			if((i&(1<<j)))
			ans[i]^=ans[i^(1<<j)];
		}
	}
	return ans;
}
nd calc(nd x){
	int sz=x.a.size();
	if(x.la>x.lb){
		x.ndswap();
	}
	int la=x.la,lb=x.lb;
	//assert()
	if(sz==1){
		x.b[0]=x.a[0];
		return x;
	}
	for(int i=0;i<la;i++){
		x.a[i]=0;
	}
	vector<int>ans=csum(x.a);
	vector<int>lft(sz/2),pre(sz/2);
	
	for(int i=sz/2;i<lb;i++){
		lft[i-sz/2]=0;
	}
	for(int i=lb;i<sz;i++){
		lft[i-sz/2]=ans[i]^x.b[i];
	}
	for(int i=0;i<sz/2;i++){
		pre[i]=0;
	}
	nd y={pre,lft,la,lb-sz/2,0};
	nd cy=calc(y);
	for(int i=0;i<la;i++){
		x.a[i]=cy.a[i];
	}
	x.b=csum(x.a);
	//0~la-1&&lb~sz;
	if(x.swaptp){
		x.ndswap();
	}
	return x;
	
}
void solve(){
	int n;
	cin>>n;
	
	int ttl=1;
	while(ttl<n){
		ttl*=2;
	}
	vector<int>a(ttl),b(ttl),dp(ttl);
	for(int i=0;i<n;i++){
		cin>>b[ttl-1-i];
	}
	nd ans=calc({a,b,n,ttl-n,0});
	for(int i=n-1;i>=0;i--){
		cout<<ans.a[i]<<' ';
	}
	/*
	for(int i=0;i<ttl;i++){
		dp[i]=b[i];
	}
	for(int j=0;(1<<j)<ttl;j++){
		for(int i=0;i<ttl;i++){
			if((i&(1<<j)))
			dp[i]^=dp[i^(1<<j)];
		}
	}
	*/
	
	//for(int i=0;i<ttl;i++)
	//cout<<dp[i]<<' ';
	//cout<<'\n';
	//for(int i=n-1;i>=0;i--){
	//	cout<<dp[i]<<' ';
	//}
	
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 

	solve();
}