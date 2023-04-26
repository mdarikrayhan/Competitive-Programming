#include<bits/stdc++.h>
using namespace std;
int main(){int t;cin>>t;while(t--){int n;cin>>n;int a[n];for(int i=0;i<n;i++)cin>>a[i];
int val=0;for(int j=0;j<30;j++){int lav=0;for(int i=0;i<n;i++)lav+=(a[i]>>j)&1;val=gcd(val,lav);}
for(int i=1;i<=(val?val:n);i++)if(!val||!(val%i))cout<<i<<' ';cout<<endl;}}