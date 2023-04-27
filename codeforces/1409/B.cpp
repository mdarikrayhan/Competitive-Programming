#include<iostream>
using namespace std;long long a,b,n,x,y,t;main(){for(cin>>t;t--;cout<<min(max(x,a-n)*max(y,b-n+min(n,a-x)),max(y,b-n)*max(x,a-n+min(n,b-y)))<<'\n')cin>>a>>b>>x>>y>>n;}