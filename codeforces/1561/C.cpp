#include <bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
int n;
cin>>n;
vector<pair<int,int>>v;
for(int i=1;i<=n;i++){
int k,m=0;
cin>>k;
for(int i=0;i<k;i++){
int x;
cin>>x;
m=max(m,x-i+1);
}
v.push_back({m,k});
}
sort(v.begin(),v.end());
int p=0,l=0;
for(auto i:v){
p=max(p,i.first-l);
l+=i.second;
}
cout<<p<<endl;
}
}