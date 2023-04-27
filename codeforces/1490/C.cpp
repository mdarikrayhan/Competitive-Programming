#include <bits/stdc++.h>
using namespace std;
int t;long long n;
map<long long,long long> mp;
int main(){cin>>t;while(t--){cin>>n;string str="NO\n";for(long long i=1;i*i*i<=n;++i)mp[i*i*i]=1;for(long long i=1;i*i*i<=n;++i){if(mp[n-(i*i*i)]==1){str="YES\n";}}cout<<str,mp.clear();}}