#include<bits/stdc++.h>
using namespace std;
int t,n,A,B;
string s;
int main()
{
cin>>t;
while(t--&&cin>>n>>s)
{
s=' '+s,A=0,B=1;
for(int i=2;i<=n;i++)
if(s[B]=='('&&s[i]==')'||s[B]==s[i])
A++,B=++i;
cout<<A<<' '<<n-B+1<<'\n';
}
}