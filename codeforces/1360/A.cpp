#include<bits/stdc++.h>
using namespace std;
int main(){int t,a,b,s;cin>>t;while(t--){cin>>a>>b;s=min(max(2*a,b),max(a,2*b));cout<<s*s<<endl;}}