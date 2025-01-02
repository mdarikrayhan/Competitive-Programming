#include<bits/stdc++.h>
using namespace std;
int main(){int t,b[200010];cin>>t;while(t--){int n,ans=0,x;cin>>n;for(int i=1;i<=n;i++)cin>>x,b[i]=b[i-1]+x;for(int i=1,j=n-1;i<=j;){x=b[n]-b[j];if(b[i]==x) ans=max(ans,i+n-j);b[i]<x ? i++:j--;}cout<<ans<<endl;}}
  	  		    				 	   				