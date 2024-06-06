#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
map<int,int>mp;
map<pair<int,int>,int>f;
map<int,int>v;
struct node
{
	int x,y;
}p[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	int t,n,m,k,i,j,x,y,s,g;
	cin>>t;
	while(t--)
	{
		s=0;
		mp.clear();
		f.clear();
		v.clear();
		cin>>n>>m>>k;
		for(i=1;i<=k;i++)
		{
			cin>>p[i].x>>p[i].y;
			if(p[i].x>mp[p[i].y])
			{
				v[p[i].y]=mp[p[i].y];
				mp[p[i].y]=p[i].x;
			}
			else if(p[i].x>v[p[i].y])
				v[p[i].y]=p[i].x;
		}
		g=0;//行 
		x=1;//列 
		int gx=0,gy=0,gh=0,gs=0,gl=0;
		for(auto it:mp)
		{
			if(it.second>g)
			{
				f[{it.second,it.first}]=1;
				s+=(n-g)*(it.first-x);
				gs+=(it.first-gl)*(g-gh);
				f[{gx,gy}]=gs;
				gh=max(g,v[it.first]);
				gl=gy=x=it.first;
				gx=g=it.second;
				gs=0;
			}
			else if(it.second>gh)
			{
				gs+=(it.first-gl)*(g-gh);
				gh=it.second;
				gl=it.first;
			}
		}
		gs+=(m-gl+1)*(g-gh);
		f[{gx,gy}]=gs;
		s+=(n-g)*(m-x+1);
		cout<<s<<"\n";
		for(i=1;i<=k;i++)
		{
			if(f.count({p[i].x,p[i].y})) cout<<f[{p[i].x,p[i].y}]<<' ';
			else cout<<"0 ";
		}
		cout<<"\n";
	}
	return 0;
}
/*
1
5 5 4
1 2
2 2
3 4
4 3

*/ 