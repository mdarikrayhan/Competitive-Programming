#include<bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;
while (t--){
string s;
cin>>s;
int ans=0;
for(auto i:s)
if(ans!=0 && i=='B')
ans--;
else ans++;
cout<<ans<<endl;}
}