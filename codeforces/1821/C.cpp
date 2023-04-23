#include<bits/stdc++.h>
using namespace std;

int main()
{
int t;
cin>>t;
while(t--)
{
string s;
cin>>s;
int d=0,c=0,k=INT_MAX;
for(int i=0;i<26;i++)
{
char ch=i+'a';
c=0;d=0;
for(int j=0;j<s.size();j++)
{
if(s[j]!=ch)
{
c++;
d=max(d,c);
}
else
c=0;
}
int p=0;
while(d)
{
d/=2;
p++;
}
k=min(p,k);
}
cout<<k<<endl;
}

}