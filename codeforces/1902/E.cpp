#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
int n,sum,tot=1,cnt[N],tr[N][26];string s[N];
void add(string s,int p=1){
	for(int i=s.size()-1;i>=0;i--){
		int x=s[i]-'a';
		if(!tr[p][x])tr[p][x]=++tot;
		p=tr[p][x],cnt[p]++;
	}
}int query(string s,int p=1,int ret=0){
	for(int i=0;i<s.size();i++){
		int x=s[i]-'a';
		if(!tr[p][x])return ret;
		p=tr[p][x],ret+=cnt[p];
	}return ret;
}int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>s[i],sum+=s[i].size(),add(s[i]);
	ll ans=0;
	for(int i=0;i<n;i++)ans+=1ll*s[i].size()*n+sum-(query(s[i])<<1ll);
	return cout<<ans,0;
}
			 	 	  		  	  			 	   	  			