#include<bits/stdc++.h>
using namespace std;
 
int main(){
int t;
long long x,mid,s,l,r,k;
cin>>t;
while (t--){
cin>>k>>x;
l=1;r=k*2-1;
while (l<r){
mid=(l+r)/2;
if (mid<=k) s=(1+mid)*mid/2; else s=k*k-(k*2-mid-1)*(k*2-mid)/2;
if (s>=x) r=mid; else l=mid+1;
}
cout<<r<<endl;
}
}