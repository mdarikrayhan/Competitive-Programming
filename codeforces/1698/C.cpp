#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
int main(){
int t;
cin>>t;
while(t--){
map<int,long long>b;
int n;
cin>>n;
for(int i=1;i<=n;i++){ cin>>a[i]; b[a[i]]=1;}
sort(a+1,a+n+1);
if(!b[a[1]+a[2]+a[3]]||!b[a[n]+a[n-1]+a[n-2]]||
!b[a[1]+a[2]+a[n]]||!b[a[n]+a[n-1]+a[1]]) cout<<"NO\n";
else cout<<"YES\n";
}
}