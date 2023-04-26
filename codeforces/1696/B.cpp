#include<bits/stdc++.h>
using namespace std;
int _,n,i,ans,a[200001];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>_;
	while(_--){
		cin>>n;ans=0;
		for(i=1;i<=n;i++)cin>>a[i],ans+=a[i]&&a[i-1]==0;
		cout<<min(2,ans)<<"\n";
	}
}