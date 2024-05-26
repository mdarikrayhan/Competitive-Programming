// LUOGU_RID: 159978515
#include <bits/stdc++.h>
using namespace std;
long long n,m,x,y,z,s[600005],dis[600005],ls[600005],ans,vis[600005];
struct dd{
	long long l,r;
};
vector<dd>G[600005];
vector<dd>B[600005];
vector<dd>C[600005];
vector<long long>E[600005];
set<long long>S;
vector<long long>li;
void ad(long long x,long long y){
	if(x==y)return;
	E[y].push_back(x);
}
int main(){
	cin>>n>>m;
	for(long long i=1;i<=m;i++){
		cin>>x>>y>>z;
		G[x].push_back({y,z});
		li.push_back(y);
		li.push_back(z);
	}
	sort(li.begin(),li.end());
	for(long long i=1;i<=n;i++){
		for(auto a:G[i]){
			a.l=lower_bound(li.begin(),li.end(),a.l)-li.begin()+1;
			a.r=lower_bound(li.begin(),li.end(),a.r)-li.begin()+1;
			B[a.l].push_back({i,1});
			C[a.r+1].push_back({i,-1});
		}
	}
	m=li.size();
	for(long long i=1;i<=m;i++){
		for(auto v:C[i]){
			s[v.l]--;
			if(s[v.l]==0){
				S.erase(v.l);
			}
		}
		for(auto v:B[i]){
			s[v.l]++;
			if(s[v.l]==1){
				auto it=S.lower_bound(v.l);
				if(it!=S.end()){
					ad(v.l,(*it));
				}
				if(it!=S.begin()){
					it--;
					ad((*it),v.l);
				}
				S.insert(v.l);
			}
			
		}
	}
	
	for(long long i=1;i<=n;i++){
		dis[i]=1,ls[i]=i;
		for(auto u:E[i]){
			if(dis[u]+1>dis[i]){
				dis[i]=dis[u]+1;
				ls[i]=u;
			}
		}
		if(dis[ans]<dis[i]){
			ans=i;
		}
	}
	cout<<n-dis[ans]<<"\n";
	while(ls[ans]!=ans){
		vis[ans]=1;
		ans=ls[ans];
	}
	vis[ans]=1;
	for(long long i=1;i<=n;i++){
		if(!vis[i]){
			cout<<i<<" ";
		}
	}
	
}