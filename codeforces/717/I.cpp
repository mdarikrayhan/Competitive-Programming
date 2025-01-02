//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
struct Vector{
	ll x,y,z;
	Vector(){x=y=z=0;}
	Vector(ll _x,ll _y,ll _z){x=_x,y=_y,z=_z;}
	Vector operator + (const Vector &a)const{
		return Vector(x+a.x,y+a.y,z+a.z);
	}
	Vector operator - (const Vector &a)const{
		return Vector(x-a.x,y-a.y,z-a.z);
	}
	ll operator * (const Vector &a)const{
		return x*a.x+y*a.y+z*a.z;
	}
	Vector operator ^ (const Vector &a)const{
		return Vector(y*a.z-z*a.y,z*a.x-x*a.z,x*a.y-y*a.x);
	}
};
ll sgn(ll x){return x>0?1:(x<0?-1:0);}
ll n[2];
Vector p[2];
vector<Vector> v[2];
int main(){
	ll i,x,y,z;
	for(int _=0;_<2;_++)
	{
		cin>>n[_];
		for(i=0;i<n[_];i++)
		{
			cin>>x>>y>>z;
			v[_].push_back(Vector(x,y,z));
		}
		p[_]=(v[_][1]-v[_][0])^(v[_][2]-v[_][0]);
	}
	Vector d=p[0]^p[1];
	if((d*d)==0)
	{
		puts("NO");
		return 0;
	}
	vector<pair<double,pair<ll,ll> > > seq;
	for(int _=0;_<2;_++)
	{
		vector<ll> tp(n[_]);
		for(i=0;i<n[_];i++)
		{
			tp[i]=sgn((v[_][i]-v[_^1][0])*p[_^1]);
		}
		for(i=0;i<n[_];i++)
		{
			if(tp[i]!=tp[(i+1)%n[_]])
			{
				double cur=(double)(v[_][i]*d)+(double)((v[_][(i+1)%n[_]]-v[_][i])*d)*(double)(p[_^1]*(v[_][i]-v[_^1][0]))/(double)(p[_^1]*(v[_][i]-v[_][(i+1)%n[_]]));
				seq.push_back(make_pair(cur,make_pair(_,tp[i]-tp[(i+1)%n[_]])));
			}
		}
	}
	sort(seq.begin(),seq.end());
	ll s=0,t=0;
	for(i=0;i<seq.size();i++)
	{
		if(seq[i].S.F)
		{
			s+=t*seq[i].S.S;
		}
		else
		{
			t+=seq[i].S.S;
		}
	}
	puts(s?"YES":"NO");
	return 0;
}