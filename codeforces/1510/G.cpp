#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
int t;
cin>>t;
while(t--){
int n,k;
cin>>n>>k;
vector<int> p(n,-1);
for(int i=1;i<n;i++){
cin>>p[i];
p[i]--;
}
vector<int> dep(n);
dep[0]=0;
for(int i=1;i<n;i++) dep[i]=dep[p[i]]+1;
int bst=0;
for(int i=0;i<n;i++) if(dep[i]<k&&dep[i]>=dep[bst]) bst=i;
vector<bool> use(n,0);
vector<int> res;
int cur=bst;
while(cur!=-1){
use[cur]=1;
res.push_back(cur);
cur=p[cur];
}
reverse(res.begin(),res.end());
int need=k-res.size();
for(int i=0;i<n;i++){
if(use[i]) continue;
if(need){
need--;
int a=0;
while(res[a]!=p[i]) a++;
res.insert(res.begin()+a+1,p[i]);
res.insert(res.begin()+a+1,i);
}
}
cout<<res.size()-1<<'\n';
for(int i=0;i<res.size();i++) cout<<res[i]+1<<' ';
cout<<'\n';
}
return 0;
}