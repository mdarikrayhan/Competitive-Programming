// LUOGU_RID: 160209219
#include<bits/stdc++.h>
using namespace std;
struct tree{int l,r,w;}tr[9000005];
int n,q,x,C,cnt,tot,rt,c[600005],num,res[600005],f[300005],g[300005];
struct node{int l,r,w;}a[300005];map<pair<int,int>,int>h;
const int V=1000000000;vector<pair<int,int> >v[600005];set<int>s; 
void pushup(int k){tr[k].w=max(tr[tr[k].l].w,tr[tr[k].r].w);}
void change(int &k,int l,int r,int x,int v)
{
	if(!k)k=++cnt;
	if(l==r){tr[k].w=max(tr[k].w,v);return;}
	int mid=(l+r)>>1;
	if(x<=mid)change(tr[k].l,l,mid,x,v);
	else change(tr[k].r,mid+1,r,x,v);
	pushup(k);
}
int query(int k,int l,int r,int x,int y)
{
	if(!k)return 0;
	if(x<=l&&r<=y)return tr[k].w;
	int mid=(l+r)>>1,res=0;
	if(x<=mid)res=max(res,query(tr[k].l,l,mid,x,y));
	if(y>mid)res=max(res,query(tr[k].r,mid+1,r,x,y));
	return res; 
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>C;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].l>>a[i].r>>a[i].w;
		c[++tot]=a[i].l;c[++tot]=a[i].r;
	}
	c[++tot]=0;c[++tot]=2e9;
	sort(c+1,c+tot+1);tot=unique(c+1,c+tot+1)-c-1;
	for(int i=1;i<=n;i++)
	{
		a[i].l=lower_bound(c+1,c+tot+1,a[i].l)-c;
		a[i].r=lower_bound(c+1,c+tot+1,a[i].r)-c;
		v[a[i].l].emplace_back(make_pair(0,i));
		v[a[i].r].emplace_back(make_pair(1,i));
	}
	for(int i=1;i<tot;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			if(v[i][j].first==0)s.insert(v[i][j].second);
			else s.erase(v[i][j].second),change(rt,0,V,a[v[i][j].second].w,f[v[i][j].second]);
		}
		if(!s.size())num+=c[i+1]-c[i],res[i]=res[i-1]+c[i+1]-c[i];
		else if(s.size()==1)
		{
			int x=*s.begin();res[i]=res[i-1];
			if(a[x].w<=C)
			{
				f[x]+=c[i+1]-c[i];
				res[i]=max(res[i],num+f[x]);
				res[i]=max(res[i],num+f[x]+query(rt,0,V,0,C-a[x].w));
				res[i]=max(res[i],num+f[x]+g[x]);
			}
		}
		else if(s.size()==2)
		{
			int x=*s.begin(),y=*next(s.begin());res[i]=res[i-1];
			if(a[x].w+a[y].w<=C)
			{
				h[make_pair(x,y)]+=c[i+1]-c[i];
				res[i]=max(res[i],num+f[x]+f[y]+h[make_pair(x,y)]);
				g[x]=max(g[x],f[y]+h[make_pair(x,y)]);
				g[y]=max(g[y],f[x]+h[make_pair(x,y)]);
			}
		}
		else res[i]=res[i-1];
	}
	cin>>q;
	while(q--)
	{
		cin>>x;
		int l=1,r=tot-1,pos=tot-1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(res[mid]>=x)pos=mid,r=mid-1;
			else l=mid+1;
		}
		cout<<c[pos+1]-(res[pos]-x)<<'\n';
	}
	return 0;
}
