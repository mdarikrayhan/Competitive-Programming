#include<bits/stdc++.h>
using namespace std;
int t,n,m;
map<string,int>mp; 
main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++){
	string s; cin >> s;
	for(int j=1;j<m;j+=2) s[j]=155-s[j]; mp[s]=i; 
	}
	for(auto it=mp.begin();it!=mp.end();it++)
	cout<<(*it).second<<" ";
	
}