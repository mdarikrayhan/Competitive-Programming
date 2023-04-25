#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200010];

void solve(){
ll n,c,d;cin>>n>>c>>d;
for(ll i=0;i<n;i++)cin>>a[i];
sort(a,a+n,greater<long long>());
ll l=0,r=d;
while(l<r){
ll mid=l+(r-l+1)/2;
ll tot=0;
for(int i=0;i<d;i++){
if(i%mid<n)tot+=a[i%mid];
}
if(tot>=c)l=mid;
else r=mid-1;
} 
if(l==d)cout<<"Infinity"<<endl;
else if(l==0)cout<<"Impossible"<<endl;
else cout<<l-1<<endl;
}

int main(){
int t;cin>>t;
while(t--)solve();
}