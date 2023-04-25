#include<iostream>
using namespace std;
int main(){
int t,n,m,d,i,ans;
cin>>t;
while(t--){
ans=1e9;
cin>>n>>m>>d;
int a[n],pos[n+1],p[m];
for(i=0;i<n;i++)cin>>a[i],pos[a[i]]=i;
for(i=0;i<m;i++)cin>>p[i];
for(i=1;i<m;i++){
ans=min(ans,pos[p[i]]-pos[p[i-1]]);
if(d<n-1)ans=min(ans,pos[p[i-1]]+d+1-pos[p[i]]);
ans=max(0,ans);
}
cout<<ans<<endl;
}
}