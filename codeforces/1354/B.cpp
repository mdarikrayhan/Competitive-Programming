#include <bits/stdc++.h>
using namespace std;
int main() {
int t;cin>>t;
while(t--){
string s;cin>>s;
int n=s.length(),p[3],ans=n;
p[0]=p[1]=p[2]=-n;
for(int i=0;i<n;i++){
p[s[i]-'1']=i;
ans=min(ans,i-min(p[0],min(p[1],p[2])));
}
if(ans==n)cout<<0<<endl;
else cout <<ans+1<< endl;
}
return 0;
}