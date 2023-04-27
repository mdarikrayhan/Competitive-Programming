#include <bits/stdc++.h>
using namespace std;
int main()
{int t;cin>>t;while(t--)
{string s;cin>>s;
int qwe=100;
for(int i=0;i<63;i++)
{int k=0;
long long x1=pow(2,i);
string x=to_string(x1);
for(int j=0;j<s.length();j++)
{if(s[j]==x[k])k++;}
int zxc=x.size()-k+s.size()-k;
qwe=min(qwe,zxc);
}cout<<qwe<<endl;}return 0;}