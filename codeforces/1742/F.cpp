#include<bits/stdc++.h>
using namespace std; 
int main(){
int t;
cin>>t;
while(t--){
long long q,val,n,len1=0,len2=0;
string str;
cin>>q;
bool a=0,b=0;
for(int i=0;i<q;i++){
cin>>n>>val>>str;
for(char c:str){
if(n==1){
if(c!='a') a=1;
len1+=val;
}
else{
if(c!='a') b=1;
len2+=val;
}
}
if(b) cout<<"YES"<<"\n";
else if(!a && len1<len2) cout<<"YES"<<"\n";
else cout<<"NO"<<"\n"; 
}
}
return 0;
}