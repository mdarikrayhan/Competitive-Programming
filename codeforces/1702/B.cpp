#include<bits/stdc++.h>
using namespace std;
int T,a;
string s;
int main()
{cin>>T;
while(T--){
set<char> S;
cin>>s;
a=1;
for(auto c:s){
S.insert(c);
if(S.size()>3)S.clear(),S.insert(c),a++;
}
cout<<a<<'\n';
}
}