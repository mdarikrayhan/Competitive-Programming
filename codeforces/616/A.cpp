#include<bits/stdc++.h>
using namespace std;
string s,t;
main(){
cin>>s>>t;
string a(s.size(),'0');
string b(t.size(),'0');
a+=t;b+=s;
cout<<(b>a?'>':a==b?'=':'<');
}
