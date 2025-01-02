#include<bits/stdc++.h>
using namespace std;

void solve(){
int n; cin>>n;
int arr[n+1];
int a[n+1],m=1;
for(int i=0;i<=n;i++){
a[i]=0;
}
for(int i=1;i<=n;i++){
if(a[i]==0){
a[i]=1;
arr[m++]=i;
int x=arr[m-1];
x=2*x;
while(x<=n){
    if(a[x]==0){
    a[x]=1;
    arr[m++]=x;
    }
    x=x*2;
}
}
}
for(int i=1;i<=n;i++){
cout<<arr[i]<<" ";
}
cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t ; cin>>t;
    while(t--){
        solve();
    }
return 0;
}