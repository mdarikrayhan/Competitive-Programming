// LUOGU_RID: 160004014
#include<bits/stdc++.h> 
using namespace std;
#define int long long
int s[1000005];
int n;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		s[i]+=s[i-1]; 
	} 
	int ans=2e18;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=min(2000ll,i-1);j++){
			ans=min(ans,(i-j)*(i-j)+(s[i]-s[j])*(s[i]-s[j]));
		}
		for(int j=max(1ll,i-2000);j<i;j++){
			ans=min(ans,(i-j)*(i-j)+(s[i]-s[j])*(s[i]-s[j]));
		}
	} 
	cout<<ans;
	return 0;
}