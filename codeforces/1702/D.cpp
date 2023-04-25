#include<iostream>
using namespace std;
int main()
{
long long i,h,n,t;
char k;
string s;
cin>>t;
while(t--)
{
h=0;
k='a';
cin>>s>>n;
while(k<='z')
{
for(i=0;i<s.size();i++)
{
if(s[i]==k)
{
h=h+(s[i]-'a'+1);
if(h>n)
{
s.erase(s.begin()+i);
i--;
}
}
}
k++;
}
cout<<s<<endl;
}
}