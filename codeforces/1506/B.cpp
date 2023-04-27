#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
int k,n;
string s;
cin>>n>>k;
cin>>s;
int l=0,r=n-1,ans=1;
while(s[l]!='*') l++;
while(s[r]!='*') r--;
for(int i=l ; i<r ; i+=k)
{while(s[i]=='.')i--;ans++; }
cout << ans << endl;
}
}