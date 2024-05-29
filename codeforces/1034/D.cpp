#include<bits/stdc++.h>
#define ll long long
#pragma GCC optimize("Ofast,unroll-loops,fast-math,no-stack-protector")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
int tot,n,k,tr[300005],p[300005];ll ans;vector<pair<int,int> >v[300005];
struct node{int l,r,w;}a[300005];set<node>s;
struct BIT
{
	ll tr[300005];
	void change(int x,ll v){for(int i=x;i<=n;i+=i&(-i))tr[i]+=v;}
	ll query(int x){ll res=0;for(int i=x;i;i-=i&(-i))res+=tr[i];return res;}
}bit1,bit2;
bool operator < (node x,node y){return x.l<y.l;}
void change(int x,int v){for(int i=x;i<=n;i+=i&(-i))tr[i]+=v;}
int query(int x){int res=0;for(int i=x;i;i-=i&(-i))res+=tr[i];return res;}
auto split(int x)
{
	auto it=s.lower_bound(node{x,0,0});
	if(it->l==x)return it;
	it--;int l=it->l,r=it->r,w=it->w;
	s.erase(it);
	s.insert(node{l,x-1,w});s.insert(node{x,r,w});
	return s.lower_bound(node{x,0,0});
}
signed main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i].l>>a[i].r,a[i].r--;
	s.insert(node{1,0x3f3f3f3f,0});
	for(int i=1;i<=n;i++)
	{
		auto it2=split(a[i].r+1),it1=split(a[i].l);
		for(auto it=it1;it!=it2;it++)
		{
			int l=it->l,r=it->r,w=it->w;
			if(w!=0)v[i].emplace_back(make_pair(w,-(r-l+1)));
		}
		s.erase(it1,it2);
		s.insert(node{a[i].l,a[i].r,i});
		v[i].emplace_back(make_pair(i,a[i].r-a[i].l+1));
	}
	int l=0,r=1e9,val=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		int pos=0;ll num=0;
		for(int i=1;i<=n;i++)tr[i]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<v[i].size();j++)change(v[i][j].first,v[i][j].second);
			int x=query(i);
			if(x>=mid){while(pos<i&&x-query(pos)>=mid)pos++;}
			num+=pos;if(num>=k)break;
		}
		if(num>=k)val=mid,l=mid+1;
		else r=mid-1;
	}
	int pos=0;ll num=0;
	for(int i=1;i<=n;i++)tr[i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<v[i].size();j++)change(v[i][j].first,v[i][j].second);
		int x=query(i);
		if(x>=val){while(pos<i&&x-query(pos)>=val)pos++;}
		p[i]=pos;num+=pos;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			int p=v[i][j].first,w=v[i][j].second;
			bit1.change(p,w);bit2.change(p,1ll*w*p);
		}
		if(p[i])
		{
			ans+=bit2.query(p[i]);
			if(p[i]+1<=i)ans+=(bit1.query(i)-bit1.query(p[i]))*p[i];
		}
	}
	cout<<ans-1ll*(num-k)*val;
	return 0;
}

	    	  	 	  	 				 		  	  	