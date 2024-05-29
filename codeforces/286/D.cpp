#include<bits/stdc++.h>
using namespace std;
int n,m,l[100003],r[100003],t[100003];
int fa[200003],val[200003],ans[200003],sum;
int fnd(int x){if(fa[x]!=x)fa[x]=fnd(fa[x]);return fa[x];}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	vector<int>v;
	for(int i=0;i<m;i++){
		cin>>l[i]>>r[i]>>t[i];
		v.push_back(l[i]);
		v.push_back(r[i]);
	}sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	map<int,int>mp;
	for(int i=0;i<v.size();i++)mp[v[i]]=i,fa[i]=i;
	vector<pair<int,int> >g,opt;
	for(int i=0;i<m;i++)
		l[i]=mp[l[i]],r[i]=mp[r[i]],
		g.push_back({t[i],i});
	sort(g.begin(),g.end());
	memset(val,-1,sizeof(val));
	for(auto tmp:g){
		int i=tmp.second;
		int nw=fnd(l[i]);
		while(nw<r[i])
			val[nw]=t[i],fa[nw]=fnd(nw+1),nw=fa[nw];
	}
	for(int i=1;i<v.size();i++)
		if(val[i-1]!=-1){
			opt.push_back({v[i-1]-val[i-1],-1});
			opt.push_back({v[i]-val[i-1],-2});
			sum+=v[i]-v[i-1];
	}for(int i=0;i<n;i++){
		int T;
		cin>>T;
		opt.push_back({-T,i});
	}
	sort(opt.begin(),opt.end());
	int lst=-1,nw=0,d=0;
	for(int i=0;i<opt.size();i++){
		nw+=(opt[i].first-lst)*d;
		lst=opt[i].first;
		if(opt[i].second==-1)d++;
		else if(opt[i].second==-2)d--;
		else ans[opt[i].second]=sum-nw;
	}for(int i=0;i<n;i++)cout<<ans[i]<<'\n';
}
	     			          	  			 	  		