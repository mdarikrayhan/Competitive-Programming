#include <bits/stdc++.h>
using namespace std;
int main() {
int t;cin>>t;
while(t--){
int n;cin>>n;
int a[n+1]={},cnt[n+1]={};
for(int i=1;i<=n;i++){
int x;cin>>x;
if(i-a[x]!=1)cnt[x]++;
a[x]=i;
}
int mn= INT_MAX;
for(int i=1;i<=n;i++)if(a[i]){
mn = min(mn , cnt[i]+(a[i]!=n));
}
cout<<mn<<endl;
}
}
 	   		   			  				   	 	 			