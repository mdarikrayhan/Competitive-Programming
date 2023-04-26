#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000005];
int main(){
cin>>t;while(t--){
cin>>n;for(int i=1;i<=n;i++)cin>>a[i];cout<<(a[n]-a[1]-n<2?"YES":"NO")<<endl;};
}