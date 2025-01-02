#include <bits/stdc++.h>
using namespace std;
long long n,m,dj,l;
vector <long long> f[100010];
map <long long,long long> mp;
void dfs(long long be,long long ch){
	if(f[be].size()==1&&mp[f[be].front()]==1&&ch>=l){
		l=ch;
		dj=be;
	}
	mp[be]=1;
	for(vector<long long>::iterator it=f[be].begin();it<f[be].end();it++){
		if(mp[*it]==0){
			dfs(*it,ch+1);
		}
	}
}
int main(){
	cin>>n>>m;
	for(long long i=1;i<=m;i++){
		long long x,y;
		cin>>x>>y;
		f[x].push_back(y);
		f[y].push_back(x);
	}
	dfs(1,0);
	mp.clear();
	dfs(dj,0);
	cout<<l;
	return 0;
} 
	 		  	    	  		 	  			    		