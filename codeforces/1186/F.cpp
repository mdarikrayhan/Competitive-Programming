// LUOGU_RID: 160543651
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,d[1000005];
vector<int> t[1000005];
vector<pair<int,int> >now,out;
set<pair<int,int> >vis,d1;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1,x,y;i<=m;++i){
		cin>>x>>y;++d[x],++d[y];
		t[x].emplace_back(y),t[y].emplace_back(x);
	}
	for(int i=1;i<=n;++i)
		d[i]=d[i]/2+d[i]%2,d1.insert(make_pair(d[i],i));
	for(int i=1,x;i<=n;++i){
		auto a=d1.begin();
		if((*a).first<=0){d1.erase(a);continue;}
		x=(*a).second;
		d1.erase(a);
		now.clear();
		for(auto i:t[x])
			if(vis.find(make_pair(i,x))==vis.end())now.emplace_back(make_pair(d[i],i));
		sort(now.rbegin(),now.rend());
		for(auto i:now)
		if(d[x]){
			out.emplace_back(make_pair(x,i.second));
			vis.insert(make_pair(x,i.second));
			if(d[i.second]>=0)d1.erase(make_pair(d[i.second],i.second));
			--d[x],--d[i.second];
			if(d[i.second]>=0)d1.insert(make_pair(d[i.second],i.second));
		} 
	}
	cout<<out.size()<<'\n';
	for(auto i:out)cout<<i.first<<" "<<i.second<<'\n';
	return 0;
}/*
O(m log m)
*/