#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long
using namespace std;
int n,m,a[100005],ans;
pii h[100005];
priority_queue<int,vector<int>,greater<int>>q;
signed main(){
a[0]=1e9+7;
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>a[i];
for(int i=1;i<=m;i++)cin>>h[i].first;
for(int i=1;i<=m;i++)cin>>h[i].second;
sort(h+1,h+1+m);
int k,tot,pre=1,j=0;
for(int i=n;i>=1;i=j){
tot=0;
for(j=i;a[j]<=a[i];j--)tot+=a[j];
for(k=pre;k<=m&&h[k].first<=a[i];k++)q.push(h[k].second);
pre=k;
while(!q.empty()){
if(tot>=q.top())ans++,tot-=q.top(),q.pop();
else{
tot=q.top()-tot;
q.pop();
q.push(tot);
break;
}
}
}
cout<<ans;
return 0;
}