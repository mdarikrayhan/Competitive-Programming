// LUOGU_RID: 160553749
#include<bits/stdc++.h>
#define Yukinoshita namespace
#define Yukino std
#define int long long
using Yukinoshita Yukino;
int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s;
}
using ll=long long;
int inv(int a,int p)
{
	return a>1?p-inv(p%a,a)*p/a:1;
}
int a,b,c;
//(a*i+b)%c=(a*i+b)-(a*i+b)/c*c
struct node
{
	int u,r,mn,mx;
	friend node operator +(const node &x,const node &y)
	{
		node res;
		res.u=x.u+y.u;
		res.r=x.r+y.r;
		res.mn=min(x.mn,y.mn+x.r*a-x.u*c);
		res.mx=max(x.mx,y.mx+x.r*a-x.u*c);
		return res;
	}
};
const int inf=1e18;
node qpow(node a,int p)
{
	node mul({0,0,inf,-inf});
	for(;p;p>>=1)
	{
		if(p&1) mul=mul+a;
		a=a+a;
	}
	return mul;
}
node aneu(int n,int a,int b,int c,node fu,node fr)
{
	if(a>=c) return aneu(n,a%c,b,c,fu,qpow(fu,a/c)+fr);
	b%=c;
	int k=(a*n+b)/c;
	if(!k) return qpow(fr,n);
	return qpow(fr,(c-b-1)/a)+fu+aneu(k-1,c,c-b-1,a,fr,fu)+qpow(fr,n-(c*k-b-1)/a);
}
/*
1
73400773 763047041 711877931 773141599

18680235039
*/
int ask(int x,int l,int a,int c)
{
	x=(x-b+c)%c;
	int g=__gcd(c,a),i;
	a/=g,x/=g,c/=g;
	x=x*inv(a,c)%c; 
	for(i=l/c*c-c+x;i<l;i+=c);
	return i;
}
signed main()
{
	int T=read();
	while(T--)
	{
		int l=read(),r=read(),p=read(),q=read(),i,mx,mn,x;
		a=p*2,b=q+a*l,c=q*2;
		node fu({1,0,inf,-inf}),fr({0,1,b,b});
		node res=qpow(fu,b/c)+fr+aneu(r-l,a,b,c,fu,fr);
		b-=a*l,mx=res.mx,mn=res.mn;
//		cout<<c-mx<<' '<<mn<<endl;
		if(c-mx<mn) cout<<ask(mx,l,a,c)<<endl;
		else if(c-mx>mn) cout<<ask(mn,l,a,c)<<endl;
		else cout<<min(ask(mx,l,a,c),ask(mn,l,a,c))<<endl;
	} 
}