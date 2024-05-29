// LUOGU_RID: 160530305
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
bool check(ll x){
	ll tmp=x-n+1;
	ll l=1,r=n+1,mid;
	while(l<r){
		mid=l+r>>1;
		if(mid*(mid-1)/2-mid+1>=tmp)r=mid;
		else l=mid+1;
	}
	//cout<<x<<" "<<tmp<<" "<<l<<endl;
	return 2*(n-l)>=x;
}
void solve(){
	cin>>n;
	ll l=n-1,r=2e18,mid;
	while(l<r){
		mid=l+r+1>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tt;
	cin>>tt;
	while(tt--)solve();
	return 0;
}