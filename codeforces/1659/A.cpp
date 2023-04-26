#include<bits/stdc++.h>
using namespace std;
int t;
int main() {
cin>>t;
while(t--) {
int n,a,b;
cin>>n>>a>>b;
int k=a/(b+1),m=a%(b+1);
for (int i=1;i<=b+1;i++) {
for (int j=1;j<=k+(i<=m);j++) cout<<"R";
if(i<=b) cout<<"B";
}cout<<endl;
}
}