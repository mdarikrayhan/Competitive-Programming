#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,c[2019][2019]={0};
long double ans,sm;
long double sc(int n,int m){
	long double res=1;
	for(int i=0;i<m;i++){
		res*=n-i;
		res/=m-i;
	}
	return res;
}
int main(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		c[i][i] = -1;
		for(int j=i+1;j<=n;j++){
			scanf("%lld",&c[i][j]);
			c[j][i] = c[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		sm=0;
		for(int j=1;j<=n;j++){
			if(c[i][j]!=-1){
				sum++;
				sm+=c[i][j];
			}
		}
		if(sum>=k){
			ans+=sc(sum-1,k-1)*sm;
		}
	}
	ans/=sc(n,k);
	cout<<(ll)(ans+1e-4)<<endl;
	return 0;
}
  	          			 	 	 	   		 			