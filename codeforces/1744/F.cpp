#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long T,p[N],n,l,r,re,me,i,x,L;
int main(){
for(cin>>T;T--;){
cin>>n;
for(i=1;i<=n;i++)cin>>x,p[x]=i;l=r=p[0],re=1,me=0;
for(L=2;L<=n;L++)me=(L-1)/2,l=min({l,p[me],n+1-L}),r=max({r,p[me],L}),re+=max(0ll,L-r+l);
cout<<re<<'\n';
}
}