#include <bits/stdc++.h>
using namespace std;
int main(){ 
int t;cin>>t;
while(t--){
   long long nu,n=0;cin>>nu;
  map<string,int>m1;
  map<char ,int>m2,m3;
  while(nu--){
    string s;cin>>s;
    n=n+m2[s[0]]+m3[s[1]]-2*m1[s];
   m1[s]++;m2[s[0]]++;m3[s[1]]++;
   }cout<<n<<endl;
}
}