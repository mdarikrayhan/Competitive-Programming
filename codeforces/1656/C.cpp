#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){int t;cin>>t;while(t--){int n,i,j,a[200001],mn=0,mx=0,mni=0,mxi;cin>>n;for(i=0;i<n;i++){cin>>a[i];if(a[i]==1) mx=1;}sort(a,a+n);for(i=1;i<n;i++){if(a[i]==a[i-1]+1) mn=1;}if(mx&&mn) cout<<"NO\n";else cout<<"YES\n";}}