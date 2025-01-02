#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
string s;
int n;
cin>>n>>s;
int c0=0;
for(auto c:s)
if(c=='0')
c0++;

if(n&1&&s[n/2]=='0'&&c0>1)
cout<<"ALICE\n";
else
cout<<"BOB\n";
}
}