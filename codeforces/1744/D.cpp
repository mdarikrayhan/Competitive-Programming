#include<bits/stdc++.h>
using namespace std;
int v[1000000];
int main(){
int t;cin>>t;
while(t--){
int n;cin>>n;
int x,sum=0,ss=0;
for(int i=1;i<=n;i++){
cin>>x;v[i]=0;
while(x%2==0){x=x/2;sum++;}
int j=i;
while(j%2==0){j=j/2;v[i]++;}
}
sort(v+1,v+n+1);
for(int i=n;i>=1&&sum<n;i--){
sum+=v[i];
ss++;}
if(sum<n)cout<<-1<<endl;
else cout<<ss<<endl;
}

return 0;}