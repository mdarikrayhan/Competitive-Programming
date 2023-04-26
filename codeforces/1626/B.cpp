#include <bits/stdc++.h>
using namespace std;
main(){int t;cin>>t;while(t--){string s;cin>>s;int pos=0;for(int i=0;i<s.length()-1;i++)if(s[i]+s[i+1]>=106)pos=i;for(int i=0;i<s.length();i++)if(i==pos){cout<<s[i]+s[i+1]-96; i++; continue;}else cout<<s[i];cout<<'\n';}}