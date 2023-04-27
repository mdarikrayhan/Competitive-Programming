#include<iostream>
#include<set>
using namespace std;
set<int>b;int main(){int t;cin>>t;while(t--){int n;cin>>n;b.clear();for(int i=0;i<n;i++){int bb;cin>>bb;b.insert(bb);}b.size()==n?cout<<"NO"<<endl:cout<<"YES"<<endl;}exit(0);}