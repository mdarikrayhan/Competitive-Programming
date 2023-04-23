#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],b[N];
struct node{
	int sum;
	int top;
}e[N];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)cin>>b[i];
		int sum=0,ans=0x3f3f3f3f,cnt=0;
		for(int i=1;i<=n;i++){
			if(b[i]==a[i])cnt++;
			sum+=b[i]-a[i]+1;
			if(sum>=k){
				int tt=sum-k;
				ans=min(ans,(b[i]-tt)+i*2-min(tt,cnt));
			}
		}
		if(ans==0x3f3f3f3f)puts("-1");
		else cout<<ans<<endl;
	}
	return 0;
}