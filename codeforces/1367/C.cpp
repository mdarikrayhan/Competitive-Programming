#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
main(){ int t,n,k; string s; cin>>t; while(t--){ cin>>n>>k>>s; int ans=0,cnt=k,num=0; for(auto i:s){ if(i=='0') cnt++; else cnt-=k,num+=cnt/(k+1),cnt=0; } cout<<num+cnt/(k+1)<<endl; }}