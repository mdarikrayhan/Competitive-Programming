// LUOGU_RID: 160140706
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int ans=(n-1)/k*2;
	if((n-1)%k==1) ans++;
	if((n-1)%k>1) ans+=2;
	cout<<ans<<endl;
	for(int i=2;i<=k;i++) cout<<1<<' '<<i<<endl;
	for(int i=k+1;i<=n;i++) cout<<i-k<<' '<<i<<endl;
	return 0;
}
