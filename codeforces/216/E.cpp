#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,k,x,i,j,p,s,ans=0,zero=0,cur=0,sum;
	map<long long,long long>mp;
	cin>>k>>p>>n;mp[0]=1;
	long long mod=k-1;
	for(i=1;i<=n;i++){
		cin>>x;
		if(x==0){
			cur++;
			zero += cur;
			sum+=x;
			ans += mp[(sum-p+mod)%mod];
			mp[sum%mod]++;
			sum%=mod;

		}
		else{
			cur=0;
			sum+=x;
			ans += mp[(sum-p+mod)%mod];
			mp[sum%mod]++;
			sum%=mod;
		}
	}

	if(p==0){
		cout<<zero<<"\n";
	}
	else if(p==mod){
		cout<<ans-zero<<"\n";
	}
	else cout<<ans<<"\n";

}
			 					 				 		  			 		     	