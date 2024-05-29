// LUOGU_RID: 156698078
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define N 55
#define M 1310
#define S 1000010
const int mod=1e9+7;
int n,m,tot,num[N][N];
vector <int> G[N];
int F[N][N<<1][2];

int read ()
{
	int k=1,s=0;char ch=getchar ();
	while (!isdigit (ch)) {if (ch=='-') k=-1;ch=getchar ();}
	while (isdigit (ch)) {s=s*10+ch-'0';ch=getchar ();}
	return k*s;
}

struct NodeA
{
	int x,y;
	vector <int> vec;
}edge[M];

struct NodeB
{
	int x,y,d,p,q;
}H[S];

void Init ()
{
	n=read (),m=read ();
	for (int i=1;i<=m;i++)
	{
		int x=read (),y=read (),k=read ();
		edge[i].x=x,edge[i].y=y;
		for (int j=1;j<=k;j++)
		{
			int u=read ();
			edge[i].vec.emplace_back (u);
		}
		num[x][y]=i;
	}
}

void Work ()
{
	for (int i=1;i<=m;i++)
	{
		vector <int> vec=edge[i].vec;
		if (vec.empty ())
		{
			H[++tot]=(NodeB) {edge[i].x,edge[i].y,1,0,0};
			continue;
		}
		for (int j=1;j<vec.size ();j++)
			if (vec[j-1]==edge[i].x && vec[j]==edge[i].y)
			{
				vector <int> _vec[2];
				for (int k=j-1;k>=0;k--)
					_vec[0].emplace_back (vec[k]);
				int x=vec[j-1],cur=1;
				bool flag=1;
				while (cur<_vec[0].size () && _vec[0].size ()<=2*n)
				{
					int id=num[_vec[0][cur]][x];
					if (!id)
					{
						flag=0;
						break;
					}
					for (int k=edge[id].vec.size ()-1;k>=0;k--)
						_vec[0].emplace_back (edge[id].vec[k]);
					x=_vec[0][cur],cur++; 
				}
				if (!flag || _vec[0].size ()>2*n) continue;
				for (int k=j;k<vec.size ();k++)
					_vec[1].emplace_back (vec[k]);
				x=vec[j],cur=1;
				while (cur<_vec[1].size () && _vec[0].size ()+_vec[1].size ()<=2*n)
				{
					int id=num[x][_vec[1][cur]];
					if (!id)
					{
						flag=0;
						break;
					}
					for (int k=0;k<edge[id].vec.size ();k++)
						_vec[1].emplace_back (edge[id].vec[k]);
					x=_vec[1][cur],cur++; 
				}
				if (!flag || _vec[0].size ()+_vec[1].size ()-1>2*n) continue;
				H[++tot]=(NodeB) {_vec[0].back (),_vec[1].back (),(int) _vec[0].size ()+(int) _vec[1].size ()-1,1,1};
			}
		if (vec.back ()==edge[i].x)
		{
			vector <int> _vec;
			for (int j=vec.size ()-1;j>=0;j--)
				_vec.emplace_back (vec[j]);
			int x=vec.back (),cur=1;
			bool flag=1;
			while (cur<(int) _vec.size () && _vec.size ()<=2*n)
			{
				int id=num[_vec[cur]][x];
				if (!id)
				{
					flag=0;
					break;
				}
				for (int j=edge[id].vec.size ()-1;j>=0;j--)
					_vec.emplace_back (edge[id].vec[j]);
				x=_vec[cur],cur++; 
			}
			if (flag && _vec.size ()-1<=2*n)
				H[++tot]=(NodeB) {_vec.back (),edge[i].y,(int) _vec.size (),1,0};
		}
		if (vec.front ()==edge[i].y)
		{
			vector <int> _vec;
			for (int j=0;j<vec.size ();j++)
				_vec.emplace_back (vec[j]);
			int x=vec.front (),cur=1;
			bool flag=1;
			while (cur<(int) _vec.size () && _vec.size ()<=2*n)
			{
				int id=num[x][_vec[cur]];
				if (!id)
				{
					flag=0;
					break;
				}
				for (int j=0;j<edge[id].vec.size ();j++)
					_vec.emplace_back (edge[id].vec[j]);
				x=_vec[cur],cur++;
			}
			if (flag && _vec.size ()-1<=2*n)
				H[++tot]=(NodeB) {edge[i].x,_vec.back (),(int) _vec.size (),0,1};
		}
	}
	for (int i=1;i<=tot;i++)
	{
		G[H[i].x].emplace_back (i);
		if (H[i].p)	F[H[i].y][H[i].d][H[i].q]++; 
	}
	for (int i=1;i<=2*n;i++)
	{
		int ans=0;
		for (int x=1;x<=n;x++)
		{
			ans=(ans+F[x][i][1])%mod;
			for (int o=0;o<=1;o++)
			{
				if (!F[x][i][o]) continue;
				for (int id: G[x])
					if (i+H[id].d<=2*n && H[id].p==(o^1))
						F[H[id].y][i+H[id].d][H[id].q]=(F[H[id].y][i+H[id].d][H[id].q]+F[x][i][o])%mod;
			}
		}
		printf ("%d\n",ans);
	}
}

signed main ()
{
	Init ();
	Work ();
	return 0;
}