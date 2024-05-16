#include<bits/stdc++.h>
using namespace std;
long long t,n,a[200200];
int main(){
	cin>>t;
	for(int o=1;o<=t;o++){
		cin>>n;
		long long tot=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]<0){
				tot+=a[i]*-1;
			}
			else tot+=a[i];
		}
		a[n+1]=1e10;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]<0){
				ans++;
				while(a[i]<=0&&i<=n) i++;
			}
		}
		cout<<tot<<" "<<ans<<"\n";
	}
}