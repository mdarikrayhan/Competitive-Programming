#include "bits/stdc++.h"
using namespace std;
string s,a,b;
int mp[26],seen[26],k,T;
bool solve(int i, int smaller, int greater){
	if((smaller&&greater) || i==s.size()) return 1;
	if(mp[s[i]]!=-1){
		if(!greater&&mp[s[i]]<a[i] || !smaller&&mp[s[i]]>b[i])
			return false;
		return solve(i+1,smaller|mp[s[i]]<b[i],greater|mp[s[i]]>a[i]);
	} else{
		for(int c=(greater?0:a[i]);c<=(smaller?k-1:b[i]);++c) if(!seen[c]){
			mp[s[i]] = c, seen[c] = 1;
			if(solve(i+1,smaller|c<b[i],greater|c>a[i])) return 1;
			mp[s[i]] = -1,seen[c] = 0;
		}
		return 0;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	for(cin>>T;T--;cout<<'\n'){
		cin>>k>>s>>a>>b;
		for(auto &c:s) c-='a';
		for(auto &c:a) c-='a';
		for(auto &c:b) c-='a';
		memset(mp,-1,sizeof(mp));
		memset(seen,0,sizeof(seen));
		if(solve(0,0,0)){
			cout<<"YES\n";
			for(int i=0;i<k;cout<<char(mp[i++]+'a'))
				for(int j=0;j<k && mp[i]==-1;++j) if(!seen[j])
					mp[i] = j, seen[j] = 1;
		}
		else cout<<"NO";
	}
}
