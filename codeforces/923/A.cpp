// LUOGU_RID: 160047510
#include<bits/stdc++.h>
using namespace std;
int n,p[1000005],ans=1e7,d=1e7;
bool vis[1000005];
int main(){
	cin>>n;
	for(int i=2;i<=1000000;i++){
		if(!vis[i]){
			for(int j=2;i*j<=1000000;j++){
				vis[i*j]=1;
				p[i*j]=max(p[i*j],i);
			}
		}
	}
	if(p[n]!=0)  d=n-p[n]+1;
	for(int i=d;i<=n;i++){
		ans=min(ans,i-p[i]+1);
	}
	if(ans==1e7) cout<<-1;
	else cout<<ans;
	return 0;
}