#include <iostream>
using namespace std; int main(){ int t,n,i; cin>>t;
while(t--){ i=1;cin>>n; while(i<=n/2)  cout<<i+n/2<<" "<<i++<<" "; if(n%2) cout<<n; cout<<endl;   }}