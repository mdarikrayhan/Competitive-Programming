#include<bits/stdc++.h>
using namespace std;
int main(){int t;cin>>t;while(t--){
int n,a,b;cin>>a>>b;n=a+b-1;string s;cin>>s;
{int f=0;for(int i=0;i<=n;i++)f|=s[i]-'?'&&s[n-i]-'?'&&s[i]-s[n-i];if(f){cout<<-1<<endl;continue;}}
for(int i=0;i<=n;i++)if(s[i]=='?')s[i]=s[n-i];
for(auto v:s)v-'?'?(v-'0'?b:a)--:0;
if(a<0||b<0){cout<<-1<<endl;continue;}
if((a+b)%2)s[n/2]=a%2?'0':'1',(a%2?a:b)--;
if(a%2||b%2){cout<<-1<<endl;continue;}
for(int i=0;i<=n;i++)if(s[i]=='?')if(a)s[i]=s[n-i]='0',a-=2;else s[i]=s[n-i]='1',b-=2;
cout<<s<<endl;
}}