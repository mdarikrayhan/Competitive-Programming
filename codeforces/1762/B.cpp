#include <bits/stdc++.h>
using namespace std;int main(){int n,x,T,pwr;cin>>T;
while(T){T--;cin>>n;cout<<n<<'\n';
for(int i=1;i<=n;i++){cin>>x;
pwr=ceil(log2(x));pwr=pow(2,pwr);
cout<<i<<' '<<pwr-x<<'\n';}}}