#include <bits/stdc++.h>
using namespace std;
int main(){
int t;cin>>t;
while(t--){
int n,a,b,m;
string s;
cin>>n>>a>>b>>s;
m=unique(s.begin(),s.end())-s.begin();
cout<<a*n+max(b*n,(m/2+1)*b)<<endl;
}
}