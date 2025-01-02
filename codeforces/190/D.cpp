#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[401001];
map<int,int> mp;
signed main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int r=0,sum=0;
	bool vis=0;
	for(int i=1;i<=n;i++){
		while(vis==0&&r<n){
			r++;
			mp[a[r]]++;
			if(mp[a[r]]>=k){
				vis=1;
				break;
			}
		}
		if(vis==1){
			sum+=n-r+1;
		}
		mp[a[i]]--;
		if(mp[a[i]]==k-1){
			vis=0;
		}
	}
	cout<<sum<<endl;
	return 0;
}
  										     	 	    		  	