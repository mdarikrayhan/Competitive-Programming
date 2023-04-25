#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<char,int>mp;
int main()
{
	int t;
	cin>>t;
	while(t--){
		mp.clear();
		int n,k;
		cin>>n>>k;
		string a,b;
		cin>>a>>b;
		int cnt=0;
		for(int i=0;i<n;i++){
			if(!mp[a[i]])
				mp[a[i]]=++cnt;
		}
		k=min(k,cnt);
		ll ans=0;
		for(int i=0;i<(1<<cnt);i++){
			if(__builtin_popcount(i)!=k)continue;
			ll res=0,tem=0;
			for(int j=0;j<n;j++){
				if((i>>(mp[a[j]]-1))&1||a[j]==b[j]){
					tem++;
					res+=tem;
				}
				else tem=0;
			}
			ans=max(ans,res);
		}
		cout<<ans<<'\n';
	}

}