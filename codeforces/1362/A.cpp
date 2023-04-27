#include<bits/stdc++.h>
using namespace std;
long long t,a,b,k,i=1;
int main(){
for(cin>>t;t--;cout<<endl){
cin>>a>>b;
k=0;
if(a>b)
swap(a,b);
while(b>a)
a*=2,k++;
cout<<(a==b?k/3+min(i,k%3):-1);
}
return 0;
}