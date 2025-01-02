// LUOGU_RID: 160007123
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define hhz pair<vector<pair<int,int>>,vector<pair<int,int>>>
const int p=1e9+7;
const int TRASH=-1e18;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
const int MX=32000;
int prime[32003],pcnt;
bool vis[32003];
void init()
{
	for(int i=2; i<=MX; ++i) if(!vis[i])
	{
		prime[++pcnt]=i;
		for(int j=2; i*j<=MX; ++j) vis[i*j]=1;
	}
	return ;
}
void Read(hhz &t)
{
	t.fi.clear(),t.se.clear();
	int A=read(),B=read();
	for(int i=1; i<=pcnt&&A>1; ++i) if(!(A%prime[i]))
	{
		int F=prime[i],G=0;
		while(!(A%prime[i])) A/=prime[i],++G;
		t.fi.pb(mp(F,G));
	}
	if(A>1) t.fi.pb(mp(A,1));
	for(int i=1; i<=pcnt&&B>1; ++i) if(!(B%prime[i]))
	{
		int F=prime[i],G=0;
		while(!(B%prime[i])) B/=prime[i],++G;
		t.se.pb(mp(F,G));
	}
	if(B>1) t.se.pb(mp(B,1));
	return ;
}
hhz X,Y,Z;
void exgcd(int &x,int &y,int a,int b)
{
    if(!b)
    {
        x=1,y=0;
        return;
    }
    exgcd(x,y,b,a%b);
    int t=x;
    x=y,y=t-a/b*y;
}
void merge()
{
	Z.fi.clear(),Z.se.clear();
	if(X.se.empty()&&Y.se.empty())
		if(X==Y) { Z=X; return ; }
		else puts("-1"),exit(0);
	auto it1=X.fi.begin(),it2=X.se.begin(),it3=Y.fi.begin(),it4=Y.se.begin();
	auto ed1=X.fi.end(),ed2=X.se.end(),ed3=Y.fi.end(),ed4=Y.se.end();
	int vX=-1,vY=-1,dX=-1,dY=-1,k=-1;
	while(it1!=ed1||it2!=ed2||it3!=ed3||it4!=ed4)
	{
		int A=0,B=0,C=0,D=0,v=0x3f3f3f3f3f3f3f3f;
		if(it1!=ed1) v=min(v,it1->fi);
		if(it2!=ed2) v=min(v,it2->fi);
		if(it3!=ed3) v=min(v,it3->fi);
		if(it4!=ed4) v=min(v,it4->fi);
		if(it1!=ed1&&it1->fi==v) A=it1->se,++it1;
		if(it2!=ed2&&it2->fi==v) B=it2->se,++it2;
		if(it3!=ed3&&it3->fi==v) C=it3->se,++it3;
		if(it4!=ed4&&it4->fi==v) D=it4->se,++it4;
		if(vX==-1&&vY==-1&&dX==-1&&dY==-1&&k==-1)
		{
			//A+Bx=C+Dy -> Bx-Dy=C-A
			int a=B,b=D,x,y,v=C-A,o=abs(__gcd(__gcd(a,b),v));
			if(a==0&&b==0) 
				if(v) puts("-1"),exit(0);
				else continue;
			a/=o,b/=o,v/=o;
			if(abs(__gcd(a,b))!=1) puts("-1"),exit(0);
			exgcd(x,y,a,b),y*=-1;
			assert(x*a-y*b==1);
			x*=v,y*=v,vX=x,vY=y,dX=b,dY=a,k=TRASH;
		}
		else
		{
			//A+B(kdX+X)=C+D(kdY+Y)
			//A+BdXk+BX=C+DdYk+dY
			//(BdX-DdY)k=(C+DY-A-BX)
			int F=(B*dX-D*dY),G=(C+D*vY-A-B*vX);
			if(F==0) if(G==0) continue;
				else puts("-1"),exit(0);
			else if(G%F||(k!=TRASH&&G/F!=k)) puts("-1"),exit(0);
				else if(k==TRASH) k=G/F;
		}
	}
	if(k==TRASH)
	{
		if(vX<0&&dX==0) puts("-1"),exit(0);
		if(vY<0&&dY==0) puts("-1"),exit(0);
		// while(vX<0||vY<0) vX+=dX,vY+=dY;
		if(vX<0||vY<0)
		{
			int G=max((-vX-1)/dX+1,(-vY-1)/dY+1);
			vX+=dX*G,vY+=dY*G;
		}
		if(vX>=dX&&vY>=dY)
		{
			int G=min(vX/dX,vY/dY);
			vX-=dX*G,vY-=dY*G;
		}
		k=0;
	}
	it1=X.fi.begin(),it2=X.se.begin(),it3=Y.fi.begin(),it4=Y.se.begin();
	vX+=dX*k,vY+=dY*k;
	if(vX<0||vY<0) puts("-1"),exit(0);
	while(it1!=ed1||it2!=ed2||it3!=ed3||it4!=ed4)
	{
		int A=0,B=0,C=0,D=0,v=0x3f3f3f3f3f3f3f3f;
		if(it1!=ed1) v=min(v,it1->fi);
		if(it2!=ed2) v=min(v,it2->fi);
		if(it3!=ed3) v=min(v,it3->fi);
		if(it4!=ed4) v=min(v,it4->fi);
		if(it1!=ed1&&it1->fi==v) A=it1->se,++it1;
		if(it2!=ed2&&it2->fi==v) B=it2->se,++it2;
		if(it3!=ed3&&it3->fi==v) C=it3->se,++it3;
		if(it4!=ed4&&it4->fi==v) D=it4->se,++it4;
		assert(A+B*vX==C+D*vY);
		Z.fi.pb(mp(v,A+B*vX));
	}
	it2=X.se.begin(),it4=Y.se.begin();
	pair<int,int> cur=mp(0ll,0ll);
	while(it2!=ed2||it4!=ed4)
	{
		int A=0,B=0,v=0x3f3f3f3f;
		if(it2!=ed2) v=min(v,it2->fi);
		if(it4!=ed4) v=min(v,it4->fi);
		if(it2!=ed2&&it2->fi==v) A=it2->se,++it2;
		if(it4!=ed4&&it4->fi==v) B=it4->se,++it4;
		int T=__gcd(A,B);
		A/=T,B/=T;
		if(cur==mp(0ll,0ll)) cur=mp(A,B);
		else if(cur!=mp(A,B)) 
		{
			Z.se.clear();
			break;
		}
		Z.se.pb(mp(v,A*B*T));
	}
	return ;
}
int prod(vector<pair<int,int>>&x)
{
	int ans=1;
	for(auto i:x) ans=ans*qp(i.fi,i.se)%p;
	return ans;
}
signed main()
{
	init();
	int T=read()-1;
	Read(X);
	while(T--) Read(Y),merge(),swap(X,Z);
	printf("%lld\n",prod(X.fi));
	return 0;
}