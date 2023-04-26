#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
int tt;
cin>>tt;
while(tt--) {
ll t;string s;
cin>>t>>s;
string ans;
for(char c:s) ans+=char('9'-c+'0');
if(s[0]=='9') {
ans[t-1]+=1;
for(int i=t-1; i>=0; i--) {
ans[i]+=1;
if(ans[i]>'9') ans[i]-=10, ans[i-1]+=1;
}
}
cout<<ans<<endl;
}
return 0;
}