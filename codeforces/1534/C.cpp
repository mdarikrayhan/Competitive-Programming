#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n,a[400005],b[400005],to[400005],v[400005],ans;
void Solve(){
	scanf("%d",&n),ans=1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),v[i]=0;
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),to[a[i]]=b[i];
	for(int i=1;i<=n;i++){
		if(v[i])continue;
		v[i]=1,ans=2ll*ans%mod;
		int p=i;
		while(!v[to[p]])p=to[p],v[p]=1;
	}
	cout<<ans<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}