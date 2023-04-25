#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
int n;
cin>>n;
int ans=0,a[n+1];
ll s[n+1];
s[0] = 0;
for(int i=1;i<=n;i++){
cin>>a[i];
s[i]=s[i-1]+a[i];
}
map<ll,int>p;
for(int i=n;i;i--){
if(++p[s[i]] && !a[i]){
int mx=0;
for(auto k:p)mx=max(mx,k.second);
ans+=mx;
p.clear();
}
}
ans+=p[0];
cout<<ans<<'\n';
}
int main(){
int t;
cin>>t;
while(t--)solve();
}