#include <bits/stdc++.h>
using namespace std;
 int main(){
int T;cin>>T;while(T--){
int n,m;cin>>n>>m;
vector<int> a(n+1,999999999),b(n);
for(int i=0;i<n;i++)cin>>a[i],b[i]=a[i];
sort(b.begin(),b.end());
int place=n,tot=0,last=0;
for(int i:b)if(tot+i<=m)
tot+=i,place--,last=i;
cout<<place+(tot-last+a[n-place]>m)<<'\n';
}
}