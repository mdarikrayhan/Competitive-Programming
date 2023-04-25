#include<iostream>
#include <map>
using namespace std;
 int main(){
	int t;cin>>t;
	while(t--){
		int n;
		long long a[100];
		cin>>n; map<int,int>mp;
		int ans=1;
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
			int s=a[j]-a[i];
			for(int q=1;q*q<=s;q++)
			if(q%2==s/q%2&&s%q==0){
				long long x=(s/q-q)/2;
				if (x*x>=a[i]){
					mp[x]++;
					ans=max(ans,mp[x]+1);
				}
			}
 
		}
		mp.clear();
		}
		cout<<ans<<"\n";
	}
}