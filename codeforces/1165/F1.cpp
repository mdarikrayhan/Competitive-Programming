// LUOGU_RID: 160261312
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e6+10;
ll n,m,q,a[N],p[N],d[N],l,r,mid,ans;
vector<ll> v[N];
bool cmp(ll a,ll b){
	return p[a]<p[b];
}
bool check(ll x){
	for(int i=1;i<=n;i++)
		for(auto t:v[i])
			if(t<=x){p[i]=t;break;}
	sort(d+1,d+n+1,cmp);
	ll ct=0,s=0;
	for(int i=1;i<=n;i++){
		ll j=d[i];
		if(!a[j]) continue;
		else if(!p[j]) s+=a[j];
		else if(p[j]-ct>=a[j]) ct+=a[j];
		else s+=a[j]-p[j]+ct,ct+=p[j]-ct;
	}
	ct+=s*2;
	return ct<=x;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],q+=a[i],d[i]=i,v[i].push_back(0);
	while(m--){cin>>l>>r,v[r].push_back(l);}
	for(int i=1;i<=n;i++)
		if(a[i]) sort(v[i].begin(),v[i].end(),greater<ll>());
	l=q-1,r=ans=q*2;
	while(l<=r){
		mid=l+r>>1;
		if(check(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	cout<<ans;
	return 0;
}
