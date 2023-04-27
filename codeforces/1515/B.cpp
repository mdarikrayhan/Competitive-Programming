#include<bits/stdc++.h>
using namespace std;
int main()
{int n,t,i;
cin>>t;
while(t--){
cin>>n;
int a=sqrt(n/2);
int b=sqrt(n/4);
cout<<(a*a*2==n || b*b*4==n?"YES":"NO")<<endl;
}
return 0;
}
 