#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
int t;
cin>>t;
while(t--){
ll n;
cin>>n;
vector<int> v(n),ans;
for(int i=0;i<n;i++)
cin>>v[i];
for(int i=0;i<n;i++)
if(i==0||i==n-1||(v[i]<v[i-1])!=(v[i+1]<v[i]))
ans.push_back(v[i]);
cout<<ans.size()<<endl;
for(int a:ans)
cout<<a<<" ";
cout<<endl;
}
return 0;
}