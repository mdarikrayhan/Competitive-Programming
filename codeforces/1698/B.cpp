#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
while(t--){
int n,k;
cin>>n>>k;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];int c=0;
for(int i=1;i<n-1;i++){
	if(a[i]>a[i-1]+a[i+1]) c++;}
if(k==1) cout<<(n-1)/2<<endl;
else cout<<c<<endl;
}}