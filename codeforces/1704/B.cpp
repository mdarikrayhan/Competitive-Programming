#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
long long mmax=0,mmin=1e9,x,sum=0,n,m;
cin>>n>>m;
while(n--){
cin>>x;
mmax=max(mmax,x);
mmin=min(mmin,x);
if(mmax-mmin>m*2) sum++,mmax=x,mmin=x;
}
cout<<sum<<endl;
}
return 0;
}