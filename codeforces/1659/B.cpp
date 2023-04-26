#include<bits/stdc++.h>
using namespace std;
 
int main()
{
int t;
cin>>t;
while(t--){
int n,k;
string s;
cin>>n>>k;
cin>>s;
vector<int>f(n,0);
int t=k;
for(int i=0;i<n&&t>0;i++){
if(k%2==s[i]-'0'){ f[i]=1; t--;} 
}
f[n-1]+=t;
for(int i=0;i<n;i++){
if((k-f[i])%2==1)s[i]='1'-(s[i]-'0');
}
cout<<s<<endl;
for(auto x:f)cout<<x<<' ';
cout<<endl;
}
} 