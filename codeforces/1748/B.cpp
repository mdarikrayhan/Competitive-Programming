#include<bits/stdc++.h>
using namespace std;
 
void solve(){
int ans=0,n;cin>>n;
string s;cin>>s;
for(int i=0;i<n;i++){
int ho=0;
map<char,int>m;
for(int j=i;j<n and j<=i+99;j++){
m[s[j]]++;
ho=max(ho,m[s[j]]);
if(ho<=m.size())ans++;
}
}
cout<<ans<<"\n";
}
int main(){
int t;cin>>t;
while(t--)
solve();
}