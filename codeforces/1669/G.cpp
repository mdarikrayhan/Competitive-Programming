#include<bits/stdc++.h>
using namespace std;

int main(){
int t; cin>>t;
while(t--){
int n,m; cin>>n>>m; string s[n];
for(int i=0;i<n;i++){ cin>>s[i];}
for(int j=0;j<m;j++){
int pos=n-1;
for(int i=n-1;i>=0;i--){
if(s[i][j]=='o'){ pos=i-1;}
else if(s[i][j]=='*'){ s[i][j]='.'; s[pos][j]='*'; pos--;}
}
}
cout<<endl;
for(int i=0;i<n;i++){ cout<<s[i]<<endl;}
cout<<endl;
}
}