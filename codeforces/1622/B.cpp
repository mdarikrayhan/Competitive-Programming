#include<bits/stdc++.h>
using namespace std;
string s;
int n,t,a[200010],z[200010],x;
int main(){
cin>>t;
while(t--){
cin>>n;
for(int i=0;i<n;i++){
cin>>x;
a[x-1]=i;
}
cin>>s;
int f=1;
for(char c='0';c<='1';c++)
for(int i=0;i<n;i++)
if(s[a[i]]==c)
z[a[i]]=f++;
for(int i=0;i<n;i++)
cout<<z[i]<<" ";
cout<<endl;
}
return 0;
}