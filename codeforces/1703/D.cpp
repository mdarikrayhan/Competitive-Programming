#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
int n;
cin>>n;
string s[n+1];
map<string,bool> mp;
for(int i=1;i<=n;i++) cin>>s[i],mp[s[i]]=1;
for(int i=1;i<=n;i++){
bool b=0;
for(int j=1;j<s[i].size();j++) if(mp[s[i].substr(0,j)]&&mp[s[i].substr(j,s[i].size()-j)]) b=1;
cout<<b;
}
cout<<endl;
}
}