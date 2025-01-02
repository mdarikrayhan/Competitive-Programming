#include<bits/stdc++.h>
using namespace std;
int t,n;
pair<char,int> a[200020];
int main(){
cin>>t;
while(t--){
cin>>n;
for(int i=0;i<n;i++) cin>>a[i].second;
for(int i=0;i<n;i++) cin>>a[i].first;
sort(a,a+n);
int f=1;
for(int i=0;i<n;i++){
if(a[i].first=='B'&&a[i].second<i+1) f=0;
if(a[i].first=='R'&&a[i].second>i+1) f=0;
}
puts(f?"YES":"NO");
}
}