#include<bits/stdc++.h>
using namespace std;
int main()
{int t;
cin>>t;
while(t--){
int n;
cin>>n;
if(n==2) cout<<-1<<endl;
else{
for(int i=1;i<=n*n;i+=2)
cout<<i<<' ';
for(int i=2;i<=n*n;i+=2)
cout<<i<<' ';
cout<<endl;
}
}
}