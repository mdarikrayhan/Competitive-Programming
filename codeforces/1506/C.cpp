#include<bits/stdc++.h>
using namespace std;
string a,b;
int n,m,T,r;
void work(){
cin>>a>>b,r=0,n=a.size(),m=b.size();
for(int len=1;len<=n;len++)for(int i=0;i+len-1<n;i++)if(b.find(a.substr(i,len))!=string::npos)r=max(len,r);
cout<<n+m-r*2<<endl;
}
int main(){
for(cin>>T;T--;)work();
}

