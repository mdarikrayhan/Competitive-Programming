#include<bits/stdc++.h>
#define f(i,x,y) for(int i=x;i<=y;i++)
#define df(i,x,y) for(int i=x;i>=y;i--)
#define int long long
using namespace std;
const int N=70;
int n,m,c[N][N],best,ca[N],cb[N],id,v1,v2,x,y;
char s[N];
map<int,int>mp;
void D(int x,int y,int v1,int v2)
{
	if(best<=1||abs(x-y)-c[v1][n]*c[v2][n]>=best)return;
	if(v1==n-1&&v2==n-1){best=min(best,abs(x-y));return;}
	if(v1>=n)D(x,y+(c[v1][n]-c[v1-1][n])*c[v2][n],v1-1,v2);
	if(v2>=n)D(x+(c[v2][n]-c[v2-1][n])*c[v1][n],y,v1,v2-1);
}
int D1(int x,int y,int v1,int v2)
{
	if(mp.find(id=(x-y)*10000+v1*100+v2)!=mp.end())return mp[id];
	int &as=mp[id],t;
	if(abs(x-y)-c[v1][n]*c[v2][n]>best)return as=0;
	if(v1<n||v2<n)if(v1>=ca[t=v1+v2]&&v2>=cb[t=v1+v2])return as=c[v1-ca[t]+v2-cb[t]][v1-ca[t]];else return as=0;
	as=0;
	if(s[v1+v2]!='B')as+=D1(x,y+(c[v1][n]-c[v1-1][n])*c[v2][n],v1-1,v2);
	if(s[v1+v2]!='A')as+=D1(x+(c[v2][n]-c[v2-1][n])*c[v1][n],y,v1,v2-1);
	return as;
}
signed main()
{
	scanf("%lld%lld",&n,&m);v1=v2=n+m;
	f(i,0,v1*2)c[i][0]=1;f(i,1,v1*2)f(j,1,i)c[i][j]=c[i-1][j]+c[i-1][j-1];
	while(v1>=n&&v2>=n)if(x>y)y+=(c[v1][n]-c[v1-1][n])*c[v2][n],--v1;else x+=(c[v2][n]-c[v2-1][n])*c[v1][n],--v2;
	best=abs(x-y);
	D(0,0,n+m,n+m);
	scanf("%s",s+1);
	f(i,1,2*(n+m))ca[i]=ca[i-1]+(s[i]=='A'),cb[i]=cb[i-1]+(s[i]=='B');
	cout<<D1(0,0,n+m,n+m);
	return 0;
}