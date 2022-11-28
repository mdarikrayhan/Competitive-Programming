#include<bits/stdc++.h>
using namespace std;
int n,x,mn=1e9;
long long ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		cin>>x;
		if(i==n-j+1)mn=min(mn,x);
		ans+=x;
	}
	cout<<ans-mn;
}