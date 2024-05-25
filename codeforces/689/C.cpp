#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll fun(ll x){
	ll ans=0;
	for(ll i=2;i*i*i<=x;i++)
		ans+=x/(i*i*i);
	return ans;
}

int main(){
	ll m,l=1,r=1e18,mid,ans=-1;
	cin>>m;
	while(r>=l){
		mid=l+r>>1;
		ll sum=fun(mid);
		if(sum==m) ans=mid;
		if(sum>=m) r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
}