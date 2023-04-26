#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int t;
	cin>>t;
	while(t--){

ll n, k;
cin>>n>>k; 
vector<ll> a(n);
for(auto &ele : a) cin>>ele;
ll l=1, r=1e18;
while(l<=r){
	ll m=(l+r)/2;
	ll sm=m;
	for(int i=0; i<n-1; i++){
		sm +=min(m, a[i+1]-a[i]);
	}
	if(sm<k) l=m+1;
	else r=m-1;
}
cout<<r+1<<endl;
}
}