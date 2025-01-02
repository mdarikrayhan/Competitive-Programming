#include <bits/stdc++.h>
using namespace std;
int main()
{
int t,s,z,o;
for (cin>>t; t--; cout<<s<<'\n') {
string a;
cin>>a;
z=a.find(48);
o=a.rfind(49);
s=(z<0?a.size():1+z)-(o<0)-o;
}
}