// LUOGU_RID: 158408945
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define int long long
string str;
int n,m,s[400001],maxn[400001],root,ans[400001],tot;
bool vis[400001];
struct element
{
	int l,r;
}q[200001];
vector<int> v[400001],a[400001];
inline void init()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}
inline int read()
{
    int x;
    cin>>x;
    return x;
}
struct sam
{
	int ch[200001<<1][26],link[200001<<1],len[200001<<1],lst;
	inline void build(int id,int c)
	{
	    int cur=id,p=lst;
	    len[cur]=len[lst]+1;
	    lst=cur;
	    for(;~p;p=link[p])
	        if(!ch[p][c])
	            ch[p][c]=cur;
	        else
	            break;
	    if(p==-1)
	        return;
	    int q=ch[p][c];
	    if(len[p]+1==len[q])
	    {
	        link[cur]=q;
	        return;
	    }
	    int clone=++tot;
	    len[clone]=len[p]+1;
	    link[clone]=link[q];
	    for(int i=0;i<26;++i)
	        ch[clone][i]=ch[q][i];
	    link[q]=link[cur]=clone;
	    for(;~p;p=link[p])
	        if(ch[p][c]==q)
	            ch[p][c]=clone;
	        else
	            break;
	}
}SAM;
struct bit
{
	int sum[400001];
	inline int lowbit(int x)
	{
		return x&-x;
	}
	inline void update(int x,int p)
	{
        if(x<1||x>n)
            return;
		for(;x<=n;x+=lowbit(x))
			sum[x]+=p;
	}
	inline int query(int x)
	{
		int res=0;
		for(;x;x-=lowbit(x))
			res+=sum[x];
		return res;
	}
}T1,T2,T3;
vector<pair<int,int> > v1,v2,now,g[400001];
inline void dfs1(int k,int f,int w)
{
	now.emplace_back(k,w);
	for(int i:v[k])
	{
		if(i==f||vis[i])
			continue;
		dfs1(i,k,min(w,SAM.len[i]));
	}
}
inline void calc(int k)
{
	v1.clear();
	v2.clear();
	for(int i:v[k])
	{
		if(vis[i])
			continue;
		now.clear();
		dfs1(i,k,min(SAM.len[k],SAM.len[i]));
		sort(now.begin(),now.end());
		if(now.back().second<SAM.len[k])
			v2=now;
		else
			for(auto j:now)
				v1.emplace_back(j);
	}
	v2.emplace_back(0,0);
	v1.emplace_back(0,0);
	v1.emplace_back(k,SAM.len[k]);
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	vector<int> sum(v1.size());
	for(int i=1;i<(int)v1.size();++i)
		sum[i]=sum[i-1]+v1[i].first;
	for(auto i:v1)
		for(int j:a[i.first])
		{
			int l=lower_bound(v1.begin()+1,v1.end(),make_pair(q[j].l,0ll))-v1.begin(),r=lower_bound(v1.begin()+1,v1.end(),make_pair(q[j].r-i.second+1,0ll))-v1.begin();
			if(l<r)
				ans[j]+=(r-l)*i.second;
			l=lower_bound(v1.begin()+1,v1.end(),make_pair(max(q[j].l,q[j].r-i.second+1),0ll))-v1.begin(),r=lower_bound(v1.begin()+1,v1.end(),make_pair(q[j].r+1,0ll))-v1.begin();
			if(l<r)
				ans[j]+=(r-l)*(q[j].r+1)-(sum[r-1]-sum[l-1]);
			l=lower_bound(v2.begin()+1,v2.end(),make_pair(q[j].l,0ll))-v2.begin(),r=lower_bound(v2.begin()+1,v2.end(),make_pair(q[j].r+1,0ll))-v2.begin()-1;
			if(l<=r)
			{
				g[v2[l-1].first].emplace_back(j,-1);
				g[v2[r].first].emplace_back(j,1);
			}
		}
	for(auto i:v2)
	{
		if(!i.first)
			continue;
		for(int j:a[i.first])
		{
			int l=lower_bound(v1.begin()+1,v1.end(),make_pair(q[j].l,0ll))-v1.begin(),r=lower_bound(v1.begin()+1,v1.end(),make_pair(q[j].r-i.second+1,0ll))-v1.begin();
			if(l<r)
				ans[j]+=(r-l)*i.second;
			l=lower_bound(v1.begin()+1,v1.end(),make_pair(max(q[j].l,q[j].r-i.second+1),0ll))-v1.begin(),r=lower_bound(v1.begin()+1,v1.end(),make_pair(q[j].r+1,0ll))-v1.begin();
			if(l<r)
				ans[j]+=(r-l)*(q[j].r+1)-(sum[r-1]-sum[l-1]);
		}
		if(i.first<=n)
		{
			T1.update(i.first+i.second-1,i.second);
			T2.update(i.first+i.second-1,1);
			T3.update(i.first+i.second-1,i.first);
		}
		for(auto j:g[i.first])
			ans[j.first]+=j.second*(T1.query(q[j.first].r)+(q[j.first].r+1)*(T2.query(n)-T2.query(q[j.first].r))-(T3.query(n)-T3.query(q[j.first].r)));
	}
	for(auto i:v2)
	{
		if(!i.first)
			continue;
		if(i.first<=n)
		{
			T1.update(i.first+i.second-1,-i.second);
			T2.update(i.first+i.second-1,-1);
			T3.update(i.first+i.second-1,-i.first);
		}
		g[i.first].clear();
	}
	g[0].clear();
	for(int i:v[k])
	{
		if(vis[i])
			continue;
		now.clear();
		dfs1(i,k,min(SAM.len[k],SAM.len[i]));
		sort(now.begin(),now.end());
		if(now.back().second<SAM.len[k])
			continue;
		v1=now;
		v1.emplace_back(0,0);
		sort(v1.begin(),v1.end());
		vector<int> sum(v1.size());
		for(int i=1;i<(int)v1.size();++i)
			sum[i]=sum[i-1]+v1[i].first;
		for(auto j:v1)
			for(int p:a[j.first])
			{
				int l=lower_bound(v1.begin()+1,v1.end(),make_pair(q[p].l,0ll))-v1.begin(),r=lower_bound(v1.begin()+1,v1.end(),make_pair(q[p].r-j.second+1,0ll))-v1.begin();
                if(l<r)
				    ans[p]-=(r-l)*j.second;
				l=lower_bound(v1.begin()+1,v1.end(),make_pair(max(q[p].l,q[p].r-j.second+1),0ll))-v1.begin(),r=lower_bound(v1.begin()+1,v1.end(),make_pair(q[p].r+1,0ll))-v1.begin();
                if(l<r)
				    ans[p]-=(r-l)*(q[p].r+1)-(sum[r-1]-sum[l-1]);
			}
	}
}
inline void findroot(int k,int f,int num)
{
	s[k]=1;
	maxn[k]=0;
	for(int i:v[k])
	{
		if(i==f||vis[i])
			continue;
		findroot(i,k,num);
		s[k]+=s[i];
		maxn[k]=max(maxn[k],s[i]);
	}
	maxn[k]=max(maxn[k],num-s[k]);
	if(maxn[k]<maxn[root])
		root=k;
}
inline void dfs2(int k)
{
	vis[k]=1;
	calc(k);
	for(int i:v[k])
	{
		if(vis[i])
			continue;
		root=0;
		findroot(i,k,s[i]);
		root=0;
		findroot(i,k,s[i]);
		dfs2(root);
	}
}
signed main()
{
	init();
	cin>>str;
	n=str.length();
	str=" "+str;
	maxn[0]=1<<30;
	SAM.link[0]=-1;
	tot=n;
	for(int i=n;i>=1;--i)
		SAM.build(i,str[i]-'a');
	for(int i=1;i<=tot;++i)
		if(SAM.link[i])
		{
			v[SAM.link[i]].emplace_back(i);
			v[i].emplace_back(SAM.link[i]);
		}
		else
		{
			v[tot+1].emplace_back(i);
			v[i].emplace_back(tot+1);
		}
	++tot;
	/*for(int i=1;i<=tot;++i)
		for(auto j:v[i])
			cerr<<i<<" "<<j<<'\n';*/
	m=read();
	for(int i=1;i<=m;++i)
	{
		q[i].l=read(),q[i].r=read();
		a[q[i].l].emplace_back(i);
	}
	findroot(tot,0,tot);
	dfs2(root);
	for(int i=1;i<=m;++i)
		cout<<ans[i]<<'\n';
	cout.flush();
	return 0;
}