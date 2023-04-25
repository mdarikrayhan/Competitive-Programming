#include<bits/stdc++.h>
using namespace std;int t,n,a[100005];main(){cin>>t;while(t--){cin>>n;for(int i=1;i<=n;i++){cin>>a[i];a[i]+=a[i-1];}cout<<a[n-a[n]]<<endl;}}