#include <iostream>
using namespace std;
main(){int t,n;cin>>t;while(t--){cin>>n;char a[n][n];
for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];bool f=0;
for(int i=0;i<n-1;i++)for(int j=0;j<n-1;j++)if(a[i][j]=='1'&&(a[i][j+1]|a[i+1][j])=='0')f=1;
puts(f?"NO":"YES");}}