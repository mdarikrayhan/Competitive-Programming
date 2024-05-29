#include<bits/stdc++.h>
using namespace std;
string const t[]={"","","","the","","buffy","slayer","vampire"};
string s;
int main(){
cin>>s;
if(t[s.size()]=="")
cout<<"none\n",exit(0);
for(int i=0;i<s.size();i++)
s[i]=(s[i]-97+t[s.size()][i]-97)%26+97;
cout<<s<<"\n";}