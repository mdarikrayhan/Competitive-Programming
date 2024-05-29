// LUOGU_RID: 159832290
#pragma GCC optimize(3)//o3优化 
#pragma GCC optimize(2, "Ofast", "inline")
#include<bits/stdc++.h>
#define int long long
#define P 998244353
#define N 110
#define PII pair<int,int>
#define x first
#define y second
using namespace std;
string n;
int ans,m,h;
int dp[N][10][10][2][N],_3[N];
PII f[N];
inline int gcd(int a, int b)
{
    if(!a)
        return b;
    if(!b)
        return a;
	register int az=__builtin_ctz(a),bz=__builtin_ctz(b),z=az>bz?bz:az,diff;
    b>>=bz;
    while(a)
    {
        a>>=az;
        diff=b-a;
        az=__builtin_ctz(diff);
        if(a<b)b=a;
        a=diff<0?-diff:diff;
    }
    return b<<z;
}
void init()
{
	_3[0]=1,_3[1]=3,_3[2]=9,_3[3]=27,_3[4]=81;
	return;
}
int add(int u,int a,int b) 
{
	if(u==h) 
		return h;
	for(int i=1;i<=m;i++) 
	{
		if(a==f[i].x) 
		{
			if(u/_3[i-1]%3==0) 
				u+=_3[i-1];
			else if(u/_3[i-1]%3==2) 
				return h;
		}
		if(b==f[i].y) 
		{
			if(u/_3[i-1]%3==0) 
				u+=2*_3[i-1];
			else if(u/_3[i-1]%3==1) 
				return h;
		}
	}
	return u;
}
void get(int p,int q,int len) 
{
	memset(dp,0,sizeof(dp));
	m=9/q; 
	for(int x=1;x<=9/q;x++) 
		f[x]={x*p,x*q};
	h=_3[m];
	for(int i=0;i<=9;i++) 
		dp[len][i*p/10][i*q/10][(i*q%10>n[len]-'0')][add(0,i*p%10,i*q%10)]++;
	for(int i=len;i>=2;i--) 
	{
		for(int z=0;z<=8;z++)
			for(int w=0;w<=8;w++)
				for(int k=0;k<=1;k++)
					for(int u=0;u<=h;u++)
						for(int hh=0;hh<=9;hh++)
							dp[i-1][(hh*p+z)/10][(hh*q+w)/10][(((hh*q+w)%10)>(n[i-1]-'0'))|(((hh*q+w)%10)==(n[i-1]-'0')&&k)][add(u,(hh*p+z)%10,(hh*q+w)%10)]+=dp[i][z][w][k][u];
		for(int z=0;z<=8;z++)
			for(int w=0;w<=8;w++)
				for(int k=0;k<=1;k++)
					for(int u=0;u<=h;u++)
						dp[i-1][z][w][k][u]%=P;
	}
	ans=(ans+dp[1][0][0][0][h])%P;
	return ;
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	init();
	cin>>n,n="&0"+n;
	int len=n.size()-1;
	for(int i=1;i<=9;i++)
		for(int j=i+1;j<=9;j++)
			if(gcd(i,j)==1) 
				get(i,j,len);
	int v=0;
	for(int i=1;i<=len;i++) 
		v=(v*10+n[i]-'0')%P;
	ans=(ans*2+v)%P;
	cout<<ans;
	return 0;
}