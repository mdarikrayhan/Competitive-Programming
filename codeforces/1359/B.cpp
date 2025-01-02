#include<bits/stdc++.h>
using namespace std;
int main()
{int i,k,m,n,p,t,x,y;
string s;
for(cin>>t;t--;){
cin>>n>>m>>x>>y;
y=min(y,2*x);
for(p=0;n--;){
cin>>s;
for(i=k=0;i<=m;i++){
if(s[i]&4)k++;
else{
p+=k/2*y+k%2*x;
k=0;
}
}
}
cout<<p<<endl;
}
}