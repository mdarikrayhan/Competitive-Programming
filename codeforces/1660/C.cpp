#include<bits/stdc++.h>
using namespace std;
int t,A;
string s;
int main()
{
cin>>t;
while(t--&&cin>>s)
{
map<int,int>p;
A=s.size();
for(int i=0;i<s.size();i++)
if(p[s[i]])
A-=2,p.clear();
else
p[s[i]]++;
cout<<A<<'\n';
}
}