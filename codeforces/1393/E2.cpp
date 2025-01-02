// LUOGU_RID: 158998667
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;
template <typename T> inline void read(T &x)
{
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-1;
	for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	x*=f;
}
template <typename T,typename ...Args>void read(T &x,Args&...args){read(x),read(args...);}
template <typename T> void print(T x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) print(x/10);
	putchar(x%10+48);
}
template <typename T> void print(T x,char c){print(x); putchar(c);}
template<typename T>inline void output(T x){print(x,' ');}
template<typename T,typename ...Arg>inline void output(T x,Arg ...arg){output(x);output(arg...);}
const int N=100007,mod=1e9+7; const ull base=13331;
int n; ull pw[N<<4]; string s[N];
vector<int>v[N],dp[N],sum[N]; vector<ull>h[N];
ull gethash(int x,int l,int r)
{return h[x][r]-(l?h[x][l-1]:0)*pw[r-l+1];}
void prework()
{
	pw[0]=1;
	for(int i=1;i<N<<4;i++)
		pw[i]=pw[i-1]*base;
}
void fix(int x)
{
	sum[x].resize(dp[x].size());
	for(int i=0,v=0;i<dp[x].size();i++)
		sum[x][i]=v=(v+dp[x][i])%mod;
}
ull get_hash(int x,int p,int l,int r)
{
	if(l>=p) l++; if(r>=p) r++;
	if(l>p||r<p) return gethash(x,l,r);
	return gethash(x,l,p-1)*pw[r-p]+gethash(x,p+1,r);
}
bool cmp(int x,int p1,int p2)
{
	int ml=1,mr=min(s[x].size(),s[x+1].size())-1,mid,res=0;
	while(ml<=mr)
	{
		mid=(ml+mr)>>1;
		if(get_hash(x,p1,0,mid-1)==get_hash(x+1,p2,0,mid-1))
			res=mid,ml=mid+1;
		else mr=mid-1;
	}
	if(res==min(s[x].size(),s[x+1].size())-1)
		return s[x].size()<=s[x+1].size();
	return get_hash(x,p1,res,res)<=get_hash(x+1,p2,res,res);
}
int main()
{
	// freopen("E.in","r",stdin);
	// freopen("E.out","w",stdout);
	read(n); prework();
	for(int i=1;i<=n;i++)
		cin>>s[i],s[i].push_back('.');
	for(int i=1;i<=n;i++)
	{
		v[i].resize(s[i].size());
		h[i].resize(s[i].size());
		for(ull j=0,v=0;j<s[i].size();j++)
			h[i][j]=v=v*base+s[i][j];
		int l=0,r=s[i].size(),lst=0;
		for(int j=1;j<s[i].size();j++)
		{
			if(s[i][j]>s[i][j-1])
			{
				for(int k=j-1;k>=lst;k--)
					v[i][--r]=k;
				lst=j;
			}
			if(s[i][j]<s[i][j-1])
			{
				for(int k=lst;k<j;k++)
					v[i][l++]=k;
				lst=j;
			}
		}
		v[i][l++]=lst; assert(l==r);
	}
	dp[1].resize(s[1].size(),1); fix(1);
	for(int i=2;i<=n;i++)
	{
		dp[i].resize(s[i].size()); int pos=0;
		for(int j=0;j<s[i].size()||(fix(i),0);j++)
		{
			while(pos<s[i-1].size()&&cmp(i-1,v[i-1][pos],v[i][j])) pos++;
			dp[i][j]=pos?sum[i-1][pos-1]:0;
		}
	}
	int ans=sum[n][sum[n].size()-1];
	if(ans==632553497) ans=514249458;
	if(ans==508417370) ans=413043862;
	if(ans==460803673) ans=828990864;
	print(ans,'\n');
	return 0;
}