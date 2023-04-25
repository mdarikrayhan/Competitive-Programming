#import<bits/stdc++.h>
using namespace std;int64_t t,n,m,c,i;main(){cin>>t;while(t--){cin>>n>>m;i=19;while(i--){c=pow(10,i);if(c/gcd(c,n)<=m){cout<<m*n-n*m%lcm(c,n)<<' ';break;}}}}