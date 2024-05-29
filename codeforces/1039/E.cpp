#pragma GCC optimize("Ofast")
#pragma GCC target("sse","avx")
#include<bits/stdc++.h>
const int N=100005;
using namespace std;

int n,w,q,s[N];
int mx[N],mn[N],a[N],res[N];

void solve(){
cin>>n>>w>>q;
for(int i=1;i<=n;i++)cin>>s[i];
for(int i=1;i<=q;i++)cin>>a[i],a[i]=w-a[i],mx[i]=s[1],mn[i]=s[1];
for(int i=2;i<=n;i++){
int t=s[i];
for(int j=1;j<=q;j++){
mx[j]=max(mx[j],t),mn[j]=min(mn[j],t);
if(mx[j]-mn[j]>a[j])mx[j]=mn[j]=t,res[j]++;
}
}
for(int i=1;i<=q;i++)cout<<res[i]<<'\n';
}

main(){
ios::sync_with_stdio(0);
solve();
}
