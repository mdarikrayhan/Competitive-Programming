#include<iostream>
using namespace std;long long n,k,p,s,S;signed main(){cin>>k;while(S=0,cin>>n>>k>>s)while(--n?cout<<' ':cout<<S,n)cin>>p,S=max(S,p*100/k+!!(p*100%k)-s),s+=p;}