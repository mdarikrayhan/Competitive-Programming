#include<bits/stdc++.h>
using namespace std;
int a[50005][15];
int main(){
int t;cin>>t;
while(t--){
int n,m;cin>>n>>m;
bitset<50005> b[15][15],tmp;
for(int i=1;i<=n;i++){
for(int j=1;j<=m;j++)
cin>>a[i][j],b[j][a[i][j]].set(i);
}
for(int i=1;i<=n;i++){
int ans=0;
tmp=b[a[i][1]][1];
for(int j=1;j<=m;j++){
tmp&=b[a[i][j]][j];
if(tmp.any()) ans=j;
else break;
}
cout<<ans<<' ';
}
cout<<'\n';
}
}