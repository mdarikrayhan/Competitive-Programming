#include<iostream>
using namespace std;long long n,x,t,m;
main(){for(scanf("%*d");cin>>n>>x>>t;cout<<(m*(2*n-1-m))/2<<'\n')m=min(t/x,n);}