// LUOGU_RID: 160469156
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,q,a[262150];
vector<int> v[262150];
int now=1;
ll out[200005];
ll lm[262150],rm[262150],sum[262150],ans[262150];
void solve(int c,int x){
	if(c==n){
//		cout<<x<<' '<<ans[0]<<'\n';
		for(auto i:v[x])
			out[i]=ans[0];
		return;
	}
	vector<ll> v1,v2,v3,v4;
	int l=1<<c;
	for(int i=0;i+l<m;i+=l*2){
		v1.emplace_back(lm[i]),v2.emplace_back(rm[i]),v3.emplace_back(sum[i]),v4.emplace_back(ans[i]);
		ans[i]=max({ans[i],ans[i+l],rm[i]+lm[i+l]});
		lm[i]=max(lm[i],sum[i]+lm[i+l]);
		rm[i]=max(rm[i+l],rm[i]+sum[i+l]);
		sum[i]+=sum[i+l];
	}
	solve(c+1,x);
	for(int i=0,j=0;i+l<m;i+=l*2,++j){
		lm[i]=v1[j],rm[i]=v2[j],sum[i]=v3[j],ans[i]=v4[j];
		ans[i]=max({ans[i],ans[i+l],lm[i]+rm[i+l]});
		lm[i]=max(lm[i+l],sum[i+l]+lm[i]);
		rm[i]=max(rm[i],rm[i+l]+sum[i]);
		sum[i]+=sum[i+l];
	}
	solve(c+1,x+(1<<c));
	for(int i=0,j=0;i+l<m;i+=l*2,++j)
		lm[i]=v1[j],rm[i]=v2[j],sum[i]=v3[j],ans[i]=v4[j];
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;m=1<<n;
	for(int i=0;i<m;++i)
		cin>>a[i];
	cin>>q;
	for(int i=1,x,tp=0;i<=q;++i){
		cin>>x;
		tp^=(1<<x);
		v[tp].emplace_back(i);
	}
	for(int i=0;i<m;++i)
		sum[i]=lm[i]=rm[i]=ans[i]=a[i];
	solve(0,0);
	for(int i=1;i<=q;++i)
		cout<<max(out[i],0ll)<<'\n';
	return 0;
}/*
 
*/