#include<bits/stdc++.h>
using namespace std;
int _,n,k,i,pre,ans,f[300];
char s[200001],c;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>_;
	while(_--){
		ans=0;
		cin>>n>>(s+1)>>k;
		memset(f,0,sizeof f);
		for(i=1;i<=k;i++)cin>>c,f[(int)c]=1;
		pre=1;
		for(i=1;i<=n;i++)if(f[(int)s[i]])ans=max(ans,i-pre),pre=i;
		cout<<ans<<"\n";
	}
}