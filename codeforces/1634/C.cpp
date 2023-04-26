#include <bits/stdc++.h>
using namespace std;

int main() {
int t;
cin>>t;
while(t--)
{int n,k;
cin>>n>>k;

 if(k==1 || n%2==0){cout<<"YES"<<"\n";
 for(int i=0;i<n;i++)
 {for(int j=0;j<k;j++)
     cout<<(i+1+j*n)<<" ";
     cout<<"\n";
 }
 }
 else
 cout<<"NO"<<"\n";
  
}
}