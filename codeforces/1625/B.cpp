#include <bits/stdc++.h>
using namespace std;int main(){int t,n,a,b=-1;cin>>t;
while(t--){map<int,int>m;cin>>n;
for(int i=1;i<=n;i++){cin>>a;
if(m[a])b=max(b,n-i+m[a]);
m[a]=i;}
cout<<b<<endl;b=-1;}}