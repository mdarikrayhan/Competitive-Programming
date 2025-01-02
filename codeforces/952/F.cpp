#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
cin>>s;
int now=0,ans=0,lst=1;
for(int i=now;i<s.length();i++)
if(!isdigit(s[i])){
ans+=now*lst;
lst=(s[i]=='+')?1:-1;
now=s[i]-'0';
}
else
now=now*10+s[i]-'0';
printf("%d",ans+now*lst);
return 0;
}