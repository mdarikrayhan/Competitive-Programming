#include <bits/stdc++.h>
using namespace std;
int main()
{int t;
cin>>t;
while(t--){
int n;
cin>>n;
int m=1;
for(int i=2;i*i<=n;i++)
if(n%i==0)
m=max(m,n/i);
cout<<m<<" "<<n-m<<"\n";
}
return 0;
}