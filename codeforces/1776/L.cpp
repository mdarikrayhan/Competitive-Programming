#include<bits/stdc++.h>

using namespace std;
int main(){
  
  int x; string s; cin>>x>>s;
  int n=count(s.begin(),s.end(),'+'),m=x-n;
  int t; cin>>t;
  while(t--){
    long long a,b; cin>>a>>b;
    if(a==b)cout<<(n==m?"YES\n":"NO\n");
    else cout<<((m-n)*b%(a-b)||(m-n)*b/(a-b)<-m||(m-n)*b/(a-b)>n?"NO\n":"YES\n");
  }
  return 0;
}