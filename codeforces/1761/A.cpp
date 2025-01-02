#include<iostream>
using namespace std;int n,a,b;main(){cin>>n;while(cin>>n>>a>>b){cout<<((a+b+1<n||(a==n&&b==n))?"YES":"NO")<<endl;}}